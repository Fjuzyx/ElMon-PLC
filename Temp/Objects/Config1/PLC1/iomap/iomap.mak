$(AS_CPU_PATH)/iomap.br: \
	$(AS_PROJECT_PATH)/physical/$(AS_CONFIGURATION)/$(AS_PLC)/iomap.iom \
	$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/Hardware.hc \
	$(AS_PROJECT_PATH)/physical/$(AS_CONFIGURATION)/$(AS_PLC)/cpu.sw \
	$(AS_CPU_PATH)/ChannelConfiguration.xml \
	$(AS_PROJECT_PATH)/logical/main/main.typ \
	$(AS_PROJECT_PATH)/logical/main/main.var
	@$(AS_BIN_PATH)/BR.AS.IOMapBuilder.exe "$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/$(AS_PLC)/IoMap.iom"  -m "$(AS_CPU_PATH)/ConfigInfo.cfi" -g "$(AS_TEMP_PATH)/Objects/Declarations.lst" -x "$(AS_CPU_PATH)/ChannelConfiguration.xml" -v V1.00.0 -f "$(AS_CPU_PATH)/Global.ofs" -o "$(AS_CPU_PATH)/iomap.br" -T SGC  -B C2.31 -P "$(AS_PROJECT_PATH)" -s PLC1

-include $(AS_CPU_PATH)/Force.mak 
