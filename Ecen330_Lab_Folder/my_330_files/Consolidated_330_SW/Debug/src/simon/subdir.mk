################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/simon/buttonHandler.c \
../src/simon/flashSequence.c \
../src/simon/globals.c \
../src/simon/simonControl.c \
../src/simon/simonDisplay.c \
../src/simon/simonMain.c \
../src/simon/verifySequence.c 

OBJS += \
./src/simon/buttonHandler.o \
./src/simon/flashSequence.o \
./src/simon/globals.o \
./src/simon/simonControl.o \
./src/simon/simonDisplay.o \
./src/simon/simonMain.o \
./src/simon/verifySequence.o 

C_DEPS += \
./src/simon/buttonHandler.d \
./src/simon/flashSequence.d \
./src/simon/globals.d \
./src/simon/simonControl.d \
./src/simon/simonDisplay.d \
./src/simon/simonMain.d \
./src/simon/verifySequence.d 


# Each subdirectory must supply rules for building sources it contributes
src/simon/%.o: ../src/simon/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_EE390_Winter2016_Final_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


