/* Copyright 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Register map for STM32 processor
 */

#ifndef __CROS_EC_REGISTERS_H
#define __CROS_EC_REGISTERS_H

#include "common.h"

/*
 *  Peripheral IDs
 *
 *  nRF51 has very good design that the peripheral IDs is actually the IRQ#.
 *  Thus, the following numbers are used in DECLARE_IRQ(), task_enable_irq()
 *  and task_disable_irq().
 */
#define NRF51_PERID_POWER   0
#define NRF51_PERID_CLOCK   0
#define NRF51_PERID_RADIO   1
#define NRF51_PERID_USART   2
#define NRF51_PERID_SPI0    3
#define NRF51_PERID_TWI0    3
#define NRF51_PERID_SPI1    4
#define NRF51_PERID_TWI1    4
#define NRF51_PERID_SPIS    4
#define NRF51_PERID_GPIOTE  6
#define NRF51_PERID_ADC     7
#define NRF51_PERID_TIMER0  8
#define NRF51_PERID_TIMER1  9
#define NRF51_PERID_TIMER2  10
#define NRF51_PERID_RTC     11
#define NRF51_PERID_TEMP    12
#define NRF51_PERID_RNG     13
#define NRF51_PERID_ECB     14
#define NRF51_PERID_CCM     15
#define NRF51_PERID_AAR     16
#define NRF51_PERID_WDT     17
#define NRF51_PERID_QDEC    18
#define NRF51_PERID_LPCOMP  19
#define NRF51_PERID_NVMC    30
#define NRF51_PERID_PPI     31

/*
 * The nRF51 allows any pin to be mapped to any function.  This
 * doesn't fit well with the notion of the alternate function table.
 * Implement an alternate function table.  See ./gpio.c.
 */

	/* UART */
#define NRF51_UART_ALT_FUNC_RTS        0
#define NRF51_UART_ALT_FUNC_TXD        1
#define NRF51_UART_ALT_FUNC_CTS        2
#define NRF51_UART_ALT_FUNC_RXD        3
	/* SPI1 (SPI Master) */
#define NRF51_SPI0_ALT_FUNC_SCK        4
#define NRF51_SPI0_ALT_FUNC_MOSI       5
#define NRF51_SPI0_ALT_FUNC_MISO       6
	/* TWI0 (I2C) */
#define NRF51_TWI0_ALT_FUNC_SCL        7
#define NRF51_TWI0_ALT_FUNC_SDA        8
	/* SPI1 (SPI Master) */
#define NRF51_SPI1_ALT_FUNC_SCK        9
#define NRF51_SPI1_ALT_FUNC_MOSI       10
#define NRF51_SPI1_ALT_FUNC_MISO       11
	/* TWI1 (I2C) */
#define NRF51_TWI1_ALT_FUNC_SCL        12
#define NRF51_TWI1_ALT_FUNC_SDA        13
	/* SPIS1 (SPI SLAVE) */
#define NRF51_SPIS1_ALT_FUNC_SCK       14
#define NRF51_SPIS1_ALT_FUNC_MISO      15
#define NRF51_SPIS1_ALT_FUNC_MOSI      16
#define NRF51_SPIS1_ALT_FUNC_CSN       17
	/* QDEC (ROTARY DECODER) */
#define NRF51_QDEC_ALT_FUNC_LED        18
#define NRF51_QDEC_ALT_FUNC_A          19
#define NRF51_QDEC_ALT_FUNC_B          20
	/* LPCOMP (Low Power Comparator) */
#define NRF51_LPCOMP_ALT_FUNC          21
#define NRF51_MAX_ALT_FUNCS            22

/*
 * Configuration Registers
 */

/*
 * FICR
 */
#define NRF51_FICR_BASE                0x10000000
#define NRF51_FICR_CODEPAGESIZE        REG32(NRF51_FICR_BASE + 0x010)
#define NRF51_FICR_CLENR0              REG32(NRF51_FICR_BASE + 0x014)
#define NRF51_FICR_PPFC                REG32(NRF51_FICR_BASE + 0x028)
#define NRF51_FICR_NUMRAMBLOCK         REG32(NRF51_FICR_BASE + 0x02C)
#define NRF51_FICR_SIZERAMBLOCK(n)     REG32(NRF51_FICR_BASE + 0x034 + ((n)*4))
#define NRF51_FICR_CONFIGID            REG32(NRF51_FICR_BASE + 0x05C)
#define NRF51_FICR_DEVICEID(n)         REG32(NRF51_FICR_BASE + 0x060 + ((n)*4))
#define NRF51_FICR_ER(n)               REG32(NRF51_FICR_BASE + 0x080 + ((n)*4))
#define NRF51_FICR_IR(n)               REG32(NRF51_FICR_BASE + 0x090 + ((n)*4))
#define NRF51_FICR_DEVICEADDRTYPE      REG32(NRF51_FICR_BASE + 0x0A0)
#define NRF51_FICR_DEVICEADDR(n)       REG32(NRF51_FICR_BASE + 0x0A4 + ((n)*4))
#define NRF51_FICR_OVERRIDEEN          REG32(NRF51_FICR_BASE + 0x0AC)
#define NRF51_FICR_BLE_1MBIT(n)        REG32(NRF51_FICR_BASE + 0x0EC + ((n)*4))

/* DEVICEADDRTYPE */
#define NRF51_FICR_DEVICEADDRTYPE_RANDOM      1

/* OVERRIDEEN */
#define NRF51_FICR_OVERRIDEEN_NRF_BIT_N       1
#define NRF51_FICR_OVERRIDEEN_BLE_BIT_N       8

/*
 * UICR
 */
#define NRF51_UICR_BASE                0x10001000
#define NRF51_UICR_CLENR0              REG32(NRF51_UICR_BASE + 0x000)
#define NRF51_UICR_RBPCONF             REG32(NRF51_UICR_BASE + 0x004)
#define NRF51_UICR_XTALFREQ            REG32(NRF51_UICR_BASE + 0x008)
#define NRF51_UICR_FWID                REG32(NRF51_UICR_BASE + 0x010)
#define NRF51_UICR_FWID_CUSTOMER(n)    REG32(NRF51_UICR_BASE + 0x080 + ((n)*4))

