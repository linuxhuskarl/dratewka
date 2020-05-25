#include <Arduino.h>
#include "pms5003.h"

/* Global variables */

pms5003_data_t data;

/* Private function definitions */

/**
 * Print data to Serial port.
 * @param data data to be printed
 */
void print_data(pms5003_data_t * data);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.printf("setup: begin\n");

  pms5003_config_t * pmsconfig = pms5003_default_config();
  pmsconfig->mode = PASSIVE;

  int8_t ret = pms5003_init(pmsconfig);

  if(ret != 0)
  {
    Serial.printf("setup: pms5003_init failed, code returned: %d\n", ret);
    Serial.printf("setup: restarting in 5s\n");
    delay(5*1000);
    esp_restart();
  }

  delay(20*1000); // sleep for 20 seconds to allow sensor to collect data.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int8_t ret = pms5003_fetch(&data);
  if(ret != 0)
  {
    Serial.printf("loop: pms5003_fetch failed, code returned: %d\n", ret);
  } else 
  {
    print_data(&data);
  }
  delay(60*1000);
}

void print_data(pms5003_data_t * data) {
  Serial.printf("print_data: placeholder\n");
}