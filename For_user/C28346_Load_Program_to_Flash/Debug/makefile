################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccsv5/tools/compiler/c2000_6.1.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./sources/DSP2834x_usDelay.obj" \
"./sources/DSP2834x_Xintf.obj" \
"./sources/DSP2834x_SysCtrl.obj" \
"./sources/DSP2834x_Spi.obj" \
"./sources/DSP2834x_Sci.obj" \
"./sources/DSP2834x_PieVect.obj" \
"./sources/DSP2834x_PieCtrl.obj" \
"./sources/DSP2834x_MemCopy.obj" \
"./sources/DSP2834x_Mcbsp.obj" \
"./sources/DSP2834x_I2C.obj" \
"./sources/DSP2834x_Gpio.obj" \
"./sources/DSP2834x_EQep.obj" \
"./sources/DSP2834x_EPwm.obj" \
"./sources/DSP2834x_ECap.obj" \
"./sources/DSP2834x_ECan.obj" \
"./sources/DSP2834x_DisInt.obj" \
"./sources/DSP2834x_DefaultIsr.obj" \
"./sources/DSP2834x_DMA.obj" \
"./sources/DSP2834x_DBGIER.obj" \
"./sources/DSP2834x_CpuTimers.obj" \
"./sources/DSP2834x_CodeStartBranch.obj" \
"./main.obj" \
"./Program_to_Load.obj" \
"./DSP2834x_GlobalVariableDefs.obj" \
-l"libc.a" \
"../28346_RAM_lnk.cmd" \
"../DSP2834x_Headers_nonBIOS.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include sources/subdir_vars.mk
-include subdir_rules.mk
-include sources/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: C28346_Load_Program_to_Flash.out

# Tool invocations
C28346_Load_Program_to_Flash.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --diag_warning=225 --display_error_number --diag_wrap=off -z --stack_size=0x300 -m"C28346_Load_Program_to_Flash.map" --warn_sections -i"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/lib" -i"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/include" --reread_libs --display_error_number --diag_wrap=off --rom_model -o "C28346_Load_Program_to_Flash.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "C28346_Load_Program_to_Flash.out"
	-$(RM) "DSP2834x_GlobalVariableDefs.pp" "Program_to_Load.pp" "main.pp" "sources\DSP2834x_CpuTimers.pp" "sources\DSP2834x_DMA.pp" "sources\DSP2834x_DefaultIsr.pp" "sources\DSP2834x_ECan.pp" "sources\DSP2834x_ECap.pp" "sources\DSP2834x_EPwm.pp" "sources\DSP2834x_EQep.pp" "sources\DSP2834x_Gpio.pp" "sources\DSP2834x_I2C.pp" "sources\DSP2834x_Mcbsp.pp" "sources\DSP2834x_MemCopy.pp" "sources\DSP2834x_PieCtrl.pp" "sources\DSP2834x_PieVect.pp" "sources\DSP2834x_Sci.pp" "sources\DSP2834x_Spi.pp" "sources\DSP2834x_SysCtrl.pp" "sources\DSP2834x_Xintf.pp" 
	-$(RM) "DSP2834x_GlobalVariableDefs.obj" "Program_to_Load.obj" "main.obj" "sources\DSP2834x_CodeStartBranch.obj" "sources\DSP2834x_CpuTimers.obj" "sources\DSP2834x_DBGIER.obj" "sources\DSP2834x_DMA.obj" "sources\DSP2834x_DefaultIsr.obj" "sources\DSP2834x_DisInt.obj" "sources\DSP2834x_ECan.obj" "sources\DSP2834x_ECap.obj" "sources\DSP2834x_EPwm.obj" "sources\DSP2834x_EQep.obj" "sources\DSP2834x_Gpio.obj" "sources\DSP2834x_I2C.obj" "sources\DSP2834x_Mcbsp.obj" "sources\DSP2834x_MemCopy.obj" "sources\DSP2834x_PieCtrl.obj" "sources\DSP2834x_PieVect.obj" "sources\DSP2834x_Sci.obj" "sources\DSP2834x_Spi.obj" "sources\DSP2834x_SysCtrl.obj" "sources\DSP2834x_Xintf.obj" "sources\DSP2834x_usDelay.obj" 
	-$(RM) "sources\DSP2834x_CodeStartBranch.pp" "sources\DSP2834x_DBGIER.pp" "sources\DSP2834x_DisInt.pp" "sources\DSP2834x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
