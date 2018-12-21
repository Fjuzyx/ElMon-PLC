SHELL = C:/BrAutomation/AS30090/AS/GnuInst/V2.95.3/bin/sh
CYGWIN=nontsec
export PATH := C:\Program Files (x86)\Borland\Delphi7\Bin;C:\Program Files (x86)\Borland\Delphi7\Projects\Bpl\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode
export AS_COMPANY_NAME :=  
export AS_USER_NAME := Win7
export AS_PATH := C:/BrAutomation/AS30090
export AS_BIN_PATH := C:/BrAutomation/AS30090/Bin-en
export AS_PROJECT_PATH := C:/Data/EnMon_3081
export AS_PROJECT_NAME := EnergyMon
export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_VC_PATH := C:/BrAutomation/AS30090/AS/VC
export AS_TEMP_PATH := C:/Data/EnMon_3081/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := C:/Data/EnMon_3081/Binaries
export AS_GNU_INST_PATH := C:/BrAutomation/AS30090/AS/GnuInst/V2.95.3
export AS_GNU_BIN_PATH := $(AS_GNU_INST_PATH)/bin
export AS_GNU_INST_PATH_SUB_MAKE := C:/BrAutomation/AS30090/AS/GnuInst/V2.95.3
export AS_GNU_BIN_PATH_SUB_MAKE := $(AS_GNU_INST_PATH_SUB_MAKE)/bin
export AS_INSTALL_PATH := C:/BrAutomation/AS30090
export WIN32_AS_PATH := C:\\BrAutomation\\AS30090
export WIN32_AS_BIN_PATH := C:\\BrAutomation\\AS30090\\Bin-en
export WIN32_AS_PROJECT_PATH := C:\\Data\\EnMon_3081
export WIN32_AS_SYSTEM_PATH := C:\\BrAutomation\\AS\\System
export WIN32_AS_VC_PATH := C:\\BrAutomation\\AS30090\\AS\\VC
export WIN32_AS_TEMP_PATH := C:\\Data\\EnMon_3081\\Temp
export WIN32_AS_BINARIES_PATH := C:\\Data\\EnMon_3081\\Binaries
export WIN32_AS_GNU_INST_PATH := C:\\BrAutomation\\AS30090\\AS\\GnuInst\\V2.95.3
export WIN32_AS_GNU_BIN_PATH := $(WIN32_AS_GNU_INST_PATH)\\bin
export WIN32_AS_INSTALL_PATH := C:\\BrAutomation\\AS30090

.suffixes:

ProjectMakeFile:

	@$(AS_BIN_PATH)/BR.AS.AnalyseProject.exe "$(AS_PROJECT_PATH)/EnergyMon.apj" -t "$(AS_TEMP_PATH)" -c "$(AS_CONFIGURATION)" -o "$(AS_BINARIES_PATH)"   -sfas -buildMode "BuildAndTransfer"

	@$(AS_GNU_BIN_PATH)/make.exe -r -f "C:/Data/EnMon_3081/Temp/Objects/$(AS_CONFIGURATION)/PLC1/#cpu.mak" -k