#define NRF51_UICR_XTALFREQ_16MHZ      0xFF
#define NRF51_UICR_XTALFREQ_32MHZ      0x00

/*
 * Devices
 */

/*
 *  Power
 */
#define NRF51_POWER_BASE    0x40000000
/* Tasks */
#define NRF51_POWER_CONSTLAT  REG32(NRF51_POWER_BASE + 0x078)
#define NRF51_POWER_LOWPWR    REG32(NRF51_POWER_BASE + 0x07C)
/* Events */
#define NRF51_POWER_POFWARN   REG32(NRF51_POWER_BASE + 0x108)
/* Registers */
#define NRF51_POWER_INTENSET  REG32(NRF51_POWER_BASE + 0x304)
#define NRF51_POWER_INTENCLR  REG32(NRF51_POWER_BASE + 0x308)
#define NRF51_POWER_RESETREAS REG32(NRF51_POWER_BASE + 0x400)
#define NRF51_POWER_SYSTEMOFF REG32(NRF51_POWER_BASE + 0x500)
#define NRF51_POWER_POFCON    REG32(NRF51_POWER_BASE + 0x510)
#define NRF51_POWER_GPREGRET  REG32(NRF51_POWER_BASE + 0x51C)
#define NRF51_POWER_RAMON     REG32(NRF51_POWER_BASE + 0x524)
#define NRF51_POWER_RESET     REG32(NRF51_POWER_BASE + 0x544)
#define NRF51_POWER_DCDCEN    REG32(NRF51_POWER_BASE + 0x578)

#define NRF51_POWER_RESETREAS_RESETPIN          0x00001
#define NRF51_POWER_RESETREAS_DOG               0x00002
#define NRF51_POWER_RESETREAS_SREQ              0x00004
#define NRF51_POWER_RESETREAS_LOCKUP            0x00008
#define NRF51_POWER_RESETREAS_OFF               0x10000
#define NRF51_POWER_RESETREAS_LPCOMP            0x20000
#define NRF51_POWER_RESETREAS_DIF               0x40000


/*
 *  Clock
 */
#define NRF51_CLOCK_BASE    0x40000000
/* Tasks */
#define NRF51_CLOCK_HFCLKSTART REG32(NRF51_CLOCK_BASE + 0x000)
#define NRF51_CLOCK_HFCLKSTOP  REG32(NRF51_CLOCK_BASE + 0x004)
#define NRF51_CLOCK_LFCLKSTART REG32(NRF51_CLOCK_BASE + 0x008)
#define NRF51_CLOCK_LFCLKSTOP  REG32(NRF51_CLOCK_BASE + 0x00C)
#define NRF51_CLOCK_CAL     REG32(NRF51_CLOCK_BASE + 0x010)
#define NRF51_CLOCK_CTSTART REG32(NRF51_CLOCK_BASE + 0x014)
#define NRF51_CLOCK_CTSTOP  REG32(NRF51_CLOCK_BASE + 0x018)
/* Events */
#define NRF51_CLOCK_HFCLKSTARTED REG32(NRF51_CLOCK_BASE + 0x100)
#define NRF51_CLOCK_LFCLKSTARTED REG32(NRF51_CLOCK_BASE + 0x104)
#define NRF51_CLOCK_DONE    REG32(NRF51_CLOCK_BASE + 0x10C)
#define NRF51_CLOCK_CCTO    REG32(NRF51_CLOCK_BASE + 0x110)
/* Registers */
#define NRF51_CLOCK_INTENSET  REG32(NRF51_CLOCK_BASE + 0x304)
#define NRF51_CLOCK_INTENCLR  REG32(NRF51_CLOCK_BASE + 0x308)
#define NRF51_CLOCK_HFCLKSTAT REG32(NRF51_CLOCK_BASE + 0x40C)
#define NRF51_CLOCK_LFCLKSTAT REG32(NRF51_CLOCK_BASE + 0x418)
#define NRF51_CLOCK_LFCLKSRC  REG32(NRF51_CLOCK_BASE + 0x518)
#define NRF51_CLOCK_CTIV      REG32(NRF51_CLOCK_BASE + 0x538)
#define NRF51_CLOCK_XTALFREQ  REG32(NRF51_CLOCK_BASE + 0x550)

/*
 *  Radio
 */
