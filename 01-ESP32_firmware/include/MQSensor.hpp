#if !defined(MQSENSOR)
#define MQSENSOR

#include <cstdint>

/**
 * MQ-7 and MQ-135 sensors driver class.
 */
class MQSensor ///< MQSensor class \date $Date: 2020/05/20 14:16:20 $
{
private:
    uint8_t analogPin;  
    uint8_t enablePin; 
public:
    
    /**
     * @brief Constructor
     * @param analogPin 
     * @param enablePin
     */
    MQSensor(uint8_t analogPin, uint8_t enablePin);
    
    /**
     * Destructor 
     */
    ~MQSensor();

    /**
     * @brief Function enables MQSensor for a specific period of time
     * @param time - parameter desribing time of enabling MQSensor
     */
    void enable(int time);

    /**
     * Function disables MQSensor
     */
    void disable();
    
    /**
     * @brief getValue function
     * Function returning float as a reasult of operation getValue.
     * @param a - first argument 
     * @param b - second argument 
     */
    float getValue(int a, int b);
};


#endif // MQSENSOR
