$(AS_CPU_PATH)/asfw.br: \
	$(AS_PROJECT_PATH)/Physical/Config1/Hardware.hc \
	$(AS_INSTALL_PATH)/Upgrades/Modified.txt
	@$(AS_BIN_PATH)/BR.AS.ConfigurationBuilder.exe  "$(AS_PROJECT_PATH)/Physical/$(AS_CONFIGURATION)/Hardware.hc" -v V1.00.0 -S PLC1 -o "$(AS_CPU_PATH)/asfw.br" -T SGC -B C2.31 -P "$(AS_PROJECT_PATH)"  -s PLC1 -firmware -secret "$(AS_PROJECT_PATH)_br.as.configurationbuilder.exe"
