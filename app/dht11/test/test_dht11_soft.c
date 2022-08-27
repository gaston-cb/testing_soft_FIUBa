#include "unity.h" 
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h> ///! numeros aleatorios 
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
 * 1) inicializacion correcta del puerto seleccionado en la biblioteca.
 * 2) Conectarse con el prototipo de función provisto de la biblioteca de comunicación de llenado de buffer
 *      void read_buffer_dht11(port, uint8_t buffer* )(en desarrollo) 
 *     y leer los bytes de devolución de esta biblioteca de hardware 
 * 3) Resolver el valor de temperatura y humedad con el CRC correcto a partir de leer la capa de hardware 
 * 4) Resolver si el dato es correcto en base al crc se debe cambiar el ultimo valor de temp y hum 
 * 5) Resolver el dato si el crc falla, mantener  la ultima lectura correcta
 * 6) Transformar temperatura a kelvin 
 * 7) Leer temperatura 
 * 8) Leer humedad  
 * 9) Reconocer si la ultima lectura fue correcta o es el último valor leido correctamente. 
*/
//VARIABLES PARA TEST 1 
#define GPIO_PORT_PIN_TEST_1 8

//VARIABLES PARA TEST 2 
#define BYTE_0_TEST_2 22
#define BYTE_1_TEST_2  2
#define BYTE_2_TEST_2  3
#define BYTE_3_TEST_2  4 
#define BYTE_4_TEST_2  5 
/// VARIABLES PARA TEST 3 
#define BYTE_0_TEST_3 22
#define BYTE_1_TEST_3  0
#define BYTE_2_TEST_3  40
#define BYTE_3_TEST_3  4 
#define BYTE_4_TEST_3  (BYTE_0_TEST_3 + BYTE_1_TEST_3 + BYTE_2_TEST_3, BYTE_3_TEST_3) ///checksum
/// 


void input_buffer_test(uint8_t *buffer,uint8_t pos0,uint8_t pos1,uint8_t pos2,uint8_t pos3,bool crc){ 
    buffer[0] = pos0 ; 
    buffer[0] = pos0 ; 
    buffer[0] = pos0 ; 
    buffer[0] = pos0 ; 
    if (crc == true){ 
        buffer[4] = buffer[0]+buffer[1]+buffer[2]+buffer[3]; 
    }else buffer[4] =(uint8_t ) (rand()%255) ; 
}

void setUp(void) { 
    gpio_init_Ignore() ; 
    //read_buffer_dht11_ExpectAnyArgs() ; 

    //read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 

} 

extern uint8_t pin_number_dht_11;

void test_seleccion_de_gpio_biblioteca_dht11(void) {
    // gpio_init_Ignore() ; 

    init_dht11(8) ; 
    TEST_ASSERT_EQUAL(8,GPIO_PORT_PIN_TEST_1) ; 
}

/*
 * 2) Conectarse con el prototipo de función provisto de la biblioteca de comunicación de llenado de buffer
 *      void read_buffer_dht11(port, uint8_t buffer* )(en desarrollo) 
 *     y leer los bytes de devolución de esta biblioteca de hardware 
 */
void funcion_test_paramocs(uint8_t *buffer) { 
    read_buffer_dht11_ExpectAnyArgs() ;
    read_buffer_dht11_ReturnMemThruPtr_buffer(buffer, 5) ; 
    
}


 void test_data_sensor_rx_buffer(void) { 
    uint8_t data_get_sensor_dht11[5] ; ///respuesta del sensor copiada desde el mock de return 
    uint8_t data_sensor_simulate[5] ; 
    input_buffer_test(data_sensor_simulate, BYTE_0_TEST_2,
                        BYTE_1_TEST_2,BYTE_2_TEST_2,BYTE_3_TEST_2,true ) ; 
    funcion_test_paramocs(data_sensor_simulate ) ; 
    init_dht11(8) ;     
    read_dht11()   ; 
    get_buffer_rx(data_get_sensor_dht11) ;
    TEST_ASSERT_EQUAL_INT8_ARRAY(data_sensor_simulate,data_get_sensor_dht11,5 ) ;
} 


