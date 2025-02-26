#ifndef _VARIANT_PMSN_V1_
#define _VARIANT_PMSN_V1_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO // Board uses 32khz crystal for LF

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define PMSN_V1

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

/*
 * SWD
 */
#define USE_SEGGER

/*
 * LED
 */
#define PIN_LED1 (0 + 3) // P0.03
#define LED_BUILTIN PIN_LED1
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1 // State when LED is lit

/*
 * Lora radio
 */
#define SPI_INTERFACES_COUNT 1
#define PIN_SPI_MISO (0 + 24) // P0.24
#define PIN_SPI_MOSI (0 + 13) // P0.13
#define PIN_SPI_SCK (0 + 9) // P0.09
#define PIN_SPI_NSS (32 + 9) // P1.09
#define USE_SX1262
#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_SCK PIN_SPI_SCK
#define LORA_CS PIN_SPI_NSS
#define SX126X_CS PIN_SPI_NSS
#define SX126X_DIO1 (0 + 29) // P0.29
#define SX126X_BUSY (0 + 10) // P0.10
#define SX126X_RESET (0 + 5) // P0.05
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_RXEN RADIOLIB_NC
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

/*
 * GPS
 */
#define GPS_L76K
#define PIN_GPS_RESET (32 + 11) // P1.11 low for > 100ms will reset the L76K
#define GPS_RESET_MODE LOW
#define PIN_GPS_STANDBY (32 + 10) // P1.10 low means allow sleep, high means force wake
// #define PIN_GPS_PPS (0 + 3) // P0.03
#define GPS_TX_PIN (32 + 13) // P1.13 This is for bits going TOWARDS the CPU
#define GPS_RX_PIN (0 + 28) // P0.28 This is for bits going TOWARDS the GPS
#define PIN_SERIAL1_RX GPS_TX_PIN
#define PIN_SERIAL1_TX GPS_RX_PIN
// just required by the code
#define PIN_SERIAL2_RX (32 + 4)
#define PIN_SERIAL2_TX (32 + 6)

/*
 * I2C
 */
#define WIRE_INTERFACES_COUNT 1
#define PIN_WIRE_SDA (0 + 31) // P0.31
#define PIN_WIRE_SCL (0 + 30) // P0.30

/*
 * Battery
 */
#define BATTERY_PIN (0 + 2) // P0.02 Battery ADC
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER (1.73F) // 660K, 1M

#ifdef __cplusplus
}
#endif

#endif
