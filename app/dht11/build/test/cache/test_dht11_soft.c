#include "test/config_test_dht11.h"
#include "inc/dht11.h"
#include "build/test/mocks/mock_manage_read_dht11.h"
#include "build/test/mocks/mock_gpio.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






extern uint8_t pin_number_dht_11;





void input_buffer_test(uint8_t *buffer,uint8_t pos0,uint8_t pos1,uint8_t pos2,uint8_t pos3,

                                                                                          _Bool 

                                                                                               crc){

    buffer[0] = pos0 ;

    buffer[1] = pos1 ;

    buffer[2] = pos2 ;

    buffer[3] = pos3 ;

    if (crc == 

              1

                  ){

        buffer[4] = buffer[0]+buffer[1]+buffer[2]+buffer[3];

    }else buffer[4] =(uint8_t ) (rand()%255) ;

}







void funcion_response_read_buffer_dht11_array(uint8_t *buffer) {

    read_buffer_dht11_CMockExpectAnyArgs(56) ;

    read_buffer_dht11_CMockReturnMemThruPtr_buffer(57, buffer, 5) ;



}







void setUp(void) {

    gpio_init_CMockIgnore() ;

}





void test_seleccion_de_gpio_biblioteca_dht11(void) {





    init_dht11(8) ;

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((8)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT) ;

}













 void test_data_sensor_rx_buffer(void) {

    uint8_t data_get_sensor_dht11[5] ;

    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 22,

                        2,3,4,

                                                                 1 

                                                                      ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    init_dht11(8) ;

    read_dht11() ;

    get_buffer_rx(data_get_sensor_dht11) ;

    UnityAssertEqualIntArray(( const void*)((data_sensor_simulate)), ( const void*)((data_get_sensor_dht11)), (UNITY_UINT32)((5)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT8, UNITY_ARRAY_TO_ARRAY) ;

}









void test_temperatura_humedad_dato_leido_sensor(void){

    dht11_t data_sensor ;

    float temperatura = 22.22 ;

    float humedad = 22.22;

    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 22 ,22

                        ,22 ,22 ,

                                                      1 

                                                           ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    data_sensor = read_sensor_data() ;

    UnityAssertEqualNumber((UNITY_INT)((temperatura)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((humedad)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((data_sensor.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT) ;



}







void test_cambiar_lectura_de_temperatura_humedad(void) {

    dht11_t data_sensor ;

    float primera_temperatura = 22.22 ;

    float primera_humedad = 22.22 ;

    float segunda_temperatura = 44.55 ;

    float segunda_humedad = 25.33 ;



    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 22,22,

                        22,22,

                                                     1 

                                                          ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    data_sensor = read_sensor_data() ;

    input_buffer_test(data_sensor_simulate, 25,33,

                     44,55,

                                                  1 

                                                       ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;



    read_dht11() ;

    data_sensor = read_sensor_data() ;



    UnityAssertEqualNumber((UNITY_INT)((segunda_temperatura)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((segunda_humedad)), (UNITY_INT)((data_sensor.humedad)), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((data_sensor.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_INT) ;



}











void test_dato_crc_incorrecto_mantener_valor(void){



    dht11_t data_sensor ;

    float temperatura_crc_correcto = 22.22 ;

    float humedad_crc_correcto = 22.22 ;





    float temperatura_crc_incorrecto = 25.33;

    float humedad_crc_incorrecto = 44.55 ;

    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 22,22,

    22,22,

                                 1 

                                      ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    data_sensor = read_sensor_data() ;

    input_buffer_test(data_sensor_simulate, 25,33,

    44,55,

                                 0 

                                       ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    data_sensor = read_sensor_data() ;

    UnityAssertEqualNumber((UNITY_INT)((temperatura_crc_correcto)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((humedad_crc_correcto)), (UNITY_INT)((data_sensor.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((data_sensor.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(165), UNITY_DISPLAY_STYLE_INT) ;

}





void test_transformar_temperatura_a_kelvin(void){

    float temperatura = 22.22 ;

    float temp_kelvin = temperatura + 273.15 ;

    float temp_kelvin_dht_transform ;

    float humedad = 22.22 ;

    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 22,22,

    22,22,

                               1 

                                    ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    temp_kelvin_dht_transform = get_temperature_kelvin() ;

    UnityAssertEqualNumber((UNITY_INT)((temp_kelvin)), (UNITY_INT)((temp_kelvin_dht_transform)), (

   ((void *)0)

   ), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_INT) ;

}







void test_leer_temperatura_dht11(void){

    float temperature_sensor_data = 44.55 ;

    float temperature_read ;

    uint8_t data_sensor_simulate[5] ;

    input_buffer_test(data_sensor_simulate, 25 ,33 ,

    44 ,55 ,

                                 1 

                                      ) ;

    funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;

    read_dht11() ;

    temperature_read = get_temperature() ;

    UnityAssertEqualNumber((UNITY_INT)((temperature_read)), (UNITY_INT)((temperature_sensor_data)), (

   ((void *)0)

   ), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_INT) ;



}







void test_leer_humedad_dht11(void){

    float humedad_read_sensor = 25.33 ;

    float humedad_read ;

    uint8_t data_sensor_simulate[5] ;

   input_buffer_test(data_sensor_simulate, 25 ,33 ,

    44 ,55 ,

                                 1 

                                      ) ;

     funcion_response_read_buffer_dht11_array(data_sensor_simulate ) ;



    read_dht11() ;

    humedad_read = get_humidity() ;

    UnityAssertEqualNumber((UNITY_INT)((humedad_read)), (UNITY_INT)((humedad_read_sensor)), (

   ((void *)0)

   ), (UNITY_UINT)(210), UNITY_DISPLAY_STYLE_INT) ;



}





void test_ultima_lectura_correcta_incorrecta(void){

    float temperatura_1 = 33.22 ;

    float temperatura_2 = 22.67 ;

    float humedad_1 = 15.21 ;

    float humedad_2 = 15.45 ;

    dht11_t medida_1;

    dht11_t medida_2;

    dht11_t medida_3;



    uint8_t data_sensor_1[5] ;

    uint8_t data_sensor_2[5] ;

    uint8_t data_sensor_3[5] ;

    input_buffer_test(data_sensor_1,15,21 ,

    33,22,

                                 1 

                                      ) ;

    input_buffer_test(data_sensor_2,15,45 ,

    22,67,

                                 1 

                                      ) ;

    input_buffer_test(data_sensor_3,25,33 ,

    44,55,

                                 0 

                                       ) ;



    funcion_response_read_buffer_dht11_array(data_sensor_1 ) ;

    read_dht11() ;

    medida_1 = read_sensor_data() ;

    funcion_response_read_buffer_dht11_array(data_sensor_2 ) ;



    read_dht11() ;

    medida_2 = read_sensor_data() ;

    funcion_response_read_buffer_dht11_array(data_sensor_3 ) ;

    read_dht11() ;

    medida_3 = read_sensor_data() ;



    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((medida_1.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(245), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((medida_2.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(246), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((medida_3.last_is_correct)), (

   ((void *)0)

   ), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((humedad_2)), (UNITY_INT)((medida_3.humedad)), (

   ((void *)0)

   ), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_INT) ;

    UnityAssertEqualNumber((UNITY_INT)((temperatura_2)), (UNITY_INT)((medida_3.temperatura)), (

   ((void *)0)

   ), (UNITY_UINT)(249), UNITY_DISPLAY_STYLE_INT) ;







}
