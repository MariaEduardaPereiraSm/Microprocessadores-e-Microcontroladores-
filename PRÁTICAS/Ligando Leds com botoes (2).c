
#include "stm32f4xx.h"
#define K0 !(GPIOE->IDR & (1<<4))
#define K1 !(GPIOE->IDR & (1<<3))
#define LED_ON GPIOA->ODR &= ~(1<<6)
#define LED_OFF GPIOA->ODR |= (1<<6)
//LIGA O LED APENAS QUANDO K0 ESTIVER SENDO PRESSIONADO E K1 FOR PRESSIONADO LOGO EM SEGUIDA.
int main(void)
{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            // habilita o clock do GPIOA
	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            // habilita o clock do GPIOE

	    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada
	    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada
	    GPIOA->MODER |= (0b01 << 12);    //configura o pino PA6(LED) como saída
	    GPIOE->PUPDR |= (0b01 << 6);
	    GPIOE->PUPDR |= (0b01 << 8);

	    while(1){
	    	if(!K0 && !K1){ //Ambos botões soltos leds desligados
	        		LED_OFF;
	        	}
	        	if(!K0 && K1){// K1 pressionado primeiro
	        		LED_OFF;
	        		while(K1);
	        	}
	    	if(K0 && !K1){
	    		while(K0){ // Enquanto K0 estiver pressionado verifique as condições a seguir
	    			if(K1){ // se K1 estiver pressionado ligue o led
	    				LED_ON;
	    			}
	    			else{ // se K1 não estiver pressionado o led deve ficar desligado
	    				LED_OFF;
	    			}
	    		}
	    	}
	    }

}

