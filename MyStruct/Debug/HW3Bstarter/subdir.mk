################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HW3Bstarter/HW3B.c \
../HW3Bstarter/mystruct.c \
../HW3Bstarter/production.c \
../HW3Bstarter/tests.c 

O_SRCS += \
../HW3Bstarter/HW3B.o \
../HW3Bstarter/mystruct.o \
../HW3Bstarter/production.o \
../HW3Bstarter/tests.o 

OBJS += \
./HW3Bstarter/HW3B.o \
./HW3Bstarter/mystruct.o \
./HW3Bstarter/production.o \
./HW3Bstarter/tests.o 

C_DEPS += \
./HW3Bstarter/HW3B.d \
./HW3Bstarter/mystruct.d \
./HW3Bstarter/production.d \
./HW3Bstarter/tests.d 


# Each subdirectory must supply rules for building sources it contributes
HW3Bstarter/%.o: ../HW3Bstarter/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


