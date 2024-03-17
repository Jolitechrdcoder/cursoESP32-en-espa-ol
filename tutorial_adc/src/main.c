#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"driver/gpio.h"
#include"driver/adc.h"

#define PINADC ADC_CHANNEL_4 //pin a leer adc
#define muestras 64 // numero de mustras
//subrutina config adc
void config(void);

void app_main() {
    int pot=0;
    int smoot = 0;
while (1)
{
   for (int i = 0; i < muestras; i++)
   {
    smoot += pot  = adc1_get_raw(PINADC);
   }
    smoot/=muestras;
    if(smoot >4095){
        smoot = 4095;
    }

   
   printf("El valor crudo es: %d\n",pot);
   printf("El valor smoot es: %d\n",smoot);
   vTaskDelay(300/portTICK_PERIOD_MS);
}



}

void config(void){
    adc1_config_channel_atten(PINADC,ADC_ATTEN_DB_11);// atenuacion del adc
    adc1_config_width(ADC_WIDTH_BIT_12); // resolucion del adc
}