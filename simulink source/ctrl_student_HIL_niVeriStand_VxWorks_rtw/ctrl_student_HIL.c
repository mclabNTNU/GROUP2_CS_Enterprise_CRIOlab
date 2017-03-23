/*
 * ctrl_student_HIL.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.174
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 23 16:26:29 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

const real_T ctrl_student_HIL_RGND = 0.0;/* real_T ground */

/* Block signals (auto storage) */
B_ctrl_student_HIL_T ctrl_student_HIL_B;

/* Continuous states */
X_ctrl_student_HIL_T ctrl_student_HIL_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_T ctrl_student_HIL_DW;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_T ctrl_student_HIL_M_;
RT_MODEL_ctrl_student_HIL_T *const ctrl_student_HIL_M = &ctrl_student_HIL_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_output();
  ctrl_student_HIL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void ctrl_student_HIL_output(void)
{
  boolean_T y;
  real_T x[10];
  boolean_T guard1 = false;
  boolean_T exitg2;
  real_T Us;
  real_T x_ds;
  real_T y_ds;
  real_T x_ds2;
  real_T y_ds2;
  real_T R[9];
  real_T S[9];
  static const real_T a[9] = { 16.79, 0.0, 0.0, 0.0, 15.79, 0.55462499999999992,
    0.0, 0.55462499999999992, 2.76 };

  static const real_T b_a[9] = { -0.2, -0.0, -0.0, -0.0, -0.2, -0.0, -0.0, -0.0,
    -0.1 };

  static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T a_0[9] = { -0.059559261465157838, 0.0, -0.0, 0.0,
    -0.040521023365024243, 0.0081427436897922364, 0.0, 0.0081427436897922364,
    -0.36395513377498229 };

  static const real_T b_a_0[9] = { 0.059559261465157838, -0.0, 0.0, -0.0,
    0.040521023365024243, -0.0081427436897922364, -0.0, -0.0081427436897922364,
    0.36395513377498229 };

  static const real_T c_a[9] = { 0.059559261465157838, 0.0, 0.0, 0.0,
    0.040521023365024243, -0.0081427436897922364, 0.0, -0.0081427436897922364,
    0.36395513377498229 };

  real_T rtb_Switch[3];
  real_T rtb_U_max;
  real_T rtb_Drop;
  int32_T i;
  real_T R_0[3];
  real_T S_0[3];
  real_T R_1[9];
  real_T R_2[3];
  real_T b_a_1[3];
  real_T a_1[3];
  real_T tmp[9];
  real_T a_2[9];
  real_T tmp_0[9];
  real_T tmp_1[81];
  real_T tmp_2[9];
  int32_T i_0;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_M->solverInfo,
                            ((ctrl_student_HIL_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_M->Timing.stepSize0 +
        ctrl_student_HIL_M->Timing.clockTickH0 *
        ctrl_student_HIL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_M)) {
    ctrl_student_HIL_M->Timing.t[0] = rtsiGetT(&ctrl_student_HIL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S12>/counter' */
    ctrl_student_HIL_B.counter = ctrl_student_HIL_DW.counter_PreviousInput;
  }

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Step size'
   */
  /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S15>:1' */
  /* '<S15>:1:3' */
  if ((ctrl_student_HIL_B.counter + 1.0) * ctrl_student_HIL_P.Stepsize_Value >=
      1.0 / ctrl_student_HIL_B.Desiredsamplingfrequency) {
    /* '<S15>:1:4' */
    /* '<S15>:1:5' */
    ctrl_student_HIL_B.count = 0.0;
  } else {
    /* '<S15>:1:7' */
    ctrl_student_HIL_B.count = ctrl_student_HIL_B.counter + 1.0;
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S18>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise = ctrl_student_HIL_DW.NextOutput;

    /* RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_p = ctrl_student_HIL_DW.NextOutput_a;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_B.WhiteNoise_i = ctrl_student_HIL_DW.NextOutput_f;

    /* Memory: '<S13>/Hold' */
    ctrl_student_HIL_B.Hold[0] = ctrl_student_HIL_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_B.Hold[1] = ctrl_student_HIL_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_B.Hold[2] = ctrl_student_HIL_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S13>/MATLAB Function1' incorporates:
   *  Constant: '<S3>/Step size'
   *  Product: '<S17>/Divide'
   *  Product: '<S17>/Product'
   *  Product: '<S18>/Divide'
   *  Product: '<S18>/Product'
   *  Product: '<S19>/Divide'
   *  Product: '<S19>/Product'
   *  Sqrt: '<S17>/Sqrt'
   *  Sqrt: '<S18>/Sqrt'
   *  Sqrt: '<S19>/Sqrt'
   *  Sum: '<S3>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S16>:1' */
  if (ctrl_student_HIL_B.count == 0.0) {
    /* '<S16>:1:4' */
    /* '<S16>:1:5' */
    ctrl_student_HIL_B.output[0] = sqrt(ctrl_student_HIL_B.noisepowerposition /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise +
      ctrl_student_HIL_B.x_in;
    ctrl_student_HIL_B.output[1] = sqrt(ctrl_student_HIL_B.noisepowerposition /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_p +
      ctrl_student_HIL_B.y_in;
    ctrl_student_HIL_B.output[2] = sqrt(ctrl_student_HIL_B.noisepowerheading /
      ctrl_student_HIL_P.Stepsize_Value) * ctrl_student_HIL_B.WhiteNoise_i +
      ctrl_student_HIL_B.psi_in;
  } else {
    /* '<S16>:1:7' */
    ctrl_student_HIL_B.output[0] = ctrl_student_HIL_B.Hold[0];
    ctrl_student_HIL_B.output[1] = ctrl_student_HIL_B.Hold[1];
    ctrl_student_HIL_B.output[2] = ctrl_student_HIL_B.Hold[2];
  }

  /* End of MATLAB Function: '<S13>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S4>/Memory' */
    memcpy(&ctrl_student_HIL_B.Memory[0],
           &ctrl_student_HIL_DW.Memory_PreviousInput[0], 9U * sizeof(real_T));

    /* Memory: '<S2>/Memory4' */
    ctrl_student_HIL_B.Memory4[0] = ctrl_student_HIL_DW.Memory4_PreviousInput[0];
    ctrl_student_HIL_B.Memory4[1] = ctrl_student_HIL_DW.Memory4_PreviousInput[1];
    ctrl_student_HIL_B.Memory4[2] = ctrl_student_HIL_DW.Memory4_PreviousInput[2];
  }

  /* Switch: '<S3>/Switch' */
  if (ctrl_student_HIL_B.enablenoise != 0.0) {
    rtb_Switch[0] = ctrl_student_HIL_B.output[0];
    rtb_Switch[1] = ctrl_student_HIL_B.output[1];
    rtb_Switch[2] = ctrl_student_HIL_B.output[2];
  } else {
    rtb_Switch[0] = ctrl_student_HIL_B.x_in;
    rtb_Switch[1] = ctrl_student_HIL_B.y_in;
    rtb_Switch[2] = ctrl_student_HIL_B.psi_in;
  }

  /* End of Switch: '<S3>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    for (i = 0; i < 10; i++) {
      /* Memory: '<S1>/Memory2' */
      ctrl_student_HIL_B.Memory2[i] =
        ctrl_student_HIL_DW.Memory2_PreviousInput[i];

      /* Memory: '<S1>/Memory1' */
      ctrl_student_HIL_B.Memory1[i] =
        ctrl_student_HIL_DW.Memory1_PreviousInput[i];
    }
  }

  /* MATLAB Function: '<S1>/DROP DETECTOR' */
  /* MATLAB Function 'DROP DETECTOR (CASE B)/DROP DETECTOR': '<S9>:1' */
  /* '<S9>:1:3' */
  /* '<S9>:1:4' */
  /* '<S9>:1:6' */
  /* '<S9>:1:7' */
  /* '<S9>:1:9' */
  ctrl_student_HIL_B.Mx1[0] = ctrl_student_HIL_B.Memory2[1];
  ctrl_student_HIL_B.Mx1[1] = ctrl_student_HIL_B.Memory2[2];
  ctrl_student_HIL_B.Mx1[2] = ctrl_student_HIL_B.Memory2[3];
  ctrl_student_HIL_B.Mx1[3] = ctrl_student_HIL_B.Memory2[4];
  ctrl_student_HIL_B.Mx1[4] = ctrl_student_HIL_B.Memory2[5];
  ctrl_student_HIL_B.Mx1[5] = ctrl_student_HIL_B.Memory2[6];
  ctrl_student_HIL_B.Mx1[6] = ctrl_student_HIL_B.Memory2[7];
  ctrl_student_HIL_B.Mx1[7] = ctrl_student_HIL_B.Memory2[8];
  ctrl_student_HIL_B.Mx1[8] = ctrl_student_HIL_B.Memory2[9];
  ctrl_student_HIL_B.Mx1[9] = rtb_Switch[0];

  /* '<S9>:1:10' */
  ctrl_student_HIL_B.My1[0] = ctrl_student_HIL_B.Memory1[1];
  ctrl_student_HIL_B.My1[1] = ctrl_student_HIL_B.Memory1[2];
  ctrl_student_HIL_B.My1[2] = ctrl_student_HIL_B.Memory1[3];
  ctrl_student_HIL_B.My1[3] = ctrl_student_HIL_B.Memory1[4];
  ctrl_student_HIL_B.My1[4] = ctrl_student_HIL_B.Memory1[5];
  ctrl_student_HIL_B.My1[5] = ctrl_student_HIL_B.Memory1[6];
  ctrl_student_HIL_B.My1[6] = ctrl_student_HIL_B.Memory1[7];
  ctrl_student_HIL_B.My1[7] = ctrl_student_HIL_B.Memory1[8];
  ctrl_student_HIL_B.My1[8] = ctrl_student_HIL_B.Memory1[9];
  ctrl_student_HIL_B.My1[9] = rtb_Switch[1];
  for (i = 0; i < 10; i++) {
    x[i] = ctrl_student_HIL_B.Mx1[i] - ctrl_student_HIL_B.Memory2[i];
  }

  y = true;
  i = 0;
  exitg2 = false;
  while ((!exitg2) && (i < 10)) {
    if (x[i] == 0.0) {
      y = false;
      exitg2 = true;
    } else {
      i++;
    }
  }

  if (y) {
    for (i = 0; i < 10; i++) {
      x[i] = ctrl_student_HIL_B.My1[i] - ctrl_student_HIL_B.Memory1[i];
    }

    exitg2 = true;
    i = 0;
    y = false;
    while ((!y) && (i < 10)) {
      if (x[i] == 0.0) {
        exitg2 = false;
        y = true;
      } else {
        i++;
      }
    }

    if (exitg2) {
      /* '<S9>:1:13' */
      rtb_Drop = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    /* '<S9>:1:15' */
    rtb_Drop = 0.0;
  }

  /* End of MATLAB Function: '<S1>/DROP DETECTOR' */

  /* MATLAB Function: '<Root>/SWITCH' incorporates:
   *  Integrator: '<Root>/Int2'
   *  Sum: '<Root>/Sum4'
   */
  /* MATLAB Function 'SWITCH': '<S5>:1' */
  if (rtb_Drop == 1.0) {
    /* '<S5>:1:3' */
    /* '<S5>:1:4' */
    ctrl_student_HIL_B.Eta[0] = ctrl_student_HIL_X.Int2_CSTATE + rtb_Switch[0];
    ctrl_student_HIL_B.Eta[1] = ctrl_student_HIL_X.Int2_CSTATE + rtb_Switch[1];
    ctrl_student_HIL_B.Eta[2] = ctrl_student_HIL_X.Int2_CSTATE + rtb_Switch[2];
  } else {
    /* '<S5>:1:6' */
    ctrl_student_HIL_B.Eta[0] = rtb_Switch[0];
    ctrl_student_HIL_B.Eta[1] = rtb_Switch[1];
    ctrl_student_HIL_B.Eta[2] = rtb_Switch[2];
  }

  /* End of MATLAB Function: '<Root>/SWITCH' */
  /* %Eta = [0,0,0]'; */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S21>/Memory3' */
    ctrl_student_HIL_B.Memory3 = ctrl_student_HIL_DW.Memory3_PreviousInput;

    /* Memory: '<S21>/Memory5' */
    ctrl_student_HIL_B.Memory5 = ctrl_student_HIL_DW.Memory5_PreviousInput;
  }

  /* MATLAB Function: '<S21>/Tank Limits' */
  /* MATLAB Function 'Tank (CASE B)/TANK LIMITS (CASE B)/Tank Limits': '<S22>:1' */
  /* '<S22>:1:4' */
  /* '<S22>:1:5' */
  /* psi = eta(3); */
  /* '<S22>:1:9' */
  /* '<S22>:1:10' */
  /* '<S22>:1:11' */
  /* '<S22>:1:12' */
  /*  If too close from edges, change sign */
  if (ctrl_student_HIL_B.Memory3 == 0.0) {
    /* '<S22>:1:16' */
    if ((ctrl_student_HIL_B.Eta[0] < -1.5) || (ctrl_student_HIL_B.Eta[0] > 1.5) ||
        (ctrl_student_HIL_B.Eta[1] < -2.5) || (ctrl_student_HIL_B.Eta[1] > 2.5))
    {
      /* '<S22>:1:17' */
      /* '<S22>:1:18' */
      rtb_Drop = -ctrl_student_HIL_B.Memory5;

      /* '<S22>:1:19' */
      ctrl_student_HIL_B.M1 = 1.0;
    } else {
      /* '<S22>:1:21' */
      ctrl_student_HIL_B.M1 = ctrl_student_HIL_B.Memory3;

      /* '<S22>:1:22' */
      rtb_Drop = ctrl_student_HIL_B.Memory5;
    }
  } else {
    /*  M = 1 */
    if ((ctrl_student_HIL_B.Eta[0] >= -0.75) && (ctrl_student_HIL_B.Eta[0] <=
         0.75) && (ctrl_student_HIL_B.Eta[1] >= -1.25) &&
        (ctrl_student_HIL_B.Eta[1] <= 1.25)) {
      /* '<S22>:1:25' */
      /* '<S22>:1:26' */
      ctrl_student_HIL_B.M1 = 0.0;

      /* '<S22>:1:27' */
      rtb_Drop = ctrl_student_HIL_B.Memory5;
    } else {
      /* '<S22>:1:29' */
      ctrl_student_HIL_B.M1 = ctrl_student_HIL_B.Memory3;

      /* '<S22>:1:30' */
      rtb_Drop = ctrl_student_HIL_B.Memory5;
    }
  }

  /* '<S22>:1:34' */
  ctrl_student_HIL_B.x_d1 = rtb_Drop * ctrl_student_HIL_B.Memory4[0];
  ctrl_student_HIL_B.s1 = rtb_Drop;

  /* End of MATLAB Function: '<S21>/Tank Limits' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S2>/s(0)' */
    ctrl_student_HIL_B.s0 = ctrl_student_HIL_DW.s0_PreviousInput;
  }

  /* Step: '<S2>/Step' */
  if (ctrl_student_HIL_M->Timing.t[0] < ctrl_student_HIL_P.Step_Time) {
    rtb_U_max = ctrl_student_HIL_P.Step_Y0;
  } else {
    rtb_U_max = ctrl_student_HIL_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* Gain: '<S2>/U_max' */
  rtb_U_max *= ctrl_student_HIL_P.U_max_Gain;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S2>/Memory' */
    ctrl_student_HIL_B.Memory_c[0] = ctrl_student_HIL_DW.Memory_PreviousInput_a
      [0];
    ctrl_student_HIL_B.Memory_c[1] = ctrl_student_HIL_DW.Memory_PreviousInput_a
      [1];
    ctrl_student_HIL_B.Memory_c[2] = ctrl_student_HIL_DW.Memory_PreviousInput_a
      [2];
  }

  /* MATLAB Function: '<S2>/Guidance (Ellipse)' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  /* MATLAB Function 'Guidance (CASE D)/Guidance (Ellipse)': '<S11>:1' */
  /* % Ellipse Kinematics */
  /* '<S11>:1:9' */
  /* '<S11>:1:10' */
  /* '<S11>:1:14' */
  /* '<S11>:1:15' */
  /* '<S11>:1:17' */
  x_ds = -5.0 * sin(ctrl_student_HIL_B.s0);

  /* '<S11>:1:18' */
  y_ds = 3.0 * cos(ctrl_student_HIL_B.s0);

  /* '<S11>:1:20' */
  x_ds2 = -5.0 * cos(ctrl_student_HIL_B.s0);

  /* '<S11>:1:21' */
  y_ds2 = -3.0 * sin(ctrl_student_HIL_B.s0);

  /* '<S11>:1:23' */
  /* '<S11>:1:24' */
  /* '<S11>:1:26' */
  /* '<S11>:1:27' */
  /* '<S11>:1:28' */
  rtb_Drop = x_ds * x_ds + y_ds * y_ds;

  /* '<S11>:1:30' */
  ctrl_student_HIL_B.eta_d[0] = 5.0 * cos(ctrl_student_HIL_B.s0) + 6.0;
  ctrl_student_HIL_B.eta_d[1] = 3.0 * sin(ctrl_student_HIL_B.s0);
  ctrl_student_HIL_B.eta_d[2] = rt_atan2d_snf(y_ds, x_ds);

  /* '<S11>:1:31' */
  ctrl_student_HIL_B.eta_ds[0] = x_ds;
  ctrl_student_HIL_B.eta_ds[1] = y_ds;
  ctrl_student_HIL_B.eta_ds[2] = (-y_ds * x_ds + x_ds * y_ds2) / (x_ds * x_ds +
    y_ds * y_ds);

  /* '<S11>:1:32' */
  ctrl_student_HIL_B.eta_ds2[0] = x_ds2;
  ctrl_student_HIL_B.eta_ds2[1] = y_ds2;
  ctrl_student_HIL_B.eta_ds2[2] = ((5.0 * sin(ctrl_student_HIL_B.s0) * -y_ds +
    -3.0 * cos(ctrl_student_HIL_B.s0) * x_ds) * (x_ds * x_ds + y_ds * y_ds) -
    (2.0 * x_ds2 * x_ds + 2.0 * y_ds2 * y_ds) * (-y_ds * x_ds2 + x_ds * y_ds2)) /
    (rtb_Drop * rtb_Drop);

  /* '<S11>:1:34' */
  Us = rtb_U_max / sqrt(x_ds * x_ds + y_ds * y_ds);

  /* '<S11>:1:35' */
  rtb_Drop = (x_ds * x_ds2 + y_ds * y_ds2) * rtb_U_max / rt_powd_snf(x_ds * x_ds
    + y_ds * y_ds, 1.5);

  /* % Update Law */
  /* '<S11>:1:40' */
  /* '<S11>:1:41' */
  x_ds = 2.2250738585072014E-308;
  y_ds = fabs(ctrl_student_HIL_B.eta_ds[0]);
  if (y_ds > 2.2250738585072014E-308) {
    rtb_U_max = 1.0;
    x_ds = y_ds;
  } else {
    x_ds2 = y_ds / 2.2250738585072014E-308;
    rtb_U_max = x_ds2 * x_ds2;
  }

  y_ds = fabs(ctrl_student_HIL_B.eta_ds[1]);
  if (y_ds > x_ds) {
    x_ds2 = x_ds / y_ds;
    rtb_U_max = rtb_U_max * x_ds2 * x_ds2 + 1.0;
    x_ds = y_ds;
  } else {
    x_ds2 = y_ds / x_ds;
    rtb_U_max += x_ds2 * x_ds2;
  }

  y_ds = fabs(ctrl_student_HIL_B.eta_ds[2]);
  if (y_ds > x_ds) {
    x_ds2 = x_ds / y_ds;
    rtb_U_max = rtb_U_max * x_ds2 * x_ds2 + 1.0;
    x_ds = y_ds;
  } else {
    x_ds2 = y_ds / x_ds;
    rtb_U_max += x_ds2 * x_ds2;
  }

  rtb_U_max = x_ds * sqrt(rtb_U_max);
  ctrl_student_HIL_B.s_dot = Us - ((-ctrl_student_HIL_B.eta_ds[0] *
    ctrl_student_HIL_B.Memory_c[0] + -ctrl_student_HIL_B.eta_ds[1] *
    ctrl_student_HIL_B.Memory_c[1]) + -ctrl_student_HIL_B.eta_ds[2] *
    ctrl_student_HIL_B.Memory_c[2]) * ctrl_student_HIL_P.Constant1_Value_l /
    rtb_U_max;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S2>/Memory1' */
    ctrl_student_HIL_B.Memory1_k[0] =
      ctrl_student_HIL_DW.Memory1_PreviousInput_d[0];
    ctrl_student_HIL_B.Memory1_k[1] =
      ctrl_student_HIL_DW.Memory1_PreviousInput_d[1];
    ctrl_student_HIL_B.Memory1_k[2] =
      ctrl_student_HIL_DW.Memory1_PreviousInput_d[2];

    /* Memory: '<S2>/Memory2' */
    ctrl_student_HIL_B.Memory2_e[0] =
      ctrl_student_HIL_DW.Memory2_PreviousInput_d[0];
    ctrl_student_HIL_B.Memory2_e[1] =
      ctrl_student_HIL_DW.Memory2_PreviousInput_d[1];
    ctrl_student_HIL_B.Memory2_e[2] =
      ctrl_student_HIL_DW.Memory2_PreviousInput_d[2];

    /* Memory: '<S2>/Memory3' */
    ctrl_student_HIL_B.Memory3_l[0] =
      ctrl_student_HIL_DW.Memory3_PreviousInput_c[0];
    ctrl_student_HIL_B.Memory3_l[1] =
      ctrl_student_HIL_DW.Memory3_PreviousInput_c[1];
    ctrl_student_HIL_B.Memory3_l[2] =
      ctrl_student_HIL_DW.Memory3_PreviousInput_c[2];
  }

  /* MATLAB Function: '<S2>/Control Law' incorporates:
   *  Constant: '<S2>/Constant2'
   *  MATLAB Function: '<S2>/Guidance (Ellipse)'
   */
  /* MATLAB Function 'Guidance (CASE D)/Control Law': '<S10>:1' */
  /* % ROTATION MATRICES */
  /* '<S10>:1:7' */
  /*  psi : yaw angle */
  /* '<S10>:1:8' */
  /*  r : yaw rate */
  /* '<S10>:1:9' */
  /*  u : surge velocity */
  /* '<S10>:1:10' */
  /*  v : sway velocity */
  /* '<S10>:1:13' */
  R[0] = cos(ctrl_student_HIL_B.Eta[2]);
  R[3] = -sin(ctrl_student_HIL_B.Eta[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_B.Eta[2]);
  R[4] = cos(ctrl_student_HIL_B.Eta[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S10>:1:17' */
  S[0] = 0.0;
  S[3] = -ctrl_student_HIL_B.Memory[5];
  S[6] = 0.0;
  S[1] = ctrl_student_HIL_B.Memory[5];
  S[4] = 0.0;
  S[7] = 0.0;
  S[2] = 0.0;
  S[5] = 0.0;
  S[8] = 0.0;

  /* % MASS MATRIX (from CSEI_tau) */
  /*  x_g  =  0.0460; % Table B.1 */
  /*  Added mass */
  /*  Table B.1 */
  /*  Table B.1 guestimate */
  /*  Table B.1 */
  /*  Total mass matrix */
  /* % DAMPING MATRIX (from CSEI_tau) */
  /* '<S10>:1:43' */
  /* '<S10>:1:47' */
  /*  Y_r */
  /*  Y_rr */
  /*  Y_rv, Y_vr */
  /* '<S10>:1:53' */
  /*  N_r */
  /*  N_rr */
  /*  N_rv, N_vr */
  /*  Assembly of the damping matrix */
  /* '<S10>:1:60' */
  /* '<S10>:1:61' */
  /* '<S10>:1:62' */
  /*  using abs(r) */
  /* '<S10>:1:65' */
  /* '<S10>:1:66' */
  /* '<S10>:1:68' */
  /* % CASE D */
  /*  Kp (tuning) */
  /* '<S10>:1:77' */
  /*  K2 (tuning) */
  /* '<S10>:1:79' */
  rtb_U_max = ctrl_student_HIL_B.Eta[0] - ctrl_student_HIL_B.Memory1_k[0];
  x_ds = ctrl_student_HIL_B.Eta[1] - ctrl_student_HIL_B.Memory1_k[1];
  y_ds = ctrl_student_HIL_B.Eta[2] - ctrl_student_HIL_B.Memory1_k[2];
  for (i = 0; i < 3; i++) {
    rtb_Switch[i] = R[3 * i + 2] * y_ds + (R[3 * i + 1] * x_ds + R[3 * i] *
      rtb_U_max);
  }

  /*  z1 */
  /* '<S10>:1:80' */
  /*  alpha1 */
  /* '<S10>:1:81' */
  /*  R*z1 */
  /* '<S10>:1:83' */
  /*  z1_dot */
  /* '<S10>:1:84' */
  /*  alpha1_dot */
  /* '<S10>:1:86' */
  /*  z2 */
  /* '<S10>:1:88' */
  a_2[0] = (0.6555 - 0.3545 * ctrl_student_HIL_B.Memory[3]) -
    ctrl_student_HIL_B.Memory[3] * ctrl_student_HIL_B.Memory[3] * -3.787;
  a_2[3] = 0.0;
  a_2[6] = 0.0;
  a_2[1] = 0.0;
  a_2[4] = ((1.33 - -2.776 * ctrl_student_HIL_B.Memory[4]) -
            ctrl_student_HIL_B.Memory[4] * ctrl_student_HIL_B.Memory[4] * -64.91)
    - -0.805 * fabs(ctrl_student_HIL_B.Memory[5]);
  a_2[7] = ((7.25 - -3.45 * fabs(ctrl_student_HIL_B.Memory[5])) -
            ctrl_student_HIL_B.Memory[5] * ctrl_student_HIL_B.Memory[5] * 0.0) -
    -0.845 * fabs(ctrl_student_HIL_B.Memory[4]);
  a_2[2] = 0.0;
  a_2[5] = ((-0.0 - -0.2088 * ctrl_student_HIL_B.Memory[4]) -
            ctrl_student_HIL_B.Memory[4] * ctrl_student_HIL_B.Memory[4] * 0.0) -
    0.13 * fabs(ctrl_student_HIL_B.Memory[5]);
  a_2[8] = ((1.9 - -0.75 * fabs(ctrl_student_HIL_B.Memory[5])) -
            ctrl_student_HIL_B.Memory[5] * ctrl_student_HIL_B.Memory[5] * 0.0) -
    0.08 * fabs(ctrl_student_HIL_B.Memory[4]);
  for (i = 0; i < 3; i++) {
    R_0[i] = R[3 * i + 2] * ctrl_student_HIL_B.Memory2_e[2] + (R[3 * i + 1] *
      ctrl_student_HIL_B.Memory2_e[1] + R[3 * i] * ctrl_student_HIL_B.Memory2_e
      [0]);
  }

  for (i = 0; i < 3; i++) {
    S_0[i] = (((S[3 * i + 1] * rtb_Switch[1] + S[3 * i] * rtb_Switch[0]) + S[3 *
               i + 2] * rtb_Switch[2]) + ctrl_student_HIL_B.Memory[3 + i]) -
      R_0[i] * ctrl_student_HIL_B.s_dot;
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      R_1[i + 3 * i_0] = 0.0;
      R_1[i + 3 * i_0] += S[3 * i] * R[i_0];
      R_1[i + 3 * i_0] += S[3 * i + 1] * R[i_0 + 3];
      R_1[i + 3 * i_0] += S[3 * i + 2] * R[i_0 + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    R_0[i] = R_1[i + 6] * ctrl_student_HIL_B.Memory2_e[2] + (R_1[i + 3] *
      ctrl_student_HIL_B.Memory2_e[1] + R_1[i] * ctrl_student_HIL_B.Memory2_e[0]);
  }

  rtb_U_max = ctrl_student_HIL_B.Memory3_l[0] * Us +
    ctrl_student_HIL_B.Memory2_e[0] * rtb_Drop;
  x_ds = ctrl_student_HIL_B.Memory3_l[1] * Us + ctrl_student_HIL_B.Memory2_e[1] *
    rtb_Drop;
  y_ds = ctrl_student_HIL_B.Memory3_l[2] * Us + ctrl_student_HIL_B.Memory2_e[2] *
    rtb_Drop;
  for (i = 0; i < 3; i++) {
    R_2[i] = R[3 * i + 2] * y_ds + (R[3 * i + 1] * x_ds + R[3 * i] * rtb_U_max);
  }

  for (i = 0; i < 3; i++) {
    b_a_1[i] = (((b_a[i + 3] * S_0[1] + b_a[i] * S_0[0]) + b_a[i + 6] * S_0[2])
                + R_0[i] * Us) + R_2[i] * ctrl_student_HIL_B.s_dot;
  }

  for (i = 0; i < 3; i++) {
    R_2[i] = a_2[i + 6] * ctrl_student_HIL_B.Memory[5] + (a_2[i + 3] *
      ctrl_student_HIL_B.Memory[4] + a_2[i] * ctrl_student_HIL_B.Memory[3]);
  }

  for (i = 0; i < 3; i++) {
    a_1[i] = a[i + 6] * b_a_1[2] + (a[i + 3] * b_a_1[1] + a[i] * b_a_1[0]);
  }

  for (i = 0; i < 3; i++) {
    R_0[i] = R[3 * i + 2] * ctrl_student_HIL_B.Memory2_e[2] + (R[3 * i + 1] *
      ctrl_student_HIL_B.Memory2_e[1] + R[3 * i] * ctrl_student_HIL_B.Memory2_e
      [0]);
  }

  for (i = 0; i < 3; i++) {
    S_0[i] = ctrl_student_HIL_B.Memory[3 + i] - (((b_a[i + 3] * rtb_Switch[1] +
      b_a[i] * rtb_Switch[0]) + b_a[i + 6] * rtb_Switch[2]) + R_0[i] * Us);
  }

  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Tau[i] = ((R_2[i] + a_1[i]) - (((real_T)b_b[i + 3] *
      ctrl_student_HIL_P.Constant2_Value_p * S_0[1] +
      ctrl_student_HIL_P.Constant2_Value_p * (real_T)b_b[i] * S_0[0]) + (real_T)
      b_b[i + 6] * ctrl_student_HIL_P.Constant2_Value_p * S_0[2])) -
      rtb_Switch[i];
  }

  /*  Tau */
  for (i = 0; i < 3; i++) {
    ctrl_student_HIL_B.Rz1[i] = 0.0;
    ctrl_student_HIL_B.Rz1[i] += R[i] * rtb_Switch[0];
    ctrl_student_HIL_B.Rz1[i] += R[i + 3] * rtb_Switch[1];
    ctrl_student_HIL_B.Rz1[i] += R[i + 6] * rtb_Switch[2];
  }

  /* End of MATLAB Function: '<S2>/Control Law' */

  /* Integrator: '<S2>/s' */
  ctrl_student_HIL_B.s = ctrl_student_HIL_X.s_CSTATE;

  /* Integrator: '<Root>/Int1' */
  ctrl_student_HIL_B.Int1 = ctrl_student_HIL_X.Int1_CSTATE;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  /* Sum: '<S4>/Subtract' */
  ctrl_student_HIL_B.Subtract = ctrl_student_HIL_B.Eta[0] -
    ctrl_student_HIL_B.Memory[0];

  /* Sum: '<S4>/Subtract1' */
  ctrl_student_HIL_B.Subtract1 = ctrl_student_HIL_B.Eta[1] -
    ctrl_student_HIL_B.Memory[1];

  /* Sum: '<S4>/Subtract2' */
  ctrl_student_HIL_B.Subtract2 = ctrl_student_HIL_B.Eta[2] -
    ctrl_student_HIL_B.Memory[2];

  /* MATLAB Function: '<S4>/DP Observer' incorporates:
   *  SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport5'
   */
  /* MATLAB Function 'Observer (CASE C)/DP Observer': '<S20>:1' */
  /* % INPUT PARAMETERS */
  /*  Mass matrix */
  /* '<S20>:1:12' */
  /*  Surge velocity */
  /* '<S20>:1:13' */
  /*  Sway velocity */
  /* '<S20>:1:14' */
  /*  Yaw rate */
  /* '<S20>:1:15' */
  /*  Heading */
  /*  Inverse of M */
  /* '<S20>:1:18' */
  /* '<S20>:1:21' */
  /* '<S20>:1:24' */
  /* '<S20>:1:29' */
  /* '<S20>:1:33' */
  /* '<S20>:1:38' */
  /* '<S20>:1:39' */
  /* '<S20>:1:40' */
  /* '<S20>:1:41' */
  /* '<S20>:1:42' */
  /* '<S20>:1:44' */
  /*  Damping matrix */
  /* % TUNING & ALGORITHM */
  /* '<S20>:1:51' */
  /*  Diagonal Matrices are more simple for tuning */
  /* '<S20>:1:52' */
  /* '<S20>:1:53' */
  /*  See Appendix */
  /* '<S20>:1:56' */
  R[0] = cos(ctrl_student_HIL_B.Eta[2]);
  R[3] = -sin(ctrl_student_HIL_B.Eta[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_B.Eta[2]);
  R[4] = cos(ctrl_student_HIL_B.Eta[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /*  Rotation Matrix */
  /* '<S20>:1:61' */
  /*  State Space Matrix */
  /* '<S20>:1:66' */
  /*  Control Input (vertical vector) */
  /* '<S20>:1:69' */
  /*  See Observer Design (vertical vector) */
  /* '<S20>:1:75' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      S[i + 3 * i_0] = 0.0;
      S[i + 3 * i_0] += c_a[i] * R[i_0];
      S[i + 3 * i_0] += c_a[i + 3] * R[i_0 + 3];
      S[i + 3 * i_0] += c_a[i + 6] * R[i_0 + 6];
    }
  }

  tmp[0] = (0.6555 - 0.3545 * fabs(ctrl_student_HIL_B.Memory[3])) -
    ctrl_student_HIL_B.Memory[3] * ctrl_student_HIL_B.Memory[3] * -3.787;
  tmp[3] = 0.0;
  tmp[6] = 0.0;
  tmp[1] = 0.0;
  tmp[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_B.Memory[4])) -
            ctrl_student_HIL_B.Memory[4] * ctrl_student_HIL_B.Memory[4] * -64.91)
    - -0.805 * fabs(ctrl_student_HIL_B.Memory[5]);
  tmp[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_B.Memory[4])) - -3.45 * fabs
            (ctrl_student_HIL_B.Memory[5])) - ctrl_student_HIL_B.Memory[5] *
    ctrl_student_HIL_B.Memory[5] * 0.0;
  tmp[2] = 0.0;
  tmp[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_B.Memory[4])) -
            ctrl_student_HIL_B.Memory[4] * ctrl_student_HIL_B.Memory[4] * 0.0) -
    0.13 * fabs(ctrl_student_HIL_B.Memory[5]);
  tmp[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_B.Memory[4])) - -0.75 * fabs
            (ctrl_student_HIL_B.Memory[5])) - ctrl_student_HIL_B.Memory[5] *
    ctrl_student_HIL_B.Memory[5] * 0.0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      R_1[i + 3 * i_0] = 0.0;
      R_1[i + 3 * i_0] += (real_T)b_b_0[3 * i_0] * ctrl_student_HIL_B.L2 * S[i];
      R_1[i + 3 * i_0] += (real_T)b_b_0[3 * i_0 + 1] * ctrl_student_HIL_B.L2 *
        S[i + 3];
      R_1[i + 3 * i_0] += (real_T)b_b_0[3 * i_0 + 2] * ctrl_student_HIL_B.L2 *
        S[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      a_2[i + 3 * i_0] = 0.0;
      a_2[i + 3 * i_0] += tmp[3 * i_0] * a_0[i];
      a_2[i + 3 * i_0] += tmp[3 * i_0 + 1] * a_0[i + 3];
      a_2[i + 3 * i_0] += tmp[3 * i_0 + 2] * a_0[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      S[i + 3 * i_0] = 0.0;
      S[i + 3 * i_0] += b_a_0[i] * R[i_0];
      S[i + 3 * i_0] += b_a_0[i + 3] * R[i_0 + 3];
      S[i + 3 * i_0] += b_a_0[i + 6] * R[i_0 + 6];
    }
  }

  tmp_0[0] = ctrl_student_HIL_B.Eta[0] - 2.0 * ctrl_student_HIL_B.Memory[0];
  tmp_0[1] = ctrl_student_HIL_B.Eta[1] - 2.0 * ctrl_student_HIL_B.Memory[1];
  tmp_0[2] = ctrl_student_HIL_B.Eta[2] - 2.0 * ctrl_student_HIL_B.Memory[2];
  tmp_0[3] = 0.0;
  tmp_0[4] = 0.0;
  tmp_0[5] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[8] = 0.0;
  for (i = 0; i < 3; i++) {
    tmp_1[9 * i] = (real_T)b_b_0[3 * i] * ctrl_student_HIL_B.L1;
    tmp_1[1 + 9 * i] = (real_T)b_b_0[3 * i + 1] * ctrl_student_HIL_B.L1;
    tmp_1[2 + 9 * i] = (real_T)b_b_0[3 * i + 2] * ctrl_student_HIL_B.L1;
  }

  for (i = 0; i < 3; i++) {
    tmp_1[9 * (i + 3)] = R[3 * i];
    tmp_1[1 + 9 * (i + 3)] = R[3 * i + 1];
    tmp_1[2 + 9 * (i + 3)] = R[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_1[9 * (i + 6)] = 0.0;
    tmp_1[1 + 9 * (i + 6)] = 0.0;
    tmp_1[2 + 9 * (i + 6)] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    tmp_1[3 + 9 * i] = R_1[3 * i];
    tmp_1[4 + 9 * i] = R_1[3 * i + 1];
    tmp_1[5 + 9 * i] = R_1[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_1[3 + 9 * (i + 3)] = a_2[3 * i];
    tmp_1[4 + 9 * (i + 3)] = a_2[3 * i + 1];
    tmp_1[5 + 9 * (i + 3)] = a_2[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_1[3 + 9 * (i + 6)] = S[3 * i];
    tmp_1[4 + 9 * (i + 6)] = S[3 * i + 1];
    tmp_1[5 + 9 * (i + 6)] = S[3 * i + 2];
  }

  for (i = 0; i < 3; i++) {
    tmp_1[6 + 9 * i] = (real_T)b_b_0[3 * i] * ctrl_student_HIL_B.L3;
    tmp_1[7 + 9 * i] = (real_T)b_b_0[3 * i + 1] * ctrl_student_HIL_B.L3;
    tmp_1[8 + 9 * i] = (real_T)b_b_0[3 * i + 2] * ctrl_student_HIL_B.L3;
  }

  for (i = 0; i < 3; i++) {
    tmp_1[6 + 9 * (i + 3)] = 0.0;
    tmp_1[7 + 9 * (i + 3)] = 0.0;
    tmp_1[8 + 9 * (i + 3)] = 0.0;
  }

  for (i = 0; i < 3; i++) {
    tmp_1[6 + 9 * (i + 6)] = 0.0;
    tmp_1[7 + 9 * (i + 6)] = 0.0;
    tmp_1[8 + 9 * (i + 6)] = 0.0;
  }

  for (i = 0; i < 9; i++) {
    a_2[i] = ctrl_student_HIL_B.Memory[i] + tmp_0[i];
  }

  for (i = 0; i < 3; i++) {
    b_a_1[i] = b_a_0[i + 6] * ctrl_student_HIL_B.Memory4[2] + (b_a_0[i + 3] *
      ctrl_student_HIL_B.Memory4[1] + b_a_0[i] * ctrl_student_HIL_B.x_d1);
  }

  tmp_2[0] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[2] = 0.0;
  tmp_2[3] = b_a_1[0];
  tmp_2[4] = b_a_1[1];
  tmp_2[5] = b_a_1[2];
  tmp_2[6] = 0.0;
  tmp_2[7] = 0.0;
  tmp_2[8] = 0.0;
  for (i = 0; i < 9; i++) {
    /* MATLAB Function: '<S4>/DP Observer' */
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 9; i_0++) {
      tmp[i] += tmp_1[9 * i_0 + i] * a_2[i_0];
    }

    ctrl_student_HIL_B.x_dot[i] = tmp[i] + tmp_2[i];

    /* Integrator: '<S4>/Integrator' */
    ctrl_student_HIL_B.Integrator[i] = ctrl_student_HIL_X.Integrator_CSTATE[i];
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S7>/MATLAB Function1' */
    /* MATLAB Function 'joystick/MATLAB Function1': '<S25>:1' */
    /* The force angle. */
    /* '<S25>:1:4' */
    ctrl_student_HIL_B.a_VSP = rt_atan2d_snf(ctrl_student_HIL_B.PosXLeft,
      -ctrl_student_HIL_B.PosYLeft);

    /* generalised force */
    /* '<S25>:1:6' */
    rtb_U_max = sqrt(ctrl_student_HIL_B.PosXLeft * ctrl_student_HIL_B.PosXLeft +
                     ctrl_student_HIL_B.PosYLeft * ctrl_student_HIL_B.PosYLeft);
    if ((1.0 <= rtb_U_max) || rtIsNaN(rtb_U_max)) {
      ctrl_student_HIL_B.u_VSP = 1.0;
    } else {
      ctrl_student_HIL_B.u_VSP = rtb_U_max;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function1' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Memory: '<S7>/Memory' */
    ctrl_student_HIL_B.Memory_f = ctrl_student_HIL_DW.Memory_PreviousInput_n;
  }

  /* MATLAB Function: '<S7>/Voith Schneider Propeller' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  /* MATLAB Function 'joystick/Voith Schneider Propeller': '<S26>:1' */
  /* find the remain time. */
  /* '<S26>:1:4' */
  /* use if sentence to calculate the correct rotational speed. */
  if (ctrl_student_HIL_X.Integrator_CSTATE_e - floor
      (ctrl_student_HIL_X.Integrator_CSTATE_e) <= 0.01) {
    /* '<S26>:1:6' */
    /* '<S26>:1:7' */
    rtb_Drop = (0.1 * ctrl_student_HIL_B.ArrowUp + ctrl_student_HIL_B.Memory_f)
      - 0.1 * ctrl_student_HIL_B.ArrowDown;
  } else {
    /* '<S26>:1:9' */
    rtb_Drop = ctrl_student_HIL_B.Memory_f;
  }

  /* define the value of rotational speed. */
  /* '<S26>:1:14' */
  ctrl_student_HIL_B.Omega1 = rtb_Drop;

  /* '<S26>:1:15' */
  ctrl_student_HIL_B.Omega2 = rtb_Drop;

  /* End of MATLAB Function: '<S7>/Voith Schneider Propeller' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* MATLAB Function: '<S7>/Bow thruster' */
    /* MATLAB Function 'joystick/Bow thruster': '<S23>:1' */
    /* '<S23>:1:4' */
    ctrl_student_HIL_B.u_BT = (ctrl_student_HIL_B.R2_continuous -
      ctrl_student_HIL_B.L2_continuous) / 2.0;

    /* MATLAB Function: '<S7>/MATLAB Function' */
    /* MATLAB Function 'joystick/MATLAB Function': '<S24>:1' */
    /* '<S24>:1:4' */
    ctrl_student_HIL_B.a = rt_atan2d_snf(ctrl_student_HIL_B.PosXRight,
      -ctrl_student_HIL_B.PosYRight);

    /* '<S24>:1:5' */
    rtb_U_max = sqrt(ctrl_student_HIL_B.PosXRight * ctrl_student_HIL_B.PosXRight
                     + ctrl_student_HIL_B.PosYRight *
                     ctrl_student_HIL_B.PosYRight);
    if ((1.0 <= rtb_U_max) || rtIsNaN(rtb_U_max)) {
      ctrl_student_HIL_B.u = 1.0;
    } else {
      ctrl_student_HIL_B.u = rtb_U_max;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function' */
  }
}

/* Model update function */
void ctrl_student_HIL_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    /* Update for Memory: '<S12>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_B.count;

    /* Update for RandomNumber: '<S18>/White Noise' */
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S19>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_f) * ctrl_student_HIL_P.WhiteNoise_StdDev_o
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_h) * ctrl_student_HIL_P.WhiteNoise_StdDev_n
      + ctrl_student_HIL_P.WhiteNoise_Mean_b;

    /* Update for Memory: '<S13>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_B.output[0];
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_B.output[1];
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_B.output[2];

    /* Update for Memory: '<S4>/Memory' */
    memcpy(&ctrl_student_HIL_DW.Memory_PreviousInput[0],
           &ctrl_student_HIL_B.Integrator[0], 9U * sizeof(real_T));

    /* Update for Memory: '<S2>/Memory4' */
    ctrl_student_HIL_DW.Memory4_PreviousInput[0] = ctrl_student_HIL_B.Tau[0];
    ctrl_student_HIL_DW.Memory4_PreviousInput[1] = ctrl_student_HIL_B.Tau[1];
    ctrl_student_HIL_DW.Memory4_PreviousInput[2] = ctrl_student_HIL_B.Tau[2];
    for (i = 0; i < 10; i++) {
      /* Update for Memory: '<S1>/Memory2' */
      ctrl_student_HIL_DW.Memory2_PreviousInput[i] = ctrl_student_HIL_B.Mx1[i];

      /* Update for Memory: '<S1>/Memory1' */
      ctrl_student_HIL_DW.Memory1_PreviousInput[i] = ctrl_student_HIL_B.My1[i];
    }

    /* Update for Memory: '<S21>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput = ctrl_student_HIL_B.M1;

    /* Update for Memory: '<S21>/Memory5' */
    ctrl_student_HIL_DW.Memory5_PreviousInput = ctrl_student_HIL_B.s1;

    /* Update for Memory: '<S2>/s(0)' */
    ctrl_student_HIL_DW.s0_PreviousInput = ctrl_student_HIL_B.s;

    /* Update for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_a[0] = ctrl_student_HIL_B.Rz1[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_a[1] = ctrl_student_HIL_B.Rz1[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_a[2] = ctrl_student_HIL_B.Rz1[2];

    /* Update for Memory: '<S2>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[0] = ctrl_student_HIL_B.eta_d[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[1] = ctrl_student_HIL_B.eta_d[1];
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[2] = ctrl_student_HIL_B.eta_d[2];

    /* Update for Memory: '<S2>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[0] = ctrl_student_HIL_B.eta_ds[0];
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[1] = ctrl_student_HIL_B.eta_ds[1];
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[2] = ctrl_student_HIL_B.eta_ds[2];

    /* Update for Memory: '<S2>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[0] = ctrl_student_HIL_B.eta_ds2
      [0];
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[1] = ctrl_student_HIL_B.eta_ds2
      [1];
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[2] = ctrl_student_HIL_B.eta_ds2
      [2];

    /* Update for Memory: '<S7>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_n = ctrl_student_HIL_B.Omega2;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_student_HIL_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_student_HIL_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_M->Timing.t[1] = ctrl_student_HIL_M->Timing.clockTick1 *
      ctrl_student_HIL_M->Timing.stepSize1 +
      ctrl_student_HIL_M->Timing.clockTickH1 *
      ctrl_student_HIL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_derivatives(void)
{
  XDot_ctrl_student_HIL_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_T *) ctrl_student_HIL_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Int2' */
  _rtXdot->Int2_CSTATE = ctrl_student_HIL_B.Int1;

  /* Derivatives for Integrator: '<S2>/s' */
  _rtXdot->s_CSTATE = ctrl_student_HIL_B.s_dot;

  /* Derivatives for Integrator: '<Root>/Int1' */
  _rtXdot->Int1_CSTATE = ctrl_student_HIL_B.u_dot_imu;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  memcpy(&_rtXdot->Integrator_CSTATE[0], &ctrl_student_HIL_B.x_dot[0], 9U *
         sizeof(real_T));

  /* Derivatives for Integrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  _rtXdot->Integrator_CSTATE_e = ctrl_student_HIL_P.Constant_Value_i;
}

/* Model initialize function */
void ctrl_student_HIL_initialize(void)
{
  {
    uint32_T tseed;
    int32_T t;
    int32_T i;
    real_T tmp;

    /* InitializeConditions for Memory: '<S12>/counter' */
    ctrl_student_HIL_DW.counter_PreviousInput = ctrl_student_HIL_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S18>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed = tseed;
    ctrl_student_HIL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed) * ctrl_student_HIL_P.WhiteNoise_StdDev +
      ctrl_student_HIL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S18>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S19>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_k);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_f = tseed;
    ctrl_student_HIL_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_f) * ctrl_student_HIL_P.WhiteNoise_StdDev_o
      + ctrl_student_HIL_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S19>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S17>/White Noise' */
    tmp = floor(ctrl_student_HIL_P.WhiteNoise_Seed_c);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    ctrl_student_HIL_DW.RandSeed_h = tseed;
    ctrl_student_HIL_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_DW.RandSeed_h) * ctrl_student_HIL_P.WhiteNoise_StdDev_n
      + ctrl_student_HIL_P.WhiteNoise_Mean_b;

    /* End of InitializeConditions for RandomNumber: '<S17>/White Noise' */

    /* InitializeConditions for Memory: '<S13>/Hold' */
    ctrl_student_HIL_DW.Hold_PreviousInput[0] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[1] = ctrl_student_HIL_P.Hold_X0;
    ctrl_student_HIL_DW.Hold_PreviousInput[2] = ctrl_student_HIL_P.Hold_X0;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    memcpy(&ctrl_student_HIL_DW.Memory_PreviousInput[0],
           &ctrl_student_HIL_P.Memory_X0[0], 9U * sizeof(real_T));

    /* InitializeConditions for Memory: '<S2>/Memory4' */
    ctrl_student_HIL_DW.Memory4_PreviousInput[0] =
      ctrl_student_HIL_P.Memory4_X0[0];
    ctrl_student_HIL_DW.Memory4_PreviousInput[1] =
      ctrl_student_HIL_P.Memory4_X0[1];
    ctrl_student_HIL_DW.Memory4_PreviousInput[2] =
      ctrl_student_HIL_P.Memory4_X0[2];

    /* InitializeConditions for Integrator: '<Root>/Int2' */
    ctrl_student_HIL_X.Int2_CSTATE = ctrl_student_HIL_P.Int2_IC;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Memory: '<S1>/Memory2' */
      ctrl_student_HIL_DW.Memory2_PreviousInput[i] =
        ctrl_student_HIL_P.Memory2_X0[i];

      /* InitializeConditions for Memory: '<S1>/Memory1' */
      ctrl_student_HIL_DW.Memory1_PreviousInput[i] =
        ctrl_student_HIL_P.Memory1_X0[i];
    }

    /* InitializeConditions for Memory: '<S21>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput = ctrl_student_HIL_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S21>/Memory5' */
    ctrl_student_HIL_DW.Memory5_PreviousInput = ctrl_student_HIL_P.Memory5_X0;

    /* InitializeConditions for Memory: '<S2>/s(0)' */
    ctrl_student_HIL_DW.s0_PreviousInput = ctrl_student_HIL_P.s0_X0;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_a[0] =
      ctrl_student_HIL_P.Memory_X0_d[0];
    ctrl_student_HIL_DW.Memory_PreviousInput_a[1] =
      ctrl_student_HIL_P.Memory_X0_d[1];
    ctrl_student_HIL_DW.Memory_PreviousInput_a[2] =
      ctrl_student_HIL_P.Memory_X0_d[2];

    /* InitializeConditions for Memory: '<S2>/Memory1' */
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[0] =
      ctrl_student_HIL_P.Memory1_X0_e[0];
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[1] =
      ctrl_student_HIL_P.Memory1_X0_e[1];
    ctrl_student_HIL_DW.Memory1_PreviousInput_d[2] =
      ctrl_student_HIL_P.Memory1_X0_e[2];

    /* InitializeConditions for Memory: '<S2>/Memory2' */
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[0] =
      ctrl_student_HIL_P.Memory2_X0_h[0];
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[1] =
      ctrl_student_HIL_P.Memory2_X0_h[1];
    ctrl_student_HIL_DW.Memory2_PreviousInput_d[2] =
      ctrl_student_HIL_P.Memory2_X0_h[2];

    /* InitializeConditions for Memory: '<S2>/Memory3' */
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[0] =
      ctrl_student_HIL_P.Memory3_X0_h[0];
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[1] =
      ctrl_student_HIL_P.Memory3_X0_h[1];
    ctrl_student_HIL_DW.Memory3_PreviousInput_c[2] =
      ctrl_student_HIL_P.Memory3_X0_h[2];

    /* InitializeConditions for Integrator: '<S2>/s' */
    ctrl_student_HIL_X.s_CSTATE = ctrl_student_HIL_P.s_IC;

    /* InitializeConditions for Integrator: '<Root>/Int1' */
    ctrl_student_HIL_X.Int1_CSTATE = ctrl_student_HIL_P.Int1_IC;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    for (i = 0; i < 9; i++) {
      ctrl_student_HIL_X.Integrator_CSTATE[i] = ctrl_student_HIL_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    ctrl_student_HIL_X.Integrator_CSTATE_e = ctrl_student_HIL_P.Integrator_IC_h;

    /* InitializeConditions for Memory: '<S7>/Memory' */
    ctrl_student_HIL_DW.Memory_PreviousInput_n = ctrl_student_HIL_P.Memory_X0_a;
  }
}

