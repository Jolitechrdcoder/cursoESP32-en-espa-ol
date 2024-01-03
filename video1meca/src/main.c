#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>



#define led0 2 // define del gpio que usaremos
#define boton 18 
#define encendio 1
#define apagado 0
void app_main() {
// config gpio 
gpio_set_direction(led0,GPIO_MODE_OUTPUT);
gpio_set_direction(boton,GPIO_MODE_INPUT);
// resistencia  pull up 
gpio_set_pull_mode(boton,GPIO_PULLUP_ONLY);


while(1){
     int statutsbtn = gpio_get_level(boton);
     printf("Estatus:%d\n", statutsbtn);
    if(!statutsbtn){
        gpio_set_level(led0,encendio);
    }
    else{

      gpio_set_level(led0,apagado); //estado del gpio 
    }



vTaskDelay(200/portTICK_PERIOD_MS);

}

}