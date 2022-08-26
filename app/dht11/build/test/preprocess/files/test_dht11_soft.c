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

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT) ;

}













 void test_data_sensor_rx_buffer(void) {

    uint8_t data_get_sensor_dht11[5] ;

    uint8_t data_sensor_simulate[5] ={

        22, 2,

        3, 4,

        5} ;

    gpio_init_CMockIgnore() ;

    read_buffer_dht11_CMockExpectAnyArgs(79) ;

    read_buffer_dht11_CMockReturnMemThruPtr_buffer(80, data_sensor_simulate, 5) ;

    init_dht11(8) ;

    read_dht11() ;

    get_buffer_rx(data_get_sensor_dht11) ;

    UnityAssertEqualIntArray(( const void*)((data_sensor_simulate)), ( const void*)((data_get_sensor_dht11)), (UNITY_UINT32)((5)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT8, UNITY_ARRAY_TO_ARRAY) ;

}









void test_temperatura_humedad_dato_leido_sensor(void){

    float temperatura = 22.22 ;

    float humedad = 22.22 ;

    uint8_t data_sensor_simulate[5] ;

    data_sensor_simulate[0] = 22 ;

    data_sensor_simulate[1] = 22 ;

    data_sensor_simulate[2] = 22 ;

    data_sensor_simulate[3] = 22 ;

    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1]

                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ;



    dht11_t data_sensor ;

    read_buffer_dht11_CMockExpectAnyArgs(102) ;

    read_buffer_dht11_CMockReturnMemThruPtr_buffer(103, data_sensor_simulate, 5) ;

    read_dht11() ;

    data_sensor = read_sensor_data() ;

    UnityAssertEqualNumber((UNITY_INT)((temperatura)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((humedad)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((data_sensor.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT) ;



}
