/*
 * ctrl_student_HIL_saved.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL_saved".
 *
 * Model version              : 1.156
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 06 09:54:41 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_student_HIL_saved.h"
#include "ctrl_student_HIL_saved_private.h"

const real_T ctrl_student_HIL_saved_RGND = 0.0;/* real_T ground */

/* Block signals (auto storage) */
B_ctrl_student_HIL_saved_T ctrl_student_HIL_saved_B;

/* Continuous states */
X_ctrl_student_HIL_saved_T ctrl_student_HIL_saved_X;

/* Block states (auto storage) */
DW_ctrl_student_HIL_saved_T ctrl_student_HIL_saved_DW;

/* Real-time model */
RT_MODEL_ctrl_student_HIL_sav_T ctrl_student_HIL_saved_M_;
RT_MODEL_ctrl_student_HIL_sav_T *const ctrl_student_HIL_saved_M =
  &ctrl_student_HIL_saved_M_;

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_HIL_saved_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_student_HIL_saved_output();
  ctrl_student_HIL_saved_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_student_HIL_saved_output();
  ctrl_student_HIL_saved_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_student_HIL_saved_output();
  ctrl_student_HIL_saved_derivatives();

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

/* Model output function */
void ctrl_student_HIL_saved_output(void)
{
  real_T Omega;
  boolean_T y;
  real_T x[10];
  boolean_T guard1 = false;
  boolean_T exitg2;
  real_T R[9];
  static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T a[9] = { -0.059559261465157838, 0.0, -0.0, 0.0,
    -0.040521023365024243, 0.0081427436897922364, 0.0, 0.0081427436897922364,
    -0.36395513377498229 };

  static const real_T b_a[9] = { 0.059559261465157838, -0.0, 0.0, -0.0,
    0.040521023365024243, -0.0081427436897922364, -0.0, -0.0081427436897922364,
    0.36395513377498229 };

  static const real_T c_a[9] = { 0.059559261465157838, 0.0, 0.0, 0.0,
    0.040521023365024243, -0.0081427436897922364, 0.0, -0.0081427436897922364,
    0.36395513377498229 };

  int32_T rtb_Drop;
  int32_T i;
  int32_T i_0;
  real_T c_a_0[9];
  real_T tmp[9];
  real_T c_a_1[9];
  real_T a_0[9];
  real_T tmp_0[9];
  real_T tmp_1[81];
  real_T b_a_0[3];
  real_T tmp_2[9];
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_2;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* set solver stop time */
    if (!(ctrl_student_HIL_saved_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_HIL_saved_M->solverInfo,
                            ((ctrl_student_HIL_saved_M->Timing.clockTickH0 + 1) *
        ctrl_student_HIL_saved_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_HIL_saved_M->solverInfo,
                            ((ctrl_student_HIL_saved_M->Timing.clockTick0 + 1) *
        ctrl_student_HIL_saved_M->Timing.stepSize0 +
        ctrl_student_HIL_saved_M->Timing.clockTickH0 *
        ctrl_student_HIL_saved_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_HIL_saved_M)) {
    ctrl_student_HIL_saved_M->Timing.t[0] = rtsiGetT
      (&ctrl_student_HIL_saved_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Memory: '<Root>/Memory' */
    memcpy(&ctrl_student_HIL_saved_B.Memory[0],
           &ctrl_student_HIL_saved_DW.Memory_PreviousInput[0], 9U * sizeof
           (real_T));
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* MATLAB Function: '<S7>/MATLAB Function1' */
    /* MATLAB Function 'joystick/MATLAB Function1': '<S42>:1' */
    /* The force angle. */
    /* '<S42>:1:4' */
    ctrl_student_HIL_saved_B.a_VSP = rt_atan2d_snf
      (ctrl_student_HIL_saved_B.PosXLeft, -ctrl_student_HIL_saved_B.PosYLeft);

    /* generalised force */
    /* '<S42>:1:6' */
    Omega = sqrt(ctrl_student_HIL_saved_B.PosXLeft *
                 ctrl_student_HIL_saved_B.PosXLeft +
                 ctrl_student_HIL_saved_B.PosYLeft *
                 ctrl_student_HIL_saved_B.PosYLeft);
    if ((1.0 <= Omega) || rtIsNaN(Omega)) {
      ctrl_student_HIL_saved_B.u_VSP = 1.0;
    } else {
      ctrl_student_HIL_saved_B.u_VSP = Omega;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function1' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Memory: '<S7>/Memory' */
    ctrl_student_HIL_saved_B.Memory_f =
      ctrl_student_HIL_saved_DW.Memory_PreviousInput_n;
  }

  /* MATLAB Function: '<S7>/Voith Schneider Propeller' incorporates:
   *  Integrator: '<S7>/Integrator'
   */
  /* MATLAB Function 'joystick/Voith Schneider Propeller': '<S43>:1' */
  /* find the remain time. */
  /* '<S43>:1:4' */
  /* use if sentence to calculate the correct rotational speed. */
  if (ctrl_student_HIL_saved_X.Integrator_CSTATE - floor
      (ctrl_student_HIL_saved_X.Integrator_CSTATE) <= 0.01) {
    /* '<S43>:1:6' */
    /* '<S43>:1:7' */
    Omega = (0.1 * ctrl_student_HIL_saved_B.ArrowUp +
             ctrl_student_HIL_saved_B.Memory_f) - 0.1 *
      ctrl_student_HIL_saved_B.ArrowDown;
  } else {
    /* '<S43>:1:9' */
    Omega = ctrl_student_HIL_saved_B.Memory_f;
  }

  /* define the value of rotational speed. */
  /* '<S43>:1:14' */
  ctrl_student_HIL_saved_B.Omega1 = Omega;

  /* '<S43>:1:15' */
  ctrl_student_HIL_saved_B.Omega2 = Omega;

  /* End of MATLAB Function: '<S7>/Voith Schneider Propeller' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* MATLAB Function: '<S7>/Bow thruster' */
    /* MATLAB Function 'joystick/Bow thruster': '<S40>:1' */
    /* '<S40>:1:4' */
    ctrl_student_HIL_saved_B.u_BT = (ctrl_student_HIL_saved_B.R2_continuous -
      ctrl_student_HIL_saved_B.L2_continuous) / 2.0;

    /* MATLAB Function: '<S7>/MATLAB Function' */
    /* MATLAB Function 'joystick/MATLAB Function': '<S41>:1' */
    /* '<S41>:1:4' */
    ctrl_student_HIL_saved_B.a = rt_atan2d_snf
      (ctrl_student_HIL_saved_B.PosXRight, -ctrl_student_HIL_saved_B.PosYRight);

    /* '<S41>:1:5' */
    Omega = sqrt(ctrl_student_HIL_saved_B.PosXRight *
                 ctrl_student_HIL_saved_B.PosXRight +
                 ctrl_student_HIL_saved_B.PosYRight *
                 ctrl_student_HIL_saved_B.PosYRight);
    if ((1.0 <= Omega) || rtIsNaN(Omega)) {
      ctrl_student_HIL_saved_B.u = 1.0;
    } else {
      ctrl_student_HIL_saved_B.u = Omega;
    }

    /* End of MATLAB Function: '<S7>/MATLAB Function' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Memory: '<S10>/counter' */
    ctrl_student_HIL_saved_B.counter =
      ctrl_student_HIL_saved_DW.counter_PreviousInput;
  }

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Step size'
   */
  /* MATLAB Function 'Noise generator/Downsample	signal/MATLAB Function': '<S13>:1' */
  /* '<S13>:1:3' */
  if ((ctrl_student_HIL_saved_B.counter + 1.0) *
      ctrl_student_HIL_saved_P.Stepsize_Value >= 1.0 /
      ctrl_student_HIL_saved_B.Desiredsamplingfrequency) {
    /* '<S13>:1:4' */
    /* '<S13>:1:5' */
    ctrl_student_HIL_saved_B.count = 0.0;
  } else {
    /* '<S13>:1:7' */
    ctrl_student_HIL_saved_B.count = ctrl_student_HIL_saved_B.counter + 1.0;
  }

  /* End of MATLAB Function: '<S10>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* RandomNumber: '<S16>/White Noise' */
    ctrl_student_HIL_saved_B.WhiteNoise = ctrl_student_HIL_saved_DW.NextOutput;

    /* RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_saved_B.WhiteNoise_p =
      ctrl_student_HIL_saved_DW.NextOutput_a;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* RandomNumber: '<S15>/White Noise' */
    ctrl_student_HIL_saved_B.WhiteNoise_i =
      ctrl_student_HIL_saved_DW.NextOutput_f;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Memory: '<S11>/Hold' */
    ctrl_student_HIL_saved_B.Hold[0] =
      ctrl_student_HIL_saved_DW.Hold_PreviousInput[0];
    ctrl_student_HIL_saved_B.Hold[1] =
      ctrl_student_HIL_saved_DW.Hold_PreviousInput[1];
    ctrl_student_HIL_saved_B.Hold[2] =
      ctrl_student_HIL_saved_DW.Hold_PreviousInput[2];
  }

  /* MATLAB Function: '<S11>/MATLAB Function1' incorporates:
   *  Constant: '<S3>/Step size'
   *  Product: '<S15>/Divide'
   *  Product: '<S15>/Product'
   *  Product: '<S16>/Divide'
   *  Product: '<S16>/Product'
   *  Product: '<S17>/Divide'
   *  Product: '<S17>/Product'
   *  Sqrt: '<S15>/Sqrt'
   *  Sqrt: '<S16>/Sqrt'
   *  Sqrt: '<S17>/Sqrt'
   *  Sum: '<S3>/Sum'
   */
  /* MATLAB Function 'Noise generator/Sample & hold/MATLAB Function1': '<S14>:1' */
  if (ctrl_student_HIL_saved_B.count == 0.0) {
    /* '<S14>:1:4' */
    /* '<S14>:1:5' */
    ctrl_student_HIL_saved_B.output[0] = sqrt
      (ctrl_student_HIL_saved_B.noisepowerposition /
       ctrl_student_HIL_saved_P.Stepsize_Value) *
      ctrl_student_HIL_saved_B.WhiteNoise + ctrl_student_HIL_saved_B.x_in;
    ctrl_student_HIL_saved_B.output[1] = sqrt
      (ctrl_student_HIL_saved_B.noisepowerposition /
       ctrl_student_HIL_saved_P.Stepsize_Value) *
      ctrl_student_HIL_saved_B.WhiteNoise_p + ctrl_student_HIL_saved_B.y_in;
    ctrl_student_HIL_saved_B.output[2] = sqrt
      (ctrl_student_HIL_saved_B.noisepowerheading /
       ctrl_student_HIL_saved_P.Stepsize_Value) *
      ctrl_student_HIL_saved_B.WhiteNoise_i + ctrl_student_HIL_saved_B.psi_in;
  } else {
    /* '<S14>:1:7' */
    ctrl_student_HIL_saved_B.output[0] = ctrl_student_HIL_saved_B.Hold[0];
    ctrl_student_HIL_saved_B.output[1] = ctrl_student_HIL_saved_B.Hold[1];
    ctrl_student_HIL_saved_B.output[2] = ctrl_student_HIL_saved_B.Hold[2];
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function1' */

  /* Switch: '<S3>/Switch' */
  if (ctrl_student_HIL_saved_B.enablenoise != 0.0) {
    Omega = ctrl_student_HIL_saved_B.output[0];
    rtb_Switch_idx_1 = ctrl_student_HIL_saved_B.output[1];
    rtb_Switch_idx_2 = ctrl_student_HIL_saved_B.output[2];
  } else {
    Omega = ctrl_student_HIL_saved_B.x_in;
    rtb_Switch_idx_1 = ctrl_student_HIL_saved_B.y_in;
    rtb_Switch_idx_2 = ctrl_student_HIL_saved_B.psi_in;
  }

  /* End of Switch: '<S3>/Switch' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    for (i = 0; i < 10; i++) {
      /* Memory: '<S2>/Memory2' */
      ctrl_student_HIL_saved_B.Memory2[i] =
        ctrl_student_HIL_saved_DW.Memory2_PreviousInput[i];

      /* Memory: '<S2>/Memory1' */
      ctrl_student_HIL_saved_B.Memory1[i] =
        ctrl_student_HIL_saved_DW.Memory1_PreviousInput[i];
    }
  }

  /* MATLAB Function: '<S2>/DROP DETECTOR' */
  /* MATLAB Function 'DROP DETECTOR/DROP DETECTOR': '<S9>:1' */
  /* '<S9>:1:3' */
  /* '<S9>:1:4' */
  /* '<S9>:1:6' */
  /* '<S9>:1:7' */
  /* '<S9>:1:9' */
  ctrl_student_HIL_saved_B.Mx1[0] = ctrl_student_HIL_saved_B.Memory2[1];
  ctrl_student_HIL_saved_B.Mx1[1] = ctrl_student_HIL_saved_B.Memory2[2];
  ctrl_student_HIL_saved_B.Mx1[2] = ctrl_student_HIL_saved_B.Memory2[3];
  ctrl_student_HIL_saved_B.Mx1[3] = ctrl_student_HIL_saved_B.Memory2[4];
  ctrl_student_HIL_saved_B.Mx1[4] = ctrl_student_HIL_saved_B.Memory2[5];
  ctrl_student_HIL_saved_B.Mx1[5] = ctrl_student_HIL_saved_B.Memory2[6];
  ctrl_student_HIL_saved_B.Mx1[6] = ctrl_student_HIL_saved_B.Memory2[7];
  ctrl_student_HIL_saved_B.Mx1[7] = ctrl_student_HIL_saved_B.Memory2[8];
  ctrl_student_HIL_saved_B.Mx1[8] = ctrl_student_HIL_saved_B.Memory2[9];
  ctrl_student_HIL_saved_B.Mx1[9] = Omega;

  /* '<S9>:1:10' */
  ctrl_student_HIL_saved_B.My1[0] = ctrl_student_HIL_saved_B.Memory1[1];
  ctrl_student_HIL_saved_B.My1[1] = ctrl_student_HIL_saved_B.Memory1[2];
  ctrl_student_HIL_saved_B.My1[2] = ctrl_student_HIL_saved_B.Memory1[3];
  ctrl_student_HIL_saved_B.My1[3] = ctrl_student_HIL_saved_B.Memory1[4];
  ctrl_student_HIL_saved_B.My1[4] = ctrl_student_HIL_saved_B.Memory1[5];
  ctrl_student_HIL_saved_B.My1[5] = ctrl_student_HIL_saved_B.Memory1[6];
  ctrl_student_HIL_saved_B.My1[6] = ctrl_student_HIL_saved_B.Memory1[7];
  ctrl_student_HIL_saved_B.My1[7] = ctrl_student_HIL_saved_B.Memory1[8];
  ctrl_student_HIL_saved_B.My1[8] = ctrl_student_HIL_saved_B.Memory1[9];
  ctrl_student_HIL_saved_B.My1[9] = rtb_Switch_idx_1;
  for (i_0 = 0; i_0 < 10; i_0++) {
    x[i_0] = ctrl_student_HIL_saved_B.Mx1[i_0] -
      ctrl_student_HIL_saved_B.Memory2[i_0];
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
    for (i_0 = 0; i_0 < 10; i_0++) {
      x[i_0] = ctrl_student_HIL_saved_B.My1[i_0] -
        ctrl_student_HIL_saved_B.Memory1[i_0];
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
      rtb_Drop = 1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    /* '<S9>:1:15' */
    rtb_Drop = 0;
  }

  /* End of MATLAB Function: '<S2>/DROP DETECTOR' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Memory: '<S6>/Memory3' */
    ctrl_student_HIL_saved_B.Memory3 =
      ctrl_student_HIL_saved_DW.Memory3_PreviousInput;

    /* Memory: '<S6>/Memory5' */
    ctrl_student_HIL_saved_B.Memory5 =
      ctrl_student_HIL_saved_DW.Memory5_PreviousInput;
  }

  /* MATLAB Function: '<Root>/SWITCH' incorporates:
   *  Integrator: '<Root>/Int2'
   *  Sum: '<Root>/Sum4'
   */
  /* MATLAB Function 'SWITCH': '<S4>:1' */
  if (rtb_Drop == 1) {
    /* '<S4>:1:3' */
    /* '<S4>:1:4' */
    ctrl_student_HIL_saved_B.Eta[0] = ctrl_student_HIL_saved_X.Int2_CSTATE +
      Omega;
    ctrl_student_HIL_saved_B.Eta[1] = ctrl_student_HIL_saved_X.Int2_CSTATE +
      rtb_Switch_idx_1;
    ctrl_student_HIL_saved_B.Eta[2] = ctrl_student_HIL_saved_X.Int2_CSTATE +
      rtb_Switch_idx_2;
  } else {
    /* '<S4>:1:6' */
    ctrl_student_HIL_saved_B.Eta[0] = Omega;
    ctrl_student_HIL_saved_B.Eta[1] = rtb_Switch_idx_1;
    ctrl_student_HIL_saved_B.Eta[2] = rtb_Switch_idx_2;
  }

  /* End of MATLAB Function: '<Root>/SWITCH' */

  /* MATLAB Function: '<S6>/Tank Limits' */
  /* %Eta = [0,0,0]'; */
  /* MATLAB Function 'TANK LIMITS/Tank Limits': '<S39>:1' */
  /* '<S39>:1:4' */
  /* '<S39>:1:5' */
  /* psi = eta(3); */
  /* '<S39>:1:9' */
  /* '<S39>:1:10' */
  /* '<S39>:1:11' */
  /* '<S39>:1:12' */
  /*  If too close from edges, change sign */
  if (ctrl_student_HIL_saved_B.Memory3 == 0.0) {
    /* '<S39>:1:16' */
    if ((ctrl_student_HIL_saved_B.Eta[0] < -1.5) ||
        (ctrl_student_HIL_saved_B.Eta[0] > 1.5) ||
        (ctrl_student_HIL_saved_B.Eta[1] < -2.5) ||
        (ctrl_student_HIL_saved_B.Eta[1] > 2.5)) {
      /* '<S39>:1:17' */
      /* '<S39>:1:18' */
      Omega = -ctrl_student_HIL_saved_B.Memory5;

      /* '<S39>:1:19' */
      ctrl_student_HIL_saved_B.M1 = 1.0;
    } else {
      /* '<S39>:1:21' */
      ctrl_student_HIL_saved_B.M1 = ctrl_student_HIL_saved_B.Memory3;

      /* '<S39>:1:22' */
      Omega = ctrl_student_HIL_saved_B.Memory5;
    }
  } else {
    /*  M = 1 */
    if ((ctrl_student_HIL_saved_B.Eta[0] >= -0.75) &&
        (ctrl_student_HIL_saved_B.Eta[0] <= 0.75) &&
        (ctrl_student_HIL_saved_B.Eta[1] >= -1.25) &&
        (ctrl_student_HIL_saved_B.Eta[1] <= 1.25)) {
      /* '<S39>:1:25' */
      /* '<S39>:1:26' */
      ctrl_student_HIL_saved_B.M1 = 0.0;

      /* '<S39>:1:27' */
      Omega = ctrl_student_HIL_saved_B.Memory5;
    } else {
      /* '<S39>:1:29' */
      ctrl_student_HIL_saved_B.M1 = ctrl_student_HIL_saved_B.Memory3;

      /* '<S39>:1:30' */
      Omega = ctrl_student_HIL_saved_B.Memory5;
    }
  }

  /* '<S39>:1:34' */
  ctrl_student_HIL_saved_B.x_d1 = Omega * ctrl_student_HIL_saved_B.ArrowRight;
  ctrl_student_HIL_saved_B.s1 = Omega;

  /* End of MATLAB Function: '<S6>/Tank Limits' */
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  /* Sum: '<Root>/Subtract' */
  ctrl_student_HIL_saved_B.Subtract = ctrl_student_HIL_saved_B.Eta[0] -
    ctrl_student_HIL_saved_B.Memory[0];

  /* Sum: '<Root>/Subtract1' */
  ctrl_student_HIL_saved_B.Subtract1 = ctrl_student_HIL_saved_B.Eta[1] -
    ctrl_student_HIL_saved_B.Memory[1];

  /* Sum: '<Root>/Subtract2' */
  ctrl_student_HIL_saved_B.Subtract2 = ctrl_student_HIL_saved_B.Eta[2] -
    ctrl_student_HIL_saved_B.Memory[2];
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }

  /* MATLAB Function: '<Root>/DP Observer' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport5'
   */
  /* MATLAB Function 'DP Observer': '<S1>:1' */
  /* % INPUT PARAMETERS */
  /*  Mass matrix */
  /* '<S1>:1:12' */
  /*  Surge velocity */
  /* '<S1>:1:13' */
  /*  Sway velocity */
  /* '<S1>:1:14' */
  /*  Yaw rate */
  /* '<S1>:1:15' */
  /*  Heading */
  /*  Inverse of M */
  /* '<S1>:1:18' */
  /* '<S1>:1:21' */
  /* '<S1>:1:24' */
  /* '<S1>:1:29' */
  /* '<S1>:1:33' */
  /* '<S1>:1:38' */
  /* '<S1>:1:39' */
  /* '<S1>:1:40' */
  /* '<S1>:1:41' */
  /* '<S1>:1:42' */
  /* '<S1>:1:44' */
  /*  Damping matrix */
  /* % TUNING & ALGORITHM */
  /* '<S1>:1:51' */
  /*  Diagonal Matrices are more simple for tuning */
  /* '<S1>:1:52' */
  /* '<S1>:1:53' */
  /*  See Appendix */
  /* '<S1>:1:56' */
  R[0] = cos(ctrl_student_HIL_saved_B.Eta[2]);
  R[3] = -sin(ctrl_student_HIL_saved_B.Eta[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_student_HIL_saved_B.Eta[2]);
  R[4] = cos(ctrl_student_HIL_saved_B.Eta[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /*  Rotation Matrix */
  /* '<S1>:1:61' */
  /*  State Space Matrix */
  /* '<S1>:1:66' */
  /*  Control Input (vertical vector) */
  /* '<S1>:1:69' */
  /*  See Observer Design (vertical vector) */
  /* '<S1>:1:75' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      c_a_0[i_0 + 3 * i] = 0.0;
      c_a_0[i_0 + 3 * i] += c_a[i_0] * R[i];
      c_a_0[i_0 + 3 * i] += c_a[i_0 + 3] * R[i + 3];
      c_a_0[i_0 + 3 * i] += c_a[i_0 + 6] * R[i + 6];
    }
  }

  tmp[0] = (0.6555 - -0.3545 * fabs(ctrl_student_HIL_saved_B.Memory[3])) -
    ctrl_student_HIL_saved_B.Memory[3] * ctrl_student_HIL_saved_B.Memory[3] *
    -3.787;
  tmp[3] = 0.0;
  tmp[6] = 0.0;
  tmp[1] = 0.0;
  tmp[4] = ((1.33 - -2.776 * fabs(ctrl_student_HIL_saved_B.Memory[4])) -
            ctrl_student_HIL_saved_B.Memory[4] *
            ctrl_student_HIL_saved_B.Memory[4] * -64.91) - -0.805 * fabs
    (ctrl_student_HIL_saved_B.Memory[5]);
  tmp[7] = ((7.25 - -0.845 * fabs(ctrl_student_HIL_saved_B.Memory[4])) - -3.45 *
            fabs(ctrl_student_HIL_saved_B.Memory[5])) -
    ctrl_student_HIL_saved_B.Memory[5] * ctrl_student_HIL_saved_B.Memory[5] *
    0.0;
  tmp[2] = 0.0;
  tmp[5] = ((-0.0 - -0.2088 * fabs(ctrl_student_HIL_saved_B.Memory[4])) -
            ctrl_student_HIL_saved_B.Memory[4] *
            ctrl_student_HIL_saved_B.Memory[4] * 0.0) - 0.13 * fabs
    (ctrl_student_HIL_saved_B.Memory[5]);
  tmp[8] = ((1.9 - 0.08 * fabs(ctrl_student_HIL_saved_B.Memory[4])) - -0.75 *
            fabs(ctrl_student_HIL_saved_B.Memory[5])) -
    ctrl_student_HIL_saved_B.Memory[5] * ctrl_student_HIL_saved_B.Memory[5] *
    0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      c_a_1[i_0 + 3 * i] = 0.0;
      c_a_1[i_0 + 3 * i] += (real_T)b_b[3 * i] * ctrl_student_HIL_saved_B.L2 *
        c_a_0[i_0];
      c_a_1[i_0 + 3 * i] += (real_T)b_b[3 * i + 1] * ctrl_student_HIL_saved_B.L2
        * c_a_0[i_0 + 3];
      c_a_1[i_0 + 3 * i] += (real_T)b_b[3 * i + 2] * ctrl_student_HIL_saved_B.L2
        * c_a_0[i_0 + 6];
    }
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      a_0[i_0 + 3 * i] = 0.0;
      a_0[i_0 + 3 * i] += tmp[3 * i] * a[i_0];
      a_0[i_0 + 3 * i] += tmp[3 * i + 1] * a[i_0 + 3];
      a_0[i_0 + 3 * i] += tmp[3 * i + 2] * a[i_0 + 6];
    }
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      c_a_0[i_0 + 3 * i] = 0.0;
      c_a_0[i_0 + 3 * i] += b_a[i_0] * R[i];
      c_a_0[i_0 + 3 * i] += b_a[i_0 + 3] * R[i + 3];
      c_a_0[i_0 + 3 * i] += b_a[i_0 + 6] * R[i + 6];
    }
  }

  tmp_0[0] = ctrl_student_HIL_saved_B.Eta[0] - 2.0 *
    ctrl_student_HIL_saved_B.Memory[0];
  tmp_0[1] = ctrl_student_HIL_saved_B.Eta[1] - 2.0 *
    ctrl_student_HIL_saved_B.Memory[1];
  tmp_0[2] = ctrl_student_HIL_saved_B.Eta[2] - 2.0 *
    ctrl_student_HIL_saved_B.Memory[2];
  tmp_0[3] = 0.0;
  tmp_0[4] = 0.0;
  tmp_0[5] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[8] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[9 * i_0] = (real_T)b_b[3 * i_0] * ctrl_student_HIL_saved_B.L1_i;
    tmp_1[1 + 9 * i_0] = (real_T)b_b[3 * i_0 + 1] *
      ctrl_student_HIL_saved_B.L1_i;
    tmp_1[2 + 9 * i_0] = (real_T)b_b[3 * i_0 + 2] *
      ctrl_student_HIL_saved_B.L1_i;
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[9 * (i_0 + 3)] = R[3 * i_0];
    tmp_1[1 + 9 * (i_0 + 3)] = R[3 * i_0 + 1];
    tmp_1[2 + 9 * (i_0 + 3)] = R[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[9 * (i_0 + 6)] = 0.0;
    tmp_1[1 + 9 * (i_0 + 6)] = 0.0;
    tmp_1[2 + 9 * (i_0 + 6)] = 0.0;
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[3 + 9 * i_0] = c_a_1[3 * i_0];
    tmp_1[4 + 9 * i_0] = c_a_1[3 * i_0 + 1];
    tmp_1[5 + 9 * i_0] = c_a_1[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[3 + 9 * (i_0 + 3)] = a_0[3 * i_0];
    tmp_1[4 + 9 * (i_0 + 3)] = a_0[3 * i_0 + 1];
    tmp_1[5 + 9 * (i_0 + 3)] = a_0[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[3 + 9 * (i_0 + 6)] = c_a_0[3 * i_0];
    tmp_1[4 + 9 * (i_0 + 6)] = c_a_0[3 * i_0 + 1];
    tmp_1[5 + 9 * (i_0 + 6)] = c_a_0[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[6 + 9 * i_0] = (real_T)b_b[3 * i_0] * ctrl_student_HIL_saved_B.L3;
    tmp_1[7 + 9 * i_0] = (real_T)b_b[3 * i_0 + 1] * ctrl_student_HIL_saved_B.L3;
    tmp_1[8 + 9 * i_0] = (real_T)b_b[3 * i_0 + 2] * ctrl_student_HIL_saved_B.L3;
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[6 + 9 * (i_0 + 3)] = 0.0;
    tmp_1[7 + 9 * (i_0 + 3)] = 0.0;
    tmp_1[8 + 9 * (i_0 + 3)] = 0.0;
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_1[6 + 9 * (i_0 + 6)] = 0.0;
    tmp_1[7 + 9 * (i_0 + 6)] = 0.0;
    tmp_1[8 + 9 * (i_0 + 6)] = 0.0;
  }

  for (i_0 = 0; i_0 < 9; i_0++) {
    tmp[i_0] = ctrl_student_HIL_saved_B.Memory[i_0] + tmp_0[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    b_a_0[i_0] = b_a[i_0 + 6] * ctrl_student_HIL_saved_B.ArrowLeft + (b_a[i_0 +
      3] * ctrl_student_HIL_saved_B.L1 + b_a[i_0] *
      ctrl_student_HIL_saved_B.x_d1);
  }

  tmp_2[0] = 0.0;
  tmp_2[1] = 0.0;
  tmp_2[2] = 0.0;
  tmp_2[3] = b_a_0[0];
  tmp_2[4] = b_a_0[1];
  tmp_2[5] = b_a_0[2];
  tmp_2[6] = 0.0;
  tmp_2[7] = 0.0;
  tmp_2[8] = 0.0;

  /* Integrator: '<Root>/Int1' */
  ctrl_student_HIL_saved_B.Int1 = ctrl_student_HIL_saved_X.Int1_CSTATE;
  for (i_0 = 0; i_0 < 9; i_0++) {
    /* MATLAB Function: '<Root>/DP Observer' */
    tmp_0[i_0] = 0.0;
    for (i = 0; i < 9; i++) {
      tmp_0[i_0] += tmp_1[9 * i + i_0] * tmp[i];
    }

    ctrl_student_HIL_saved_B.x_dot[i_0] = tmp_0[i_0] + tmp_2[i_0];

    /* Integrator: '<Root>/Integrator' */
    ctrl_student_HIL_saved_B.Integrator[i_0] =
      ctrl_student_HIL_saved_X.Integrator_CSTATE_k[i_0];
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
  }
}

/* Model update function */
void ctrl_student_HIL_saved_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    /* Update for Memory: '<Root>/Memory' */
    memcpy(&ctrl_student_HIL_saved_DW.Memory_PreviousInput[0],
           &ctrl_student_HIL_saved_B.Integrator[0], 9U * sizeof(real_T));

    /* Update for Memory: '<S7>/Memory' */
    ctrl_student_HIL_saved_DW.Memory_PreviousInput_n =
      ctrl_student_HIL_saved_B.Omega2;

    /* Update for Memory: '<S10>/counter' */
    ctrl_student_HIL_saved_DW.counter_PreviousInput =
      ctrl_student_HIL_saved_B.count;

    /* Update for RandomNumber: '<S16>/White Noise' */
    ctrl_student_HIL_saved_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean;

    /* Update for RandomNumber: '<S17>/White Noise' */
    ctrl_student_HIL_saved_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed_f) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev_o +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean_h;

    /* Update for RandomNumber: '<S15>/White Noise' */
    ctrl_student_HIL_saved_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed_h) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev_n +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean_b;

    /* Update for Memory: '<S11>/Hold' */
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_saved_B.output[0];
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_saved_B.output[1];
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_saved_B.output[2];
    for (i = 0; i < 10; i++) {
      /* Update for Memory: '<S2>/Memory2' */
      ctrl_student_HIL_saved_DW.Memory2_PreviousInput[i] =
        ctrl_student_HIL_saved_B.Mx1[i];

      /* Update for Memory: '<S2>/Memory1' */
      ctrl_student_HIL_saved_DW.Memory1_PreviousInput[i] =
        ctrl_student_HIL_saved_B.My1[i];
    }

    /* Update for Memory: '<S6>/Memory3' */
    ctrl_student_HIL_saved_DW.Memory3_PreviousInput =
      ctrl_student_HIL_saved_B.M1;

    /* Update for Memory: '<S6>/Memory5' */
    ctrl_student_HIL_saved_DW.Memory5_PreviousInput =
      ctrl_student_HIL_saved_B.s1;
  }

  if (rtmIsMajorTimeStep(ctrl_student_HIL_saved_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_HIL_saved_M->solverInfo);
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
  if (!(++ctrl_student_HIL_saved_M->Timing.clockTick0)) {
    ++ctrl_student_HIL_saved_M->Timing.clockTickH0;
  }

  ctrl_student_HIL_saved_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_HIL_saved_M->solverInfo);

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
    if (!(++ctrl_student_HIL_saved_M->Timing.clockTick1)) {
      ++ctrl_student_HIL_saved_M->Timing.clockTickH1;
    }

    ctrl_student_HIL_saved_M->Timing.t[1] =
      ctrl_student_HIL_saved_M->Timing.clockTick1 *
      ctrl_student_HIL_saved_M->Timing.stepSize1 +
      ctrl_student_HIL_saved_M->Timing.clockTickH1 *
      ctrl_student_HIL_saved_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_HIL_saved_derivatives(void)
{
  XDot_ctrl_student_HIL_saved_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_HIL_saved_T *)
             ctrl_student_HIL_saved_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  _rtXdot->Integrator_CSTATE = ctrl_student_HIL_saved_P.Constant_Value_i;

  /* Derivatives for Integrator: '<Root>/Int2' */
  _rtXdot->Int2_CSTATE = ctrl_student_HIL_saved_B.Int1;

  /* Derivatives for Integrator: '<Root>/Int1' */
  _rtXdot->Int1_CSTATE = ctrl_student_HIL_saved_B.u_dot_imu;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  memcpy(&_rtXdot->Integrator_CSTATE_k[0], &ctrl_student_HIL_saved_B.x_dot[0],
         9U * sizeof(real_T));
}

