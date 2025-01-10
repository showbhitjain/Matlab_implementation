###########################################################################
## Makefile generated for component 'inverseKinematics'. 
## 
## Makefile     : inverseKinematics_rtw.mk
## Generated on : Sun Nov 10 04:04:52 2024
## Final product: ./inverseKinematics.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = inverseKinematics
MAKEFILE                  = inverseKinematics_rtw.mk
MATLAB_ROOT               = /usr/local/MATLAB/R2023b
MATLAB_BIN                = /usr/local/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
START_DIR                 = /home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/robotmodelling/Matlab_implementation/functions_for_codegen/inverseKinematics
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = inverseKinematics.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./inverseKinematics.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/lib/inverseKinematics -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=inverseKinematics

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/inverseKinematics/rt_nonfinite.cpp $(START_DIR)/codegen/lib/inverseKinematics/rtGetNaN.cpp $(START_DIR)/codegen/lib/inverseKinematics/rtGetInf.cpp $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct.cpp $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct1.cpp $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct2.cpp $(START_DIR)/codegen/lib/inverseKinematics/xnrm2.cpp $(START_DIR)/codegen/lib/inverseKinematics/inverseKinematicsWithConstraints.cpp $(START_DIR)/codegen/lib/inverseKinematics/xzsvdc.cpp $(START_DIR)/codegen/lib/inverseKinematics/Jacobi_final_link.cpp $(START_DIR)/codegen/lib/inverseKinematics/Hessian_final_link.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeComplError.cpp $(START_DIR)/codegen/lib/inverseKinematics/fmincon.cpp $(START_DIR)/codegen/lib/inverseKinematics/compressBounds.cpp $(START_DIR)/codegen/lib/inverseKinematics/removeDependentLinearEq.cpp $(START_DIR)/codegen/lib/inverseKinematics/ComputeNumDependentEq_.cpp $(START_DIR)/codegen/lib/inverseKinematics/xgeqp3.cpp $(START_DIR)/codegen/lib/inverseKinematics/xzgeqp3.cpp $(START_DIR)/codegen/lib/inverseKinematics/xzlarfg.cpp $(START_DIR)/codegen/lib/inverseKinematics/xzlarf.cpp $(START_DIR)/codegen/lib/inverseKinematics/xgerc.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeQ_.cpp $(START_DIR)/codegen/lib/inverseKinematics/countsort.cpp $(START_DIR)/codegen/lib/inverseKinematics/xaxpy.cpp $(START_DIR)/codegen/lib/inverseKinematics/xrotg.cpp $(START_DIR)/codegen/lib/inverseKinematics/xgetrf.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/inverseKinematics/xgemv.cpp $(START_DIR)/codegen/lib/inverseKinematics/setProblemType.cpp $(START_DIR)/codegen/lib/inverseKinematics/modifyOverheadPhaseOne_.cpp $(START_DIR)/codegen/lib/inverseKinematics/driver.cpp $(START_DIR)/codegen/lib/inverseKinematics/test_exit.cpp $(START_DIR)/codegen/lib/inverseKinematics/sortLambdaQP.cpp $(START_DIR)/codegen/lib/inverseKinematics/step.cpp $(START_DIR)/codegen/lib/inverseKinematics/driver1.cpp $(START_DIR)/codegen/lib/inverseKinematics/PresolveWorkingSet.cpp $(START_DIR)/codegen/lib/inverseKinematics/removeConstr.cpp $(START_DIR)/codegen/lib/inverseKinematics/feasibleX0ForWorkingSet.cpp $(START_DIR)/codegen/lib/inverseKinematics/factorQR.cpp $(START_DIR)/codegen/lib/inverseKinematics/maxConstraintViolation.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeFval.cpp $(START_DIR)/codegen/lib/inverseKinematics/linearForm_.cpp $(START_DIR)/codegen/lib/inverseKinematics/iterate.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeGrad_StoreHx.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeFval_ReuseHx.cpp $(START_DIR)/codegen/lib/inverseKinematics/deleteColMoveEnd.cpp $(START_DIR)/codegen/lib/inverseKinematics/compute_deltax.cpp $(START_DIR)/codegen/lib/inverseKinematics/xpotrf.cpp $(START_DIR)/codegen/lib/inverseKinematics/factor.cpp $(START_DIR)/codegen/lib/inverseKinematics/solve.cpp $(START_DIR)/codegen/lib/inverseKinematics/xgemm.cpp $(START_DIR)/codegen/lib/inverseKinematics/addBoundToActiveSetMatrix_.cpp $(START_DIR)/codegen/lib/inverseKinematics/addAeqConstr.cpp $(START_DIR)/codegen/lib/inverseKinematics/relaxed.cpp $(START_DIR)/codegen/lib/inverseKinematics/evalObjAndConstr.cpp $(START_DIR)/codegen/lib/inverseKinematics/BFGSUpdate.cpp $(START_DIR)/codegen/lib/inverseKinematics/initActiveSet.cpp $(START_DIR)/codegen/lib/inverseKinematics/computeGradLag.cpp $(START_DIR)/codegen/lib/inverseKinematics/feasibleratiotest.cpp $(START_DIR)/codegen/lib/inverseKinematics/unsafeSxfun.cpp $(START_DIR)/codegen/lib/inverseKinematics/configurableObjective.cpp $(START_DIR)/codegen/lib/inverseKinematics/partialColLDL3_.cpp $(START_DIR)/codegen/lib/inverseKinematics/fullColLDL2_.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.o rtGetNaN.o rtGetInf.o factoryConstruct.o factoryConstruct1.o factoryConstruct2.o xnrm2.o inverseKinematicsWithConstraints.o xzsvdc.o Jacobi_final_link.o Hessian_final_link.o computeComplError.o fmincon.o compressBounds.o removeDependentLinearEq.o ComputeNumDependentEq_.o xgeqp3.o xzgeqp3.o xzlarfg.o xzlarf.o xgerc.o computeQ_.o countsort.o xaxpy.o xrotg.o xgetrf.o computeFiniteDifferences.o xgemv.o setProblemType.o modifyOverheadPhaseOne_.o driver.o test_exit.o sortLambdaQP.o step.o driver1.o PresolveWorkingSet.o removeConstr.o feasibleX0ForWorkingSet.o factorQR.o maxConstraintViolation.o computeFval.o linearForm_.o iterate.o computeGrad_StoreHx.o computeFval_ReuseHx.o deleteColMoveEnd.o compute_deltax.o xpotrf.o factor.o solve.o xgemm.o addBoundToActiveSetMatrix_.o addAeqConstr.o relaxed.o evalObjAndConstr.o BFGSUpdate.o initActiveSet.o computeGradLag.o feasibleratiotest.o unsafeSxfun.o configurableObjective.o partialColLDL3_.o fullColLDL2_.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm -lstdc++

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/lib/inverseKinematics/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/lib/inverseKinematics/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/lib/inverseKinematics/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/lib/inverseKinematics/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.o : $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct1.o : $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct2.o : $(START_DIR)/codegen/lib/inverseKinematics/factoryConstruct2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/codegen/lib/inverseKinematics/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inverseKinematicsWithConstraints.o : $(START_DIR)/codegen/lib/inverseKinematics/inverseKinematicsWithConstraints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzsvdc.o : $(START_DIR)/codegen/lib/inverseKinematics/xzsvdc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Jacobi_final_link.o : $(START_DIR)/codegen/lib/inverseKinematics/Jacobi_final_link.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Hessian_final_link.o : $(START_DIR)/codegen/lib/inverseKinematics/Hessian_final_link.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeComplError.o : $(START_DIR)/codegen/lib/inverseKinematics/computeComplError.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fmincon.o : $(START_DIR)/codegen/lib/inverseKinematics/fmincon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