/* Model terminate function */
void ctrl_student_HIL_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_student_HIL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_student_HIL_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_T *ctrl_student_HIL(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_M->solverInfo,
                          &ctrl_student_HIL_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_M->solverInfo, &rtmGetTPtr(ctrl_student_HIL_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_M->solverInfo,
                       &ctrl_student_HIL_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_M->solverInfo,
                 &ctrl_student_HIL_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_M->solverInfo,
      &ctrl_student_HIL_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_HIL_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_M->solverInfo, ctrl_student_HIL_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_M->ModelData.intgData.y = ctrl_student_HIL_M->ModelData.odeY;
  ctrl_student_HIL_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_M->ModelData.odeF[0];
  ctrl_student_HIL_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_M->ModelData.odeF[1];
  ctrl_student_HIL_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_M->ModelData.odeF[2];
  ctrl_student_HIL_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_M->ModelData.odeF[3];
  ctrl_student_HIL_M->ModelData.contStates = ((real_T *) &ctrl_student_HIL_X);
  rtsiSetSolverData(&ctrl_student_HIL_M->solverInfo, (void *)
                    &ctrl_student_HIL_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_M->Timing.sampleTimes =
      (&ctrl_student_HIL_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_M->Timing.offsetTimes =
      (&ctrl_student_HIL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_M, &ctrl_student_HIL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_M, -1);
  ctrl_student_HIL_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_M->solverInfoPtr = (&ctrl_student_HIL_M->solverInfo);
  ctrl_student_HIL_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_M->ModelData.blockIO = ((void *) &ctrl_student_HIL_B);
  (void) memset(((void *) &ctrl_student_HIL_B), 0,
                sizeof(B_ctrl_student_HIL_T));

  /* parameters */
  ctrl_student_HIL_M->ModelData.defaultParam = ((real_T *)&ctrl_student_HIL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_X;
    ctrl_student_HIL_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_X, 0,
                  sizeof(X_ctrl_student_HIL_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_M->ModelData.dwork = ((void *) &ctrl_student_HIL_DW);
  (void) memset((void *)&ctrl_student_HIL_DW, 0,
                sizeof(DW_ctrl_student_HIL_T));

  /* Initialize Sizes */
  ctrl_student_HIL_M->Sizes.numContStates = (13);/* Number of continuous states */
  ctrl_student_HIL_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_M->Sizes.numBlocks = (135);/* Number of blocks */
  ctrl_student_HIL_M->Sizes.numBlockIO = (71);/* Number of block outputs */
  ctrl_student_HIL_M->Sizes.numBlockPrms = (454);/* Sum of parameter "widths" */
  return ctrl_student_HIL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================*
 * This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student_HIL
#include "model_info.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;
double NIRT_GetValueByDataType(void* ptr,int subindex, int type, int Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

long NIRT_SetValueByDataType(void* ptr,int subindex, double value, int type, int
  Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.y_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.psi_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.x_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.r_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.v_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Desired sampling frequency
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.Desiredsamplingfrequency, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise power position
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.noisepowerposition, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise power heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.noisepowerheading, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // u_dot_imu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.u_dot_imu, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // enable noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.enablenoise, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/L2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/L1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/L3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYLeft, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosXRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.PosYRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowUp, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.L1_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_B.ArrowRight, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 26;
}

double ni_extout[41];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_true: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);
  } else {
    index += 1;
  }

  // psi_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.psi_in,0,0,
      0);
  } else {
    index += 1;
  }

  // fater noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.output,0,17,
      0);
  } else {
    index += 1;
  }

  // eta_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,0,22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,1,22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,2,22,
      0);
  } else {
    index += 3;
  }

  // nu_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,3,22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,4,22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,5,22,
      0);
  } else {
    index += 3;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_d1,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,2,
      17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,1,
      17,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,
      0,0,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/u_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,3,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/x_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,0,17,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/x_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,0,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/y_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,1,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,2,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/v_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,4,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/r_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,5,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/bx_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,6,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/by_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,7,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/bpsi_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,8,22,
      0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/y_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,1,17,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/psi_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,2,17,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/x-error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract,0,
      0,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/y-error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract1,0,
      0,0);
  } else {
    index += 1;
  }

  // Observer (CASE C)/psi_error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract2,0,
      0,0);
  } else {
    index += 1;
  }

  // Tank (CASE B)/X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_d1,0,0,0);
  } else {
    index += 1;
  }

  // Tank (CASE B)/Y: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,1,
      17,0);
  } else {
    index += 1;
  }

  // Tank (CASE B)/Z: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,2,
      17,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.a_VSP,0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Omega1,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Omega2,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.a,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 41;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_true: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_in,0,0,0);

  // psi_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.psi_in,0,0,0);

  // fater noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.output,0,17,0);

  // eta_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,0,22,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,1,22,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,2,22,0);

  // nu_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,3,22,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,4,22,0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,5,22,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_d1,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,2,17,
    0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,1,17,
    0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_student_HIL_RGND,0,
    0,0);

  // Observer (CASE C)/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,3,22,0);

  // Observer (CASE C)/x_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,0,17,0);

  // Observer (CASE C)/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,0,22,0);

  // Observer (CASE C)/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,1,22,0);

  // Observer (CASE C)/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,2,22,0);

  // Observer (CASE C)/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,4,22,0);

  // Observer (CASE C)/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,5,22,0);

  // Observer (CASE C)/bx_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,6,22,0);

  // Observer (CASE C)/by_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,7,22,0);

  // Observer (CASE C)/bpsi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory,8,22,0);

  // Observer (CASE C)/y_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,1,17,0);

  // Observer (CASE C)/psi_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Eta,2,17,0);

  // Observer (CASE C)/x-error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract,0,0,
    0);

  // Observer (CASE C)/y-error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract1,0,0,
    0);

  // Observer (CASE C)/psi_error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Subtract2,0,0,
    0);

  // Tank (CASE B)/X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.x_d1,0,0,0);

  // Tank (CASE B)/Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,1,17,
    0);

  // Tank (CASE B)/Z: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Memory4,2,17,
    0);

  // joystick/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_VSP,0,0,0);

  // joystick/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.a_VSP,0,0,0);

  // joystick/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Omega1,0,0,0);

  // joystick/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.Omega2,0,0,0);

  // joystick/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u_BT,0,0,0);

  // joystick/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.a,0,0,0);

  // joystick/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_B.u,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_T, Stepsize_Value), 33, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/Noise generator/Downsamplesignal/counter/X0", offsetof
    (P_ctrl_student_HIL_T, counter_X0), 33, 1, 2, 2, 0 },

  { 2,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean), 33, 1, 2, 4, 0 },

  { 3,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev), 33, 1, 2, 6, 0 },

  { 4,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed), 33, 1, 2, 8, 0 },

  { 5,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_h), 33, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_o), 33, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_k), 33, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Mean_b), 33, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_StdDev_n), 33, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_T, WhiteNoise_Seed_c), 33, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_T, Hold_X0), 33, 1, 2, 22, 0 },

  { 12, "ctrl_student_hil/Observer (CASE C)/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0), 23, 9, 2, 24, 0 },

  { 13, "ctrl_student_hil/Guidance (CASE D)/Memory4/X0", offsetof
    (P_ctrl_student_HIL_T, Memory4_X0), 24, 3, 2, 26, 0 },

  { 14, "ctrl_student_hil/Int2/InitialCondition", offsetof(P_ctrl_student_HIL_T,
    Int2_IC), 33, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2/X0", offsetof
    (P_ctrl_student_HIL_T, Memory2_X0), 19, 10, 2, 30, 0 },

  { 16, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1/X0", offsetof
    (P_ctrl_student_HIL_T, Memory1_X0), 19, 10, 2, 32, 0 },

  { 17, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Memory3/X0",
    offsetof(P_ctrl_student_HIL_T, Memory3_X0), 33, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Memory5/X0",
    offsetof(P_ctrl_student_HIL_T, Memory5_X0), 33, 1, 2, 36, 0 },

  { 19,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_T, Constant2_Value), 33, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_T, Constant_Value), 33, 1, 2, 40, 0 },

  { 21,
    "ctrl_student_hil/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_T, Constant1_Value), 33, 1, 2, 42, 0 },

  { 22, "ctrl_student_hil/Guidance (CASE D)/Constant1/Value", offsetof
    (P_ctrl_student_HIL_T, Constant1_Value_l), 33, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil/Guidance (CASE D)/Constant2/Value", offsetof
    (P_ctrl_student_HIL_T, Constant2_Value_p), 33, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil/Guidance (CASE D)/s(0)/X0", offsetof
    (P_ctrl_student_HIL_T, s0_X0), 33, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil/Guidance (CASE D)/Step/Time", offsetof
    (P_ctrl_student_HIL_T, Step_Time), 33, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil/Guidance (CASE D)/Step/Before", offsetof
    (P_ctrl_student_HIL_T, Step_Y0), 33, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil/Guidance (CASE D)/Step/After", offsetof
    (P_ctrl_student_HIL_T, Step_YFinal), 33, 1, 2, 54, 0 },

  { 28, "ctrl_student_hil/Guidance (CASE D)/U_max/Gain", offsetof
    (P_ctrl_student_HIL_T, U_max_Gain), 33, 1, 2, 56, 0 },

  { 29, "ctrl_student_hil/Guidance (CASE D)/Memory/X0", offsetof
    (P_ctrl_student_HIL_T, Memory_X0_d), 24, 3, 2, 58, 0 },

  { 30, "ctrl_student_hil/Guidance (CASE D)/Memory1/X0", offsetof
    (P_ctrl_student_HIL_T, Memory1_X0_e), 24, 3, 2, 60, 0 },

  { 31, "ctrl_student_hil/Guidance (CASE D)/Memory2/X0", offsetof
    (P_ctrl_student_HIL_T, Memory2_X0_h), 24, 3, 2, 62, 0 },

  { 32, "ctrl_student_hil/Guidance (CASE D)/Memory3/X0", offsetof
    (P_ctrl_student_HIL_T, Memory3_X0_h), 24, 3, 2, 64, 0 },

  { 33, "ctrl_student_hil/Guidance (CASE D)/s/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, s_IC), 33, 1, 2, 66, 0 },

  { 34, "ctrl_student_hil/Int1/InitialCondition", offsetof(P_ctrl_student_HIL_T,
    Int1_IC), 33, 1, 2, 68, 0 },

  { 35, "ctrl_student_hil/Observer (CASE C)/Integrator/InitialCondition",
    offsetof(P_ctrl_student_HIL_T, Integrator_IC), 33, 1, 2, 70, 0 },

  { 36, "ctrl_student_hil/joystick/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_T, Integrator_IC_h), 33, 1, 2, 72, 0 },

  { 37, "ctrl_student_hil/joystick/Memory/X0", offsetof(P_ctrl_student_HIL_T,
    Memory_X0_a), 33, 1, 2, 74, 0 },

  { 38, "ctrl_student_hil/joystick/Constant/Value", offsetof
    (P_ctrl_student_HIL_T, Constant_Value_i), 33, 1, 2, 76, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 39;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  9, 1,                                /* Parameter at index 12 */
  3, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 10,                               /* Parameter at index 15 */
  1, 10,                               /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  3, 1,                                /* Parameter at index 29 */
  3, 1,                                /* Parameter at index 30 */
  3, 1,                                /* Parameter at index 31 */
  3, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil/u_in", 0, "", offsetof(B_ctrl_student_HIL_T, u_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil/y_in", 0, "", offsetof(B_ctrl_student_HIL_T, y_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil/psi_in", 0, "", offsetof(B_ctrl_student_HIL_T, psi_in)+
    0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil/x_in", 0, "", offsetof(B_ctrl_student_HIL_T, x_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil/r_in", 0, "", offsetof(B_ctrl_student_HIL_T, r_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 8, 0 },

  { 5, "ctrl_student_hil/v_in", 0, "", offsetof(B_ctrl_student_HIL_T, v_in)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 10, 0 },

  { 6, "ctrl_student_hil/Noise generator/Downsamplesignal/counter", 0, "",
    offsetof(B_ctrl_student_HIL_T, counter)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 12, 0 },

  { 7, "ctrl_student_hil/Desired sampling frequency", 0, "", offsetof
    (B_ctrl_student_HIL_T, Desiredsamplingfrequency)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 14, 0 },

  { 8, "ctrl_student_hil/noise power position", 0, "", offsetof
    (B_ctrl_student_HIL_T, noisepowerposition)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_p)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 20, 0 },

  { 11, "ctrl_student_hil/noise power heading", 0, "", offsetof
    (B_ctrl_student_HIL_T, noisepowerheading)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_T, WhiteNoise_i)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 24, 0 },

  { 13, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    26, 0 },

  { 14, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    28, 0 },

  { 15, "ctrl_student_hil/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    30, 0 },

  { 16, "ctrl_student_hil/u_dot_imu", 0, "", offsetof(B_ctrl_student_HIL_T,
    u_dot_imu)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 32, 0 },

  { 17, "ctrl_student_hil/enable noise", 0, "", offsetof(B_ctrl_student_HIL_T,
    enablenoise)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 36,
    0 },

  { 19, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory)+1*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 38,
    0 },

  { 20, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory)+2*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 40,
    0 },

  { 21, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory)+3*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory)+4*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 44,
    0 },

  { 23, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory)+5*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 46,
    0 },

  { 24, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory)+6*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 48,
    0 },

  { 25, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory)+7*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 50,
    0 },

  { 26, "ctrl_student_hil/Observer (CASE C)/Memory", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory)+8*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2, 52,
    0 },

  { 27, "ctrl_student_hil/Guidance (CASE D)/Memory4", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 54,
    0 },

  { 28, "ctrl_student_hil/Guidance (CASE D)/Memory4", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 56,
    0 },

  { 29, "ctrl_student_hil/Guidance (CASE D)/Memory4", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory4)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 58,
    0 },

  { 30, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 60,
    0 },

  { 31, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 62,
    0 },

  { 32, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 64,
    0 },

  { 33, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 66,
    0 },

  { 34, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 68,
    0 },

  { 35, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 70,
    0 },

  { 36, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 72,
    0 },

  { 37, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 74,
    0 },

  { 38, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 76,
    0 },

  { 39, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory2", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_T, Memory2)+9*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 78,
    0 },

  { 40, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 80,
    0 },

  { 41, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 82,
    0 },

  { 42, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 84,
    0 },

  { 43, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 86,
    0 },

  { 44, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 88,
    0 },

  { 45, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 90,
    0 },

  { 46, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 92,
    0 },

  { 47, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 94,
    0 },

  { 48, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 96,
    0 },

  { 49, "ctrl_student_hil/DROP DETECTOR (CASE B)/Memory1", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_T, Memory1)+9*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2, 98,
    0 },

  { 50, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Memory3", 0, "",
    offsetof(B_ctrl_student_HIL_T, Memory3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 100, 0 },

  { 51, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Memory5", 0, "",
    offsetof(B_ctrl_student_HIL_T, Memory5)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 102, 0 },

  { 52, "ctrl_student_hil/Guidance (CASE D)/s(0)", 0, "", offsetof
    (B_ctrl_student_HIL_T, s0)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 104, 0 },

  { 53, "ctrl_student_hil/Guidance (CASE D)/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    106, 0 },

  { 54, "ctrl_student_hil/Guidance (CASE D)/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    108, 0 },

  { 55, "ctrl_student_hil/Guidance (CASE D)/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory_c)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    110, 0 },

  { 56, "ctrl_student_hil/Guidance (CASE D)/Memory1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory1_k)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    112, 0 },

  { 57, "ctrl_student_hil/Guidance (CASE D)/Memory1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory1_k)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    114, 0 },

  { 58, "ctrl_student_hil/Guidance (CASE D)/Memory1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory1_k)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    116, 0 },

  { 59, "ctrl_student_hil/Guidance (CASE D)/Memory2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory2_e)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    118, 0 },

  { 60, "ctrl_student_hil/Guidance (CASE D)/Memory2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory2_e)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    120, 0 },

  { 61, "ctrl_student_hil/Guidance (CASE D)/Memory2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory2_e)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    122, 0 },

  { 62, "ctrl_student_hil/Guidance (CASE D)/Memory3", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Memory3_l)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    124, 0 },

  { 63, "ctrl_student_hil/Guidance (CASE D)/Memory3", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Memory3_l)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    126, 0 },

  { 64, "ctrl_student_hil/Guidance (CASE D)/Memory3", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Memory3_l)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    128, 0 },

  { 65, "ctrl_student_hil/Guidance (CASE D)/s", 0, "", offsetof
    (B_ctrl_student_HIL_T, s)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 130, 0 },

  { 66, "ctrl_student_hil/Int1", 0, "", offsetof(B_ctrl_student_HIL_T, Int1)+0*
    sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 132, 0 },

  { 67, "ctrl_student_hil/Observer (CASE C)/L2", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 134, 0 },

  { 68, "ctrl_student_hil/Observer (CASE C)/L1", 0, "", offsetof
    (B_ctrl_student_HIL_T, L1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 136, 0 },

  { 69, "ctrl_student_hil/Observer (CASE C)/L3", 0, "", offsetof
    (B_ctrl_student_HIL_T, L3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 138, 0 },

  { 70, "ctrl_student_hil/Observer (CASE C)/Subtract", 0, "", offsetof
    (B_ctrl_student_HIL_T, Subtract)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 140,
    0 },

  { 71, "ctrl_student_hil/Observer (CASE C)/Subtract1", 0, "", offsetof
    (B_ctrl_student_HIL_T, Subtract1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    142, 0 },

  { 72, "ctrl_student_hil/Observer (CASE C)/Subtract2", 0, "", offsetof
    (B_ctrl_student_HIL_T, Subtract2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    144, 0 },

  { 73, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    146, 0 },

  { 74, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    148, 0 },

  { 75, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    150, 0 },

  { 76, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+3*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    152, 0 },

  { 77, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+4*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    154, 0 },

  { 78, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+5*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    156, 0 },

  { 79, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+6*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    158, 0 },

  { 80, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+7*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil/Observer (CASE C)/Integrator", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_T, Integrator)+8*sizeof(real_T), BLOCKIO_SIG, 22, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    164, 0 },

  { 83, "ctrl_student_hil/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 166,
    0 },

  { 84, "ctrl_student_hil/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 168,
    0 },

  { 85, "ctrl_student_hil/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    170, 0 },

  { 86, "ctrl_student_hil/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    172, 0 },

  { 87, "ctrl_student_hil/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 174,
    0 },

  { 88, "ctrl_student_hil/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    176, 0 },

  { 89, "ctrl_student_hil/joystick/Memory", 0, "", offsetof(B_ctrl_student_HIL_T,
    Memory_f)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 178, 0 },

  { 90, "ctrl_student_hil/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    180, 0 },

  { 91, "ctrl_student_hil/joystick/L1", 0, "", offsetof(B_ctrl_student_HIL_T,
    L1_b)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 182, 0 },

  { 92, "ctrl_student_hil/joystick/R1", 0, "", offsetof(B_ctrl_student_HIL_T, R1)
    +0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 184, 0 },

  { 93, "ctrl_student_hil/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    186, 0 },

  { 94, "ctrl_student_hil/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    188, 0 },

  { 95, "ctrl_student_hil/joystick/Voith Schneider Propeller", 0, "Omega1",
    offsetof(B_ctrl_student_HIL_T, Omega1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 190, 0 },

  { 96, "ctrl_student_hil/joystick/Voith Schneider Propeller", 1, "Omega2",
    offsetof(B_ctrl_student_HIL_T, Omega2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 192, 0 },

  { 97, "ctrl_student_hil/joystick/MATLAB Function1", 0, "u_VSP", offsetof
    (B_ctrl_student_HIL_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 194, 0
  },

  { 98, "ctrl_student_hil/joystick/MATLAB Function1", 1, "a_VSP", offsetof
    (B_ctrl_student_HIL_T, a_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 196, 0
  },

  { 99, "ctrl_student_hil/joystick/MATLAB Function", 0, "u", offsetof
    (B_ctrl_student_HIL_T, u)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 198, 0 },

  { 100, "ctrl_student_hil/joystick/MATLAB Function", 1, "a", offsetof
    (B_ctrl_student_HIL_T, a)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 200, 0 },

  { 101, "ctrl_student_hil/joystick/Bow thruster", 0, "u_BT", offsetof
    (B_ctrl_student_HIL_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 202, 0
  },

  { 102, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Tank Limits", 0,
    "x_d1", offsetof(B_ctrl_student_HIL_T, x_d1)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 204, 0 },

  { 103, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Tank Limits", 1,
    "M1", offsetof(B_ctrl_student_HIL_T, M1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 206, 0 },

  { 104, "ctrl_student_hil/Tank (CASE B)/TANK LIMITS (CASE B)/Tank Limits", 2,
    "s1", offsetof(B_ctrl_student_HIL_T, s1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 208, 0 },

  { 105, "ctrl_student_hil/SWITCH", 0, "Eta(1,1)", offsetof(B_ctrl_student_HIL_T,
    Eta)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 210, 0 },

  { 106, "ctrl_student_hil/SWITCH", 0, "Eta(1,2)", offsetof(B_ctrl_student_HIL_T,
    Eta)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 212, 0 },

  { 107, "ctrl_student_hil/SWITCH", 0, "Eta(1,3)", offsetof(B_ctrl_student_HIL_T,
    Eta)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2, 214, 0 },

  { 108, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,1)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+0*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 216, 0 },

  { 109, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,2)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+1*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 218, 0 },

  { 110, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,3)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+2*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 220, 0 },

  { 111, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,4)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+3*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 222, 0 },

  { 112, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,5)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+4*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 224, 0 },

  { 113, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,6)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+5*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 226, 0 },

  { 114, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,7)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+6*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 228, 0 },

  { 115, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,8)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+7*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 230, 0 },

  { 116, "ctrl_student_hil/Observer (CASE C)/DP Observer", 0, "x_dot(1,9)",
    offsetof(B_ctrl_student_HIL_T, x_dot)+8*sizeof(real_T), BLOCKIO_SIG, 22, 1,
    2, 232, 0 },

  { 117, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,1)", offsetof(B_ctrl_student_HIL_T, output)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 234, 0 },

  { 118, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,2)", offsetof(B_ctrl_student_HIL_T, output)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 236, 0 },

  { 119, "ctrl_student_hil/Noise generator/Sample & hold/MATLAB Function1", 0,
    "output(1,3)", offsetof(B_ctrl_student_HIL_T, output)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 238, 0 },

  { 120, "ctrl_student_hil/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_T, count)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 240, 0 },

  { 121, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 0, "s_dot",
    offsetof(B_ctrl_student_HIL_T, s_dot)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    242, 0 },

  { 122, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 3,
    "eta_d(1,1)", offsetof(B_ctrl_student_HIL_T, eta_d)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 244, 0 },

  { 123, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 3,
    "eta_d(1,2)", offsetof(B_ctrl_student_HIL_T, eta_d)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 246, 0 },

  { 124, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 3,
    "eta_d(1,3)", offsetof(B_ctrl_student_HIL_T, eta_d)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 248, 0 },

  { 125, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 4,
    "eta_ds(1,1)", offsetof(B_ctrl_student_HIL_T, eta_ds)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 250, 0 },

  { 126, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 4,
    "eta_ds(1,2)", offsetof(B_ctrl_student_HIL_T, eta_ds)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 252, 0 },

  { 127, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 4,
    "eta_ds(1,3)", offsetof(B_ctrl_student_HIL_T, eta_ds)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 254, 0 },

  { 128, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 5,
    "eta_ds2(1,1)", offsetof(B_ctrl_student_HIL_T, eta_ds2)+0*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 256, 0 },

  { 129, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 5,
    "eta_ds2(1,2)", offsetof(B_ctrl_student_HIL_T, eta_ds2)+1*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 258, 0 },

  { 130, "ctrl_student_hil/Guidance (CASE D)/Guidance (Ellipse)", 5,
    "eta_ds2(1,3)", offsetof(B_ctrl_student_HIL_T, eta_ds2)+2*sizeof(real_T),
    BLOCKIO_SIG, 17, 1, 2, 260, 0 },

  { 131, "ctrl_student_hil/Guidance (CASE D)/Control Law", 0, "Tau(1,1)",
    offsetof(B_ctrl_student_HIL_T, Tau)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    262, 0 },

  { 132, "ctrl_student_hil/Guidance (CASE D)/Control Law", 0, "Tau(1,2)",
    offsetof(B_ctrl_student_HIL_T, Tau)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    264, 0 },

  { 133, "ctrl_student_hil/Guidance (CASE D)/Control Law", 0, "Tau(1,3)",
    offsetof(B_ctrl_student_HIL_T, Tau)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    266, 0 },

  { 134, "ctrl_student_hil/Guidance (CASE D)/Control Law", 1, "Rz1(1,1)",
    offsetof(B_ctrl_student_HIL_T, Rz1)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    268, 0 },

  { 135, "ctrl_student_hil/Guidance (CASE D)/Control Law", 1, "Rz1(1,2)",
    offsetof(B_ctrl_student_HIL_T, Rz1)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    270, 0 },

  { 136, "ctrl_student_hil/Guidance (CASE D)/Control Law", 1, "Rz1(1,3)",
    offsetof(B_ctrl_student_HIL_T, Rz1)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    272, 0 },

  { 137, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,1)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    274, 0 },

  { 138, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,2)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    276, 0 },

  { 139, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,3)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    278, 0 },

  { 140, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,4)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    280, 0 },

  { 141, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,5)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    282, 0 },

  { 142, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,6)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    284, 0 },

  { 143, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,7)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    286, 0 },

  { 144, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,8)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    288, 0 },

  { 145, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,9)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    290, 0 },

  { 146, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 1, "Mx1(1,10)",
    offsetof(B_ctrl_student_HIL_T, Mx1)+9*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    292, 0 },

  { 147, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,1)",
    offsetof(B_ctrl_student_HIL_T, My1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    294, 0 },

  { 148, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,2)",
    offsetof(B_ctrl_student_HIL_T, My1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    296, 0 },

  { 149, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,3)",
    offsetof(B_ctrl_student_HIL_T, My1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    298, 0 },

  { 150, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,4)",
    offsetof(B_ctrl_student_HIL_T, My1)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    300, 0 },

  { 151, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,5)",
    offsetof(B_ctrl_student_HIL_T, My1)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    302, 0 },

  { 152, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,6)",
    offsetof(B_ctrl_student_HIL_T, My1)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    304, 0 },

  { 153, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,7)",
    offsetof(B_ctrl_student_HIL_T, My1)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    306, 0 },

  { 154, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,8)",
    offsetof(B_ctrl_student_HIL_T, My1)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    308, 0 },

  { 155, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,9)",
    offsetof(B_ctrl_student_HIL_T, My1)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    310, 0 },

  { 156, "ctrl_student_hil/DROP DETECTOR (CASE B)/DROP DETECTOR", 2, "My1(1,10)",
    offsetof(B_ctrl_student_HIL_T, My1)+9*sizeof(real_T), BLOCKIO_SIG, 19, 1, 2,
    312, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 157;
static int NI_VirtualBlockSources[1][1];
static int NI_VirtualBlockOffsets[1][1];
static int NI_VirtualBlockLengths[1][1];
static int NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 63;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 1, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 5, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 6, "Desired sampling frequency", 0, EXT_IN, 1, 1, 1 },

  { 7, "noise power position", 0, EXT_IN, 1, 1, 1 },

  { 8, "noise power heading", 0, EXT_IN, 1, 1, 1 },

  { 9, "u_dot_imu", 0, EXT_IN, 1, 1, 1 },

  { 10, "enable noise", 0, EXT_IN, 1, 1, 1 },

  { 11, "Observer (CASE C)/L2", 0, EXT_IN, 1, 1, 1 },

  { 12, "Observer (CASE C)/L1", 0, EXT_IN, 1, 1, 1 },

  { 13, "Observer (CASE C)/L3", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 15, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 16, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 17, "joystick/PosXRight", 1, EXT_IN, 1, 1, 1 },

  { 18, "joystick/PosYRight", 1, EXT_IN, 1, 1, 1 },

  { 19, "joystick/ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 20, "joystick/ArrowDown", 0, EXT_IN, 1, 1, 1 },

  { 21, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 22, "joystick/L1", 1, EXT_IN, 1, 1, 1 },

  { 23, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 24, "joystick/ArrowLeft", 1, EXT_IN, 1, 1, 1 },

  { 25, "joystick/ArrowRight", 1, EXT_IN, 1, 1, 1 },

  { 0, "u_true", 1, EXT_OUT, 1, 1, 1 },

  { 1, "psi_out", 0, EXT_OUT, 1, 1, 1 },

  { 2, "fater noise", 0, EXT_OUT, 1, 1, 1 },

  { 3, "eta_hat", 1, EXT_OUT, 3, 3, 1 },

  { 4, "nu_hat", 1, EXT_OUT, 3, 3, 1 },

  { 5, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1 },

  { 6, "tau to CSE mocell (only use for HIL testing)/N_d", 1, EXT_OUT, 1, 1, 1 },

  { 7, "tau to CSE mocell (only use for HIL testing)/Y_d", 1, EXT_OUT, 1, 1, 1 },

  { 8, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 9, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1 },

  { 10, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 11, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 1,
    EXT_OUT, 1, 1, 1 },

  { 12, "Observer (CASE C)/u_hat", 1, EXT_OUT, 1, 1, 1 },

  { 13, "Observer (CASE C)/x_m", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Observer (CASE C)/x_hat", 1, EXT_OUT, 1, 1, 1 },

  { 15, "Observer (CASE C)/y_hat", 1, EXT_OUT, 1, 1, 1 },

  { 16, "Observer (CASE C)/psi_hat", 1, EXT_OUT, 1, 1, 1 },

  { 17, "Observer (CASE C)/v_hat", 1, EXT_OUT, 1, 1, 1 },

  { 18, "Observer (CASE C)/r_hat", 1, EXT_OUT, 1, 1, 1 },

  { 19, "Observer (CASE C)/bx_hat", 1, EXT_OUT, 1, 1, 1 },

  { 20, "Observer (CASE C)/by_hat", 1, EXT_OUT, 1, 1, 1 },

  { 21, "Observer (CASE C)/bpsi_hat", 1, EXT_OUT, 1, 1, 1 },

  { 22, "Observer (CASE C)/y_m", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Observer (CASE C)/psi_m", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Observer (CASE C)/x-error", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Observer (CASE C)/y-error", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Observer (CASE C)/psi_error", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Tank (CASE B)/X", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Tank (CASE B)/Y", 1, EXT_OUT, 1, 1, 1 },

  { 29, "Tank (CASE B)/Z", 1, EXT_OUT, 1, 1, 1 },

  { 30, "joystick/u_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 31, "joystick/alpha_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 32, "joystick/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 33, "joystick/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 34, "joystick/u_BT", 1, EXT_OUT, 1, 1, 1 },

  { 35, "joystick/alpha_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 36, "joystick/u_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_student_hil";
static char* NI_CompiledModelVersion = "1.174";
static char* NI_CompiledModelDateTime = "Thu Mar 23 16:26:29 2017";
static char* NI_builder DataSection(".NIVS.builder") =
  "NI VeriStand 2014.0.0.82 (2014) RTW Build";
static char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2014.0.0.82";

/* Model Information Query fucntions for MATLAB
 */
/* dll information
 * Returns 1 for RTW DLL
 *		   2 for AutoCode DLL
 */
DLL_EXPORT long NIRT_GetBuildInfo(char* detail, long* len)
{
  // There are no console properties to set for VxWorks, because the console is simply serial output data.
  // Just do printf for VxWorks and ignore all console properties.
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  printf("\n*******************************************************************************\n");
  printf("%s\nModel Name: %s\nModel Version: %s\nCompiled On: %s",
         NI_builder, NI_CompiledModelName, NI_CompiledModelVersion,
         NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len>=(long)strlen(NI_builder))
    *len = strlen(NI_builder)+1;
  strncpy(detail,NI_builder,*len);
  return 1;
}

/*
 * Distinction between Index and ID:
 * Index is a long datatype (used to set parameter/probe signals).
 * ID on the other hand is a string (tag "2-3-2-12" for MatrixX/ Full path "f14/Gain/Gain" for Matlab).
 * If Bus support is added then signal path from the block name is added to the end of the port number (Model/subsystem1:1/X/A)
 * where X/A is the path from the block
 * NOTE: ID may not be the same as Paramname or signal name.
 */

/* signal information
   NOTE: signal ID == the blockname and port that feeds it extended with /sinalname.

   The port number in Simulation Environment is 1 indexed.. but on RT is 0 indexed.
 */
DLL_EXPORT long NIRT_GetSignalSpec(long* sidx, char* ID, long* ID_len, char
  * blkname, long *bnlen,
  long *portnum, char* signame, long *snlen, long *dattype, long* dims, long
  * numdim)
{
  long sigidx = *sidx;
  int i = 0;
  char *IDblk = 0;
  int IDport = 0;
  if (sigidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // parse ID into blkname and port
      i = strrchr(ID, ':') - ID;

      // malformed ID
      if (i<=0)
        return NI_SigListSize;

      //ID[i] = 0;
      IDblk = ID;
      IDport = atoi(ID+i+1);

      // lookup the table for matching ID
      // Bus support
      for (i=0;i<NI_SigListSize;i++) {
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname)+ 11, sizeof(char));

        //sprintf(tempID,"%s%s%s",NI_SigList[i].blockname,"/",NI_SigList[i].signalname);
        if (strlen(NI_SigList[i].signalname)>0)
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        else
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1))
          break;
        free(tempID);
      }

      if (i<NI_SigListSize)
        sigidx = *sidx = i;
      else
        return NI_SigListSize;
    } else                             // no index or ID specified.
      return NI_SigListSize;
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID) {
      // no need for return string to be null terminated!
      // 11 to accomodate ':','/', port number and null character
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0)
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      else
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      if ((long)strlen(tempID)<*ID_len)
        *ID_len = strlen(tempID);
      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].blockname)<*bnlen)
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_SigList[sigidx].signalname)<*snlen)
        *snlen = strlen(NI_SigList[sigidx].signalname);
      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum)
      *portnum = NI_SigList[sigidx].portno;
    if (dattype)
      *dattype = NI_SigList[sigidx].datatype;
    if (dims && *numdim>=NI_SigList[sigidx].numofdims) {
      *numdim = NI_SigList[sigidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_SigListSize;
}

/*
 * Get parameter indices
 */
DLL_EXPORT long NIRT_GetParameterIndices(long* indices, long* len)
{
  long i;
  for (i=0;i<NI_ParamListSize && i<*len;i++)
    indices[i] = NI_ParamList[i].idx;
  *len = i;
  return NI_OK;
}

/*
 * parameter information
 *
 * if *pidx < 0, Lookup parameter by ID if ID != NULL.
 * if ID == NULL or no matching ID found, return number of parameters.
 *
 * plen  -> size of path
 * pnlen -> size of paramname
 * numdim -> size of dims array
 */
DLL_EXPORT long NIRT_GetParameterSpec(long* pidx, char* ID, long* ID_len, char
  * paramname, long *pnlen,
  long *dattype, long* dims, long* numdim)
{
  int i= 0;
  int paramidx = *pidx;
  if (paramidx<0) {
    // check if ID has been specified.
    if (ID && *ID_len>0) {
      // lookup the table for matching ID
      for (i=0;i<NI_ParamListSize;i++) {
        if (!strcmp(ID,NI_ParamList[i].paramname))
          break;
      }

      if (i<NI_ParamListSize)
        paramidx = *pidx = i;
      else
        return NI_ParamListSize;
    } else                             // no index or ID specified.
      return NI_ParamListSize;
  }

  if (paramidx>=0 && paramidx<NI_ParamListSize) {
    if (ID) {
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*ID_len)
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname) {
      // no need for return string to be null terminated!
      if ((long)strlen(NI_ParamList[paramidx].paramname)<*pnlen)
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype)
      *dattype = NI_ParamList[paramidx].datatype;
    if (!numdim)
      return 0;
    if (*numdim>=NI_ParamList[paramidx].numofdims) {
      *numdim = NI_ParamList[paramidx].numofdims;
      for (i=0;i < *numdim; i++)
        dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset +i];
    } else
      *numdim = 0;                     // set numdim to 0 to indicate that no enough memory to return the info.
    return 0;
  }

  return NI_ParamListSize;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetParameterExpression(long paramidx, char* expression,
  long *exp_len)
{
  return 0;
}

