#include "build/test/mocks/mock_gpio.h"
#include "build/test/mocks/mock_sio.h"
#include "inc/dht11.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"














extern int pin_number_dht_11;





void test_prueba(void) {

    gpio_init_CMockExpect(16, 8) ;





    init_dht11(8) ;

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((pin_number_dht_11)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT) ;



}



void test_pin_seleccion_inicio_dht11(void){

    test_prueba();

}
