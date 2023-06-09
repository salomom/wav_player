#include <math.h>


#include "ptl_lib.h"
#include "dig_filter.h"
#include "echo.h"
#include "globals.h"

#include "gui.h"
#include "gui_plotter.h"




static App *app;
static Window *w, *w_plot;
static Timer *T;

/* Controls für die GUI */
Control *cbParametricEQ, *cbHideBodeDisplay;
Control *cbEcho;
Control *file_name, *volume;
Control *f_u, *f_0, *q, *f_o, *a_tp, *a_bp, *a_hp, *b;
Control *gain, *n_0, *feedback;


/* Prototypen für die Callback-Fktn */


void use_cbParametricEQ(Control *b);

void hide_plot_win_CB(Control *c);


void use_cbEcho(Control *b);


void redraw_main_win(Window *w, Graphics *g);
void close_plot_win(Window *w);
void close_win_and_shutdown(Window *w);
void Timer_CB(Timer *t);

void place_gui_elements_file(void);
void place_gui_elements_EQ(void);
void place_gui_elements_Echo(void);
void init_gui_elements(void);


/*--------------------------------------------------*/

void gui(int argc, char *argv[])
{
  app = new_app(argc, argv);
  w = new_window(app,rect(50,50,640,660),
                "Wave-Player", STANDARD_WINDOW);
  w_plot = new_window(app,rect(400,200,N_X_PLOT_WIN,N_Y_PLOT_WIN),
                "EQ-Amplitudengang", (TITLEBAR|MINIMIZE));

  place_gui_elements_file();
  place_gui_elements_EQ();
  place_gui_elements_Echo();

  on_window_redraw(w, redraw_main_win);
  on_window_redraw(w_plot, redraw_plot_win);

  init_gui_elements();




  show_window(w);
  show_window(w_plot);

  T = new_timer(app, Timer_CB, 1000);
  on_window_close (w_plot, close_plot_win);
  on_window_close (w, close_win_and_shutdown);

  main_loop(app);
  return;
}


/*-----------------------------*/




void use_cbParametricEQ(Control *b)
{   int flag_use_EQ=0;
    if(is_checked(b))
    {   printf("is_checked is TRUE\n");
        flag_use_EQ = 1;
    }
    else
    {   printf("is_checked is FALSE\n");
        flag_use_EQ = 0;
    }
    PTL_SemWait(&sRamSema);
    sRam.flag_EQ_is_active = flag_use_EQ;
    PTL_SemSignal(&sRamSema);
}


/*-----------------------------*/
void load_file(Control *c)
{
    PTL_SemWait(&sRamSema);
    strcpy(sRam.Dateiname, get_control_text(file_name));
    PTL_SemSignal(&sRamSema);
    printf("Dateiname: %s\n", get_control_text(file_name));
}

void play_file(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.cmd_play = 1;
    PTL_SemSignal(&sRamSema);
    printf("Play");
}

void stop_file(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.cmd_play = 0;
    sRam.cmd_end = 0;
    PTL_SemSignal(&sRamSema);
    printf("Stop");
}

void change_volume(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.B = (float)get_control_value(volume)/100;
    PTL_SemSignal(&sRamSema);
    printf("Volume: %f\n",(float)get_control_value(volume)/100);
}
/*-----------------------------*/


void hide_plot_win_CB(Control *c)
{
    if(is_checked(c))
    {
        hide_window(w_plot);
    }
    else
    {
        show_window(w_plot);
    }
}




/*-----------------------------*/

void use_cbEcho(Control *b)
{   int flag_use_Echo=0;

    if(is_checked(b))
    {   printf("is_checked is TRUE\n");
        flag_use_Echo=1;
    }
    else
    {   printf("is_checked is FALSE\n");
        flag_use_Echo=0;
    }
    PTL_SemWait(&sRamSema);
    sRam.flag_Echo_is_active = flag_use_Echo;
    PTL_SemSignal(&sRamSema);
}

/*-----------------------------*/

void change_n0(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.Echo.delay_n0 = get_control_value(n_0);
    PTL_SemSignal(&sRamSema);
    printf("N_0: %d\n",get_control_value(n_0));
}

void change_gain(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.Echo.gain = (float)get_control_value(gain)/100;
    PTL_SemSignal(&sRamSema);
    printf("Gain: %f\n",(float)get_control_value(gain)/100);
}

