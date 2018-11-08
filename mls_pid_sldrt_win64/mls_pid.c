/*
 * mls_pid.c
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
#include "mls_pid_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* Block signals (auto storage) */
B_mls_pid_T mls_pid_B;

/* Continuous states */
X_mls_pid_T mls_pid_X;

/* Block states (auto storage) */
DW_mls_pid_T mls_pid_DW;

/* Real-time model */
RT_MODEL_mls_pid_T mls_pid_M_;
RT_MODEL_mls_pid_T *const mls_pid_M = &mls_pid_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  mls_pid_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  mls_pid_output();
  mls_pid_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  mls_pid_output();
  mls_pid_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  mls_pid_output();
  mls_pid_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  mls_pid_output();
  mls_pid_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  mls_pid_output();
  mls_pid_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void mls_pid_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  int_T iy;
  real_T rtb_Sum;
  real_T u0;
  if (rtmIsMajorTimeStep(mls_pid_M)) {
    /* set solver stop time */
    if (!(mls_pid_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&mls_pid_M->solverInfo,
                            ((mls_pid_M->Timing.clockTickH0 + 1) *
        mls_pid_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&mls_pid_M->solverInfo,
                            ((mls_pid_M->Timing.clockTick0 + 1) *
        mls_pid_M->Timing.stepSize0 + mls_pid_M->Timing.clockTickH0 *
        mls_pid_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(mls_pid_M)) {
    mls_pid_M->Timing.t[0] = rtsiGetT(&mls_pid_M->solverInfo);
  }

  /* Integrator: '<S1>/Integrator'
   *
   * Regarding '<S1>/Integrator':
   *  Limited Integrator
   */
  if (mls_pid_X.Integrator_CSTATE >= mls_pid_P.Integrator_UpperSat ) {
    mls_pid_X.Integrator_CSTATE = mls_pid_P.Integrator_UpperSat;
  } else if (mls_pid_X.Integrator_CSTATE <= (mls_pid_P.Integrator_LowerSat) ) {
    mls_pid_X.Integrator_CSTATE = (mls_pid_P.Integrator_LowerSat);
  }

  rtb_Integrator = mls_pid_X.Integrator_CSTATE;

  /* StateSpace: '<S2>/State-Space' */
  mls_pid_B.StateSpace[0] = 0.0;
  mls_pid_B.StateSpace[1] = 0.0;
  mls_pid_B.StateSpace[2] = 0.0;
  for (iy = 0; iy < 3; iy++) {
    mls_pid_B.StateSpace[iy] += mls_pid_P.StateSpace_C[iy] *
      mls_pid_X.StateSpace_CSTATE[0];
    mls_pid_B.StateSpace[iy] += mls_pid_P.StateSpace_C[3 + iy] *
      mls_pid_X.StateSpace_CSTATE[1];
    mls_pid_B.StateSpace[iy] += mls_pid_P.StateSpace_C[6 + iy] *
      mls_pid_X.StateSpace_CSTATE[2];
  }

  /* End of StateSpace: '<S2>/State-Space' */

  /* Saturate: '<Root>/Saturation' */
  if (mls_pid_B.StateSpace[0] > mls_pid_P.Saturation_UpperSat) {
    mls_pid_B.Saturation = mls_pid_P.Saturation_UpperSat;
  } else if (mls_pid_B.StateSpace[0] < mls_pid_P.Saturation_LowerSat) {
    mls_pid_B.Saturation = mls_pid_P.Saturation_LowerSat;
  } else {
    mls_pid_B.Saturation = mls_pid_B.StateSpace[0];
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Desired position [m]'
   *  SignalGenerator: '<Root>/Signal Generator'
   *  Sum: '<Root>/Sum2'
   */
  if (mls_pid_P.ManualSwitch_CurrentSetting == 1) {
    mls_pid_B.ManualSwitch = mls_pid_P.Desiredpositionm_Value;
  } else {
    mls_pid_B.ManualSwitch = sin(6.2831853071795862 * mls_pid_M->Timing.t[0] *
      mls_pid_P.SignalGenerator_Frequency) * mls_pid_P.SignalGenerator_Amplitude
      + mls_pid_P.Desiredpositionm_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(mls_pid_M)) {
    /* Memory: '<Root>/Memory' */
    mls_pid_B.Memory = mls_pid_DW.Memory_PreviousInput;
  }

  /* Sum: '<Root>/Sum' */
  rtb_Sum = mls_pid_B.ManualSwitch - mls_pid_B.Memory;

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  Gain: '<S3>/Derivative Gain'
   *  Integrator: '<S3>/Filter'
   *  Sum: '<S3>/SumD'
   */
  mls_pid_B.FilterCoefficient = (mls_pid_P.PIDController_D * rtb_Sum -
    mls_pid_X.Filter_CSTATE) * mls_pid_P.PIDController_N;

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Proportional Gain'
   *  Integrator: '<S3>/Integrator'
   */
  u0 = (mls_pid_P.PIDController_P * rtb_Sum + mls_pid_X.Integrator_CSTATE_c) +
    mls_pid_B.FilterCoefficient;

  /* Saturate: '<S2>/Saturation' */
  if (u0 > mls_pid_P.Saturation_UpperSat_i) {
    mls_pid_B.Saturation_f = mls_pid_P.Saturation_UpperSat_i;
  } else if (u0 < mls_pid_P.Saturation_LowerSat_f) {
    mls_pid_B.Saturation_f = mls_pid_P.Saturation_LowerSat_f;
  } else {
    mls_pid_B.Saturation_f = u0;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(mls_pid_M)) {
  }

  /* Gain: '<S3>/Integral Gain' */
  mls_pid_B.IntegralGain = mls_pid_P.PIDController_I * rtb_Sum;
}

/* Model update function */
void mls_pid_update(void)
{
  if (rtmIsMajorTimeStep(mls_pid_M)) {
    /* Update for Memory: '<Root>/Memory' */
    mls_pid_DW.Memory_PreviousInput = mls_pid_B.Saturation;
  }

  if (rtmIsMajorTimeStep(mls_pid_M)) {
    rt_ertODEUpdateContinuousStates(&mls_pid_M->solverInfo);
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
  if (!(++mls_pid_M->Timing.clockTick0)) {
    ++mls_pid_M->Timing.clockTickH0;
  }

  mls_pid_M->Timing.t[0] = rtsiGetSolverStopTime(&mls_pid_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++mls_pid_M->Timing.clockTick1)) {
      ++mls_pid_M->Timing.clockTickH1;
    }

    mls_pid_M->Timing.t[1] = mls_pid_M->Timing.clockTick1 *
      mls_pid_M->Timing.stepSize1 + mls_pid_M->Timing.clockTickH1 *
      mls_pid_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void mls_pid_derivatives(void)
{
  int_T is;
  XDot_mls_pid_T *_rtXdot;
  _rtXdot = ((XDot_mls_pid_T *) mls_pid_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( mls_pid_X.Integrator_CSTATE <= (mls_pid_P.Integrator_LowerSat) );
    usat = ( mls_pid_X.Integrator_CSTATE >= mls_pid_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (0.0 > 0)) ||
        (usat && (0.0 < 0)) ) {
      ((XDot_mls_pid_T *) mls_pid_M->ModelData.derivs)->Integrator_CSTATE = 0.0;
    } else {
      /* in saturation */
      ((XDot_mls_pid_T *) mls_pid_M->ModelData.derivs)->Integrator_CSTATE = 0.0;
    }
  }

  /* Derivatives for StateSpace: '<S2>/State-Space' */
  _rtXdot->StateSpace_CSTATE[0] = 0.0;
  _rtXdot->StateSpace_CSTATE[1] = 0.0;
  _rtXdot->StateSpace_CSTATE[2] = 0.0;
  for (is = 0; is < 3; is++) {
    _rtXdot->StateSpace_CSTATE[is] += mls_pid_P.A[is] *
      mls_pid_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[is] += mls_pid_P.A[3 + is] *
      mls_pid_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[is] += mls_pid_P.A[6 + is] *
      mls_pid_X.StateSpace_CSTATE[2];
  }

  _rtXdot->StateSpace_CSTATE[0] += mls_pid_P.B[0] * mls_pid_B.Saturation_f;
  _rtXdot->StateSpace_CSTATE[1] += mls_pid_P.B[1] * mls_pid_B.Saturation_f;
  _rtXdot->StateSpace_CSTATE[2] += mls_pid_P.B[2] * mls_pid_B.Saturation_f;

  /* End of Derivatives for StateSpace: '<S2>/State-Space' */

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = mls_pid_B.IntegralGain;

  /* Derivatives for Integrator: '<S3>/Filter' */
  _rtXdot->Filter_CSTATE = mls_pid_B.FilterCoefficient;
}

/* Model initialize function */
void mls_pid_initialize(void)
{
  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  mls_pid_X.Integrator_CSTATE = (mls_pid_P.Integrator_IC);

  /* InitializeConditions for StateSpace: '<S2>/State-Space' */
  mls_pid_X.StateSpace_CSTATE[0] = mls_pid_P.StateSpace_X0;
  mls_pid_X.StateSpace_CSTATE[1] = mls_pid_P.StateSpace_X0;
  mls_pid_X.StateSpace_CSTATE[2] = mls_pid_P.StateSpace_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  mls_pid_DW.Memory_PreviousInput = mls_pid_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  mls_pid_X.Integrator_CSTATE_c = mls_pid_P.Integrator_IC_j;

  /* InitializeConditions for Integrator: '<S3>/Filter' */
  mls_pid_X.Filter_CSTATE = mls_pid_P.Filter_IC;
}

/* Model terminate function */
void mls_pid_terminate(void)
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
  mls_pid_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  mls_pid_update();
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
  mls_pid_initialize();
}

void MdlTerminate(void)
{
  mls_pid_terminate();
}

/* Registration function */
RT_MODEL_mls_pid_T *mls_pid(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mls_pid_M, 0,
                sizeof(RT_MODEL_mls_pid_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&mls_pid_M->solverInfo, &mls_pid_M->Timing.simTimeStep);
    rtsiSetTPtr(&mls_pid_M->solverInfo, &rtmGetTPtr(mls_pid_M));
    rtsiSetStepSizePtr(&mls_pid_M->solverInfo, &mls_pid_M->Timing.stepSize0);
    rtsiSetdXPtr(&mls_pid_M->solverInfo, &mls_pid_M->ModelData.derivs);
    rtsiSetContStatesPtr(&mls_pid_M->solverInfo, (real_T **)
                         &mls_pid_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&mls_pid_M->solverInfo,
      &mls_pid_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&mls_pid_M->solverInfo, (&rtmGetErrorStatus(mls_pid_M)));
    rtsiSetRTModelPtr(&mls_pid_M->solverInfo, mls_pid_M);
  }

  rtsiSetSimTimeStep(&mls_pid_M->solverInfo, MAJOR_TIME_STEP);
  mls_pid_M->ModelData.intgData.y = mls_pid_M->ModelData.odeY;
  mls_pid_M->ModelData.intgData.f[0] = mls_pid_M->ModelData.odeF[0];
  mls_pid_M->ModelData.intgData.f[1] = mls_pid_M->ModelData.odeF[1];
  mls_pid_M->ModelData.intgData.f[2] = mls_pid_M->ModelData.odeF[2];
  mls_pid_M->ModelData.intgData.f[3] = mls_pid_M->ModelData.odeF[3];
  mls_pid_M->ModelData.intgData.f[4] = mls_pid_M->ModelData.odeF[4];
  mls_pid_M->ModelData.intgData.f[5] = mls_pid_M->ModelData.odeF[5];
  mls_pid_M->ModelData.contStates = ((real_T *) &mls_pid_X);
  rtsiSetSolverData(&mls_pid_M->solverInfo, (void *)
                    &mls_pid_M->ModelData.intgData);
  rtsiSetSolverName(&mls_pid_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = mls_pid_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mls_pid_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    mls_pid_M->Timing.sampleTimes = (&mls_pid_M->Timing.sampleTimesArray[0]);
    mls_pid_M->Timing.offsetTimes = (&mls_pid_M->Timing.offsetTimesArray[0]);

    /* task periods */
    mls_pid_M->Timing.sampleTimes[0] = (0.0);
    mls_pid_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    mls_pid_M->Timing.offsetTimes[0] = (0.0);
    mls_pid_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(mls_pid_M, &mls_pid_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = mls_pid_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mls_pid_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(mls_pid_M, 5.0);
  mls_pid_M->Timing.stepSize0 = 0.001;
  mls_pid_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  mls_pid_M->Sizes.checksums[0] = (2272973806U);
  mls_pid_M->Sizes.checksums[1] = (1280715647U);
  mls_pid_M->Sizes.checksums[2] = (2019946063U);
  mls_pid_M->Sizes.checksums[3] = (749678362U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    mls_pid_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mls_pid_M->extModeInfo,
      &mls_pid_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mls_pid_M->extModeInfo, mls_pid_M->Sizes.checksums);
    rteiSetTPtr(mls_pid_M->extModeInfo, rtmGetTPtr(mls_pid_M));
  }

  mls_pid_M->solverInfoPtr = (&mls_pid_M->solverInfo);
  mls_pid_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&mls_pid_M->solverInfo, 0.001);
  rtsiSetSolverMode(&mls_pid_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  mls_pid_M->ModelData.blockIO = ((void *) &mls_pid_B);

  {
    mls_pid_B.StateSpace[0] = 0.0;
    mls_pid_B.StateSpace[1] = 0.0;
    mls_pid_B.StateSpace[2] = 0.0;
    mls_pid_B.Saturation = 0.0;
    mls_pid_B.ManualSwitch = 0.0;
    mls_pid_B.Memory = 0.0;
    mls_pid_B.FilterCoefficient = 0.0;
    mls_pid_B.Saturation_f = 0.0;
    mls_pid_B.IntegralGain = 0.0;
  }

  /* parameters */
  mls_pid_M->ModelData.defaultParam = ((real_T *)&mls_pid_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &mls_pid_X;
    mls_pid_M->ModelData.contStates = (x);
    (void) memset((void *)&mls_pid_X, 0,
                  sizeof(X_mls_pid_T));
  }

  /* states (dwork) */
  mls_pid_M->ModelData.dwork = ((void *) &mls_pid_DW);
  (void) memset((void *)&mls_pid_DW, 0,
                sizeof(DW_mls_pid_T));
  mls_pid_DW.Memory_PreviousInput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    mls_pid_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  mls_pid_M->Sizes.numContStates = (6);/* Number of continuous states */
  mls_pid_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  mls_pid_M->Sizes.numY = (0);         /* Number of model outputs */
  mls_pid_M->Sizes.numU = (0);         /* Number of model inputs */
  mls_pid_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  mls_pid_M->Sizes.numSampTimes = (2); /* Number of sample times */
  mls_pid_M->Sizes.numBlocks = (20);   /* Number of blocks */
  mls_pid_M->Sizes.numBlockIO = (7);   /* Number of block outputs */
  mls_pid_M->Sizes.numBlockPrms = (40);/* Sum of parameter "widths" */
  return mls_pid_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
