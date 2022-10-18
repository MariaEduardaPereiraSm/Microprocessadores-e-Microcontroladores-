
#include "stm32f4xx.h"
#define K0 !(GPIOE->IDR & (1<<4))
#define K_UP (GPIOA->IDR & (1<<0))
#define LED_ON_D2 GPIOA->ODR &= ~(1<<6)		//define D2 como saída e ligar led
#define LED_OFF_D2 GPIOA->ODR |= (1<<6)	//define D2 como saída e desliga led
//UTILIZANDO UM NOVO BOTÃO K_UP
int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída
    GPIOA->MODER &= ~(0b00 << 0); //Configura pino K_UP como entrada
    GPIOA->PUPDR |= (0b10<<0);	//liga o resistor de pull-down do pino PA0

    while(1){
    	if(K_UP)
    		LED_ON_D2;
    	else
    		LED_OFF_D2;
    }

	}