#define NRF51_RADIO_BASE    0x40001000
/* Tasks */
#define NRF51_RADIO_TXEN      REG32(NRF51_RADIO_BASE + 0x000)
#define NRF51_RADIO_RXEN      REG32(NRF51_RADIO_BASE + 0x004)
#define NRF51_RADIO_START     REG32(NRF51_RADIO_BASE + 0x008)
#define NRF51_RADIO_STOP      REG32(NRF51_RADIO_BASE + 0x00C)
#define NRF51_RADIO_DISABLE   REG32(NRF51_RADIO_BASE + 0x010)
#define NRF51_RADIO_RSSISTART REG32(NRF51_RADIO_BASE + 0x014)
#define NRF51_RADIO_RSSISTOP  REG32(NRF51_RADIO_BASE + 0x018)
#define NRF51_RADIO_BCSTART   REG32(NRF51_RADIO_BASE + 0x01C)
#define NRF51_RADIO_BCSTOP    REG32(NRF51_RADIO_BASE + 0x020)
/* Events */
#define NRF51_RADIO_READY     REG32(NRF51_RADIO_BASE + 0x100)
#define NRF51_RADIO_ADDRESS   REG32(NRF51_RADIO_BASE + 0x104)
#define NRF51_RADIO_PAYLOAD   REG32(NRF51_RADIO_BASE + 0x108)
#define NRF51_RADIO_END       REG32(NRF51_RADIO_BASE + 0x10C)
#define NRF51_RADIO_DISABLED  REG32(NRF51_RADIO_BASE + 0x110)
#define NRF51_RADIO_DEVMATCH  REG32(NRF51_RADIO_BASE + 0x114)
#define NRF51_RADIO_DEVMISS   REG32(NRF51_RADIO_BASE + 0x118)
#define NRF51_RADIO_RSSIEND   REG32(NRF51_RADIO_BASE + 0x11C)
#define NRF51_RADIO_BCMATCH   REG32(NRF51_RADIO_BASE + 0x128)
/* Registers */
#define NRF51_RADIO_SHORTS      REG32(NRF51_RADIO_BASE + 0x200)
#define NRF51_RADIO_INTENSET    REG32(NRF51_RADIO_BASE + 0x304)
#define NRF51_RADIO_INTENCLR    REG32(NRF51_RADIO_BASE + 0x308)
#define NRF51_RADIO_CRCSTATUS   REG32(NRF51_RADIO_BASE + 0x400)
#define NRF51_RADIO_RXMATCH     REG32(NRF51_RADIO_BASE + 0x408)
#define NRF51_RADIO_RXCRC       REG32(NRF51_RADIO_BASE + 0x40C)
#define NRF51_RADIO_DAI         REG32(NRF51_RADIO_BASE + 0x410)
#define NRF51_RADIO_PACKETPTR   REG32(NRF51_RADIO_BASE + 0x504)
#define NRF51_RADIO_FREQUENCY   REG32(NRF51_RADIO_BASE + 0x508)
#define NRF51_RADIO_TXPOWER     REG32(NRF51_RADIO_BASE + 0x50C)
#define NRF51_RADIO_MODE        REG32(NRF51_RADIO_BASE + 0x510)
#define NRF51_RADIO_PCNF0       REG32(NRF51_RADIO_BASE + 0x514)
#define NRF51_RADIO_PCNF1       REG32(NRF51_RADIO_BASE + 0x518)
#define NRF51_RADIO_BASE0       REG32(NRF51_RADIO_BASE + 0x51C)
#define NRF51_RADIO_BASE1       REG32(NRF51_RADIO_BASE + 0x520)
#define NRF51_RADIO_PREFIX0     REG32(NRF51_RADIO_BASE + 0x524)
#define NRF51_RADIO_PREFIX1     REG32(NRF51_RADIO_BASE + 0x528)
#define NRF51_RADIO_TXADDRESS   REG32(NRF51_RADIO_BASE + 0x52C)
#define NRF51_RADIO_RXADDRESSES REG32(NRF51_RADIO_BASE + 0x530)
#define NRF51_RADIO_CRCCNF      REG32(NRF51_RADIO_BASE + 0x534)
#define NRF51_RADIO_CRCPOLY     REG32(NRF51_RADIO_BASE + 0x538)
#define NRF51_RADIO_CRCINIT     REG32(NRF51_RADIO_BASE + 0x53C)
#define NRF51_RADIO_TEST        REG32(NRF51_RADIO_BASE + 0x540)
#define NRF51_RADIO_TIFS        REG32(NRF51_RADIO_BASE + 0x544)
#define NRF51_RADIO_RSSISAMPLE  REG32(NRF51_RADIO_BASE + 0x548)
/* NRF51_RADIO_STATE (0x550) is Broken (PAN 2.4) */
#define NRF51_RADIO_DATAWHITEIV REG32(NRF51_RADIO_BASE + 0x554)
#define NRF51_RADIO_BCC         REG32(NRF51_RADIO_BASE + 0x560)
#define NRF51_RADIO_DAB(n)      REG32(NRF51_RADIO_BASE + 0x600 + ((n) * 4))
#define NRF51_RADIO_DAP(n)      REG32(NRF51_RADIO_BASE + 0x620 + ((n) * 4))
#define NRF51_RADIO_DACNF       REG32(NRF51_RADIO_BASE + 0x640)
#define NRF51_RADIO_OVERRIDE(n) REG32(NRF51_RADIO_BASE + 0x724 + ((n) * 4))
#define NRF51_RADIO_POWER       REG32(NRF51_RADIO_BASE + 0xFFC)

/* Shorts */
#define NRF51_RADIO_SHORTS_READY_START                0x001
#define NRF51_RADIO_SHORTS_END_DISABLE                0x002
#define NRF51_RADIO_SHORTS_DISABLED_TXEN              0x004
#define NRF51_RADIO_SHORTS_DISABLED_RXEN              0x008
#define NRF51_RADIO_SHORTS_ADDRESS_RSSISTART          0x010
/* NRF51_RADIO_SHORTS_END_START (0x20) is Broken (PAN 2.4) */
#define NRF51_RADIO_SHORTS_ADDRESS_BCSTART            0x040
#define NRF51_RADIO_SHORTS_DISABLED_RSSISTOP          0x100

/* For RADIO.INTEN bits */
#define NRF51_RADIO_READY_BIT                         0
#define NRF51_RADIO_ADDRESS_BIT                       1
#define NRF51_RADIO_PAYLOAD_BIT                       2
#define NRF51_RADIO_END_BIT                           3
#define NRF51_RADIO_DISABLED_BIT                      4
#define NRF51_RADIO_DEVMATCH_BIT                      5
#define NRF51_RADIO_DEVMISS_BIT                       6
#define NRF51_RADIO_RSSIEND_BIT                       7
#define NRF51_RADIO_BCMATCH_BIT                       10

/* CRC Status */
#define NRF51_RADIO_CRCSTATUS_OK                      0x1

/* Frequency (in MHz) */
#define NRF51_RADIO_FREQUENCY_VAL(x)                  ((x) - 2400)

/* TX Power */
#define NRF51_RADIO_TXPOWER_POS_4_DBM                 0x04
#define NRF51_RADIO_TXPOWER_0_DBM                     0x00
#define NRF51_RADIO_TXPOWER_NEG_8_DBM                 0xFC
#define NRF51_RADIO_TXPOWER_NEG_12_DBM                0xF8
#define NRF51_RADIO_TXPOWER_NEG_16_DBM                0xF4
#define NRF51_RADIO_TXPOWER_NEG_20_DBM                0xEC
#define NRF51_RADIO_TXPOWER_NEG_30_DBM                0xD8