/* Model initialize function */
void ctrl_student_HIL_saved_initialize(void)
{
  {
    uint32_T tseed;
    int32_T t;
    int32_T i;
    real_T tmp;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    memcpy(&ctrl_student_HIL_saved_DW.Memory_PreviousInput[0],
           &ctrl_student_HIL_saved_P.Memory_X0[0], 9U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    ctrl_student_HIL_saved_X.Integrator_CSTATE =
      ctrl_student_HIL_saved_P.Integrator_IC;

    /* InitializeConditions for Memory: '<S7>/Memory' */
    ctrl_student_HIL_saved_DW.Memory_PreviousInput_n =
      ctrl_student_HIL_saved_P.Memory_X0_a;

    /* InitializeConditions for Memory: '<S10>/counter' */
    ctrl_student_HIL_saved_DW.counter_PreviousInput =
      ctrl_student_HIL_saved_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S16>/White Noise' */
    tmp = floor(ctrl_student_HIL_saved_P.WhiteNoise_Seed);
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

    ctrl_student_HIL_saved_DW.RandSeed = tseed;
    ctrl_student_HIL_saved_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S16>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S17>/White Noise' */
    tmp = floor(ctrl_student_HIL_saved_P.WhiteNoise_Seed_k);
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

    ctrl_student_HIL_saved_DW.RandSeed_f = tseed;
    ctrl_student_HIL_saved_DW.NextOutput_a = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed_f) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev_o +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean_h;

    /* End of InitializeConditions for RandomNumber: '<S17>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S15>/White Noise' */
    tmp = floor(ctrl_student_HIL_saved_P.WhiteNoise_Seed_c);
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

    ctrl_student_HIL_saved_DW.RandSeed_h = tseed;
    ctrl_student_HIL_saved_DW.NextOutput_f = rt_nrand_Upu32_Yd_f_pw_snf
      (&ctrl_student_HIL_saved_DW.RandSeed_h) *
      ctrl_student_HIL_saved_P.WhiteNoise_StdDev_n +
      ctrl_student_HIL_saved_P.WhiteNoise_Mean_b;

    /* End of InitializeConditions for RandomNumber: '<S15>/White Noise' */

    /* InitializeConditions for Memory: '<S11>/Hold' */
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[0] =
      ctrl_student_HIL_saved_P.Hold_X0;
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[1] =
      ctrl_student_HIL_saved_P.Hold_X0;
    ctrl_student_HIL_saved_DW.Hold_PreviousInput[2] =
      ctrl_student_HIL_saved_P.Hold_X0;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for Memory: '<S2>/Memory2' */
      ctrl_student_HIL_saved_DW.Memory2_PreviousInput[i] =
        ctrl_student_HIL_saved_P.Memory2_X0[i];

      /* InitializeConditions for Memory: '<S2>/Memory1' */
      ctrl_student_HIL_saved_DW.Memory1_PreviousInput[i] =
        ctrl_student_HIL_saved_P.Memory1_X0[i];
    }

    /* InitializeConditions for Memory: '<S6>/Memory3' */
    ctrl_student_HIL_saved_DW.Memory3_PreviousInput =
      ctrl_student_HIL_saved_P.Memory3_X0;

    /* InitializeConditions for Memory: '<S6>/Memory5' */
    ctrl_student_HIL_saved_DW.Memory5_PreviousInput =
      ctrl_student_HIL_saved_P.Memory5_X0;

    /* InitializeConditions for Integrator: '<Root>/Int2' */
    ctrl_student_HIL_saved_X.Int2_CSTATE = ctrl_student_HIL_saved_P.Int2_IC;

    /* InitializeConditions for Integrator: '<Root>/Int1' */
    ctrl_student_HIL_saved_X.Int1_CSTATE = ctrl_student_HIL_saved_P.Int1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    for (i = 0; i < 9; i++) {
      ctrl_student_HIL_saved_X.Integrator_CSTATE_k[i] =
        ctrl_student_HIL_saved_P.Integrator_IC_j;
    }

    /* End of InitializeConditions for Integrator: '<Root>/Integrator' */
  }
}

