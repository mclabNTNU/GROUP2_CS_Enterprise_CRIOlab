/*========================================================================*
 * NI VeriStand Generated Code                                            *
 *========================================================================**/
#include "NIVERISTAND_API.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_HIL_P            ctrl_student_HIL_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_HIL_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.188
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 20 07:24:25 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student_HIL.h"
#include "ctrl_student_HIL_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_HIL_T ctrl_student_HIL_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_true'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_true'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_true'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_true'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_true'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_true'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/r_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/r_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/r_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/v_in'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/v_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/v_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/v_in'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S3>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise power position'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise power position'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/noise power position'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise power position'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise power position'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise power position'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S19>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S19>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_o
                                        * Referenced by: '<S20>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S20>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_n
                                        * Referenced by: '<S18>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S18>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/fater noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/fater noise'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/fater noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/fater noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/fater noise'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/fater noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/enable noise'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ON_OFF'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ON_OFF'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/ON_OFF'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ON_OFF'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ON_OFF'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ON_OFF'
                                        */

  /*  Expression: [0;0;0;0;0;0;0;0;0]
   * Referenced by: '<S4>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  22.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/eta_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  23.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/nu_hat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/s(0)'
                                        */
  2000.0,                              /* Expression: 2000
                                        * Referenced by: '<S2>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Step'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/U_max'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/mu1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/mu1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/mu1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/mu1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/mu1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/mu1'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/k22'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/k22'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/k22'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/k22'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/k22'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/k22'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S2>/Memory3'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Int2'
                                        */

  /*  Expression: [0,0,0,0,0,0,0,0,0,0]
   * Referenced by: '<S1>/Memory2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0,0,0,0,0,0,0,0,0,0]
   * Referenced by: '<S1>/Memory1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Memory3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Memory5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/integrator reset model'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/s'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Int1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/L2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_hat'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_hat'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/v_hat'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/r_hat'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/r_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L1'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/bx_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/L3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/L3'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/L3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/L3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/L3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/L3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/by_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/by_hat'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/by_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/by_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/by_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/by_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/bpsi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x-error'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x-error'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/x-error'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x-error'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x-error'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x-error'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y-error'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y-error'
                                        */
  20.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/y-error'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y-error'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y-error'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y-error'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_error'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_error'
                                        */
  21.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/psi_error'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_error'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_error'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_error'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/X'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Y'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/Z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/Z'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/Z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/Z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/Z'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/Z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowDown'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/ArrowRight'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/NIVeriStandSignalProbe'
                                        */
};

#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  long size;
  long width;
  long basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_HIL_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_student_HIL_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 10, 0 },

  { sizeof(real_T), 10, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