/* TX Mode */
#define NRF51_RADIO_MODE_BLE_1MBIT                    0x03

/*
 * PCNF0 and PCNF1 Packet Configuration
 *
 * The radio unpacks the packet for you according to these settings.
 *
 * The on-air format is:
 *
 * |_Preamble_|___Base___|_Prefix_|___S0____|_Length_,_S1_|__Payload__|___|
 * 0           <ba_bytes> <1 byte><s0_bytes>   <1 byte>    <max_bytes> <extra>
 *
 * The in-memory format is
 *
 * uint8_t s0[s0_bytes];
 * uint8_t length;
 * uint8_t s1;
 * uint8_t payload[max_bytes];
 *
 * lf_bits is how many bits to store in length
 * s1_bits is how many bits to store in s1
 *
 * If any one of these lengths are set to zero, the field is omitted in memory.
 */

#define NRF51_RADIO_PCNF0_LFLEN_SHIFT                 0
#define NRF51_RADIO_PCNF0_S0LEN_SHIFT                 8
#define NRF51_RADIO_PCNF0_S1LEN_SHIFT                 16

#define NRF51_RADIO_PCNF0_VAL(lf_bits, s0_bytes, s1_bits) \
	((lf_bits) << NRF51_RADIO_PCNF0_LFLEN_SHIFT | \
	 (s0_bytes) << NRF51_RADIO_PCNF0_S0LEN_SHIFT | \
	 (s1_bits) << NRF51_RADIO_PCNF0_S1LEN_SHIFT)

#define NRF51_RADIO_PCNF1_MAXLEN_SHIFT                0
#define NRF51_RADIO_PCNF1_STATLEN_SHIFT               8
#define NRF51_RADIO_PCNF1_BALEN_SHIFT                 16
#define NRF51_RADIO_PCNF1_ENDIAN_BIG                  0x1000000
#define NRF51_RADIO_PCNF1_WHITEEN                     0x2000000

#define NRF51_RADIO_PCNF1_VAL(max_bytes, extra_bytes, ba_bytes, whiten) \
	((max_bytes) << NRF51_RADIO_PCNF1_MAXLEN_SHIFT | \
	 (extra_bytes) << NRF51_RADIO_PCNF1_STATLEN_SHIFT | \
	 (ba_bytes) << NRF51_RADIO_PCNF1_BALEN_SHIFT | \
	 ((whiten) ? NRF51_RADIO_PCNF1_WHITEEN : 0))

/* PREFIX0 */
#define NRF51_RADIO_PREFIX0_AP0_SHIFT                 0
#define NRF51_RADIO_PREFIX0_AP1_SHIFT                 8
#define NRF51_RADIO_PREFIX0_AP2_SHIFT                 16
#define NRF51_RADIO_PREFIX0_AP3_SHIFT                 24

/* PREFIX1 */
#define NRF51_RADIO_PREFIX1_AP4_SHIFT                 0
#define NRF51_RADIO_PREFIX1_AP5_SHIFT                 8
#define NRF51_RADIO_PREFIX1_AP6_SHIFT                 16
#define NRF51_RADIO_PREFIX1_AP7_SHIFT                 24

/* CRCCNF */
#define NRF51_RADIO_CRCCNF_SKIP_ADDR                  0x100

/* TEST */
#define NRF51_RADIO_TEST_CONST_CARRIER_EN             0x01
#define NRF51_RADIO_TEST_PLL_LOCK_EN                  0x02

/* STATE */
#define NRF51_RADIO_STATE_DISABLED                    0
#define NRF51_RADIO_STATE_RXRU                        1
#define NRF51_RADIO_STATE_RXIDLE                      2
#define NRF51_RADIO_STATE_RX                          3
#define NRF51_RADIO_STATE_RXDISABLE                   4
#define NRF51_RADIO_STATE_TXRU                        9
#define NRF51_RADIO_STATE_TXIDLE                      10
#define NRF51_RADIO_STATE_TX                          11
#define NRF51_RADIO_STATE_TXDISABLE                   12

/* DACNF */
#define NRF51_RADIO_DACNF_ENA(n)                      (1 << (n))
#define NRF51_RADIO_DACNF_MAX                         8
#define NRF51_RADIO_DACNF_TXADD(n)                    (1 << ((n)+8))
#define NRF51_RADIO_TXADD_MAX                         8

/* OVERRIDE4 */
#define NRF51_RADIO_OVERRIDE_EN                       BIT(31)


/*
 *  UART
 */
#define NRF51_UART_BASE     0x40002000
/* Tasks */
#define NRF51_UART_STARTRX  REG32(NRF51_UART_BASE + 0x000)
#define NRF51_UART_STOPRX   REG32(NRF51_UART_BASE + 0x004)
#define NRF51_UART_STARTTX  REG32(NRF51_UART_BASE + 0x008)
#define NRF51_UART_STOPTX   REG32(NRF51_UART_BASE + 0x00C)
/* Events */
#define NRF51_UART_RXDRDY   REG32(NRF51_UART_BASE + 0x108)
#define NRF51_UART_TXDRDY   REG32(NRF51_UART_BASE + 0x11C)
#define NRF51_UART_ERROR    REG32(NRF51_UART_BASE + 0x124)
#define NRF51_UART_RXTO     REG32(NRF51_UART_BASE + 0x144)
/* Registers */
#define NRF51_UART_INTENSET REG32(NRF51_UART_BASE + 0x304)
#define NRF51_UART_INTENCLR REG32(NRF51_UART_BASE + 0x308)
#define NRF51_UART_ERRORSRC REG32(NRF51_UART_BASE + 0x480)
#define NRF51_UART_ENABLE   REG32(NRF51_UART_BASE + 0x500)
#define NRF51_UART_PSELRTS  REG32(NRF51_UART_BASE + 0x508)
#define NRF51_UART_PSELTXD  REG32(NRF51_UART_BASE + 0x50C)
#define NRF51_UART_PSELCTS  REG32(NRF51_UART_BASE + 0x510)
#define NRF51_UART_PSELRXD  REG32(NRF51_UART_BASE + 0x514)
#define NRF51_UART_RXD      REG32(NRF51_UART_BASE + 0x518)
#define NRF51_UART_TXD      REG32(NRF51_UART_BASE + 0x51C)
#define NRF51_UART_BAUDRATE REG32(NRF51_UART_BASE + 0x524)
#define NRF51_UART_CONFIG   REG32(NRF51_UART_BASE + 0x56C)
/* For UART.INTEN bits */
#define NRF55_UART_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_UART_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  TWI (I2C) Instances
 */
