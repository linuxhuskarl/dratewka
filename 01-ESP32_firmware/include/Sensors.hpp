/**
 * @file Sensors.hpp
 * 
 * @brief Sensors class header file for Dratewka ESP32 firmware
 * 
 * @author Weronika Bulińska (fairybu)
 * @author Tomasz Leliwa (Leroy404)
 * @author Szymon Plec (Grafiks11)
 * @author Maciej Brzeski (linuxhuskarl)
 */

#if !defined(SENSORS_HEADER)
#define SENSORS_HEADER

#include <PMserial.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "MQSensor.hpp"
#include "SensorData.hpp"

/**
 * @brief Wrapper class for sensors.
 * 
 * Purpose of this class is to give a level of abstraction to getting values
 * from various sensors. 
 * 
 * @see SensorData
 * @see MQSensor
 */
class Sensors
{
private:
    SerialPM * pms; 
    Adafruit_BME280 * bme;
    SensorData * data;
    MQSensor * mq7;
    MQSensor * mq135;

    int8_t PMS5003_init();
    int8_t BME280_init();
    int8_t MQ135_init();
    int8_t MQ7_init();

public:
    /**
     * Constructor
     */
    Sensors();

    /**
     * Destructor
     */
    ~Sensors();

    /**
     * @brief Initialize sensors and begin collecting data.
     * 
     * Each sensor must be properly initialized before starting measurements.
     * Otherwise, it may show incorrect values.
     * 
     * @see PMS5003_init()
     * @see BME280_init()
     * @see MQ135_init()
     * @see MQ7_init()
     * 
     * @return zero if successful
     */
    uint8_t begin();

    /**
     * @brief Fetch new data from all sensors.
     * 
     * Fetching is required only from time to time, when new data is expected.
     * 
     * @return nonzero if new data is present
     */
    uint8_t fetchData();

    /**
     * @brief Get current readings of sensors.
     * 
     * @return struct containing current measurements
     */
    SensorData getSensorData();
};

#endif // SENSORS_HEADER
