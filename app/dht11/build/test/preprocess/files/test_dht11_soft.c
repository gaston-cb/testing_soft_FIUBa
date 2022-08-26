#include "inc/dht11.h"
#include "build/test/mocks/mock_manage_read_dht11.h"
#include "build/test/mocks/mock_gpio.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






extern uint8_t pin_number_dht_11;



void test_seleccion_de_gpio_biblioteca_dht11(void) {





    gpio_init_CMockIgnore() ;





    init_dht11(8) ;

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((8)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT) ;

}

void test_data_sensor_rx_buffer(void) {

    uint8_t data_sensor_simulate[5] ={0x16,2,3,4,5} ;

    uint8_t data_get_sensor_dht11[5] ;



    gpio_init_CMockIgnore() ;

    read_buffer_dht11_CMockExpectAnyArgs(67) ;

    read_buffer_dht11_CMockReturnMemThruPtr_buffer(68, data_sensor_simulate, 5) ;





    init_dht11(8) ;



    read_dht11() ;

    get_buffer_rx(data_get_sensor_dht11) ;





    UnityAssertEqualIntArray(( const void*)((data_sensor_simulate)), ( const void*)((data_get_sensor_dht11)), (UNITY_UINT32)((5)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT8, UNITY_ARRAY_TO_ARRAY) ;

}
