################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../supportFiles/Adafruit_GFX.cpp \
../supportFiles/Adafruit_STMPE610.cpp \
../supportFiles/Adafruit_TFTLCD.cpp \
../supportFiles/Print.cpp \
../supportFiles/WString.cpp \
../supportFiles/display.cpp \
../supportFiles/new.cpp \
../supportFiles/utils.cpp 

C_SRCS += \
../supportFiles/bluetooth.c \
../supportFiles/circularBuffer.c \
../supportFiles/glcdfont.c \
../supportFiles/globalTimer.c \
../supportFiles/interrupts.c \
../supportFiles/lcd.c \
../supportFiles/leds.c \
../supportFiles/mio.c \
../supportFiles/spi.c \
../supportFiles/tftGpio.c 

OBJS += \
./supportFiles/Adafruit_GFX.o \
./supportFiles/Adafruit_STMPE610.o \
./supportFiles/Adafruit_TFTLCD.o \
./supportFiles/Print.o \
./supportFiles/WString.o \
./supportFiles/bluetooth.o \
./supportFiles/circularBuffer.o \
./supportFiles/display.o \
./supportFiles/glcdfont.o \
./supportFiles/globalTimer.o \
./supportFiles/interrupts.o \
./supportFiles/lcd.o \
./supportFiles/leds.o \
./supportFiles/mio.o \
./supportFiles/new.o \
./supportFiles/spi.o \
./supportFiles/tftGpio.o \
./supportFiles/utils.o 

C_DEPS += \
./supportFiles/bluetooth.d \
./supportFiles/circularBuffer.d \
./supportFiles/glcdfont.d \
./supportFiles/globalTimer.d \
./supportFiles/interrupts.d \
./supportFiles/lcd.d \
./supportFiles/leds.d \
./supportFiles/mio.d \
./supportFiles/spi.d \
./supportFiles/tftGpio.d 

CPP_DEPS += \
./supportFiles/Adafruit_GFX.d \
./supportFiles/Adafruit_STMPE610.d \
./supportFiles/Adafruit_TFTLCD.d \
./supportFiles/Print.d \
./supportFiles/WString.d \
./supportFiles/display.d \
./supportFiles/new.d \
./supportFiles/utils.d 


# Each subdirectory must supply rules for building sources it contributes
supportFiles/%.o: ../supportFiles/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_Student_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

supportFiles/%.o: ../supportFiles/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_Student_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


