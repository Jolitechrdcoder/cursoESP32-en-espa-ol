#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>



#define led0 2 // define del gpio que usaremos
#define encendio 1
#define apagado 0
void app_main() {
// config gpio 
gpio_set_direction(led0,GPIO_MODE_OUTPUT);

while(1){
gpio_set_level(led0,encendio);
vTaskDelay(1000/portTICK_PERIOD_MS);// delay en milisegundois
gpio_set_level(led0,apagado); //estado del gpio 
vTaskDelay(1000/portTICK_PERIOD_MS);

}

printf("hello desde esp32\n");


}