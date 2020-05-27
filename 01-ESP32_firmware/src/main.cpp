#include "main.hpp"

const char* ssid = "........";
const char* password = "........";
const char* mqtt_server = "54.36.99.31";

WiFiClient espClient;
PubSubClient mqttClient(espClient);
Sensors sensors;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  WiFi.begin(ssid, password);
  Serial.println("connected");
  mqttClient.setServer(mqtt_server, 1883);//connecting to mqtt server
  mqttClient.setCallback(callback);
  
  delay(5000);
  connectmqtt();

  sensors.begin();
}

void loop() {
  if (!mqttClient.connected())
  {
    reconnect();
  }

  if (sensors.fetchData())
  {
    digitalWrite(LED, LOW);
    SensorData data = sensors.getSensorData();
    mqttSendSensorData(data, NULL);
    digitalWrite(LED, HIGH);
  }

  mqttClient.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {   //callback includes topic and payload ( from which (topic) the payload is comming)
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  if ((char)payload[0] == 'O' && (char)payload[1] == 'N') //on
  {
    digitalWrite(LED, HIGH);
    Serial.println("on");
    mqttClient.publish("outTopic", "LED turned ON");
  }
  else if ((char)payload[0] == 'O' && (char)payload[1] == 'F' && (char)payload[2] == 'F') //off
  {
    digitalWrite(LED, LOW);
    Serial.println(" off");
    mqttClient.publish("outTopic", "LED turned OFF");
  }
  Serial.println();
}

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (mqttClient.connect("ESP32_clientID")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqttClient.publish("outTopic", "Nodemcu connected to MQTT");
      // ... and resubscribe
      mqttClient.subscribe("inTopic");

    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void connectmqtt()
{
  mqttClient.connect("ESP32_clientID");  // ESP will connect to mqtt broker with clientID
  {
    Serial.println("connected to MQTT");
    // Once connected, publish an announcement...

    // ... and resubscribe
    mqttClient.subscribe("inTopic"); //topic=Demo
    mqttClient.publish("outTopic",  "connected to MQTT");

    if (!mqttClient.connected())
    {
      reconnect();
    }
  }
}