/* Model terminate function */
void ctrl_student_HIL_saved_terminate(void)
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
  ctrl_student_HIL_saved_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_HIL_saved_update();
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
  ctrl_student_HIL_saved_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_HIL_saved_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_HIL_sav_T *ctrl_student_HIL_saved(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_HIL_saved_M, 0,
                sizeof(RT_MODEL_ctrl_student_HIL_sav_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_HIL_saved_M->solverInfo,
                          &ctrl_student_HIL_saved_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_HIL_saved_M->solverInfo, &rtmGetTPtr
                (ctrl_student_HIL_saved_M));
    rtsiSetStepSizePtr(&ctrl_student_HIL_saved_M->solverInfo,
                       &ctrl_student_HIL_saved_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_HIL_saved_M->solverInfo,
                 &ctrl_student_HIL_saved_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_HIL_saved_M->solverInfo, (real_T **)
                         &ctrl_student_HIL_saved_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_HIL_saved_M->solverInfo,
      &ctrl_student_HIL_saved_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_student_HIL_saved_M->solverInfo,
                          (&rtmGetErrorStatus(ctrl_student_HIL_saved_M)));
    rtsiSetRTModelPtr(&ctrl_student_HIL_saved_M->solverInfo,
                      ctrl_student_HIL_saved_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_HIL_saved_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_HIL_saved_M->ModelData.intgData.y =
    ctrl_student_HIL_saved_M->ModelData.odeY;
  ctrl_student_HIL_saved_M->ModelData.intgData.f[0] =
    ctrl_student_HIL_saved_M->ModelData.odeF[0];
  ctrl_student_HIL_saved_M->ModelData.intgData.f[1] =
    ctrl_student_HIL_saved_M->ModelData.odeF[1];
  ctrl_student_HIL_saved_M->ModelData.intgData.f[2] =
    ctrl_student_HIL_saved_M->ModelData.odeF[2];
  ctrl_student_HIL_saved_M->ModelData.intgData.f[3] =
    ctrl_student_HIL_saved_M->ModelData.odeF[3];
  ctrl_student_HIL_saved_M->ModelData.contStates = ((real_T *)
    &ctrl_student_HIL_saved_X);
  rtsiSetSolverData(&ctrl_student_HIL_saved_M->solverInfo, (void *)
                    &ctrl_student_HIL_saved_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_HIL_saved_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_HIL_saved_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_HIL_saved_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_HIL_saved_M->Timing.sampleTimes =
      (&ctrl_student_HIL_saved_M->Timing.sampleTimesArray[0]);
    ctrl_student_HIL_saved_M->Timing.offsetTimes =
      (&ctrl_student_HIL_saved_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_HIL_saved_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_HIL_saved_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_HIL_saved_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_HIL_saved_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_HIL_saved_M, &ctrl_student_HIL_saved_M->Timing.tArray
             [0]);

  {
    int_T *mdlSampleHits = ctrl_student_HIL_saved_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_HIL_saved_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_HIL_saved_M, -1);
  ctrl_student_HIL_saved_M->Timing.stepSize0 = 0.01;
  ctrl_student_HIL_saved_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_student_HIL_saved_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_HIL_saved_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_HIL_saved_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_HIL_saved_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_HIL_saved_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_HIL_saved_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_HIL_saved_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_HIL_saved_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_HIL_saved_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_HIL_saved_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_HIL_saved_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_HIL_saved_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_HIL_saved_M->rtwLogInfo, (NULL));
  }

  ctrl_student_HIL_saved_M->solverInfoPtr =
    (&ctrl_student_HIL_saved_M->solverInfo);
  ctrl_student_HIL_saved_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_HIL_saved_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_HIL_saved_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_HIL_saved_M->ModelData.blockIO = ((void *)
    &ctrl_student_HIL_saved_B);
  (void) memset(((void *) &ctrl_student_HIL_saved_B), 0,
                sizeof(B_ctrl_student_HIL_saved_T));

  /* parameters */
  ctrl_student_HIL_saved_M->ModelData.defaultParam = ((real_T *)
    &ctrl_student_HIL_saved_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_HIL_saved_X;
    ctrl_student_HIL_saved_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_HIL_saved_X, 0,
                  sizeof(X_ctrl_student_HIL_saved_T));
  }

  /* states (dwork) */
  ctrl_student_HIL_saved_M->ModelData.dwork = ((void *)
    &ctrl_student_HIL_saved_DW);
  (void) memset((void *)&ctrl_student_HIL_saved_DW, 0,
                sizeof(DW_ctrl_student_HIL_saved_T));

  /* Initialize Sizes */
  ctrl_student_HIL_saved_M->Sizes.numContStates = (12);/* Number of continuous states */
  ctrl_student_HIL_saved_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_HIL_saved_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_student_HIL_saved_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_student_HIL_saved_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_HIL_saved_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_HIL_saved_M->Sizes.numBlocks = (118);/* Number of blocks */
  ctrl_student_HIL_saved_M->Sizes.numBlockIO = (58);/* Number of block outputs */
  ctrl_student_HIL_saved_M->Sizes.numBlockPrms = (419);/* Sum of parameter "widths" */
  return ctrl_student_HIL_saved_M;
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
#ifdef NI_ROOTMODEL_ctrl_student_HIL_saved
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_HIL_saved_rtModel *S;
extern _SITexportglobals SITexportglobals;
void SetExternalInputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.u_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // y_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.y_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // psi_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.psi_in, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/L2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.L2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.PosXLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYLeft
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.PosYLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosXRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.PosXRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/PosYRight
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.PosYRight, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.ArrowUp, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowDown
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.ArrowDown, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/R2_continuous
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.R2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/L1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.L1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/R1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.R1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.ArrowLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // joystick/ArrowRight
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.ArrowRight, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Desired sampling frequency
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.Desiredsamplingfrequency,
      0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise power position
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.noisepowerposition, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // noise power heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.noisepowerheading, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // x_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.x_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // enable noise
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.enablenoise, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // r_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.r_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // v_in
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.v_in, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // L2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.L2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u_dot_imu
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.u_dot_imu, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // L1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.L1_i, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // L3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_B.L3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

