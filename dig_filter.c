#include <stdio.h>
#include <math.h>
#include "dig_filter.h"
#include "cplx.h"



/****************************************************************/
/* TODO: Filter implementieren:                                 */
/*   Differenzengleichungen für TP, BP, HP je links und rechts  */
/*   Filterkoeffizienten berechen                               */
/*   Frequenzgang und Amplitudengang berechnen                  */
/****************************************************************/

void print_IIR_2_coeff(IIR_2_coeff_t p);

IIR_2_coeff_t compute_TP_Filter_Parameters(double fu_Hz, double fa_Hz) {
    double w0, k, d, b0, b1, b2, a1, a2;
    IIR_2_coeff_t TP_params;

    w0 = 2 * M_PI * fu_Hz;
    k = (w0 / tan(M_PI * (fu_Hz / fa_Hz)));
    d = w0 + k;
    b0 = pow((w0 / d), 2.0);
    b1 = 2 * b0;
    b2 = b0;
    a1 = 2 * ((w0 - k) / d);
    a2 = pow(a1, 2) / 4.0;

    TP_params.a1 = (float)a1;
    TP_params.a2 = (float)a2;
    TP_params.b0 = (float)b0;
    TP_params.b1 = (float)b1;
    TP_params.b2 = (float)b2;

    return TP_params;
};

IIR_2_coeff_t compute_BP_Filter_Parameters(double f0_Hz, double Q, double fa_Hz) {
    double w0, k, d, b0, b1, b2, a1, a2;
    IIR_2_coeff_t BP_params;

    w0 = 2 * M_PI * f0_Hz;
    k = (w0 / (tan(M_PI * (f0_Hz / fa_Hz))));
    d = ((w0 * w0) * Q) + w0 * k + ((k * k) * Q);
    b0 = (w0 * k) / d;
    b1 = 0;
    b2 = (-1) * b0;
    a1 = 2 * Q * (((w0 * w0) - (k * k)) / d);
    a2 = ((w0 * w0 * Q) - (w0 * k) + (k * k * Q)) / d;

    BP_params.a1 = (float)a1;
    BP_params.a2 = (float)a2;
    BP_params.b0 = (float)b0;
    BP_params.b1 = (float)b1;
    BP_params.b2 = (float)b2;

    return BP_params;
};

IIR_2_coeff_t compute_HP_Filter_Parameters(double fo_Hz, double fa_Hz) {
    double w0, k, d, b0, b1, b2, a1, a2;
    IIR_2_coeff_t HP_params;

    w0 = 2 * M_PI * fo_Hz;
    k = (w0 / tan(M_PI * (fo_Hz / fa_Hz)));
    d = w0 + k;
    b0 = pow((w0 / d), 2.0);
    b1 = -(2 * b0);
    b2 = b0;
    a1 = 2 * ((w0 - k) / d);
    a2 = pow(a1, 2) / 4.0;

    HP_params.a1 = (float)a1;
    HP_params.a2 = (float)a2;
    HP_params.b0 = (float)b0;
    HP_params.b1 = (float)b1;
    HP_params.b2 = (float)b2;

    return HP_params;
};

float TP_filter_left(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float TP_filter_right(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float BP_filter_left(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float BP_filter_right(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float HP_filter_left(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float HP_filter_right(float x, IIR_2_coeff_t p)
{
    static float x1, x2, y0, y1, y2;

    y0 = p.b0 * x + p.b1 * x1 + p.b2 * x2 - p.a1 * y1 - p.a2 * y2;

    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y0;

    return (y0);
}

float EQ_filter_left(float x, IIR_2_coeff_t p_TP, IIR_2_coeff_t p_BP, IIR_2_coeff_t p_HP,
                     float A_TP, float A_BP, float A_HP, float B)
{
    float tp_x, bp_x, hp_x, b_x;

    tp_x = TP_filter_left(x, p_TP) * A_TP;
    bp_x = BP_filter_left(x, p_BP) * A_BP;
    hp_x = HP_filter_left(x, p_HP) * A_HP;

    b_x = (x + tp_x + bp_x + hp_x) * B;

    return b_x;
}

float EQ_filter_right(float x, IIR_2_coeff_t p_TP, IIR_2_coeff_t p_BP, IIR_2_coeff_t p_HP,
                      float A_TP, float A_BP, float A_HP, float B)
{
    float tp_x, bp_x, hp_x, b_x;

    tp_x = TP_filter_right(x, p_TP) * A_TP;
    bp_x = BP_filter_right(x, p_BP) * A_BP;
    hp_x = HP_filter_right(x, p_HP) * A_HP;

    b_x = (x + tp_x + bp_x + hp_x) * B;

    return b_x;
}
