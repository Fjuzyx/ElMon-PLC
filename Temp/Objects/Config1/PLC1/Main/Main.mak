UnmarkedObjectFolder := C:/Data/EnMon_3081/Logical/Main
MarkedObjectFolder := C:/Data/EnMon_3081/Logical/Main

$(AS_CPU_PATH)/Main.br: \
	$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/$(AS_PLC)/Cpu.per \
	$(AS_CPU_PATH)/Main/Main.ox
	@$(AS_BIN_PATH)/BR.AS.TaskBuilder.exe "$(AS_CPU_PATH)/Main/Main.ox" -o "$(AS_CPU_PATH)/Main.br" -v V1.00.0 -f "$(AS_CPU_PATH)/Global.ofs" -T SGC  -B C2.31 -extConstants -d "gcloader: V1.32 - V*" -r Cyclic1 -p 2 -s Main -L "astime: V*, brsystem: V*, Convert: V*, Operator: V*, Runtime: V*" -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.as.taskbuilder.exe"

$(AS_CPU_PATH)/Main/Main.ox: \
	$(AS_CPU_PATH)/Main/a.out
	@$(AS_BIN_PATH)/BR.AS.Backend.exe "$(AS_CPU_PATH)/Main/a.out" -o "$(AS_CPU_PATH)/Main/Main.ox" -T SGC -r Cyclic1   -G V2.95.3  -secret "$(AS_PROJECT_PATH)_br.as.backend.exe"

$(AS_CPU_PATH)/Main/a.out: \
	$(AS_CPU_PATH)/Main/Main.o
	@$(AS_BIN_PATH)/BR.AS.CCompiler.exe -link -o "$(AS_CPU_PATH)/Main/a.out" "$(AS_CPU_PATH)/Main/Main.o"  -G V2.95.3  -Wl,--script=SG3.x -Wl,-q -T SGC  "-Wl,$(AS_PROJECT_PATH)/AS/System/C0231/SGC/libastime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/C0231/SGC/libbrsystem.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/C0231/SGC/libOperator.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/C0231/SGC/libRuntime.a" "-Wl,$(AS_PROJECT_PATH)/AS/System/C0231/SGC/libConvert.a" -secret "$(AS_PROJECT_PATH)_br.as.ccompiler.exe"

$(AS_CPU_PATH)/Main/Main.o: \
	$(AS_PROJECT_PATH)/Logical/Main/Main.c \
	$(AS_PROJECT_PATH)/Logical/Libraries/astime/astime.fun \
	$(AS_PROJECT_PATH)/Logical/Libraries/brsystem/brsystem.fun \
	$(AS_PROJECT_PATH)/Logical/Main/Main.var \
	$(AS_PROJECT_PATH)/Logical/Main/Main.typ \
	$(AS_PROJECT_PATH)/Physical/Config1/PLC1/Cpu.per \
	$(AS_PROJECT_PATH)/Logical/Global.var
	@$(AS_BIN_PATH)/BR.AS.CCompiler.exe "$(AS_PROJECT_PATH)/Logical/Main/Main.c" -o "$(AS_CPU_PATH)/Main/Main.o"  -T SGC  -B C2.31 -G V2.95.3  -s Main -t "$(AS_TEMP_PATH)" -I "$(AS_PROJECT_PATH)/Logical/Main" "$(AS_TEMP_PATH)/Includes/Main" "$(AS_TEMP_PATH)/Includes" -trigraphs -fno-asm -D _DEFAULT_INCLUDES -D _SGC -Wall -fpic -m68000 -msoft-float -O0 -g -nostartfiles -x c -include "$(AS_CPU_PATH)/Libraries.h" -P "$(AS_PROJECT_PATH)/" -secret "$(AS_PROJECT_PATH)_br.as.ccompiler.exe"

-include $(AS_CPU_PATH)/Force.mak 

