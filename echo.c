/*****************************************************************
  Projekt-Name    : ringbuffer
  File-Name         : ringbuffer.c
  Programm-Zweck  :  Implementierung eines Ringbuffers fuer short-Werte.

  Der Einfachheit halber wird hier auf Pruefungen wie "rungbuffer voll"
  oder "leer" verzichtet. Der Ringbuffer hat eine feste Länge, die einer
  maximalen Verzögerung von 1sec entspricht.
  Ringbuffer gefuellt mit Nullen, maximales Delay:
    0   1                                                         len-1
  ---------------------------------------------------------------------
  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  ---------------------------------------------------------------------
    |                        ------->                               |
   rd                     Arbeitsrichtung                          wr
  nach einem Lesezugriff:
    0   1                                                         len-1
  ---------------------------------------------------------------------
  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
  ---------------------------------------------------------------------
        |                    ------->                               |
       rd                 Arbeitsrichtung                          wr
  nach einem Schreibzugriff:
    0   1                                                         len-1
  ---------------------------------------------------------------------
  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | x |
  ---------------------------------------------------------------------
    |   |                    ------->
   wr  rd                 Arbeitsrichtung
Die beiden Indizes laufen zirkular durch das Feld, was durch
inkrementieren und anschliessendes Modulo len erreicht wird.

  Erstellt durch  : Fgb
  Erstellt am     : 20.03.2007
  Historie: 20.3.2007 erstellt, Modul ringbuffer entwickelt.
            29.7.2020 angepasst für Wav-Player 2.0
 *****************************************************************/


#include <stdio.h>
#include <stdlib.h>


#include "echo.h"
#include "globals.h"

#define N_BUF F_S     /* F_S ist die Abtastfrequenz in Hz, d.h. 1 Sekunde max Delay */

typedef struct {
    short buf[N_BUF];  /* max 1sec Delay */
    int wr;	/* next write at this index */
    int rd;     /* next read at this index */
}RingBufferShort_t;

static RingBufferShort_t rb={0};

static void WriteToRingBufferShort(short x)
{
  rb.buf[rb.wr] = x;
}

static short ReadFromRingBufferShort(void)
{
  short buf;
  buf = rb.buf[rb.rd];
  rb.rd++;
  rb.rd = rb.rd % N_BUF;
  return buf;
}





/***********************************************************************/
/* TODO: Echo implementieren                                           */
/***********************************************************************/

sndStereo16_t add_echo(sndStereo16_t x, echo_params_t p)
{
      sndStereo16_t y;
      float mono_buffer;
      float gain_buffer;
      float feedback_buffer;
      short bufferIn;
      static short bufferOut = 0;

      mono_buffer = x.val_li + x.val_re;
      gain_buffer = mono_buffer * p.gain;
      feedback_buffer = bufferOut * p.feedback;
      bufferIn = (short)(feedback_buffer + gain_buffer);

      rb.wr = (rb.rd + p.delay_n0) % N_BUF;
      WriteToRingBufferShort(bufferIn);
      bufferOut = ReadFromRingBufferShort();

      y.val_re = (short)(bufferOut + x.val_re);
      y.val_li = (short)(bufferOut + x.val_li);

      return y;
}
