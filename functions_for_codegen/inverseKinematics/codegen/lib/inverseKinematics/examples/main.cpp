//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Nov-2024 04:04:05
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
#include "inverseKinematicsWithConstraints.h"
#include "inverseKinematics_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
static coder::array<double, 1U> argInit_Unboundedx1_real_T();

static boolean_T argInit_boolean_T();

static int argInit_d6x1_real_T(double result_data[]);

static coder::array<double, 2U> argInit_d6xUnbounded_real_T();

static double argInit_real_T();

static void argInit_struct0_T(struct0_T &result);

// Function Definitions
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
// Return Type  : boolean_T
//
static boolean_T argInit_boolean_T()
{
  return false;
}

//
// Arguments    : double result_data[]
// Return Type  : int
//
static int argInit_d6x1_real_T(double result_data[])
{
  int result_size;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size = 2;
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_data[idx0] = argInit_real_T();
  }
  return result_size;
}

//
// Arguments    : void
// Return Type  : coder::array<double, 2U>
//
static coder::array<double, 2U> argInit_d6xUnbounded_real_T()
{
  coder::array<double, 2U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2);
  // Loop over the array to initialize each element.
  for (int idx0{0}; idx0 < result.size(0); idx0++) {
    for (int idx1{0}; idx1 < result.size(1); idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + result.size(0) * idx1] = argInit_real_T();
    }
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
// Arguments    : struct0_T &result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T &result)
{
  double b_result_tmp;
  boolean_T result_tmp;
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_boolean_T();
  result.useObjective2 = result_tmp;
  b_result_tmp = argInit_real_T();
  result.weight2 = b_result_tmp;
  result.useObjective3 = result_tmp;
  result.weight3 = b_result_tmp;
  result.useObjective4 = result_tmp;
  result.weight4 = b_result_tmp;
  result.useObjective5 = result_tmp;
  result.weight5 = b_result_tmp;
  result.useObjective6 = result_tmp;
  result.weight6 = b_result_tmp;
  result.useObjective1 = result_tmp;
  result.weight1 = b_result_tmp;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  inverseKinematicsWithConstraints *classInstance;
  classInstance = new inverseKinematicsWithConstraints;
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_inverseKinematics(classInstance);
  delete classInstance;
  return 0;
}

//
// Arguments    : inverseKinematicsWithConstraints *instancePtr
// Return Type  : void
//
void main_inverseKinematics(inverseKinematicsWithConstraints *instancePtr)
{
  coder::array<double, 2U> jacobi;
  coder::array<double, 1U> joint_values_tmp;
  coder::array<double, 1U> optimal_joint_velocity;
  struct0_T r;
  double xd_eff_vel_data[6];
  double Exit_Flag;
  int xd_eff_vel_size;
  // Initialize function 'inverseKinematics' input arguments.
  // Initialize function input argument 'joint_values'.
  joint_values_tmp = argInit_Unboundedx1_real_T();
  // Initialize function input argument 'jacobi'.
  jacobi = argInit_d6xUnbounded_real_T();
  // Initialize function input argument 'xd_eff_vel'.
  xd_eff_vel_size = argInit_d6x1_real_T(xd_eff_vel_data);
  // Initialize function input argument 'jointminvalues'.
  // Initialize function input argument 'jointmaxvalues'.
  // Initialize function input argument 'joint_min_vel'.
  // Initialize function input argument 'joint_max_vel'.
  // Initialize function input argument 'config'.
  // Call the entry-point 'inverseKinematics'.
  argInit_struct0_T(r);
  instancePtr->inverseKinematics(
      joint_values_tmp, jacobi, xd_eff_vel_data, &xd_eff_vel_size,
      joint_values_tmp, joint_values_tmp, joint_values_tmp, joint_values_tmp,
      &r, optimal_joint_velocity, &Exit_Flag);
}

//
// File trailer for main.cpp
//
// [EOF]
//
