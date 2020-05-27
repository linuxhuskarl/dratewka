#if !defined(MQSENSOR)
#define MQSENSOR

#include <cstdint>

/**
 * MQ-7 and MQ-135 sensors driver class.
 */
class MQSensor
{
private:
    uint8_t analogPin;
    uint8_t enablePin;
public:
    
    /**
     * Constructor
     * @param analogPin
     * @param enablePin
     */
    MQSensor(uint8_t analogPin, uint8_t enablePin);
    
    /**
     * Destructor
     */
    ~MQSensor();

    /**
     * Function enables MQSensor for a specific period of time
     * @param time - parameter desribing time of enabling MQSensor
     */
    void enable(int time);

    /**
     * Function disables MQSensor
     */
    void disable();
    
    /**
     * getValue function
     * Function returning float as a reasult of operation getValue.
     * @param a - first argument 
     * @param b - second argument 
     */
    float getValue(int a, int b);
};


#endif // MQSENSOR
