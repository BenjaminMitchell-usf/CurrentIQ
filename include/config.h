#ifndef CONFIG_H
#define CONFIG_H

// Pin definitions for Wio E5 Mini
#define LED_PIN                     LED_BUILTIN  // Onboard LED pin

// Loop timing configuration
#define LOOP_FREQUENCY_HZ           10           // Target loop frequency in Hz
#define LOOP_DELAY_MS               (1000 / LOOP_FREQUENCY_HZ)  // Delay in milliseconds

// Feature toggles
#define ENABLE_SERIAL_OUTPUT        1           // Enable serial debug output
#define ENABLE_LED_BLINK           1           // Enable LED blinking for status indication

// Serial configuration
#define SERIAL_BAUD_RATE           115200       // Serial communication baud rate

// Firmware version information
#define FIRMWARE_VERSION           "v0.1.0"
#define FIRMWARE_NAME              "Wio-E5-Mini-Firmware"

// Sensor configuration placeholders
#define ENABLE_ACCEL_SENSOR        0           // Enable accelerometer sensor
#define ENABLE_GYRO_SENSOR         0           // Enable gyroscope sensor
#define ENABLE_MAG_SENSOR          0           // Enable magnetometer sensor
#define ENABLE_PRESSURE_SENSOR     0           // Enable pressure sensor
#define ENABLE_TEMP_SENSOR         0           // Enable temperature sensor

#endif // CONFIG_H