#include <stdint.h>
typedef struct {
    uint8_t temperature ; 
    uint8_t humidity ; 
}dht11 ; 



void read_dht11() ; 
void init_dht11(uint8_t pin_number_dht_11) ; 
