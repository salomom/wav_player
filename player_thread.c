/* player_thread.c */


#include "player_thread.h"
#include "dig_filter.h"
#include "echo.h"

#define N 8192             /* Anzahl der El. im soundcard Buffer */


/****************** Threadfunktion und Funktionen, die der Thread nutzt *****/
PTL_THREAD_RET_TYPE WavPlayerThreadFunc(void* pt)
{   sRam_t parameter;  // fuer lokale Kopie des shared RAM
    sndWaveHeader_t wh;
    short buf[N];
    int i=0;
    int err=0;
    FILE *fp_in;
    SndDevice_t *psd;


    printf("WAV-Player Thread ist gestartet...");
    // soundcard initialisieren ...

    psd = sndOpen(SND_WRITE_ONLY , SND_STEREO );
    if (NULL==psd) puts("cannot open dsp device");

    do
    {   // neue parameter holen: Dateinamen, play, end, usw.
        PTL_SemWait(&sRamSema);
        parameter = sRam;
        PTL_SemSignal(&sRamSema);

        //Feld auf 0 setzen
        for(i=0; i<N; i++){
            buf[i]=0;
        }

    /* != 0 bedeutet: Datei abspielen */
    if (parameter.cmd_play!=0){

        //Datei öffnen
        fp_in  = fopen(parameter.Dateiname,"rb");
        if (NULL==fp_in) puts("Fehler beim öffnen der Datei");

        /* Dateikopf auslesen */
        if(0!=sndWAVReadFileHeader(fp_in, &wh))
        {   puts("error in sndWAVReadFileHeader");
        }
        printf("Abtastfrequenz: %lu\n" , wh.nSamplesPerSec);
        printf("Anzahl Kanaele: %d\n" , wh.nChannels);
        printf("Anzahl Abtastwertepaare: %lu\n" , sndWAVGetNumberOfSamples(wh));

        /* Hier: nur 16Bit Stereo Dateien */
        if((wh.nChannels != 2) || (wh.nBytesPerSample != 4))
        {   puts("sorry: nur 16Bit Stereo-Dateien bitte:");
            return -1;//???
        }

        //kein error und nicht dateiende und play!=0 datei abspielen
        while(err==0 && feof(fp_in)==0 && parameter.cmd_play!=0){
            i=0;
        }


        //Datei Schliessen
        fclose(fp_in);
    }


    } while(parameter.cmd_end == 0);
    // soundcard schliessen ...
    sndClose(psd);

    printf("WAV-Player Thread terminiert...");
    PTL_SemSignal(&endSema);

    return 0;
}
/* Prototyp der Funktionen, die der Thread nutzt */



/*---------------------------------------------*/


/*---------------------------------------------*/





