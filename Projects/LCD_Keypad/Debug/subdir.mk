################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dio.c \
../dio_cfg.c \
../keypad.c \
../keypad_cfg.c \
../lcd.c \
../main.c 

OBJS += \
./dio.o \
./dio_cfg.o \
./keypad.o \
./keypad_cfg.o \
./lcd.o \
./main.o 

C_DEPS += \
./dio.d \
./dio_cfg.d \
./keypad.d \
./keypad_cfg.d \
./lcd.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


