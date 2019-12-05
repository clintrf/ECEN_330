################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../supportFiles/nrf8001_bluetooth/Adafruit_BLE_UART.cpp 

OBJS += \
./supportFiles/nrf8001_bluetooth/Adafruit_BLE_UART.o 

CPP_DEPS += \
./supportFiles/nrf8001_bluetooth/Adafruit_BLE_UART.d 


# Each subdirectory must supply rules for building sources it contributes
supportFiles/nrf8001_bluetooth/%.o: ../supportFiles/nrf8001_bluetooth/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


