################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ClockLab/clockControl.c \
../src/ClockLab/clockMainFlagBasedInterrupts.c \
../src/ClockLab/clockMainIsrFunctionBasedInterrupts.c \
../src/ClockLab/clockdisplay.c 

OBJS += \
./src/ClockLab/clockControl.o \
./src/ClockLab/clockMainFlagBasedInterrupts.o \
./src/ClockLab/clockMainIsrFunctionBasedInterrupts.o \
./src/ClockLab/clockdisplay.o 

C_DEPS += \
./src/ClockLab/clockControl.d \
./src/ClockLab/clockMainFlagBasedInterrupts.d \
./src/ClockLab/clockMainIsrFunctionBasedInterrupts.d \
./src/ClockLab/clockdisplay.d 


# Each subdirectory must supply rules for building sources it contributes
src/ClockLab/%.o: ../src/ClockLab/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_EE390_Winter2016_Final_SW_Student\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