void change_feedback(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.Echo.feedback = (float)get_control_value(feedback)/100;
    PTL_SemSignal(&sRamSema);
    printf("Feedback: %f\n",(float)get_control_value(feedback)/100);
}

void change_f_u(Control *c)
{
    float fu;
    fu = (float)get_control_value(f_u);
    PTL_SemWait(&sRamSema);
    sRam.TP = compute_TP_Filter_Parameters(fu, F_S);
    PTL_SemSignal(&sRamSema);
}

void change_f_0(Control *c)
{
    float f0, q0;
    f0 = (float)get_control_value(f_0);
    q0 = (float)get_control_value(q) / 10;
    PTL_SemWait(&sRamSema);
    sRam.BP = compute_BP_Filter_Parameters(f0, q0, F_S);
    PTL_SemSignal(&sRamSema);
}

void change_f_o(Control *c)
{
    float fo;
    fo = (float)get_control_value(f_o);
    PTL_SemWait(&sRamSema);
    sRam.HP = compute_HP_Filter_Parameters(fo, F_S);
    PTL_SemSignal(&sRamSema);
}

void change_a_tp(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.A_TP = (float)(get_control_value(a_tp)-9)/10;
    PTL_SemSignal(&sRamSema);
    printf("A_TP: %f\n",(float)(get_control_value(a_tp)-9)/10);
}

void change_a_bp(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.A_BP = (float)(get_control_value(a_bp)-9)/10;
    PTL_SemSignal(&sRamSema);
    printf("A_BP: %f\n",(float)(get_control_value(a_bp)-9)/10);
}

void change_a_hp(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.A_HP = (float)(get_control_value(a_hp)-9)/10;
    PTL_SemSignal(&sRamSema);
    printf("A_HP: %f\n",(float)(get_control_value(a_hp)-9)/10);
}

void change_b(Control *c)
{
    PTL_SemWait(&sRamSema);
    sRam.B = (float)get_control_value(b)/100;
    PTL_SemSignal(&sRamSema);
    printf("A_HP: %f\n",(float)get_control_value(b)/100);
}

/*-----------------------------*/
void redraw_main_win(Window *w, Graphics *g)
{   Rect r;
    Point p_left,p_right,p_up,p_down,p_middle;
    int dx=32, dy=8;

    r = rect(10,10,620,130);
    draw_rect(g, r);            // Rahmen um File-Elemente
    r.y += (10 + r.height);
    r.height = 350;
    draw_rect(g, r);            // Rahmen um EQ-Elemente
    r.y += (10 + r.height);
    r.height = 140;
    draw_rect(g, r);            // Rahmen um Echo-Elemente

    // Kreuz bei Nullstellung der Gain-SLider des EQ
    // Low
    p_middle = pt(305,280);
    p_left   = pt(p_middle.x-dx/2,p_middle.y);
    p_right  = pt(p_middle.x+dx/2,p_middle.y);
    p_up     = pt(p_middle.x,p_middle.y-dy/2);
    p_down   = pt(p_middle.x,p_middle.y+dy/2);
    draw_line(g,p_left,p_right);
    draw_line(g,p_up,p_down);

    // Mid
    p_middle = pt(305,400);
    p_left   = pt(p_middle.x-dx/2,p_middle.y);
    p_right  = pt(p_middle.x+dx/2,p_middle.y);
    p_up     = pt(p_middle.x,p_middle.y-dy/2);
    p_down   = pt(p_middle.x,p_middle.y+dy/2);
    draw_line(g,p_left,p_right);
    draw_line(g,p_up,p_down);

    // High
    p_middle = pt(305,490);
    p_left   = pt(p_middle.x-dx/2,p_middle.y);
    p_right  = pt(p_middle.x+dx/2,p_middle.y);
    p_up     = pt(p_middle.x,p_middle.y-dy/2);
    p_down   = pt(p_middle.x,p_middle.y+dy/2);
    draw_line(g,p_left,p_right);
    draw_line(g,p_up,p_down);
}

/*-----------------------------*/
void Timer_CB(Timer *t)
{
    redraw_window(w_plot);
}