#define NRF51_TWI_BASE(port)     (0x40003000 + ((port == 0) ? 0 : 0x1000))
/* Tasks */
#define NRF51_TWI_STARTRX(port)   REG32(NRF51_TWI_BASE(port) + 0x000)
#define NRF51_TWI_STARTTX(port)   REG32(NRF51_TWI_BASE(port) + 0x008)
#define NRF51_TWI_STOP(port)      REG32(NRF51_TWI_BASE(port) + 0x014)
#define NRF51_TWI_SUSPEND(port)   REG32(NRF51_TWI_BASE(port) + 0x01C)
#define NRF51_TWI_RESUME(port)    REG32(NRF51_TWI_BASE(port) + 0x020)
/* Events */
#define NRF51_TWI_STOPPED(port)   REG32(NRF51_TWI_BASE(port) + 0x104)
#define NRF51_TWI_RXDRDY(port)    REG32(NRF51_TWI_BASE(port) + 0x108)
#define NRF51_TWI_TXDSENT(port)   REG32(NRF51_TWI_BASE(port) + 0x11C)
#define NRF51_TWI_ERROR(port)     REG32(NRF51_TWI_BASE(port) + 0x124)
#define NRF51_TWI_BB(port)        REG32(NRF51_TWI_BASE(port) + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI_INTEN(port)     REG32(NRF51_TWI_BASE(port) + 0x300)
#define NRF51_TWI_INTENSET(port)  REG32(NRF51_TWI_BASE(port) + 0x304)
#define NRF51_TWI_INTENCLR(port)  REG32(NRF51_TWI_BASE(port) + 0x308)
#define NRF51_TWI_ERRORSRC(port)  REG32(NRF51_TWI_BASE(port) + 0x4C4)
#define NRF51_TWI_ENABLE(port)    REG32(NRF51_TWI_BASE(port) + 0x500)
#define NRF51_TWI_PSELSCL(port)   REG32(NRF51_TWI_BASE(port) + 0x508)
#define NRF51_TWI_PSELSDA(port)   REG32(NRF51_TWI_BASE(port) + 0x50C)
#define NRF51_TWI_RXD(port)       REG32(NRF51_TWI_BASE(port) + 0x518)
#define NRF51_TWI_TXD(port)       REG32(NRF51_TWI_BASE(port) + 0x51C)
#define NRF51_TWI_FREQUENCY(port) REG32(NRF51_TWI_BASE(port) + 0x524)
#define NRF51_TWI_ADDRESS(port)   REG32(NRF51_TWI_BASE(port) + 0x588)
#define NRF51_TWI_POWER(port)     REG32(NRF51_TWI_BASE(port) + 0xFFC)

#define NRF51_TWI_100KBPS         0x01980000
#define NRF51_TWI_250KBPS         0x40000000
#define NRF51_TWI_400KBPS         0x06680000

#define NRF51_TWI_ENABLE_VAL      0x5
#define NRF51_TWI_DISABLE_VAL     0x0

#define NRF51_TWI_ERRORSRC_ANACK  BIT(1) /* Address NACK */
#define NRF51_TWI_ERRORSRC_DNACK  BIT(2) /* Data NACK */

/*
 *  TWI (I2C) Instance 0
 */
#define NRF51_TWI0_BASE     0x40003000
/* Tasks */
#define NRF51_TWI0_STARTRX   REG32(NRF51_TWI0_BASE + 0x000)
#define NRF51_TWI0_STARTTX   REG32(NRF51_TWI0_BASE + 0x008)
#define NRF51_TWI0_STOP      REG32(NRF51_TWI0_BASE + 0x014)
#define NRF51_TWI0_SUSPEND   REG32(NRF51_TWI0_BASE + 0x01C)
#define NRF51_TWI0_RESUME    REG32(NRF51_TWI0_BASE + 0x020)
/* Events */
#define NRF51_TWI0_STOPPED   REG32(NRF51_TWI0_BASE + 0x104)
#define NRF51_TWI0_RXDRDY    REG32(NRF51_TWI0_BASE + 0x108)
#define NRF51_TWI0_TXDSENT   REG32(NRF51_TWI0_BASE + 0x11C)
#define NRF51_TWI0_ERROR     REG32(NRF51_TWI0_BASE + 0x124)
#define NRF51_TWI0_BB        REG32(NRF51_TWI0_BASE + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI0_INTENSET  REG32(NRF51_TWI0_BASE + 0x304)
#define NRF51_TWI0_INTENCLR  REG32(NRF51_TWI0_BASE + 0x308)
#define NRF51_TWI0_ERRORSRC  REG32(NRF51_TWI0_BASE + 0x4C4)
#define NRF51_TWI0_ENABLE    REG32(NRF51_TWI0_BASE + 0x500)
#define NRF51_TWI0_PSELSCL   REG32(NRF51_TWI0_BASE + 0x508)
#define NRF51_TWI0_PSELSDA   REG32(NRF51_TWI0_BASE + 0x50C)
#define NRF51_TWI0_RXD       REG32(NRF51_TWI0_BASE + 0x518)
#define NRF51_TWI0_TXD       REG32(NRF51_TWI0_BASE + 0x51C)
#define NRF51_TWI0_FREQUENCY REG32(NRF51_TWI0_BASE + 0x524)
#define NRF51_TWI0_ADDRESS   REG32(NRF51_TWI0_BASE + 0x588)