compressBounds.o : $(START_DIR)/codegen/lib/inverseKinematics/compressBounds.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


removeDependentLinearEq.o : $(START_DIR)/codegen/lib/inverseKinematics/removeDependentLinearEq.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ComputeNumDependentEq_.o : $(START_DIR)/codegen/lib/inverseKinematics/ComputeNumDependentEq_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.o : $(START_DIR)/codegen/lib/inverseKinematics/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzgeqp3.o : $(START_DIR)/codegen/lib/inverseKinematics/xzgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.o : $(START_DIR)/codegen/lib/inverseKinematics/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.o : $(START_DIR)/codegen/lib/inverseKinematics/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgerc.o : $(START_DIR)/codegen/lib/inverseKinematics/xgerc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeQ_.o : $(START_DIR)/codegen/lib/inverseKinematics/computeQ_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


countsort.o : $(START_DIR)/codegen/lib/inverseKinematics/countsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.o : $(START_DIR)/codegen/lib/inverseKinematics/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.o : $(START_DIR)/codegen/lib/inverseKinematics/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgetrf.o : $(START_DIR)/codegen/lib/inverseKinematics/xgetrf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.o : $(START_DIR)/codegen/lib/inverseKinematics/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.o : $(START_DIR)/codegen/lib/inverseKinematics/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


