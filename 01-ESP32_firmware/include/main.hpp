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
 * 
 */
void setup();

/**
 * 
 */
void loop();

/**
 * 
 */
void callback(char* topic, byte* payload, unsigned int length);

/**
 * 
 */
void reconnect();

/**
 * 
 */
void connectmqtt();

/**
 * Send sensor data over mqtt to specific topic.
 * 
 * @see sensorDataToJson()
 * @param data data to be sent
 * @param topic MQTT topic to publish to
 */
void mqttSendSensorData(SensorData &data, char * topic);

/**
 * Prepare JSON document containing sensor data.
 * @param data data to be sent
 * @param topic MQTT topic to publish to
 */
DynamicJsonDocument sensorDataToJson(SensorData &data);

#endif // MAIN_HEADER
