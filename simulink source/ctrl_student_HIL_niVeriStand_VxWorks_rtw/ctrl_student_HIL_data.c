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
 * Model version              : 1.141
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Feb 23 14:54:30 2017
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_hat'
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
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosXRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowDown'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/omega_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_BT'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_BT'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_BT'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_BT'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_VSP2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/L1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/L1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/L1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/R1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/R1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/R1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ArrowRight'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S3>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/counter'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Desired sampling frequency'
                                        */
  12.0,                                /* Expression: portnum
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
  10.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S17>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S17>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S17>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_o
                                        * Referenced by: '<S18>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S18>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/noise power heading'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S16>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_n
                                        * Referenced by: '<S16>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S16>/White Noise'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enable noise'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enable noise'
                                        */
  9.0,                                 /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */

  /*  Expression: [0,0,0,0,0,0,0,0,0,0]
   * Referenced by: '<Root>/Memory2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0,0,0,0,0,0,0,0,0,0]
   * Referenced by: '<Root>/Memory1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Memory5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/X'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/X'
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
                                        * Referenced by: '<Root>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_m'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_m'
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
                                        * Referenced by: '<Root>/k_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/k_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/k_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/k_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/k_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/k_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_dot_imu'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/X_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/X_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/X_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/N_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/N_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/N_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/N_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/Y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/Y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/Y_d'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/psi_0 '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/x_0'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/x_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/x_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/x_0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/y_0'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/y_0'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/y_0'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/y_0'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/integrator reset model'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
