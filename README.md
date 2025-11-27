# Wio E5 Mini Firmware

This project contains the firmware scaffold for the Seeed Wio E5 Mini (STM32WLE5JC) development board using PlatformIO with the Arduino framework.

## Hardware

- **Board**: Seeed Wio E5 Mini
- **MCU**: STM32WLE5JC (ARM Cortex-M4, 48MHz)
- **Framework**: Arduino
- **Serial Speed**: 115200 baud

## Prerequisites

### 1. Install PlatformIO

#### Option A: Using pipx (Recommended)
```bash
pipx install platformio
```

#### Option B: Using pip (if pipx is not available)
```bash
pip install --break-system-packages platformio
```

### 2. Install USB Drivers

For the Wio E5 Mini, you may need to install the STM32 USB driver:

- **Windows**: Download and install [STM32 Virtual COM Port Driver](https://www.st.com/en/development-tools/stsw-stm32102.html)
- **macOS**: Usually works out of the box with built-in drivers
- **Linux**: Usually works out of the box. If not, install `modemmanager`:
  ```bash
  sudo apt install modemmanager
  ```

### 3. Board Selection

The project is configured for the `lora_e5_mini` board in PlatformIO.

## Project Structure

```
├── src/
│   ├── main.cpp           # Main application entry point
│   ├── drivers/           # Hardware-specific drivers
│   └── utils/
│       └── sample.h       # Shared data structure definitions
├── include/
│   └── config.h           # Configuration parameters
├── analysis/              # Data analysis and processing
├── docs/                  # Documentation
├── lib/                   # Project-specific libraries
├── test/                  # Unit tests
└── platformio.ini         # PlatformIO configuration
```

## Building and Uploading

### 1. Build the Firmware

```bash
pio run
```

### 2. Upload to Board

Connect the Wio E5 Mini to your computer via USB, then:

```bash
pio run -t upload
```

### 3. Monitor Serial Output

```bash
pio device monitor
```

Or specify the baud rate explicitly:
```bash
pio device monitor -b 115200
```

## Version 0 Toolchain Verification

The initial firmware performs basic verification of the toolchain:

### Expected Behavior

1. **LED Blink**: The onboard LED should blink at 1 Hz (500ms on, 500ms off)
2. **Serial Output**: A structured banner should appear on the serial monitor at 115200 baud

### Sample Serial Output

```
========================================
      Wio E5 Mini Firmware v0
========================================
Board: LoRa-E5 mini
Firmware Version: v0.1.0
Build Timestamp: Nov 27 2024 19:36:00
Arduino Framework: 10810
CPU Frequency: 48 MHz
Serial Baud Rate: 115200
========================================
Version 0 Toolchain Verification
LED Blink Test: 1 Hz
Serial Output: Active
========================================
```

## Configuration

Key configuration parameters are defined in `include/config.h`:

- **LED_PIN**: Onboard LED pin definition
- **SERIAL_BAUD_RATE**: Serial communication speed (115200)
- **LOOP_FREQUENCY_HZ**: Main loop frequency
- **Feature Toggles**: Enable/disable various features

## Data Structure

The `sample_t` structure in `src/utils/sample.h` defines the shared data format:

```c
typedef struct {
    uint32_t timestamp;    // Timestamp in milliseconds
    float accel_x, accel_y, accel_z;  // Accelerometer data
    float gyro_x, gyro_y, gyro_z;     // Gyroscope data
    float mag_x, mag_y, mag_z;        // Magnetometer data
    float pressure;       // Pressure in hPa
    float temperature;    // Temperature in Celsius
    float depth;          // Depth in meters
} sample_t;
```

## Troubleshooting

### Upload Issues

1. **Port not found**: Check USB connection and drivers
2. **Permission denied**: On Linux, add user to dialout group:
   ```bash
   sudo usermod -a -G dialout $USER
   ```
3. **Boot mode**: Ensure the board is in bootloader mode if upload fails

### Serial Monitor Issues

1. **No output**: Check baud rate is set to 115200
2. **Garbled text**: Verify correct COM port and baud rate
3. **Port busy**: Close other applications using the COM port

### Build Issues

1. **Missing dependencies**: Run `pio lib install` to install required libraries
2. **Platform update**: Update PlatformIO and platforms:
   ```bash
   pio platform update
   ```

## Development Workflow

1. Make code changes
2. Build: `pio run`
3. Upload: `pio run -t upload`
4. Monitor: `pio device monitor`
5. Iterate

For more advanced usage and debugging, refer to the [PlatformIO documentation](https://docs.platformio.org/).