#include "unity.h" 
#include <stdint.h>
//#include "mock_sio.h"

#include "mock_gpio.h"
#include "mock_manage_read_dht11.h"
#include "dht11.h"

/* Requerimientos sobre el sensor:
  1 - El puerto debe seleccionarse en la inicialización del sensor. EL inicio y finalización del puerto 
      debe hacerse desde la biblioteca
  2 - Leer temperatura y humedad por separado 
  3 - Detectar si es correcta o no la ultima lectura 
  4 - Debe tener una función para devolver los bytes leidos por el sensor para el usuario final de esta biblioteca
  5 - Si una lectura falla, entonces debe mantener la ultima lectura válida 
  6 - Debe teener una función que devuelva temperatura, humedad o ambas 
  7 - La temperatura y humedad debe expresarse en ° C y en %. Se debe adicionar la opción de leer en kelvin 
  8 - Esta biblioteca se debe comunicar con otra que se encuentra en desarrollo, que es la encargada de leer los 
      puertos correspondientes. 
*/ 

/* ****************Lista de test *************************************
 * 1) inicializacion correcta del puerto seleccionado en la biblioteca 
 * 2) Conectarse con el prototipo de función provisto de la biblioteca de comunicación de llenado de buffer
 *      void read_buffer_dht11(port, uint8_t buffer* )(en desarrollo) 
 * 3) Función de devolución de bytes leidos por el hardware 
 * 4) Resolver si el dato es correcta en base al crc debe cambiar el ultimo valor de temp y hum 
 * 5) Resolver el dato si el crc falla, poniendo los flags correspondientes  
 * 6) Transformar temperatura a kelvin 
 * 7) Leer temperatura 
 * 8) Leer humedad  
 * 9) Reconocer si la ultima lectura fue correcta o es el último valor leido correctamente. 
*/
//VARIABLES PARA TEST 1 
#define GPIO_PORT_PIN_TEST_1 8

//VARIABLES PARA TEST 2 
//#define 
extern uint8_t pin_number_dht_11;

void test_seleccion_de_gpio_biblioteca_dht11(void) {
    //gpio_init_Expect(8) ; 
    //gpio_set_dir_Ignore() ; 
    gpio_init_Ignore() ; 
    //gpio_set_inover_ExpectAnyArgs() ; 

    init_dht11(8) ; 
    TEST_ASSERT_EQUAL(8,GPIO_PORT_PIN_TEST_1) ; 
}
//2) Conectarse con el prototipo de función provisto de la biblioteca de comunicación de llenado de buffer
/* mocks encontrados en gpio 
//read_buffer_dht11_ReturnArrayThruPtr_buffer(5,data_sensor_simulate);   
    //read_buffer_dht11_IgnoreArg_gpio() ; 
    //read_buffer_dht11_Expect(8, data_sensor_simulate) ; 
    //read_buffer_dht11_ReturnArrayThruPtr_buffer(data_sensor_simulate, 5) ; 
    //read_buffer_dht11_ExpectWithArray(8,data_sensor_simulate,5 ) ;  
    //read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate,5) ; 
*/



void test_data_sensor_rx_buffer(void) { 
    uint8_t data_sensor_simulate[5] ={0x16,2,3,4,5} ; 
    uint8_t data_get_sensor_dht11[5] ; 
 
    gpio_init_Ignore() ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    init_dht11(8) ;     
    read_dht11()   ; 
    get_buffer_rx(data_get_sensor_dht11) ; 
     TEST_ASSERT_EQUAL_INT8_ARRAY(data_sensor_simulate,data_get_sensor_dht11,5 ) ;
} 