/*
 * DEPRECATED.
 */
DLL_EXPORT long NIRT_GetVariableName(long varidx, char* variable_name, long
  *var_len)
{
  return 0;
}

/*
 * NIRT_GetExtIOSpec
 *
 * Inputs:
 *		index: index of the task
 * Outputs:
 *		idx:  idx of the IO.
 *		name: Name of the IO block
 *		tid: task id
 *		type: EXT_IN or EXT_OUT
 *		dimX: size of 0th dimension
 *		dimY: size of 1th dimension
 * Return value: 0 if no error. (if index == -1, return number of tasks in the model)
 */
DLL_EXPORT long NIRT_GetExtIOSpec(long index, long *idx, char* name, long* tid,
  long *type, long *dims, long* numdims)
{
  if (index==-1)
    return NI_ExtListSize;
  if (idx)
    *idx = NI_ExtList[index].idx;
  if (name) {
    int sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid)
    *tid = NI_ExtList[index].TID;
  if (type)
    *type = NI_ExtList[index].type;
  if (numdims && dims) {
    if (*numdims>=2) {
      *numdims= 2;
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    } else
      *numdims= 0;
  }

  return 0;
}

/* Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG */
static long NI_ProbeOneSignal(long idx, double *value, long len, long *count,
  long vOffset, long vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (int)
    NI_SigList[idx].addr;
  long subindex = (vLength == -1) ? 0 : vOffset;
  long sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength + vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*
 * NIRT_ProbeSignals
 *
 * Inputs:
 *		sigindices: indeces of signals
 *		numsigs: number of signals
 *		len: total length of all signals
 * Outputs:
 *		value: probed signal data
 *		len: length of data (may vary from input)
 * Return value: equal to len
 */
DLL_EXPORT long NIRT_ProbeSignals(long* sigindices, long numsigs,
  double* value, long* len)
{
  int i, j, idx;
  long count = 0;
  if (!SITexportglobals.inCriticalSection)
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0)
      break;
    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        for (j = 0; j < 2; j++) {
          long vidx = NI_VirtualBlockSources[NI_SigList[idx].addr][j];
          long voff = NI_VirtualBlockOffsets[NI_SigList[idx].addr][j];
          long vlen = NI_VirtualBlockLengths[NI_SigList[idx].addr][j];
          if (vidx == -1)
            break;
          NI_ProbeOneSignal(vidx, value, *len, &count, voff, vlen);
        }
      } else
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
    }
  }

  *len = count;
  return count;
}

