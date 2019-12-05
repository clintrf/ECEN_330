################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../supportFiles/nrf8001_bluetooth/utility/aci_setup.cpp \
../supportFiles/nrf8001_bluetooth/utility/acilib.cpp \
../supportFiles/nrf8001_bluetooth/utility/hal_aci_tl.cpp \
../supportFiles/nrf8001_bluetooth/utility/lib_aci.cpp 

C_SRCS += \
../supportFiles/nrf8001_bluetooth/utility/bluetoothRadioGpio.c 

OBJS += \
./supportFiles/nrf8001_bluetooth/utility/aci_setup.o \
./supportFiles/nrf8001_bluetooth/utility/acilib.o \
./supportFiles/nrf8001_bluetooth/utility/bluetoothRadioGpio.o \
./supportFiles/nrf8001_bluetooth/utility/hal_aci_tl.o \
./supportFiles/nrf8001_bluetooth/utility/lib_aci.o 

C_DEPS += \
./supportFiles/nrf8001_bluetooth/utility/bluetoothRadioGpio.d 

CPP_DEPS += \
./supportFiles/nrf8001_bluetooth/utility/aci_setup.d \
./supportFiles/nrf8001_bluetooth/utility/acilib.d \
./supportFiles/nrf8001_bluetooth/utility/hal_aci_tl.d \
./supportFiles/nrf8001_bluetooth/utility/lib_aci.d 


# Each subdirectory must supply rules for building sources it contributes
supportFiles/nrf8001_bluetooth/utility/%.o: ../supportFiles/nrf8001_bluetooth/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

supportFiles/nrf8001_bluetooth/utility/%.o: ../supportFiles/nrf8001_bluetooth/utility/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


