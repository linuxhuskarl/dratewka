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
     * 
     */
    void enable();

    /**
     * 
     */
    void disable();
    
    /**
     * 
     */
    float getValue();
};


#endif // MQSENSOR