/* Copy the	statically initialized params into our copy of the param struct
   The undef allows us to access the real ctrl_student_HIL_P
   In the rest of the code ctrl_student_HIL_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_P, sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_T));
  return NI_OK;
}

static int NI_SetParamTxStatus = NI_OK;

// This function is called by the BGL to set parameters.  When a commit is requested (index < 0),
// the code enters a critical section shared with the TCL. This ensures that the flip occurs only
// when safe, and acts as a messaging scheme for us to copy back the parameters.
DLL_EXPORT long NIRT_SetParameter(long index, long subindex, double value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_HIL_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0)
        return NI_OK;
      SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                         1);
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    if (NI_SetParamTxStatus==NI_ERROR) {
      // fail the transaction.
      // copy old	list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1)
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_student_HIL_T));

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /*Do nothing if no new parameters were written after last commit*/
    if (WriteSideDirtyFlag == 0)
      return NI_OK;

    // commit changes
    S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
    WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
    READSIDE = 1 - READSIDE;
    SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
    ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

    // Copy back the newly set parameters to the writeside.
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    WriteSideDirtyFlag = 0;
    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_SetVectorParameter( unsigned long index, const double
  * paramvalues, unsigned long paramlength)
{
  unsigned int i = 0;
  long retval= NI_OK, temp_retval;
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_HIL_T));
    ReadSideDirtyFlag = 0;
  }

  ptr = (char *)(&rtParameter[1-READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    if (temp_retval = NIRT_SetValueByDataType(ptr, i, paramvalues[i],
         NI_ParamList[index].datatype, NI_ParamList[index].IsComplex))//assignment intended in if condition
      retval= temp_retval;
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

DLL_EXPORT long NIRT_SetScalarParameterInline( unsigned long index, unsigned
  long subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

DLL_EXPORT long NIRT_GetParameter(long index, long subindex, double *value)
{
  char* ptr = NULL;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

DLL_EXPORT long NIRT_GetVectorParameter(unsigned long index, double* paramvalues,
  unsigned long paramlength)
{
  char* ptr = NULL;
  unsigned int i = 0;
  if (index>=NI_ParamListSize || index < 0)
    return NI_ERROR;

  // verify that subindex is within bounds.
  if (paramlength!=NI_ParamList[index].width)
    return NI_ERROR;
  ptr = (char *)(&rtParameter[READSIDE]);
  ptr += (int)NI_ParamList[index].addr;
  while (i<paramlength) {
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_GetSimState(long* numContStates, char* contStatesNames,
  double* contStates, long* numDiscStates, char* discStatesNames, double
  * discStates, long* numClockTicks, char* clockTicksNames, long* clockTicks)
{
  long count, idx;
  if (numContStates && numDiscStates && numClockTicks) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 13;
      *numDiscStates = 1274;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.Int2_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Int2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.s_CSTATE, 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "s_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_X.Int1_CSTATE, 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Int1_CSTATE");
    for (count = 0; count < 9; count++) {
      contStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_X.Integrator_CSTATE[0], count, 0, 0);
      strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    }

    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_X.Integrator_CSTATE_e, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_true_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_true_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.noisepowerposition_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.noisepowerposition_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.noisepowerheading_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.noisepowerheading_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.NextOutput_f,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.NextOutput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Hold_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.faternoise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.faternoise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.u_dot_imu_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.u_dot_imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.enablenoise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.enablenoise_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory_PreviousInput, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.eta_hat_DWORK1, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.eta_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1,
      0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1,
      1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1,
      2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.nu_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory4_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory4_PreviousInput");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory2_PreviousInput, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory2_PreviousInput");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Memory1_PreviousInput, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Memory1_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory5_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.s0_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.s0_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_a, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_a, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_a, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory1_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory2_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory3_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.bx_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.bx_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.by_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.by_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.bpsi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.bpsi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.xerror_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.xerror_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.yerror_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.yerror_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.psi_error_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.psi_error_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.Memory_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_f, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.RandSeed_h, 0,
      7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.RandSeed_h");
    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_true_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_true_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_in_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.r_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_out_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_out_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.v_in_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.noisepowerposition_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.noisepowerposition_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.noisepowerheading_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.noisepowerheading_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.faternoise_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.faternoise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_dot_imu_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_dot_imu_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.enablenoise_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.enablenoise_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.eta_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.eta_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.nu_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.nu_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.N_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_0_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_0_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.integratorresetmodel_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.x_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.x_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.y_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.v_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.r_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bx_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bx_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L3_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L3_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.by_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.by_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.bpsi_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.bpsi_hat_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.y_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_m_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.xerror_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.xerror_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.yerror_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.yerror_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.psi_error_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.psi_error_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.X_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.X_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Y_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.Z_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.Z_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.L2_continuous_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXLeft_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYLeft_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosXRight_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.PosYRight_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowUp_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowDown_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.R2_continuous_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.u_VSP2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2_o,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.L1_DWORK2_o");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_HIL_DW.R1_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.ArrowRight_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 17; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 60; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3");
    }
  }

  if (clockTicks && clockTicksNames) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

DLL_EXPORT long NIRT_SetSimState(double* contStates, double* discStates, long
  * clockTicks)
{
  long count, idx;
  if (contStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Int2_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.s_CSTATE, 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Int1_CSTATE, 0, contStates[idx++],
      0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE[0], count,
        contStates[idx++], 0, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_X.Integrator_CSTATE_e, 0,
      contStates[idx++], 0, 0);
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_true_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepowerposition_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepowerheading_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NextOutput_f, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.faternoise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_dot_imu_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enablenoise_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput, count,
        discStates[idx++], 22, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK1, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory4_PreviousInput, 2,
      discStates[idx++], 17, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput, count,
        discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.s0_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_a, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_a, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_a, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory1_PreviousInput_d, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory2_PreviousInput_d, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory3_PreviousInput_c, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bx_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.by_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bpsi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.xerror_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.yerror_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_error_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK1_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK2,
      0, discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_f, 0, discStates[idx++],
      7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_DW.RandSeed_h, 0, discStates[idx++],
      7, 0);
    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_true_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_out_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_in_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_DW.Desiredsamplingfrequency_DWORK2, count,
         discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepowerposition_DWORK2,
        count, discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.noisepowerheading_DWORK2,
        count, discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.faternoise_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_dot_imu_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.enablenoise_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.eta_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.nu_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.N_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_0_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_0_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_0_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.integratorresetmodel_DWORK2,
        count, discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_m_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.x_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.v_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.r_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bx_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.by_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.bpsi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.y_m_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_m_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.xerror_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.yerror_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.psi_error_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.X_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.Z_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosXRight_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.PosYRight_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.omega_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_BT_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.alpha_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.L1_DWORK2_o, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.R1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.ArrowRight_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 17; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK1,
        count, discStates[idx++], 20, 0);
    }

    for (count = 0; count < 60; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_DW.NIVeriStandSignalProbe_DWORK3,
        count, discStates[idx++], 21, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL
