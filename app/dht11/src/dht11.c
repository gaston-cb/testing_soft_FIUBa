#include "dht11.h"
#include "manage_read_dht11.h"
#include "string.h"
#ifdef TEST
    #include "gpio.h" 
    #define TESTABLE_STATIC 
#else
    #include "hardware/gpio.h" 
    #define TESTABLE_STATIC static
#endif  
#define BUFFER_SIZE_RECEIVED 40 


uint8_t buffer_rx[5] ; 
TESTABLE_STATIC uint8_t pin_number_dht_11 ; 

void init_dht11(uint8_t number_port){ 
    pin_number_dht_11 = number_port ; 
    gpio_init(pin_number_dht_11) ; 
    //gpio_set_dir(pin_number_dht_11, GPIO_OUT);
}


void read_dht11(){
    read_buffer_dht11(pin_number_dht_11, buffer_rx) ;  
}

void get_buffer_rx(uint8_t *buffer){ 
    memcpy(buffer, buffer_rx,5 ) ; 
} 