/* For TWI0.INTEN bits */
#define NRF55_TWI0_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_TWI0_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  TWI (I2C) Instance 1
 */
#define NRF51_TWI1_BASE     0x40004000
/* Tasks */
#define NRF51_TWI1_STARTRX   REG32(NRF51_TWI1_BASE + 0x000)
#define NRF51_TWI1_STARTTX   REG32(NRF51_TWI1_BASE + 0x008)
#define NRF51_TWI1_STOP      REG32(NRF51_TWI1_BASE + 0x014)
#define NRF51_TWI1_SUSPEND   REG32(NRF51_TWI1_BASE + 0x01C)
#define NRF51_TWI1_RESUME    REG32(NRF51_TWI1_BASE + 0x020)
/* Events */
#define NRF51_TWI1_STOPPED   REG32(NRF51_TWI1_BASE + 0x104)
#define NRF51_TWI1_RXDRDY    REG32(NRF51_TWI1_BASE + 0x108)
#define NRF51_TWI1_TXDSENT   REG32(NRF51_TWI1_BASE + 0x11C)
#define NRF51_TWI1_ERROR     REG32(NRF51_TWI1_BASE + 0x124)
#define NRF51_TWI1_BB        REG32(NRF51_TWI1_BASE + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI1_INTENSET  REG32(NRF51_TWI1_BASE + 0x304)
#define NRF51_TWI1_INTENCLR  REG32(NRF51_TWI1_BASE + 0x308)
#define NRF51_TWI1_ERRORSRC  REG32(NRF51_TWI1_BASE + 0x4C4)
#define NRF51_TWI1_ENABLE    REG32(NRF51_TWI1_BASE + 0x500)
#define NRF51_TWI1_PSELSCL   REG32(NRF51_TWI1_BASE + 0x508)
#define NRF51_TWI1_PSELSDA   REG32(NRF51_TWI1_BASE + 0x50C)
#define NRF51_TWI1_RXD       REG32(NRF51_TWI1_BASE + 0x518)
#define NRF51_TWI1_TXD       REG32(NRF51_TWI1_BASE + 0x51C)
#define NRF51_TWI1_FREQUENCY REG32(NRF51_TWI1_BASE + 0x524)
#define NRF51_TWI1_ADDRESS   REG32(NRF51_TWI1_BASE + 0x588)

/* For TWI1.INTEN bits */
#define NRF55_TWI1_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_TWI1_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  GPIOTE - GPIO Tasks and Events
 */
#define NRF51_GPIOTE_BASE   0x40006000
/* Tasks */
#define NRF51_GPIOTE_OUT(n)    REG32(NRF51_GPIOTE_BASE + ((n) * 4))
/* Events */
#define NRF51_GPIOTE_IN(n)     REG32(NRF51_GPIOTE_BASE + 0x100 + ((n) * 4))
#define NRF51_GPIOTE_PORT      REG32(NRF51_GPIOTE_BASE + 0x17C)
/* Registers */
#define NRF51_GPIOTE_INTENSET  REG32(NRF51_GPIOTE_BASE + 0x304)
#define NRF51_GPIOTE_INTENCLR  REG32(NRF51_GPIOTE_BASE + 0x308)
#define NRF51_GPIOTE_CONFIG(n) REG32(NRF51_GPIOTE_BASE + 0x510 + ((n) * 4))
#define NRF51_GPIOTE_POWER     REG32(NRF51_GPIOTE_BASE + 0xFFC)

/* Number of IN events */
#define NRF51_GPIOTE_IN_COUNT  4

/* Bits */
/* For GPIOTE.INTEN */
#define NRF51_GPIOTE_IN_BIT(n) (n)
#define NRF51_GPIOTE_PORT_BIT  31
/* For GPIOTE.CONFIG */
#define NRF51_GPIOTE_MODE_DISABLED     (0<<0)
#define NRF51_GPIOTE_MODE_EVENT        BIT(0)
#define NRF51_GPIOTE_MODE_TASK         (3<<0)
#define NRF51_GPIOTE_PSEL_POS          (8)
#define NRF51_GPIOTE_POLARITY_LOTOHI   BIT(16)
#define NRF51_GPIOTE_POLARITY_HITOLO   (2<<16)
#define NRF51_GPIOTE_POLARITY_TOGGLE   (3<<16)
#define NRF51_GPIOTE_OUTINIT_LOW       (0<<20)
#define NRF51_GPIOTE_OUTINIT_HIGH      BIT(20)

/*
 *  Timer / Counter
 */
