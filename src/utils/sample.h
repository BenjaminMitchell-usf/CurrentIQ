#ifndef SAMPLE_H
#define SAMPLE_H

#include <stdint.h>

typedef struct {
    uint32_t timestamp;    // Timestamp in milliseconds
    
    // Sensor data fields
    float accel_x;         // Accelerometer X axis
    float accel_y;         // Accelerometer Y axis  
    float accel_z;         // Accelerometer Z axis
    
    float gyro_x;          // Gyroscope X axis
    float gyro_y;          // Gyroscope Y axis
    float gyro_z;          // Gyroscope Z axis
    
    float mag_x;           // Magnetometer X axis
    float mag_y;           // Magnetometer Y axis
    float mag_z;           // Magnetometer Z axis
    
    float pressure;        // Pressure in hPa
    float temperature;     // Temperature in Celsius
    float depth;           // Depth in meters
} sample_t;

#endif // SAMPLE_H