#include "stm32f4xx.h"
#include "Utility.h"

#define K0 !(GPIOE->IDR & (1<<4))
#define K_UP (GPIOA->IDR & (1<<0))
#define LED_ON_D2 GPIOA->ODR &= ~(1<<6)	//define D2 como saida e ligar led
#define LED_OFF_D2 GPIOA->ODR |= (1<<6)	//define D2 como saida e desliga led
//UTILIZANDO UMA BIBLIOTECA NOVA
int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOa
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            //habilita o clock do GPIOE

    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6 como saída
    GPIOA->MODER &= ~(0b00 << 0); //Configura pino K_UP como entrada
    GPIOA->PUPDR |= (0b10<<0);	//liga o resistor de pull-down do pino PA0
    Configure_Clock();
    Delay_Start(); //prepara o temporizar interno para inicia as funções de delay

    while(1){
    	LED_ON_D2;
    	Delay_ms(1000);
    	LED_OFF_D2;
    	Delay_ms(1000);
    }

}