/*-----------------------------*/
void close_plot_win(Window *w)
{   hide_window(w);
    check(cbHideBodeDisplay);

}
/*-----------------------------*/
 void close_win_and_shutdown(Window *w)
 {
    /* Thread-Ende kommandieren: */
    PTL_SemWait(&sRamSema);
    sRam.cmd_play = 0;
    sRam.cmd_end  = 1;
    PTL_SemSignal(&sRamSema);
    puts("WAV-Player: main() wartet auf das Ende des Player-Threads...\n");
    PTL_SemWait(&endSema);
    puts("WAV-Player: main() wartet auf das Ende des Plotter-Threads...\n");
    PTL_SemWait(&endSema);
    puts("threads beendet...");
    puts("WAV-Player: main() ist beendet...\n");
    exit(-1);
    //del_timer(T);
    //del_app(app);
    //exit(-1);
 }

 void close_win_and_shutdown_control(Control *b) {
     close_win_and_shutdown(w);
 }
/*-----------------------------*/


void place_gui_elements_file(void)
{   Rect r;
    Control *b;

    r = rect(20,20,90,40);

    /********************************************************/
    /* TODO: hier Ihre GUI-Elemente load, play,stop         */
    /********************************************************/
    new_label(w, r, "Dateiname:", ALIGN_LEFT);
    r.x += 80; r.width = 300; r.height = 25;
    file_name = new_field(w, r, "");
    r.width = 80;
    r.x += 320;
    new_button(w, r, "Load", load_file);
    r.x = 20;
    r.y += 35;
    new_button(w, r, "Play", play_file);
    r.x += 100;
    new_button(w, r, "Stop", stop_file);
    r.x += 100;
    new_button(w, r, "Quit", close_win_and_shutdown_control);
    r.y += 50;
    r.x = 20;
    new_label(w, r, "Lautstärke:", ALIGN_LEFT);
    r.x += 100;
    r.width = 350;
    volume = new_scroll_bar(w,r,100,1, change_volume);


}
/*-----------------------------*/
void place_gui_elements_EQ(void)
{   Rect r;
    int space;

    r = rect(30, 160, 250, 20);
    cbParametricEQ = new_check_box(w, r, "use Parametric Filters",
                             use_cbParametricEQ);
    r.x += (10 + r.width);
    cbHideBodeDisplay = new_check_box(w,r, "hide Bode-Plot",
                        hide_plot_win_CB);

    /********************************************************/
    /* TODO: hier Ihre GUI-Elemente für die Filter erzeugen */
    /********************************************************/
    r.x = 30;
    r.y = 200;
    space = 35;
    new_label(w, r, "f_u:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "f_0:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "Q:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "f_o:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "A_tp:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "A_bp:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "A_hp:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "B:", ALIGN_LEFT);
    r.x += 100;
    r.y = 200;
    r.width = 450;
    f_u = new_scroll_bar(w,r,19999,1,change_f_u);
    r.y += space;
    f_0 = new_scroll_bar(w,r,19999,1,change_f_0);
    r.y += space;
    q = new_scroll_bar(w,r,100,1,change_f_0);
    r.y += space;
    f_o = new_scroll_bar(w,r,19999,1,change_f_o);
    r.y += space;
    a_tp = new_scroll_bar(w,r,99,1,change_a_tp);
    r.y += space;
    a_bp = new_scroll_bar(w,r,99,1,change_a_bp);
    r.y += space;
    a_hp = new_scroll_bar(w,r,99,1,change_a_hp);
    r.y += space;
    b = new_scroll_bar(w,r,100,1,change_b);


}
/*-----------------------------*/
void place_gui_elements_Echo(void)
{   Rect r;
    int space;

    r = rect(30, 520, 450, 20);
    cbEcho = new_check_box(w, r, "use Echo",
                                use_cbEcho);
    /********************************************************/
    /* TODO: hier Ihre GUI-Elemente für Echo erzeugen       */
    /********************************************************/
    r.y = 550;
    space = 35;
    new_label(w, r, "Gain:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "n_0:", ALIGN_LEFT);
    r.y += space;
    new_label(w, r, "Feedback:", ALIGN_LEFT);
    r.x += 100;
    r.y = 550;
    r.width = 450;
    gain = new_scroll_bar(w,r,50,1,change_gain);
    r.y += space;
    n_0 = new_scroll_bar(w,r,(F_S-1),1,change_n0);
    r.y += space;
    feedback = new_scroll_bar(w,r,100,1,change_feedback);
}
/*-----------------------------*/
void init_gui_elements(void)
{
    uncheck(cbParametricEQ);
    uncheck(cbHideBodeDisplay);


    uncheck(cbEcho);

}
/*-----------------------------*/