long NumInputPorts(void)
{
  return 26;
}

double ni_extout[35];
void SetExternalOutputs(double* data, int* TaskSampleHit)
{
  int index = 0, count = 0;

  // u_true: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_in,
      0,0,0);
  } else {
    index += 1;
  }

  // u_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,3,18,0);
  } else {
    index += 1;
  }

  // joystick/u_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_VSP,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.a_VSP,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Omega1,0,0,0);
  } else {
    index += 1;
  }

  // joystick/omega_VSP2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Omega2,0,0,0);
  } else {
    index += 1;
  }

  // joystick/u_BT: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_BT,
      0,0,0);
  } else {
    index += 1;
  }

  // joystick/alpha_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.a,0,0,
      0);
  } else {
    index += 1;
  }

  // joystick/u_VSP2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u,0,0,
      0);
  } else {
    index += 1;
  }

  // X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.x_d1,
      0,0,0);
  } else {
    index += 1;
  }

  // psi_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.psi_in,0,0,0);
  } else {
    index += 1;
  }

  // x_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,0,
      17,0);
  } else {
    index += 1;
  }

  // fater noise: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.output,0,17,0);
  } else {
    index += 1;
  }

  // Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.L1,0,
      0,0);
  } else {
    index += 1;
  }

  // Z: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.ArrowLeft,0,0,0);
  } else {
    index += 1;
  }

  // x_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,0,18,0);
  } else {
    index += 1;
  }

  // y_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,1,18,0);
  } else {
    index += 1;
  }

  // psi_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,2,18,0);
  } else {
    index += 1;
  }

  // v_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,4,18,0);
  } else {
    index += 1;
  }

  // r_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,5,18,0);
  } else {
    index += 1;
  }

  // bx_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,6,18,0);
  } else {
    index += 1;
  }

  // by_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,7,18,0);
  } else {
    index += 1;
  }

  // bpsi_hat: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Memory,8,18,0);
  } else {
    index += 1;
  }

  // y_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,1,
      17,0);
  } else {
    index += 1;
  }

  // psi_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,2,
      17,0);
  } else {
    index += 1;
  }

  // x-error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Subtract,0,0,0);
  } else {
    index += 1;
  }

  // y-error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Subtract1,0,0,0);
  } else {
    index += 1;
  }

  // psi_error: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.Subtract2,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.x_d1,
      0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_B.ArrowLeft,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.L1,0,
      0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_P.Constant2_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_P.Constant_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_P.Constant1_Value,0,0,0);
  } else {
    index += 1;
  }

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)
      &ctrl_student_HIL_saved_RGND,0,0,0);
  } else {
    index += 1;
  }

  if (data)
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
}

