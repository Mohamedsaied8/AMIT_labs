################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Keypad.lss \

FLASH_IMAGE += \
Keypad.hex \

EEPROM_IMAGE += \
Keypad.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Keypad.elf secondary-outputs

# Tool invocations
Keypad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Keypad.map -mmcu=atmega16 -o "Keypad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Keypad.lss: Keypad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Keypad.elf  >"Keypad.lss"
	@echo 'Finished building: $@'
	@echo ' '

Keypad.hex: Keypad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Keypad.elf  "Keypad.hex"
	@echo 'Finished building: $@'
	@echo ' '

Keypad.eep: Keypad.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Keypad.elf  "Keypad.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Keypad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Keypad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Keypad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
