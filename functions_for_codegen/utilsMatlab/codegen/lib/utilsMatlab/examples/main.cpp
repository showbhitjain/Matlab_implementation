//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 14-Nov-2024 02:49:51
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "add_noise.h"
#include "integrateRungeKutta.h"
#include "rt_nonfinite.h"
#include "utilsMatlab_terminate.h"
#include "coder_array.h"

// Function Declarations
static void argInit_1x2_real_T(double result[2]);

static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static double argInit_real_T();

// Function Definitions
//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_1x2_real_T(double result[2])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 2; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : coder::array<double, 1U>
//
static coder::array<double, 1U> argInit_Unboundedx1_real_T()
{
  coder::array<double, 1U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_add_noise();
  main_integrateRungeKutta();
  // Terminate the application.
  // You do not need to do this more than one time.
  utilsMatlab_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_add_noise()
{
  coder::array<double, 1U> joint_vector;
  coder::array<double, 1U> noisy_joint_vector;
  double noise_min_tmp;
  // Initialize function 'add_noise' input arguments.
  // Initialize function input argument 'joint_vector'.
  joint_vector = argInit_Unboundedx1_real_T();
  noise_min_tmp = argInit_real_T();
  // Call the entry-point 'add_noise'.
  add_noise(joint_vector, noise_min_tmp, noise_min_tmp, noisy_joint_vector);
}

//
// Arguments    : void
// Return Type  : void
//
void main_integrateRungeKutta()
{
  coder::array<double, 1U> desired_joint_vector;
  coder::array<double, 1U> desired_joint_velocity_current_tmp;
  double dv[2];
  // Initialize function 'integrateRungeKutta' input arguments.
  // Initialize function input argument 'desired_joint_velocity_current'.
  desired_joint_velocity_current_tmp = argInit_Unboundedx1_real_T();
  // Initialize function input argument 'tspan'.
  // Initialize function input argument 'start_joint_Velocity'.
  // Call the entry-point 'integrateRungeKutta'.
  argInit_1x2_real_T(dv);
  integrateRungeKutta(desired_joint_velocity_current_tmp, dv,
                      desired_joint_velocity_current_tmp, desired_joint_vector);
}

//
// File trailer for main.cpp
//
// [EOF]
//
