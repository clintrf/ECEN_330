################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/spaceInvadersTest1/aliens.c \
../src/spaceInvadersTest1/isr.c \
../src/spaceInvadersTest1/main.c \
../src/spaceInvadersTest1/rapidDraw.c \
../src/spaceInvadersTest1/tank.c 

OBJS += \
./src/spaceInvadersTest1/aliens.o \
./src/spaceInvadersTest1/isr.o \
./src/spaceInvadersTest1/main.o \
./src/spaceInvadersTest1/rapidDraw.o \
./src/spaceInvadersTest1/tank.o 

C_DEPS += \
./src/spaceInvadersTest1/aliens.d \
./src/spaceInvadersTest1/isr.d \
./src/spaceInvadersTest1/main.d \
./src/spaceInvadersTest1/rapidDraw.d \
./src/spaceInvadersTest1/tank.d 


# Each subdirectory must supply rules for building sources it contributes
src/spaceInvadersTest1/%.o: ../src/spaceInvadersTest1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"C:\Users\hutch\ZYBO\EE330_Fall2015_EE390_Winter2016\EE330_Fall2015_EE390_Winter2016_Final_SW\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


