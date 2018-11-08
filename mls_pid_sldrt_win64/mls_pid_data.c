/*
 * mls_pid_data.c
 *
 * Code generation for model "mls_pid".
 *
 * Model version              : 1.403
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Thu Nov 08 12:54:36 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mls_pid.h"
#include "mls_pid_private.h"

/* Block parameters (auto storage) */
P_mls_pid_T mls_pid_P = {
  /*  Variable: A
   * Referenced by: '<S2>/State-Space'
   */
  { 0.0, 1612.688, 0.0, 1.0, 0.0, 12.52, 0.0, -24.25, -36.848 },

  /*  Variable: B
   * Referenced by: '<S2>/State-Space'
   */
  { 0.0, 0.0, 8.9 },
  2.0,                                 /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  5.0,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  50.0,                                /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: 0*4e-5
                                        * Referenced by: '<S1>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Integrator'
                                        */

  /*  Expression: eye(3)
   * Referenced by: '<S2>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/State-Space'
                                        */
  0.02,                                /* Expression: 0.02
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -0.02,                               /* Expression: -0.02
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<Root>/Desired position [m]'
                                        */
  0.002,                               /* Expression: 2e-3
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Saturation'
                                        */
  1U                                   /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
};