// * 3) Resolver el valor de temperatura y humedad con el CRC correcto a partir del vector de bytes 
//      recibido por la capa de abstracción 
void test_temperatura_humedad_dato_leido_sensor(void){ 
    float temperatura = 22.22 ; 
    float humedad = 22.22 ;  
    uint8_t data_sensor_simulate[5] ; /// temperatura: 22.22°c , humedad : 22.22 %(VER DATASHEET) 
    data_sensor_simulate[0] = 22 ; 
    data_sensor_simulate[1] = 22 ; 
    data_sensor_simulate[2] = 22 ; 
    data_sensor_simulate[3] = 22 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
    
    dht11_t data_sensor ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    data_sensor = read_sensor_data() ; 
    TEST_ASSERT_EQUAL(temperatura, data_sensor.temperatura) ; 
    TEST_ASSERT_EQUAL(humedad, data_sensor.temperatura) ; 
    TEST_ASSERT_EQUAL(true,data_sensor.last_is_correct ) ; 

}


// * 4) Resolver si el dato es correcto en base al crc se debe cambiar el ultimo valor de temp y hum 
void test_cambiar_lectura_de_temperatura_humedad(void) { 
    float primera_temperatura = 22.22 ; 
    float primera_humedad = 22.22 ; 
    float segunda_temperatura = 44.55 ; 
    float segunda_humedad = 25.33 ; 
    
    uint8_t data_sensor_simulate[5] ; /// temperatura: 22.22°c , humedad : 22.22 %(VER DATASHEET) 
    data_sensor_simulate[0] = 22 ; 
    data_sensor_simulate[1] = 22 ; 
    data_sensor_simulate[2] = 22 ; 
    data_sensor_simulate[3] = 22 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
    dht11_t data_sensor ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    data_sensor = read_sensor_data() ;  /// identico al test anterior 
    
    data_sensor_simulate[0] = 25 ; 
    data_sensor_simulate[1] = 33 ; 
    data_sensor_simulate[2] = 44 ; 
    data_sensor_simulate[3] = 55 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1]
        +  data_sensor_simulate[2] + data_sensor_simulate[3]  ) ; ///!crc incorrecto  
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    data_sensor = read_sensor_data() ;  /// identico al test anterior 
   
    TEST_ASSERT_EQUAL(segunda_temperatura, data_sensor.temperatura) ; 
    TEST_ASSERT_EQUAL(segunda_humedad, data_sensor.humedad) ; 
    TEST_ASSERT_EQUAL(true,data_sensor.last_is_correct ) ; 

}




///!  *  * 5) Resolver el dato si el crc falla, mantener  la ultima lectura correcta
void test_dato_crc_incorrecto_mantener_valor(void){
    ///! primer valor de temperatura y humedad correcto: 
    float temperatura_crc_correcto = 22.22 ;
    float humedad_crc_correcto = 22.22 ;  
    // se cambiaron los valores ya que al realizar otra medición es mas probable que cambien 
    // los parametros y el CRC sea invalido.
    float temperatura_crc_incorrecto = 25.33 ;     
    float humedad_crc_incorrecto = 44.55 ;  

    uint8_t data_sensor_simulate[5] ; /// temperatura: 22.22°c , humedad : 22.22 %(VER DATASHEET) 
    data_sensor_simulate[0] = 22 ; 
    data_sensor_simulate[1] = 22 ; 
    data_sensor_simulate[2] = 22 ; 
    data_sensor_simulate[3] = 22 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
    dht11_t data_sensor ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    data_sensor = read_sensor_data() ;  /// identico al test anterior 
    
    data_sensor_simulate[0] = 25 ; 
    data_sensor_simulate[1] = 33 ; 
    data_sensor_simulate[2] = 44 ; 
    data_sensor_simulate[3] = 55 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1]) ; ///!crc incorrecto  
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    data_sensor = read_sensor_data() ;  /// identico al test anterior 
   
    TEST_ASSERT_EQUAL(temperatura_crc_correcto, data_sensor.temperatura) ; 
    TEST_ASSERT_EQUAL(humedad_crc_correcto, data_sensor.temperatura) ; 
    TEST_ASSERT_EQUAL(false,data_sensor.last_is_correct ) ; 
}