long NumOutputPorts(void)
{
  return 35;
}

int NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // u_true: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_in,0,
    0,0);

  // u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    3,18,0);

  // joystick/u_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_VSP,0,
    0,0);

  // joystick/alpha_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.a_VSP,0,
    0,0);

  // joystick/omega_VSP1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Omega1,
    0,0,0);

  // joystick/omega_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Omega2,
    0,0,0);

  // joystick/u_BT: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u_BT,0,
    0,0);

  // joystick/alpha_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.a,0,0,0);

  // joystick/u_VSP2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.u,0,0,0);

  // X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.x_d1,0,
    0,0);

  // psi_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.psi_in,
    0,0,0);

  // x_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,0,
    17,0);

  // fater noise: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.output,
    0,17,0);

  // Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.L1,0,0,
    0);

  // Z: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_B.ArrowLeft,0,0,0);

  // x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    0,18,0);

  // y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    1,18,0);

  // psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    2,18,0);

  // v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    4,18,0);

  // r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    5,18,0);

  // bx_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    6,18,0);

  // by_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    7,18,0);

  // bpsi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Memory,
    8,18,0);

  // y_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,1,
    17,0);

  // psi_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.Eta,2,
    17,0);

  // x-error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_B.Subtract,0,0,0);

  // y-error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_B.Subtract1,0,0,0);

  // psi_error: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_B.Subtract2,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/X_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.x_d1,0,
    0,0);

  // tau to CSE mocell (only use for HIL testing)/N_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_B.ArrowLeft,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/Y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_HIL_saved_B.L1,0,0,
    0);

  // tau to CSE mocell (only use for HIL testing)/psi_0 : Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_P.Constant2_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/x_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_P.Constant_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/y_0: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_HIL_saved_P.Constant1_Value,0,0,0);

  // tau to CSE mocell (only use for HIL testing)/integrator reset model: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)
    &ctrl_student_HIL_saved_RGND,0,0,0);
  return NI_OK;
}

