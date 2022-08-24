#include "unity.h" 
#include "dht11.h"
#include "mock_sio.h"
#include "mock_gpio.h"


/// 1) Revisar la inicializacion del puerto en modo output 
/// 2) Revisar si la transformación de bytes recibida desde el timer_event es correcta
/// 3) 
/// 4) 
/// 5) 
extern int pin_number_dht_11;


void test_prueba(void) {
    gpio_init_Expect(8)   ; 
    //gpio_init_IgnoreArg_gpio() ;  
    
    init_dht11(8) ;  
    TEST_ASSERT_EQUAL(8,pin_number_dht_11) ; 

}
//gpio_init()
void test_pin_seleccion_inicio_dht11(void){
    test_prueba(); 
}


//void test_buffer_correcto_temperatura_humedad(void){}