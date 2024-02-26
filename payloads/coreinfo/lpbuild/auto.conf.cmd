deps_config := \
	arch/x86/Kconfig \
	arch/arm64/Kconfig \
	arch/arm/Kconfig \
	drivers/usb/Kconfig \
	drivers/storage/Kconfig \
	drivers/timer/Kconfig \
	Kconfig

/home/sayali/Documents/internal_project/coreboot/payloads/coreinfo/lpbuild/auto.conf: \
	$(deps_config)


$(deps_config): ;
