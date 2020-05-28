#if !defined(MAIN_HEADER)
#define MAIN_HEADER

#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "Sensors.hpp"

#define LED 2 //!< Onboard LED for signalizing

/**
 *  @brief Use it to initialize variables, pin modes, start using libraries, etc. 
 * The setup() function will only run once
 */
void setup(){

}

/**
 * @brief Use it to actively control the board.
 * After creating a setup() function, which initializes and sets the initial values, 
 * the loop() function does precisely what its name suggests, and loops consecutively, 
 * allowing your program to change and respond.
 */
void loop(){

}

/**
 * @brief  Function passed into another function as an argument, 
 * Is then invoked inside the outer function to complete some kind of routine or action.
 * @param topic mqtt topic of the received message
 * @param payload message body, e.g. text or JSON
 * @param length size of payload in bytes
 */
void callback(char* topic, byte* payload, unsigned int length);

/**
 * @brief Will create a new session and update the `id` to the new authenticated id
 *  After roughly X seconds, an authenticated session will time-out.
 *  Also, a connection made with snapshot will be disconnected after it is used once.
 * @param id
 */
void reconnect(int id);

/**
 * @brief This method opens a new MQTT connection to the specified broker
 * The connection is made asynchronously, and any function 
 * will be called whether the attempt succeeds or fails.
 */
void connectmqtt();

/**
 * @brief Send sensor data over mqtt to specific topic.
 * 
 * @see sensorDataToJson()
 * @param data data to be sent
 * @param topic MQTT topic to publish to
 */
void mqttSendSensorData(SensorData &data, char * topic);

/**
 * @brief Prepare JSON document containing sensor data.
 * @param data data to be sent
 * @param topic MQTT topic to publish to
 */
DynamicJsonDocument sensorDataToJson(SensorData &data);

#endif // MAIN_HEADER
