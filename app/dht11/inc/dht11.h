#include <stdint.h>
#include <stdbool.h>

typedef struct { 
    float temperatura ; 
    float humedad ; 
    bool last_is_correct ;    
}dht11_t ;  


void read_dht11() ; 
void init_dht11(uint8_t pin_number_dht_11) ; 
void get_buffer_rx(uint8_t *buffer) ; 
/**
 * @brief debe llamarse luego de invocar a read_dht11
 *         Parsea los bytes que reciben desde el hardware   
 * 
 */
dht11_t read_sensor_data() ; 
