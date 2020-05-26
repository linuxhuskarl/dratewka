#if !defined(SENSORS_HEADER)
#define SENSORS_HEADER

#include <PMserial.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "MQSensor.hpp"
#include <SensorData.hpp>

class Sensors
{
private:
    SerialPM * pms; 
    Adafruit_BME280 * bme;
    SensorData * data;
    MQSensor * mq7;
    MQSensor * mq135;
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
     * @return zero if successful
     */
    uint8_t begin();

    /**
     * 
     * @return nonzero if new data is present.
     */
    uint8_t fetchData();

    /**
     * ...
     * 
     * @return struct containing current measurements
     */
    SensorData getSensorData();
};

#endif // SENSORS_HEADER