#define NRF51_TIMER0_BASE   0x40008000
#define NRF51_TIMER_BASE(n)   (NRF51_TIMER0_BASE + (n) * 0x1000)
#define NRF51_PERID_TIMER(n)  (NRF51_PERID_TIMER0 + (n))
/* Tasks */
#define NRF51_TIMER_START(n)  REG32(NRF51_TIMER_BASE(n) + 0x000)
#define NRF51_TIMER_STOP(n)   REG32(NRF51_TIMER_BASE(n) + 0x004)
#define NRF51_TIMER_COUNT(n)  REG32(NRF51_TIMER_BASE(n) + 0x008)
#define NRF51_TIMER_CLEAR(n)  REG32(NRF51_TIMER_BASE(n) + 0x00C)
#define NRF51_TIMER_CAPTURE(n, c)  REG32(NRF51_TIMER_BASE(n) + 0x040 + 4 * (c))
/* Events */
#define NRF51_TIMER_COMPARE(n, c)  REG32(NRF51_TIMER_BASE(n) + 0x140 + 4 * (c))
/* Registers */
#define NRF51_TIMER_SHORTCUT(n)  REG32(NRF51_TIMER_BASE(n) + 0x200)
#define NRF51_TIMER_INTENSET(n)  REG32(NRF51_TIMER_BASE(n) + 0x304)
#define NRF51_TIMER_INTENCLR(n)  REG32(NRF51_TIMER_BASE(n) + 0x308)
#define NRF51_TIMER_MODE(n)      REG32(NRF51_TIMER_BASE(n) + 0x504)
#define NRF51_TIMER_BITMODE(n)   REG32(NRF51_TIMER_BASE(n) + 0x508)
#define NRF51_TIMER_PRESCALER(n) REG32(NRF51_TIMER_BASE(n) + 0x510)
#define NRF51_TIMER_CC(n, c)     REG32(NRF51_TIMER_BASE(n) + 0x540 + 4 * (c))
/* For Timer.INTEN bits */
#define NRF51_TIMER_COMPARE_BIT(n)  (((0x140 - 0x100) / 4) + (n))
/* For Timer Shortcuts */
#define NRF51_TIMER_COMPARE_CLEAR(n)  (1 << (n))
#define NRF51_TIMER_COMPARE_STOP(n)   (1 << (8 + (n)))
/* Timer Mode (NRF51_TIMER_MODE) */
#define NRF51_TIMER_MODE_TIMER   0  /* reset default */
#define NRF51_TIMER_MODE_COUNTER 1
/* Prescaler */
#define NRF51_TIMER_PRESCALER_MASK (0xf)  /* range: 0-9, reset default: 4 */
/* Bit length (NRF51_TIMER_BITMODE) */
#define NRF51_TIMER_BITMODE_16  0  /* reset default */
#define NRF51_TIMER_BITMODE_8   1
#define NRF51_TIMER_BITMODE_24  2
#define NRF51_TIMER_BITMODE_32  3


/*
 *  Random Number Generator (RNG)
 */
#define NRF51_RNG_BASE               0x4000D000
/* Tasks */
#define NRF51_RNG_START              REG32(NRF51_RNG_BASE + 0x000)
#define NRF51_RNG_STOP               REG32(NRF51_RNG_BASE + 0x004)
/* Events */
#define NRF51_RNG_VALRDY             REG32(NRF51_RNG_BASE + 0x100)
/* Registers */
#define NRF51_RNG_SHORTS             REG32(NRF51_RNG_BASE + 0x200)
#define NRF51_RNG_INTENSET           REG32(NRF51_RNG_BASE + 0x304)
#define NRF51_RNG_INTENCLR           REG32(NRF51_RNG_BASE + 0x308)
#define NRF51_RNG_CONFIG             REG32(NRF51_RNG_BASE + 0x504)
#define NRF51_RNG_VALUE              REG32(NRF51_RNG_BASE + 0x508)
/* For RNG Shortcuts */
#define NRF51_RNG_SHORTS_VALRDY_STOP BIT(0)
/* For RNG Config */
#define NRF51_RNG_DERCEN             BIT(0)


/*
 *  Watchdog Timer (WDT)
 */
#define NRF51_WDT_BASE        0x40010000
/* Tasks */
#define NRF51_WDT_START       REG32(NRF51_WDT_BASE + 0x000)
/* Events */
#define NRF51_WDT_TIMEOUT     REG32(NRF51_WDT_BASE + 0x100)
/* Registers */
#define NRF51_WDT_INTENSET    REG32(NRF51_WDT_BASE + 0x304)
#define NRF51_WDT_INTENCLR    REG32(NRF51_WDT_BASE + 0x308)
#define NRF51_WDT_RUNSTATUS   REG32(NRF51_WDT_BASE + 0x400)
#define NRF51_WDT_REQSTATUS   REG32(NRF51_WDT_BASE + 0x404)
#define NRF51_WDT_CRV         REG32(NRF51_WDT_BASE + 0x504)
#define NRF51_WDT_RREN        REG32(NRF51_WDT_BASE + 0x508)
#define NRF51_WDT_CONFIG      REG32(NRF51_WDT_BASE + 0x50C)
#define NRF51_WDT_RR(n)       REG32(NRF51_WDT_BASE + 0x600 + ((n) * 4))
#define NRF51_WDT_POWER       REG32(NRF51_WDT_BASE + 0xFFC)
/* Bitfields */
#define NRF51_WDT_RUNSTATUS_RUNNING        1
#define NRF51_WDT_REQSTATUS_BIT(n)        (1<<(n))
#define NRF51_WDT_RREN_BIT(n)             (1<<(n))
#define NRF51_WDT_CONFIG_SLEEP_PAUSE       0
#define NRF51_WDT_CONFIG_SLEEP_RUN         1
#define NRF51_WDT_CONFIG_HALT_PAUSE       (0<<4)
#define NRF51_WDT_CONFIG_HALT_RUN         BIT(4)

#define NRF51_WDT_RELOAD_VAL             0x6E524635


/*
 *  GPIO
 */
#define NRF51_GPIO_BASE     0x50000000
#define NRF51_GPIO0_BASE    (NRF51_GPIO_BASE + 0x500)
#define NRF51_GPIO0_OUT     REG32(NRF51_GPIO0_BASE + 0x004)
#define NRF51_GPIO0_OUTSET  REG32(NRF51_GPIO0_BASE + 0x008)
#define NRF51_GPIO0_OUTCLR  REG32(NRF51_GPIO0_BASE + 0x00C)
#define NRF51_GPIO0_IN      REG32(NRF51_GPIO0_BASE + 0x010)
#define NRF51_GPIO0_DIR     REG32(NRF51_GPIO0_BASE + 0x014)  /* 1 for output */
#define NRF51_GPIO0_DIRSET  REG32(NRF51_GPIO0_BASE + 0x018)
#define NRF51_GPIO0_DIRCLR  REG32(NRF51_GPIO0_BASE + 0x01C)
#define NRF51_PIN_BASE      (NRF51_GPIO_BASE + 0x700)
#define NRF51_PIN_CNF(n)    REG32(NRF51_PIN_BASE + ((n) * 4))
#define GPIO_0              NRF51_GPIO0_BASE