setProblemType.o : $(START_DIR)/codegen/lib/inverseKinematics/setProblemType.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


modifyOverheadPhaseOne_.o : $(START_DIR)/codegen/lib/inverseKinematics/modifyOverheadPhaseOne_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.o : $(START_DIR)/codegen/lib/inverseKinematics/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


test_exit.o : $(START_DIR)/codegen/lib/inverseKinematics/test_exit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortLambdaQP.o : $(START_DIR)/codegen/lib/inverseKinematics/sortLambdaQP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


step.o : $(START_DIR)/codegen/lib/inverseKinematics/step.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver1.o : $(START_DIR)/codegen/lib/inverseKinematics/driver1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PresolveWorkingSet.o : $(START_DIR)/codegen/lib/inverseKinematics/PresolveWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


removeConstr.o : $(START_DIR)/codegen/lib/inverseKinematics/removeConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleX0ForWorkingSet.o : $(START_DIR)/codegen/lib/inverseKinematics/feasibleX0ForWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factorQR.o : $(START_DIR)/codegen/lib/inverseKinematics/factorQR.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


maxConstraintViolation.o : $(START_DIR)/codegen/lib/inverseKinematics/maxConstraintViolation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval.o : $(START_DIR)/codegen/lib/inverseKinematics/computeFval.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearForm_.o : $(START_DIR)/codegen/lib/inverseKinematics/linearForm_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


iterate.o : $(START_DIR)/codegen/lib/inverseKinematics/iterate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeGrad_StoreHx.o : $(START_DIR)/codegen/lib/inverseKinematics/computeGrad_StoreHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval_ReuseHx.o : $(START_DIR)/codegen/lib/inverseKinematics/computeFval_ReuseHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


deleteColMoveEnd.o : $(START_DIR)/codegen/lib/inverseKinematics/deleteColMoveEnd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


compute_deltax.o : $(START_DIR)/codegen/lib/inverseKinematics/compute_deltax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xpotrf.o : $(START_DIR)/codegen/lib/inverseKinematics/xpotrf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factor.o : $(START_DIR)/codegen/lib/inverseKinematics/factor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


solve.o : $(START_DIR)/codegen/lib/inverseKinematics/solve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemm.o : $(START_DIR)/codegen/lib/inverseKinematics/xgemm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


addBoundToActiveSetMatrix_.o : $(START_DIR)/codegen/lib/inverseKinematics/addBoundToActiveSetMatrix_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


addAeqConstr.o : $(START_DIR)/codegen/lib/inverseKinematics/addAeqConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


relaxed.o : $(START_DIR)/codegen/lib/inverseKinematics/relaxed.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


evalObjAndConstr.o : $(START_DIR)/codegen/lib/inverseKinematics/evalObjAndConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


BFGSUpdate.o : $(START_DIR)/codegen/lib/inverseKinematics/BFGSUpdate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


initActiveSet.o : $(START_DIR)/codegen/lib/inverseKinematics/initActiveSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeGradLag.o : $(START_DIR)/codegen/lib/inverseKinematics/computeGradLag.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleratiotest.o : $(START_DIR)/codegen/lib/inverseKinematics/feasibleratiotest.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.o : $(START_DIR)/codegen/lib/inverseKinematics/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


configurableObjective.o : $(START_DIR)/codegen/lib/inverseKinematics/configurableObjective.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


partialColLDL3_.o : $(START_DIR)/codegen/lib/inverseKinematics/partialColLDL3_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fullColLDL2_.o : $(START_DIR)/codegen/lib/inverseKinematics/fullColLDL2_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


