#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<driver/gpio.h>



#define led1 2 // define del gpio que usaremos
#define led2 18

#define GPIO_OUT ((1ULL<<led1)|(1ULL<<led2))




void app_main() 
{
printf("Estamos configurando los GPIOS\n");

gpio_config_t io_conf = {};
io_conf.mode = GPIO_MODE_OUTPUT;
io_conf.pin_bit_mask = GPIO_OUT;
io_conf.intr_type = GPIO_INTR_DISABLE;
io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

gpio_config(&io_conf);
printf("Configuracion Exitosa!!\n");

while(1){
    printf("LED1 STATUS: ON!!\n");
    gpio_set_level(led1,1);
    
    vTaskDelay(500/portTICK_PERIOD_MS);
     printf("LED1 STATUS: OFF!!\n");
    gpio_set_level(led1,0);
   
    vTaskDelay(100/portTICK_PERIOD_MS);


    gpio_set_level(led2,1);
       printf("LED2 STATUS: ON!!\n");
    vTaskDelay(500/portTICK_PERIOD_MS);
    gpio_set_level(led2,0);
     printf("LED2 STATUS: OFF!!\n");
    vTaskDelay(100/portTICK_PERIOD_MS);
}






}

