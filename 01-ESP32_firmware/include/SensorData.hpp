#if !defined(SENSORDATA_HEADER)
#define SENSORDATA_HEADER

#include <cstdint>

/**
 * @brief Data structure containing all measurements from sensors.
 * A Struct object contains a value for each attribute of the structured type that it represents. 
 * By default, an instance of Struct is valid as long as the application has a reference to it.
 * @see Sensors
 */
struct SensorData
{
    uint16_t pm01;      //!< PMS5003 PM1.0 concentration in ug/m3
    uint16_t pm25;      //!< PMS5003 PM2.5 concentration in ug/m3
    uint16_t pm10;      //!< PMS5003 PM10 concentration in ug/m3
    float    tempC;     //!< BME280 temprature in °C
    float    humi;      //!< BME280 humidity in % RH
    uint16_t benzene;   //!< MQ-135 benzene concetration in PPM
    uint16_t ammonia;   //!< MQ-135 ammonia concetration in PPM
    uint16_t monoxide;  //!< MQ-7 carbon monoxide concetrarion in PPM
};

#endif // SENSORDATA_HEADER