// by default, all elements (inclulding	scalars) have 2 dimensions [1,1]
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_student_hil_saved/Memory/X0", offsetof(P_ctrl_student_HIL_saved_T,
    Memory_X0), 23, 9, 2, 0, 0 },

  { 1, "ctrl_student_hil_saved/joystick/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_saved_T, Integrator_IC), 32, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil_saved/joystick/Memory/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Memory_X0_a), 32, 1, 2, 4, 0 },

  { 3, "ctrl_student_hil_saved/Noise generator/Step size/Value", offsetof
    (P_ctrl_student_HIL_saved_T, Stepsize_Value), 32, 1, 2, 6, 0 },

  { 4, "ctrl_student_hil_saved/Noise generator/Downsamplesignal/counter/X0",
    offsetof(P_ctrl_student_HIL_saved_T, counter_X0), 32, 1, 2, 8, 0 },

  { 5,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Mean), 32, 1, 2, 10, 0 },

  { 6,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_StdDev), 32, 1, 2, 12, 0 },

  { 7,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Seed), 32, 1, 2, 14, 0 },

  { 8,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Mean_h), 32, 1, 2, 16, 0 },

  { 9,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_StdDev_o), 32, 1, 2, 18, 0 },

  { 10,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Seed_k), 32, 1, 2, 20, 0 },

  { 11,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Mean_b), 32, 1, 2, 22, 0 },

  { 12,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_StdDev_n), 32, 1, 2, 24, 0 },

  { 13,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_ctrl_student_HIL_saved_T, WhiteNoise_Seed_c), 32, 1, 2, 26, 0 },

  { 14, "ctrl_student_hil_saved/Noise generator/Sample & hold/Hold/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Hold_X0), 32, 1, 2, 28, 0 },

  { 15, "ctrl_student_hil_saved/DROP DETECTOR/Memory2/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Memory2_X0), 20, 10, 2, 30, 0 },

  { 16, "ctrl_student_hil_saved/DROP DETECTOR/Memory1/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Memory1_X0), 20, 10, 2, 32, 0 },

  { 17, "ctrl_student_hil_saved/TANK LIMITS/Memory3/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Memory3_X0), 32, 1, 2, 34, 0 },

  { 18, "ctrl_student_hil_saved/TANK LIMITS/Memory5/X0", offsetof
    (P_ctrl_student_HIL_saved_T, Memory5_X0), 32, 1, 2, 36, 0 },

  { 19, "ctrl_student_hil_saved/Int2/InitialCondition", offsetof
    (P_ctrl_student_HIL_saved_T, Int2_IC), 32, 1, 2, 38, 0 },

  { 20,
    "ctrl_student_hil_saved/tau to CSE mocell (only use for HIL testing)/Constant2/Value",
    offsetof(P_ctrl_student_HIL_saved_T, Constant2_Value), 32, 1, 2, 40, 0 },

  { 21,
    "ctrl_student_hil_saved/tau to CSE mocell (only use for HIL testing)/Constant/Value",
    offsetof(P_ctrl_student_HIL_saved_T, Constant_Value), 32, 1, 2, 42, 0 },

  { 22,
    "ctrl_student_hil_saved/tau to CSE mocell (only use for HIL testing)/Constant1/Value",
    offsetof(P_ctrl_student_HIL_saved_T, Constant1_Value), 32, 1, 2, 44, 0 },

  { 23, "ctrl_student_hil_saved/Int1/InitialCondition", offsetof
    (P_ctrl_student_HIL_saved_T, Int1_IC), 32, 1, 2, 46, 0 },

  { 24, "ctrl_student_hil_saved/Integrator/InitialCondition", offsetof
    (P_ctrl_student_HIL_saved_T, Integrator_IC_j), 32, 1, 2, 48, 0 },

  { 25, "ctrl_student_hil_saved/joystick/Constant/Value", offsetof
    (P_ctrl_student_HIL_saved_T, Constant_Value_i), 32, 1, 2, 50, 0 },
};

static int NI_ParamListSize DataSection(".NIVS.paramlistsize") = 26;
static int NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  9, 1,                                /* Parameter at index 0 */
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
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student_hil_saved/u_in", 0, "", offsetof(B_ctrl_student_HIL_saved_T,
    u_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student_hil_saved/y_in", 0, "", offsetof(B_ctrl_student_HIL_saved_T,
    y_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 2, 0 },

  { 2, "ctrl_student_hil_saved/Memory", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    4, 0 },

  { 3, "ctrl_student_hil_saved/Memory", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    6, 0 },

  { 4, "ctrl_student_hil_saved/Memory", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    8, 0 },

  { 5, "ctrl_student_hil_saved/Memory", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    10, 0 },

  { 6, "ctrl_student_hil_saved/Memory", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    12, 0 },

  { 7, "ctrl_student_hil_saved/Memory", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    14, 0 },

  { 8, "ctrl_student_hil_saved/Memory", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    16, 0 },

  { 9, "ctrl_student_hil_saved/Memory", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    18, 0 },

  { 10, "ctrl_student_hil_saved/Memory", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    20, 0 },

  { 11, "ctrl_student_hil_saved/psi_in", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, psi_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    22, 0 },

  { 12, "ctrl_student_hil_saved/joystick/L2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, L2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 24, 0 },

  { 13, "ctrl_student_hil_saved/joystick/PosXLeft", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, PosXLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 26, 0 },

  { 14, "ctrl_student_hil_saved/joystick/PosYLeft", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, PosYLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 28, 0 },

  { 15, "ctrl_student_hil_saved/joystick/PosXRight", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, PosXRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 30, 0 },

  { 16, "ctrl_student_hil_saved/joystick/PosYRight", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, PosYRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 32, 0 },

  { 17, "ctrl_student_hil_saved/joystick/ArrowUp", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, ArrowUp)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    34, 0 },

  { 18, "ctrl_student_hil_saved/joystick/ArrowDown", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, ArrowDown)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 36, 0 },

  { 19, "ctrl_student_hil_saved/joystick/Memory", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Memory_f)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 38, 0 },

  { 20, "ctrl_student_hil_saved/joystick/R2_continuous", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, R2_continuous)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 40, 0 },

  { 21, "ctrl_student_hil_saved/joystick/L1", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, L1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 42,
    0 },

  { 22, "ctrl_student_hil_saved/joystick/R1", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, R1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 44,
    0 },

  { 23, "ctrl_student_hil_saved/joystick/ArrowLeft", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, ArrowLeft)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 46, 0 },

  { 24, "ctrl_student_hil_saved/joystick/ArrowRight", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, ArrowRight)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 48, 0 },

  { 25, "ctrl_student_hil_saved/Noise generator/Downsamplesignal/counter", 0, "",
    offsetof(B_ctrl_student_HIL_saved_T, counter)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 50, 0 },

  { 26, "ctrl_student_hil_saved/Desired sampling frequency", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Desiredsamplingfrequency)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 52, 0 },

  { 27, "ctrl_student_hil_saved/noise power position", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, noisepowerposition)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 54, 0 },

  { 28,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise x/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_saved_T, WhiteNoise)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 56, 0 },

  { 29,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise y/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_saved_T, WhiteNoise_p)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 58, 0 },

  { 30, "ctrl_student_hil_saved/noise power heading", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, noisepowerheading)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 60, 0 },

  { 31,
    "ctrl_student_hil_saved/Noise generator/noise generator/Band-limited white noise psi/White Noise",
    0, "", offsetof(B_ctrl_student_HIL_saved_T, WhiteNoise_i)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 62, 0 },

  { 32, "ctrl_student_hil_saved/x_in", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, x_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    64, 0 },

  { 33, "ctrl_student_hil_saved/Noise generator/Sample & hold/Hold", 0, "(1,1)",
    offsetof(B_ctrl_student_HIL_saved_T, Hold)+0*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 66, 0 },

  { 34, "ctrl_student_hil_saved/Noise generator/Sample & hold/Hold", 0, "(1,2)",
    offsetof(B_ctrl_student_HIL_saved_T, Hold)+1*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 68, 0 },

  { 35, "ctrl_student_hil_saved/Noise generator/Sample & hold/Hold", 0, "(1,3)",
    offsetof(B_ctrl_student_HIL_saved_T, Hold)+2*sizeof(real_T), BLOCKIO_SIG, 17,
    1, 2, 70, 0 },

  { 36, "ctrl_student_hil_saved/enable noise", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, enablenoise)+0*sizeof(real_T), BLOCKIO_SIG, 0,
    1, 2, 72, 0 },

  { 37, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 74, 0 },

  { 38, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 76, 0 },

  { 39, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 78, 0 },

  { 40, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 80, 0 },

  { 41, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 82, 0 },

  { 42, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 84, 0 },

  { 43, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 86, 0 },

  { 44, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 88, 0 },

  { 45, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 90, 0 },

  { 46, "ctrl_student_hil_saved/DROP DETECTOR/Memory2", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory2)+9*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 92, 0 },

  { 47, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+0*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 94, 0 },

  { 48, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+1*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 96, 0 },

  { 49, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+2*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 98, 0 },

  { 50, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+3*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 100, 0 },

  { 51, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+4*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 102, 0 },

  { 52, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+5*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 104, 0 },

  { 53, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+6*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 106, 0 },

  { 54, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+7*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 108, 0 },

  { 55, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+8*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 110, 0 },

  { 56, "ctrl_student_hil_saved/DROP DETECTOR/Memory1", 0, "(1,10)", offsetof
    (B_ctrl_student_HIL_saved_T, Memory1)+9*sizeof(real_T), BLOCKIO_SIG, 19, 1,
    2, 112, 0 },

  { 57, "ctrl_student_hil_saved/TANK LIMITS/Memory3", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Memory3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    114, 0 },

  { 58, "ctrl_student_hil_saved/TANK LIMITS/Memory5", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Memory5)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    116, 0 },

  { 59, "ctrl_student_hil_saved/r_in", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, r_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    118, 0 },

  { 60, "ctrl_student_hil_saved/v_in", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, v_in)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    120, 0 },

  { 61, "ctrl_student_hil_saved/L2", 0, "", offsetof(B_ctrl_student_HIL_saved_T,
    L2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 122, 0 },

  { 62, "ctrl_student_hil_saved/u_dot_imu", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, u_dot_imu)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 124, 0 },

  { 63, "ctrl_student_hil_saved/L1", 0, "", offsetof(B_ctrl_student_HIL_saved_T,
    L1_i)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 126, 0 },

  { 64, "ctrl_student_hil_saved/L3", 0, "", offsetof(B_ctrl_student_HIL_saved_T,
    L3)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 128, 0 },

  { 65, "ctrl_student_hil_saved/Subtract", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Subtract)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 130, 0 },

  { 66, "ctrl_student_hil_saved/Subtract1", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Subtract1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 132, 0 },

  { 67, "ctrl_student_hil_saved/Subtract2", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Subtract2)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1,
    2, 134, 0 },

  { 68, "ctrl_student_hil_saved/Int1", 0, "", offsetof
    (B_ctrl_student_HIL_saved_T, Int1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    136, 0 },

  { 69, "ctrl_student_hil_saved/Integrator", 0, "(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+0*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 138, 0 },

  { 70, "ctrl_student_hil_saved/Integrator", 0, "(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+1*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 140, 0 },

  { 71, "ctrl_student_hil_saved/Integrator", 0, "(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+2*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 142, 0 },

  { 72, "ctrl_student_hil_saved/Integrator", 0, "(1,4)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+3*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 144, 0 },

  { 73, "ctrl_student_hil_saved/Integrator", 0, "(1,5)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+4*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 146, 0 },

  { 74, "ctrl_student_hil_saved/Integrator", 0, "(1,6)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+5*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 148, 0 },

  { 75, "ctrl_student_hil_saved/Integrator", 0, "(1,7)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+6*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 150, 0 },

  { 76, "ctrl_student_hil_saved/Integrator", 0, "(1,8)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+7*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 152, 0 },

  { 77, "ctrl_student_hil_saved/Integrator", 0, "(1,9)", offsetof
    (B_ctrl_student_HIL_saved_T, Integrator)+8*sizeof(real_T), BLOCKIO_SIG, 18,
    1, 2, 154, 0 },

  { 78, "ctrl_student_hil_saved/joystick/Voith Schneider Propeller", 0, "Omega1",
    offsetof(B_ctrl_student_HIL_saved_T, Omega1)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 156, 0 },

  { 79, "ctrl_student_hil_saved/joystick/Voith Schneider Propeller", 1, "Omega2",
    offsetof(B_ctrl_student_HIL_saved_T, Omega2)+0*sizeof(real_T), BLOCKIO_SIG,
    0, 1, 2, 158, 0 },

  { 80, "ctrl_student_hil_saved/joystick/MATLAB Function1", 0, "u_VSP", offsetof
    (B_ctrl_student_HIL_saved_T, u_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    160, 0 },

  { 81, "ctrl_student_hil_saved/joystick/MATLAB Function1", 1, "a_VSP", offsetof
    (B_ctrl_student_HIL_saved_T, a_VSP)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    162, 0 },

  { 82, "ctrl_student_hil_saved/joystick/MATLAB Function", 0, "u", offsetof
    (B_ctrl_student_HIL_saved_T, u)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 164,
    0 },

  { 83, "ctrl_student_hil_saved/joystick/MATLAB Function", 1, "a", offsetof
    (B_ctrl_student_HIL_saved_T, a)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 166,
    0 },

  { 84, "ctrl_student_hil_saved/joystick/Bow thruster", 0, "u_BT", offsetof
    (B_ctrl_student_HIL_saved_T, u_BT)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    168, 0 },

  { 85, "ctrl_student_hil_saved/TANK LIMITS/Tank Limits", 0, "x_d1", offsetof
    (B_ctrl_student_HIL_saved_T, x_d1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2,
    170, 0 },

  { 86, "ctrl_student_hil_saved/TANK LIMITS/Tank Limits", 1, "M1", offsetof
    (B_ctrl_student_HIL_saved_T, M1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 172,
    0 },

  { 87, "ctrl_student_hil_saved/TANK LIMITS/Tank Limits", 2, "s1", offsetof
    (B_ctrl_student_HIL_saved_T, s1)+0*sizeof(real_T), BLOCKIO_SIG, 0, 1, 2, 174,
    0 },

  { 88, "ctrl_student_hil_saved/SWITCH", 0, "Eta(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, Eta)+0*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    176, 0 },

  { 89, "ctrl_student_hil_saved/SWITCH", 0, "Eta(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, Eta)+1*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    178, 0 },

  { 90, "ctrl_student_hil_saved/SWITCH", 0, "Eta(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, Eta)+2*sizeof(real_T), BLOCKIO_SIG, 17, 1, 2,
    180, 0 },

  { 91, "ctrl_student_hil_saved/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,1)", offsetof(B_ctrl_student_HIL_saved_T, output)+0*sizeof
    (real_T), BLOCKIO_SIG, 17, 1, 2, 182, 0 },

  { 92, "ctrl_student_hil_saved/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,2)", offsetof(B_ctrl_student_HIL_saved_T, output)+1*sizeof
    (real_T), BLOCKIO_SIG, 17, 1, 2, 184, 0 },

  { 93, "ctrl_student_hil_saved/Noise generator/Sample & hold/MATLAB Function1",
    0, "output(1,3)", offsetof(B_ctrl_student_HIL_saved_T, output)+2*sizeof
    (real_T), BLOCKIO_SIG, 17, 1, 2, 186, 0 },

  { 94,
    "ctrl_student_hil_saved/Noise generator/Downsamplesignal/MATLAB Function", 0,
    "count", offsetof(B_ctrl_student_HIL_saved_T, count)+0*sizeof(real_T),
    BLOCKIO_SIG, 0, 1, 2, 188, 0 },

  { 95, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,1)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+0*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 190, 0 },

  { 96, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,2)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+1*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 192, 0 },

  { 97, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,3)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+2*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 194, 0 },

  { 98, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,4)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+3*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 196, 0 },

  { 99, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,5)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+4*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 198, 0 },

  { 100, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,6)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+5*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 200, 0 },

  { 101, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,7)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+6*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 202, 0 },

  { 102, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,8)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+7*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 204, 0 },

  { 103, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,9)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+8*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 206, 0 },

  { 104, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 1, "Mx1(1,10)",
    offsetof(B_ctrl_student_HIL_saved_T, Mx1)+9*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 208, 0 },

  { 105, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,1)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+0*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 210, 0 },

  { 106, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,2)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+1*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 212, 0 },

  { 107, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,3)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+2*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 214, 0 },

  { 108, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,4)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+3*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 216, 0 },

  { 109, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,5)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+4*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 218, 0 },

  { 110, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,6)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+5*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 220, 0 },

  { 111, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,7)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+6*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 222, 0 },

  { 112, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,8)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+7*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 224, 0 },

  { 113, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,9)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+8*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 226, 0 },

  { 114, "ctrl_student_hil_saved/DROP DETECTOR/DROP DETECTOR", 2, "My1(1,10)",
    offsetof(B_ctrl_student_HIL_saved_T, My1)+9*sizeof(real_T), BLOCKIO_SIG, 20,
    1, 2, 228, 0 },

  { 115, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,1)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+0*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    230, 0 },

  { 116, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,2)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+1*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    232, 0 },

  { 117, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,3)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+2*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    234, 0 },

  { 118, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,4)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+3*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    236, 0 },

  { 119, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,5)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+4*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    238, 0 },

  { 120, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,6)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+5*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    240, 0 },

  { 121, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,7)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+6*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    242, 0 },

  { 122, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,8)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+7*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    244, 0 },

  { 123, "ctrl_student_hil_saved/DP Observer", 0, "x_dot(1,9)", offsetof
    (B_ctrl_student_HIL_saved_T, x_dot)+8*sizeof(real_T), BLOCKIO_SIG, 18, 1, 2,
    246, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int NI_SigListSize DataSection(".NIVS.siglistsize") = 124;
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
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

static long NI_ExtListSize DataSection(".NIVS.extlistsize") = 61;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 0, "u_in", 1, EXT_IN, 1, 1, 1 },

  { 1, "y_in", 0, EXT_IN, 1, 1, 1 },

  { 2, "psi_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "joystick/L2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 4, "joystick/PosXLeft", 1, EXT_IN, 1, 1, 1 },

  { 5, "joystick/PosYLeft", 1, EXT_IN, 1, 1, 1 },

  { 6, "joystick/PosXRight", 1, EXT_IN, 1, 1, 1 },

  { 7, "joystick/PosYRight", 1, EXT_IN, 1, 1, 1 },

  { 8, "joystick/ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 9, "joystick/ArrowDown", 0, EXT_IN, 1, 1, 1 },

  { 10, "joystick/R2_continuous", 1, EXT_IN, 1, 1, 1 },

  { 11, "joystick/L1", 0, EXT_IN, 1, 1, 1 },

  { 12, "joystick/R1", 1, EXT_IN, 1, 1, 1 },

  { 13, "joystick/ArrowLeft", 0, EXT_IN, 1, 1, 1 },

  { 14, "joystick/ArrowRight", 0, EXT_IN, 1, 1, 1 },

  { 15, "Desired sampling frequency", 0, EXT_IN, 1, 1, 1 },

  { 16, "noise power position", 0, EXT_IN, 1, 1, 1 },

  { 17, "noise power heading", 0, EXT_IN, 1, 1, 1 },

  { 18, "x_in", 0, EXT_IN, 1, 1, 1 },

  { 19, "enable noise", 0, EXT_IN, 1, 1, 1 },

  { 20, "r_in", 1, EXT_IN, 1, 1, 1 },

  { 21, "v_in", 1, EXT_IN, 1, 1, 1 },

  { 22, "L2", 0, EXT_IN, 1, 1, 1 },

  { 23, "u_dot_imu", 0, EXT_IN, 1, 1, 1 },

  { 24, "L1", 0, EXT_IN, 1, 1, 1 },

  { 25, "L3", 0, EXT_IN, 1, 1, 1 },

  { 0, "u_true", 1, EXT_OUT, 1, 1, 1 },

  { 1, "u_hat", 1, EXT_OUT, 1, 1, 1 },

  { 2, "joystick/u_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 3, "joystick/alpha_VSP1", 1, EXT_OUT, 1, 1, 1 },

  { 4, "joystick/omega_VSP1", 0, EXT_OUT, 1, 1, 1 },

  { 5, "joystick/omega_VSP2", 0, EXT_OUT, 1, 1, 1 },

  { 6, "joystick/u_BT", 1, EXT_OUT, 1, 1, 1 },

  { 7, "joystick/alpha_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 8, "joystick/u_VSP2", 1, EXT_OUT, 1, 1, 1 },

  { 9, "X", 0, EXT_OUT, 1, 1, 1 },

  { 10, "psi_out", 0, EXT_OUT, 1, 1, 1 },

  { 11, "x_m", 0, EXT_OUT, 1, 1, 1 },

  { 12, "fater noise", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Y", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Z", 0, EXT_OUT, 1, 1, 1 },

  { 15, "x_hat", 1, EXT_OUT, 1, 1, 1 },

  { 16, "y_hat", 1, EXT_OUT, 1, 1, 1 },

  { 17, "psi_hat", 1, EXT_OUT, 1, 1, 1 },

  { 18, "v_hat", 1, EXT_OUT, 1, 1, 1 },

  { 19, "r_hat", 1, EXT_OUT, 1, 1, 1 },

  { 20, "bx_hat", 1, EXT_OUT, 1, 1, 1 },

  { 21, "by_hat", 1, EXT_OUT, 1, 1, 1 },

  { 22, "bpsi_hat", 1, EXT_OUT, 1, 1, 1 },

  { 23, "y_m", 0, EXT_OUT, 1, 1, 1 },

  { 24, "psi_m", 0, EXT_OUT, 1, 1, 1 },

  { 25, "x-error", 0, EXT_OUT, 1, 1, 1 },

  { 26, "y-error", 0, EXT_OUT, 1, 1, 1 },

  { 27, "psi_error", 0, EXT_OUT, 1, 1, 1 },

  { 28, "tau to CSE mocell (only use for HIL testing)/X_d", 0, EXT_OUT, 1, 1, 1
  },

  { 29, "tau to CSE mocell (only use for HIL testing)/N_d", 0, EXT_OUT, 1, 1, 1
  },

  { 30, "tau to CSE mocell (only use for HIL testing)/Y_d", 0, EXT_OUT, 1, 1, 1
  },

  { 31, "tau to CSE mocell (only use for HIL testing)/psi_0 ", 1, EXT_OUT, 1, 1,
    1 },

  { 32, "tau to CSE mocell (only use for HIL testing)/x_0", 1, EXT_OUT, 1, 1, 1
  },

  { 33, "tau to CSE mocell (only use for HIL testing)/y_0", 1, EXT_OUT, 1, 1, 1
  },

  { 34, "tau to CSE mocell (only use for HIL testing)/integrator reset model", 1,
    EXT_OUT, 1, 1, 1 },

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
  "ctrl_student_hil_saved";
static char* NI_CompiledModelVersion = "1.156";
static char* NI_CompiledModelDateTime = "Thu Apr 06 09:54:41 2017";
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
   The undef allows us to access the real ctrl_student_HIL_saved_P
   In the rest of the code ctrl_student_HIL_saved_P is redefine to be the read-side
   of rtParameter.
 */
#undef ctrl_student_HIL_saved_P

int NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_student_HIL_saved_P, sizeof
         (P_ctrl_student_HIL_saved_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_HIL_saved_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int NI_InitParamDoubleBuf()
{
  int idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_HIL_saved_T));
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
             (P_ctrl_student_HIL_saved_T));
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
               (P_ctrl_student_HIL_saved_T));

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
           (P_ctrl_student_HIL_saved_T));
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
           (P_ctrl_student_HIL_saved_T));
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
           (P_ctrl_student_HIL_saved_T));
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
      *numContStates = 12;
      *numDiscStates = 1596;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if (contStates && contStatesNames) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_X.Integrator_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_X.Int2_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Int2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_X.Int1_CSTATE, 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Int1_CSTATE");
    for (count = 0; count < 9; count++) {
      contStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_X.Integrator_CSTATE_k[0], count, 0, 0);
      strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    }
  }

  if (discStates && discStatesNames) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_true_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_true_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.y_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.y_in_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Memory_PreviousInput, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Memory_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.PosXRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.PosXRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.PosYRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.PosYRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Memory_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_BT_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_BT_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.L1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.L1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_VSP2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_VSP2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.R1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.R1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.ArrowRight_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.ArrowRight_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.NextOutput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.NextOutput_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.NextOutput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.NextOutput_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.NextOutput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.x_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.x_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.enablenoise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.enablenoise_DWORK1");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Memory2_PreviousInput, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Memory2_PreviousInput");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Memory1_PreviousInput, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Memory1_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Memory3_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Memory5_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.X_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.r_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.r_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_out_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.v_in_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.v_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.faternoise_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.faternoise_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.L2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.L2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Z_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.v_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.r_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.L1_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.L1_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.bx_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.bx_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.L3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.L3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.by_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.by_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.xerror_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.xerror_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.yerror_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.yerror_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_error_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_error_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.X_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.X_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.N_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.N_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.Y_d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.Y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.psi_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.psi_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.x_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.x_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.y_0_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.y_0_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK2, 0, 6, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.RandSeed_f, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.RandSeed_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_HIL_saved_DW.RandSeed_h, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_HIL_saved_DW.RandSeed_h");
    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_true_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_true_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.y_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.y_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.L2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.PosXLeft_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.PosYLeft_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_VSP1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.PosXRight_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.PosXRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.PosYRight_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.PosYRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.ArrowUp_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.ArrowDown_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.R2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_BT_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_BT_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.L1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.L1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_VSP2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_VSP2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.R1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.R1_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.ArrowRight_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.ArrowRight_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK2, count, 21,
         0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.x_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.x_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.enablenoise_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.enablenoise_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.X_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.X_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.r_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.r_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_out_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_out_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.x_m_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.x_m_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.v_in_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.v_in_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.faternoise_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.faternoise_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Y_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Y_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.L2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.L2_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Z_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Z_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.x_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.y_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.v_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.r_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.L1_DWORK2_i, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.L1_DWORK2_i");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.bx_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.bx_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.L3_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.L3_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.by_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.by_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.y_m_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.y_m_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_m_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.xerror_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.xerror_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.yerror_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.yerror_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_error_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_error_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.X_d_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.X_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.N_d_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.N_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.Y_d_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.Y_d_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.psi_0_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.psi_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.x_0_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.x_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.y_0_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.y_0_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK2");
    }

    for (count = 0; count < 23; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK1, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK1");
    }

    for (count = 0; count < 66; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK3, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK3");
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
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_X.Integrator_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_X.Int2_CSTATE, 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_X.Int1_CSTATE, 0,
      contStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_X.Integrator_CSTATE_k[0],
        count, contStates[idx++], 0, 0);
    }
  }

  if (discStates) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_true_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory_PreviousInput,
        count, discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosXRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosYRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_BT_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_VSP2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.R1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowRight_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK1, 0,
       discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.NextOutput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.NextOutput_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK1,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.NextOutput_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 0,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 1,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Hold_PreviousInput, 2,
      discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.enablenoise_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory2_PreviousInput,
        count, discStates[idx++], 19, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory1_PreviousInput,
        count, discStates[idx++], 19, 0);
    }

    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Memory5_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.X_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.r_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_out_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_m_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.v_in_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.faternoise_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Z_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.v_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.r_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L1_DWORK1_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.bx_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.by_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_m_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_m_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.xerror_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.yerror_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_error_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.X_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.N_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Y_d_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_0_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK1, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType
      (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK2, 0,
       discStates[idx++], 6, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.RandSeed, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.RandSeed_f, 0,
      discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.RandSeed_h, 0,
      discStates[idx++], 7, 0);
    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_true_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L2_continuous_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_VSP1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.alpha_VSP1_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosXRight_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.PosYRight_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.omega_VSP1_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.R2_continuous_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.omega_VSP2_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_BT_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.alpha_VSP2_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_VSP2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.R1_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowLeft_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.ArrowRight_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.Desiredsamplingfrequency_DWORK2, count,
         discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.noisepowerposition_DWORK2, count,
         discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.noisepowerheading_DWORK2, count,
         discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.enablenoise_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.X_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.r_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_out_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_m_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.v_in_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.faternoise_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Y_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L2_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Z_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.u_dot_imu_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.v_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.r_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L1_DWORK2_i, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.bx_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.L3_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.by_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.bpsi_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_m_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_m_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.xerror_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.yerror_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_error_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.X_d_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.N_d_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.Y_d_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.psi_0_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.x_0_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType(&ctrl_student_HIL_saved_DW.y_0_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.integratorresetmodel_DWORK2, count,
         discStates[idx++], 21, 0);
    }

    for (count = 0; count < 23; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK1, count,
         discStates[idx++], 21, 0);
    }

    for (count = 0; count < 66; count++) {
      NIRT_SetValueByDataType
        (&ctrl_student_HIL_saved_DW.NIVeriStandSignalProbe_DWORK3, count,
         discStates[idx++], 22, 0);
    }
  }

  if (clockTicks) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student_HIL_saved