/// * 6) Transformar temperatura a kelvin 
void test_transformar_temperatura_a_kelvin(void){ 
    float temperatura = 22.22 ; 
    float temp_kelvin = temperatura + 273.15 ; ///! form_conv: T(°C) + 273.15 = T[K]  
    float temp_kelvin_dht_transform ; 
    float humedad = 22.22 ; 
    uint8_t data_sensor_simulate[5] ; /// temperatura: 22.22°c , humedad : 22.22 %(VER DATASHEET) 
    data_sensor_simulate[0] = 22 ; 
    data_sensor_simulate[1] = 22 ; 
    data_sensor_simulate[2] = 22 ; 
    data_sensor_simulate[3] = 22 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware -- uso de mocks 
    temp_kelvin_dht_transform = get_temperature_kelvin() ; 
    TEST_ASSERT_EQUAL(temp_kelvin, temp_kelvin_dht_transform)  ; 
}


/// * 7) Leer temperatura 
void test_leer_temperatura_dht11(void){
    float temperature_sensor_data = 44.55 ; 
    float temperature_read ; 
    uint8_t data_sensor_simulate[5] ; 
    data_sensor_simulate[0] = 25 ; 
    data_sensor_simulate[1] = 33 ; 
    data_sensor_simulate[2] = 44 ; 
    data_sensor_simulate[3] = 55 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
     read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware  
    temperature_read = get_temperature() ; 
    TEST_ASSERT_EQUAL(temperature_read, temperature_sensor_data) ; 

}


// * 8) Leer humedad  
void test_leer_humedad_dht11(void){
    float humedad_read_sensor = 25.33 ; 
    float humedad_read ; 
    uint8_t data_sensor_simulate[5] ; 
    data_sensor_simulate[0] = 25 ; 
    data_sensor_simulate[1] = 33 ; 
    data_sensor_simulate[2] = 44 ; 
    data_sensor_simulate[3] = 55 ; 
    data_sensor_simulate[4] = ( data_sensor_simulate[0] + data_sensor_simulate[1] 
                                + data_sensor_simulate[2] + data_sensor_simulate[3]) ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_simulate, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware  
    humedad_read = get_humidity() ; 
    TEST_ASSERT_EQUAL(humedad_read, humedad_read_sensor) ; 

}

// * 9) Reconocer si la ultima lectura fue correcta o es el último valor leido correctamente. 
void test_ultima_lectura_correcta_incorrecta(void){ 
    float temperatura_1 = 33.22 ; 
    float temperatura_2 = 22.67 ; 
    float humedad_1 = 15.21 ; 
    float humedad_2 = 15.45 ; 
    dht11_t medida_1; 
    dht11_t medida_2; 
    dht11_t medida_3; 

    uint8_t data_sensor_1[5] = { 
        15,21, 33, 22 , (15+21+33+22)
    } ; 
    uint8_t data_sensor_2[5] = { 
        15,45,22,67 ,(15+45+22+67)
    } ; 
    uint8_t data_sensor_3[5] = { 
        15,45,22,67 ,(15)  
    } ; 
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_1, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware  
    medida_1 = read_sensor_data() ;
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_2, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware  
    medida_2 = read_sensor_data() ;
    read_buffer_dht11_ExpectAnyArgs() ; 
    read_buffer_dht11_ReturnMemThruPtr_buffer(data_sensor_3, 5) ; 
    read_dht11()   ;  ///! se comunica con la capa de hardware  
    medida_3 = read_sensor_data() ;

    TEST_ASSERT_EQUAL(true,medida_1.last_is_correct) ; 
    TEST_ASSERT_EQUAL(true,medida_2.last_is_correct) ; 
    TEST_ASSERT_EQUAL(false,medida_3.last_is_correct) ; 
    TEST_ASSERT_EQUAL(humedad_2,medida_3.humedad) ; 
    TEST_ASSERT_EQUAL(temperatura_2,medida_3.temperatura) ; 



}