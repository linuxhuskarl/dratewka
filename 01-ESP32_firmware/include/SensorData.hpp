#if !defined(SENSORDATA_HEADER)
#define SENSORDATA_HEADER

#include <cstdint>

/**
 * @brief Data structure containing all measurements from sensors.
 * A Struct object contains a value for each attribute of the structured type that it represents. 
 * By default, an instance of Struct is valid as long as the application has a reference to it.
 * @see Sensors
 * @param pm01 data to be sent
 * @param pm25 data to be sent
 * @param tempC data to be sent
 * @param humi data to be sent
 * @param benzene data to be sent
 * @param ammonia data to be sent
 * @param monoxide data to be sent
 */
struct SensorData
{
    uint16_t pm01;      //!< PMS5003 PM1.0 concentration in um/m3
    uint16_t pm25;      //!< ...
    uint16_t pm10;      //!< ...
    float    tempC;     //!< BME280 ...
    float    humi;      //!< ...
    uint16_t benzene;   //!< MQ-135 ...
    uint16_t ammonia;   //!< MQ-135 ...
    uint16_t monoxide;  //!< MQ-7 ...
};

#endif // SENSORDATA_HEADER
