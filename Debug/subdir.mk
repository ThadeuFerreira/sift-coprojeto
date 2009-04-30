################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../cvaccum.o \
../cvadapthresh.o \
../cvapprox.o \
../cvcalccontrasthistogram.o \
../cvcalcimagehomography.o \
../cvcalibinit.o \
../cvcalibration.o \
../cvcamshift.o \
../cvcanny.o \
../cvcolor.o \
../cvcondens.o \
../cvcontours.o \
../cvcontourtree.o \
../cvconvhull.o \
../cvconvolve.o \
../cvcorner.o \
../cvcornersubpix.o \
../cvderiv.o \
../cvdistransform.o \
../cvdominants.o \
../cvemd.o \
../cvfeatureselect.o \
../cvfloodfill.o \
../cvfundam.o \
../cvgeometry.o \
../cvhaar.o \
../cvhistogram.o \
../cvhough.o \
../cvimgwarp.o \
../cvkalman.o \
../cvlinefit.o \
../cvlkpyramid.o \
../cvmatchcontours.o \
../cvmoments.o \
../cvmorph.o \
../cvmotempl.o \
../cvoptflowbm.o \
../cvoptflowhs.o \
../cvoptflowlk.o \
../cvpgh.o \
../cvposit.o \
../cvprecomp.o \
../cvpyramids.o \
../cvpyrsegmentation.o \
../cvrotcalipers.o \
../cvsamplers.o \
../cvshapedescr.o \
../cvsmooth.o \
../cvsnakes.o \
../cvsubdivision2d.o \
../cvsumpixels.o \
../cvswitcher.o \
../cvtables.o \
../cvtemplmatch.o \
../cvthresh.o \
../cvundistort.o \
../cvutils.o \
../cxalloc.o \
../cxarithm.o \
../cxarray.o \
../cxcmp.o \
../cxconvert.o \
../cxcopy.o \
../cxdatastructs.o \
../cxdrawing.o \
../cxdxt.o \
../cxerror.o \
../cxjacobieigens.o \
../cxlogic.o \
../cxlut.o \
../cxmathfuncs.o \
../cxmatmul.o \
../cxmatrix.o \
../cxmean.o \
../cxmeansdv.o \
../cxminmaxloc.o \
../cxnorm.o \
../cxouttext.o \
../cxpersistence.o \
../cxprecomp.o \
../cxrand.o \
../cxsumpixels.o \
../cxsvd.o \
../cxtables.o \
../cxutils.o \
../imgfeatures.o \
../main.o \
../sift.o \
../utils.o 

C_SRCS += \
../imgfeatures.c \
../main.c \
../sift.c \
../utils.c 

OBJS += \
./imgfeatures.o \
./main.o \
./sift.o \
./utils.o 

C_DEPS += \
./imgfeatures.d \
./main.d \
./sift.d \
./utils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


