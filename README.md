coreboot is a Free Software project aimed at replacing the proprietary BIOS
(firmware) found in most computers.  coreboot performs a little bit of
hardware initialization and then executes additional boot logic, called a
payload.

With the separation of hardware initialization and later boot logic,
coreboot can scale from specialized applications that run directly
firmware, run operating systems in flash, load custom
bootloaders, or implement firmware standards, like PC BIOS services or
UEFI. This allows for systems to only include the features necessary
in the target application, reducing the amount of code and flash space
required.

coreboot was formerly known as LinuxBIOS.


Payloads
--------

After the basic initialization of the hardware has been performed, any
desired "payload" can be started by coreboot.

See <https://www.coreboot.org/Payloads> for a list of supported payloads.

Build Requirements
------------------

 * make

