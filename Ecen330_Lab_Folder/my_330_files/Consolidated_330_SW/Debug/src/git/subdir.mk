################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/git/buttonHandler.c \
../src/git/flashSequence.c \
../src/git/globals.c \
../src/git/main.c \
../src/git/simonControl.c \
../src/git/simonDispaly.c \
../src/git/verifySequence.c 

OBJS += \
./src/git/buttonHandler.o \
./src/git/flashSequence.o \
./src/git/globals.o \
./src/git/main.o \
./src/git/simonControl.o \
./src/git/simonDispaly.o \
./src/git/verifySequence.o 

C_DEPS += \
./src/git/buttonHandler.d \
./src/git/flashSequence.d \
./src/git/globals.d \
./src/git/main.d \
./src/git/simonControl.d \
./src/git/simonDispaly.d \
./src/git/verifySequence.d 


# Each subdirectory must supply rules for building sources it contributes
src/git/%.o: ../src/git/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O0 -g3 -I"F:\Ecen330_Lab_Folder\my_330_files\Consolidated_330_SW" -c -fmessage-length=0 -I../../Consolidated_330_SW_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


