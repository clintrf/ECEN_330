################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab2_switch_button/buttons.c \
../src/Lab2_switch_button/switches.c 

OBJS += \
./src/Lab2_switch_button/buttons.o \
./src/Lab2_switch_button/switches.o 

C_DEPS += \
./src/Lab2_switch_button/buttons.d \
./src/Lab2_switch_button/switches.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lab2_switch_button/%.o: ../src/Lab2_switch_button/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"F:\Ecen330_Lab_Folder\my_330_files\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


