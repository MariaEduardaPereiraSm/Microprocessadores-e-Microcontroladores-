//10. Acender dois LEDs com diferentes intensidades de brilho, alterando alternadamente a intensidade em
//tempo de execução, semelhantemente ao que foi feito na questão 7.
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
    GPIOA->MODER |=(0B01 <<14);
    GPIOA->MODER |=(0b01 << 12);

    while(1){
    	for(int i=0;i<=10000;i+=10){
    				LED_ON_D2;
    				Delay_us(i);
    				LED_OFF_D2;
    				Delay_us(10000-i);
    				LED_ON_D3;
    				Delay_us(10000-i);
    				LED_OFF_D3;
    				Delay_us(i);
    	    	}

    }
}


