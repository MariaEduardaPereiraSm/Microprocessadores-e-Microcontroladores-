
//9. Apresentar uma contagem binária de 2 bits a partir de 2 LEDs.
#include "stm32f4xx.h"
#include "Utility.h"

#define LED_ON_D2 GPIOA->ODR &= ~(1<<6)				//define D2 como saida e ligar led
#define LED_OFF_D2 GPIOA->ODR |= (1<<6)				//define D2 como saida e desliga led
#define LED_ON_D3 GPIOA -> ODR &= ~(1 << 7)			//define D3 como saída e ligar led
#define LED_OFF_D3 GPIOA -> ODR |= (1 << 7)			//define D3 como saida e desliga led

int main(void){
	Configure_Clock();								//deixando o clock mais rapido
	Delay_Start();									//inicia as funções de delay

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    GPIOA->MODER |= (0b01 << 12);    				//configura o pino PA6 como saída
    GPIOA->MODER |=(0B01 <<14);
    LED_OFF_D2;
    LED_OFF_D3;
    while(1){
    	Delay_ms(1000);
        LED_OFF_D2;
        LED_OFF_D3;
        Delay_ms(1000);
        LED_ON_D3;
        Delay_ms(1000);
        LED_OFF_D3;
    	LED_ON_D2;
    	Delay_ms(1000);
    	LED_ON_D3;



    }
}


