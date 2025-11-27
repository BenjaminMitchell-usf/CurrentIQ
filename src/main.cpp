#include <Arduino.h>
#include "config.h"

void setup() {
    // Initialize Serial communication
    #if ENABLE_SERIAL_OUTPUT
    Serial.begin(SERIAL_BAUD_RATE);
    delay(1000); // Wait for serial to be ready
    #endif
    
    // Initialize LED pin
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    
    // Print structured banner
    #if ENABLE_SERIAL_OUTPUT
    Serial.println();
    Serial.println("========================================");
    Serial.println("      Wio E5 Mini Firmware v0");
    Serial.println("========================================");
    Serial.print("Board: ");
    Serial.println(BOARD_NAME);
    Serial.print("Firmware Version: ");
    Serial.println(FIRMWARE_VERSION);
    Serial.print("Build Timestamp: ");
    Serial.print(__DATE__);
    Serial.print(" ");
    Serial.println(__TIME__);
    Serial.print("Arduino Framework: ");
    Serial.println(ARDUINO);
    Serial.print("CPU Frequency: ");
    Serial.print(F_CPU / 1000000);
    Serial.println(" MHz");
    Serial.print("Serial Baud Rate: ");
    Serial.println(SERIAL_BAUD_RATE);
    Serial.println("========================================");
    Serial.println("Version 0 Toolchain Verification");
    Serial.println("LED Blink Test: 1 Hz");
    Serial.println("Serial Output: Active");
    Serial.println("========================================");
    Serial.println();
    #endif
}

void loop() {
    #if ENABLE_LED_BLINK
    // Blink LED at 1 Hz (500ms on, 500ms off)
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    #else
    delay(1000); // Just wait if LED blink is disabled
    #endif
}