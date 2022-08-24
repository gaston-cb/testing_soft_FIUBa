#include "inc/dht11.h"
#include "mock_manage_read_dht11.h"
#include "mock_gpio.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






extern uint8_t pin_number_dht_11;



void setUp(void){



}





void test_seleccion_de_gpio_biblioteca_dht11(void) {

    gpio_init_CMockExpect(51, 8) ;

    gpio_init_CMockIgnore() ;

    init_dht11(8) ;

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((8)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT) ;



}



uint8_t data_sensor_simulate[5] ={0x16,2,3,4,5} ;



void test_buffer_correcto_temperatura_humedad(void){















}
