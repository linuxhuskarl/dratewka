/**
 * @file MQSensor.hpp
 * 
 * @brief MQSensor class header file for Dratewka ESP32 firmware
 * 
 * @author Weronika Bulińska (fairybu)
 * @author Tomasz Leliwa (Leroy404)
 * @author Szymon Plec (Grafiks11)
 * @author Maciej Brzeski (linuxhuskarl)
 */

#if !defined(MQSENSOR)
#define MQSENSOR

#include <cstdint>

/**
 * @brief MQ-7 and MQ-135 sensors driver class.
 * 
 * It contains all methods needed for working with analog air quality sensors,
 * e.g. MQ-7 monoxide sensor or MQ-135 benzene sensor
 * 
 * @see Sensors
 * @see SensorData
 */
class MQSensor 
{
private:
    uint8_t analogPin; //!< GPIO pin for reading input from sensor
    uint8_t enablePin; //!< GPIO pin for enabling power
public:
    
    /**
     * @brief MQSensor class constructor
     * 
     * @see enable()
     * @see disable()
     * 
     * @param analogPin analog input GPIO pin reading input from sensor
     * @param enablePin digital output (open-drain) GPIO pin for enabling power
     */
    MQSensor(uint8_t analogPin, uint8_t enablePin);
    
    /**
     * MQSensor class destructor
     */
    ~MQSensor();

    /**
     * @brief Enables sensor's power for a specific period of time
     * 
     * @param time - parameter desribing time of enabling MQSensor
     */
    void enable(int time);

    /**
     * Function disables sensor's power
     */
    void disable();
    
    /**
     * @brief Fetch and convert current reading from sensor.
     * 
     * Function returning measured value as a decimal.
     * 
     * @param a first calibration parameter
     * @param b second calibration parameter
     */
    float getValue(float a, float b);
};

#endif // MQSENSOR
