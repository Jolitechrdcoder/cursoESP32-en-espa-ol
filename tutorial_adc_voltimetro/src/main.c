#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"driver/gpio.h"
#include"driver/adc.h"
#define voltaje 3.3
float volt = 0.00;
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

   volt=(smoot/4096.0)*voltaje;
   printf("signal  %d\n",smoot);
   printf("voltaje:  %.2fV\n",volt);
   vTaskDelay(300/portTICK_PERIOD_MS);
}



}

void config(void){
    adc1_config_channel_atten(PINADC,ADC_ATTEN_DB_11);// atenuacion del adc
    adc1_config_width(ADC_WIDTH_BIT_12); // resolucion del adc
}