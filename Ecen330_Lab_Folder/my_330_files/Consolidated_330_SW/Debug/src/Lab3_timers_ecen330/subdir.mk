################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab3_timers_ecen330/intervalTimer.c 

OBJS += \
./src/Lab3_timers_ecen330/intervalTimer.o 

C_DEPS += \
./src/Lab3_timers_ecen330/intervalTimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab3_timers_ecen330/%.o: ../src/Lab3_timers_ecen330/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"F:\Ecen330_Lab_Folder\my_330_files\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


