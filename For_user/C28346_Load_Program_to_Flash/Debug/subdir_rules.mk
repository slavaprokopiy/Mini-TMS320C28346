################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP2834x_GlobalVariableDefs.obj: ../DSP2834x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/TI/workspace_v5_3/Mini-TMS320C28346/For_user/C28346_Load_Program_to_Flash/headers" --include_path="C:/TI/ccsv5/tools/compiler/c2000_6.1.0/include" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2834x_GlobalVariableDefs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Program_to_Load.obj: C:/TI/workspace_v5_3/Mini-TMS320C28346/For_user/C28346_User_Program/Debug/Program_to_Load.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/TI/workspace_v5_3/Mini-TMS320C28346/For_user/C28346_Load_Program_to_Flash/headers" --include_path="C:/TI/ccsv5/tools/compiler/c2000_6.1.0/include" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="Program_to_Load.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/TI/ccsv5/tools/compiler/c2000_6.1.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/TI/workspace_v5_3/Mini-TMS320C28346/For_user/C28346_Load_Program_to_Flash/headers" --include_path="C:/TI/ccsv5/tools/compiler/c2000_6.1.0/include" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


