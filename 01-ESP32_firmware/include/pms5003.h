#if !defined(PMS5003_HEADER_FILE)
/* PMS5003 driver library */
#define PMS5003_HEADER_FILE

#include <cstdint>

/* Public defines */

/* Public typedefs */

typedef enum {
    PASSIVE,
    ACTIVE
} pms5003_mode_t;

// PMS5003 driver configuration structure.
typedef struct {
    uint8_t uart;
    uint8_t tx;
    uint8_t rx;
    uint8_t set;
    uint8_t reset;
    pms5003_mode_t mode;
} pms5003_config_t;

// PMS5003 return data structure.
typedef struct {
    uint16_t pm010std; // PM1.0 concentration (um/m3) standard particle
    uint16_t pm025std; // PM2.5 concentration (um/m3) standard particle
    uint16_t pm100std; // PM10  concentration (um/m3) standard particle
    uint16_t pm010atm; // PM1.0 concentration (um/m3) under atmospheric env
    uint16_t pm025atm; // PM2.5 concentration (um/m3) under atmospheric env
    uint16_t pm100atm; // PM10  concentration (um/m3) under atmospheric env
    uint16_t part003;  // 0.3 um particle count in 0.1L of air 
    uint16_t part008;  // 0.8 um particle count in 0.1L of air 
    uint16_t part010;  // 1.0 um particle count in 0.1L of air 
    uint16_t part025;  // 2.5 um particle count in 0.1L of air 
    uint16_t part050;  // 5.0 um particle count in 0.1L of air 
    uint16_t part100;  // 10 um  particle count in 0.1L of air 
} pms5003_data_t;

/* Public function definitions */

/**
 * Initialize PMS5003 driver. 
 * 
 * @param config configuration structure
 * @return 0 if initialization was successful
 */
int8_t pms5003_init(pms5003_config_t * config);

/**
 * Fetch data from PMS5003 sensor.
 * 
 * @param data pointer to return data structure
 * @return 0 if fetch was successful
 */
int8_t pms5003_fetch(pms5003_data_t * data);

/**
 * Get default driver config structure.
 * 
 * @param data pointer to return data structure
 * @return 0 if fetch was successful
 */
pms5003_config_t * pms5003_default_config(void);

#endif // PMS5003_HEADER_FILE
