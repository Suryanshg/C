################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HW1/src/HW1.c \
../HW1/src/production.c \
../HW1/src/tests.c 

OBJS += \
./HW1/src/HW1.o \
./HW1/src/production.o \
./HW1/src/tests.o 

C_DEPS += \
./HW1/src/HW1.d \
./HW1/src/production.d \
./HW1/src/tests.d 


# Each subdirectory must supply rules for building sources it contributes
HW1/src/%.o: ../HW1/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