#define NRF51_PIN_CNF_DIR_INPUT        (0)
#define NRF51_PIN_CNF_DIR_OUTPUT       (1)
#define NRF51_PIN_CNF_INPUT_CONNECT    (0<<1)
#define NRF51_PIN_CNF_INPUT_DISCONNECT BIT(1)
#define NRF51_PIN_CNF_PULL_DISABLED    (0<<2)
#define NRF51_PIN_CNF_PULLDOWN         BIT(2)
#define NRF51_PIN_CNF_PULLUP           (3<<2)
/*
 * Logic levels 0 and 1, strengths S=Standard, H=High D=Disconnect
 * for example, S0D1 = Standard drive 0, disconnect on 1
 */
#define NRF51_PIN_CNF_DRIVE_S0S1       (0<<8)
#define NRF51_PIN_CNF_DRIVE_H0S1       BIT(8)
#define NRF51_PIN_CNF_DRIVE_S0H1       (2<<8)
#define NRF51_PIN_CNF_DRIVE_H0H1       (3<<8)
#define NRF51_PIN_CNF_DRIVE_D0S1       (4<<8)
#define NRF51_PIN_CNF_DRIVE_D0H1       (5<<8)
#define NRF51_PIN_CNF_DRIVE_S0D1       (6<<8)
#define NRF51_PIN_CNF_DRIVE_H0D1       (7<<8)

#define NRF51_PIN_CNF_SENSE_DISABLED   (0<<16)
#define NRF51_PIN_CNF_SENSE_HIGH       (2<<16)
#define NRF51_PIN_CNF_SENSE_LOW        (3<<16)

#define DUMMY_GPIO_BANK     GPIO_0  /* for UNIMPLEMENTED() macro */

#define NRF51_PPI_BASE                 0x4001F000
#define NRF51_PPI_CHEN                 REG32(NRF51_PPI_BASE + 0x500)
#define NRF51_PPI_CHENSET              REG32(NRF51_PPI_BASE + 0x504)
#define NRF51_PPI_CHENCLR              REG32(NRF51_PPI_BASE + 0x508)
#define NRF51_PPI_EEP(channel)         REG32(NRF51_PPI_BASE + 0x510 + channel*8)
#define NRF51_PPI_TEP(channel)         REG32(NRF51_PPI_BASE + 0x514 + channel*8)
#define NRF51_PPI_CHG(group)           REG32(NRF51_PPI_BASE + 0x800 + group*4)

#define NRF51_PPI_NUM_PROGRAMMABLE_CHANNELS        16
#define NRF51_PPI_NUM_GROUPS                       4

#define NRF51_PPI_CH_TIMER0_CC0__RADIO_TXEN        20
#define NRF51_PPI_CH_TIMER0_CC0__RADIO_RXEN        21
#define NRF51_PPI_CH_TIMER0_CC1__RADIO_DISABLE     22
#define NRF51_PPI_CH_RADIO_BCMATCH__AAR_START      23
#define NRF51_PPI_CH_RADIO_READY__CCM_KSGEN        24
#define NRF51_PPI_CH_RADIO_ADDR__CCM_CRYPT         25
#define NRF51_PPI_CH_RADIO_ADDR__TIMER0CC1         26
#define NRF51_PPI_CH_RADIO_END_TIMER0CC2           27
#define NRF51_PPI_CH_RTC0_COMPARE0__RADIO_TXEN     28
#define NRF51_PPI_CH_RTC0_COMPARE0__RADIO_RXEN     29
#define NRF51_PPI_CH_RTC0_COMPARE0__TIMER0_CLEAR   30
#define NRF51_PPI_CH_RTC0_COMPARE0__TIMER0_START   31

#define NRF51_PPI_CH_FIRST NRF51_PPI_CH_TIMER0_CC0__RADIO_TXEN
#define NRF51_PPI_CH_LAST  NRF51_PPI_CH_RTC0_COMPARE0__TIMER0_START


/* These will be defined in their respective functions if/when they are used. */
#define NRF51_SPI0_BASE       0x40003000
#define NRF51_SPI0_PSELSCK    REG32(NRF51_SPI0_BASE + 0x508)
#define NRF51_SPI0_PSELMOSI   REG32(NRF51_SPI0_BASE + 0x50C)
#define NRF51_SPI0_PSELMISO   REG32(NRF51_SPI0_BASE + 0x510)
#define NRF51_SPI1_BASE       0x40004000
#define NRF51_SPI1_PSELSCK    REG32(NRF51_SPI1_BASE + 0x508)
#define NRF51_SPI1_PSELMOSI   REG32(NRF51_SPI1_BASE + 0x50C)
#define NRF51_SPI1_PSELMISO   REG32(NRF51_SPI1_BASE + 0x510)
#define NRF51_SPIS1_BASE      0x40004000
#define NRF51_SPIS1_PSELSCK   REG32(NRF51_SPIS1_BASE + 0x508)
#define NRF51_SPIS1_PSELMISO  REG32(NRF51_SPIS1_BASE + 0x50C)
#define NRF51_SPIS1_PSELMOSI  REG32(NRF51_SPIS1_BASE + 0x510)
#define NRF51_SPIS1_PSELCSN   REG32(NRF51_SPIS1_BASE + 0x514)
#define NRF51_QDEC_BASE       0x40012000
#define NRF51_QDEC_PSELLED    REG32(NRF51_QDEC_BASE + 0x51C)
#define NRF51_QDEC_PSELA      REG32(NRF51_QDEC_BASE + 0x520)
#define NRF51_QDEC_PSELB      REG32(NRF51_QDEC_BASE + 0x524)
#define NRF51_LPCOMP_BASE     0x40013000
#define NRF51_LPCOMP_PSEL     REG32(NRF51_LPCOMP_BASE + 0x504)

#endif /* __CROS_EC_REGISTERS_H */

