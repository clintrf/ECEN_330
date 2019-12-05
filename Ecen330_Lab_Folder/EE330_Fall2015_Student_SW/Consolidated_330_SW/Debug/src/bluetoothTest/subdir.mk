################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bluetoothTest/Adafruit_BLE.cpp \
../src/bluetoothTest/Adafruit_BluefruitLE_UART.cpp \
../src/bluetoothTest/main.cpp 

C_SRCS += \
../src/bluetoothTest/isr_function.c 

OBJS += \
./src/bluetoothTest/Adafruit_BLE.o \
./src/bluetoothTest/Adafruit_BluefruitLE_UART.o \
./src/bluetoothTest/isr_function.o \
./src/bluetoothTest/main.o 

C_DEPS += \
./src/bluetoothTest/isr_function.d 

CPP_DEPS += \
./src/bluetoothTest/Adafruit_BLE.d \
./src/bluetoothTest/Adafruit_BluefruitLE_UART.d \
./src/bluetoothTest/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/bluetoothTest/%.o: ../src/bluetoothTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_EE390_Winter2016_Final_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/bluetoothTest/%.o: ../src/bluetoothTest/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_EE390_Winter2016_Final_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


