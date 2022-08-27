/**
 * @file dht11.h
 * @author Gaston Valdez (gaston.cb.90@gmail.com)
 * @brief  Biblioteca para leer el sensor dht11 y se comunique con una capa de hardware 
 *         encargada de leer los bytes del sensor 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdint.h>
#include <stdbool.h>

typedef struct { 
    float temperatura ; 
    float humedad ; 
    bool last_is_correct ;    
}dht11_t ;  


void read_dht11() ; 
void init_dht11(uint8_t pin_number_dht_11) ; 
/**
 * @brief debe llamarse luego de invocar a read_dht11
 *        Parsea los bytes que reciben desde el hardware   
 * 
 */
void get_buffer_rx(uint8_t *buffer) ; 


/**
 * @brief devuelve una estructura dht11_t con los valores que lee desde el hardware o la ultima 
 *        lectura correcta. 
 * 
 * @return dht11_t estructura con los valores correspondientes a temperatura y humedad
 */
dht11_t read_sensor_data() ; 
float get_temperature() ; 
float get_humidity() ; 
float get_temperature_kelvin() ; 