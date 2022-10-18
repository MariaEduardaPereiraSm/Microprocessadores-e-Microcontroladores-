
//2- Piscar um LED numa frequência de 0,5Hz, com largura de pulso de 100ms, produzindo um comportamento semelhante aos sinalizadores para aeronaves de baixa altitude que são instalados no topo de edifícios.

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
    	LED_OFF_D2;
		Delay_ms(1900);
		LED_ON_D2;
		Delay_ms(100);
    }
}


