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
     * Each sensor must be properly initialized before starting measurements.
     * Otherwise, it may show incorrect measurments.
     * @return zero if successful
     */
    uint8_t begin(){
        PMS5003_init();
        BME280_init();
        MQ135_init();
        MQ7_init();
    };

    /**
     * 
     * @return nonzero if new data is present
     */
    uint8_t fetchData();

    /**
     * @brief Download measurements.
     * 
     * @return struct containing current measurements
     */
    SensorData getSensorData();
};

#endif // SENSORS_HEADER
