################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab6_simon/buttonHandler.c \
../src/Lab6_simon/flashSequence.c \
../src/Lab6_simon/globals.c \
../src/Lab6_simon/simonControl.c \
../src/Lab6_simon/simonDisplay.c \
../src/Lab6_simon/verifySequence_runTest.c 

OBJS += \
./src/Lab6_simon/buttonHandler.o \
./src/Lab6_simon/flashSequence.o \
./src/Lab6_simon/globals.o \
./src/Lab6_simon/simonControl.o \
./src/Lab6_simon/simonDisplay.o \
./src/Lab6_simon/verifySequence_runTest.o 

C_DEPS += \
./src/Lab6_simon/buttonHandler.d \
./src/Lab6_simon/flashSequence.d \
./src/Lab6_simon/globals.d \
./src/Lab6_simon/simonControl.d \
./src/Lab6_simon/simonDisplay.d \
./src/Lab6_simon/verifySequence_runTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab6_simon/%.o: ../src/Lab6_simon/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"F:\Ecen330_Lab_Folder\my_330_files\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


