//5- Acionar um buzzer para emitir um som semelhante ao de um alarme sonoro: 4 beeps curtos de 50ms de largura, seguidos de uma pausa.

#include "stm32f4xx.h"
#include "Utility.h"

#define LED_ON_D2 GPIOA->ODR &= ~(1<<6)				//define D2 como saida e ligar led
#define LED_OFF_D2 GPIOA->ODR |= (1<<6)				//define D2 como saida e desliga led

int main(void){
	Configure_Clock();								//deixando o clock mais rapido
	Delay_Start();									//inicia as funções de delay

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    GPIOA->MODER |= (0b01 << 12);    				//configura o pino PA6 como saída

    while(1){

    	LED_ON_D2;
		Delay_ms(1000);
		for(int i=0;i<4;i++){
			LED_ON_D2;
			Delay_ms(50);
			LED_OFF_D2;
			Delay_ms(50);

		}

    }
}

