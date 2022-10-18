#include "stm32f4xx.h"
#define K0 !(GPIOE->IDR & (1<<4))	//define K0 como entrada quando pressionar
#define K1 !(GPIOE->IDR & (1<<3))	//define K1 como entrada quando pressionar
#define LED_ON_D2 GPIOA->ODR &= ~(1<<6)		//define D2 como saída e ligar led
#define LED_OFF_D2 GPIOA->ODR |= (1<<6)	//define D2 como saída e desliga led
#define LED_ON_D3 GPIOA -> ODR &= ~(1 << 7)	//define D3 como saída e ligar led
#define LED_OFF_D3 GPIOA -> ODR |= (1 << 7)	//define D3 como saída e desliga led
//LIGA DOIS LEDS APENAS QUANDO K0 ESTIVER SENDO PRESSIONADO E EM SEGUIDA PRESSIONARMOS O K1.
int main(void)
{
	  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;            //habilita o clock do GPIOE

	    GPIOA->MODER |= (0b01 << 12);    // configura o pino PA6 como saída
	    GPIOA->MODER |= (0b01 << 14);    //configura o pino PA7 como saída
	    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada
	   GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada
	    GPIOE->PUPDR |= (0b01 << 6);    // liga o resistor de pull-up no pino PE3 (para garantir nível alto quando a chave estiver solta)
	    GPIOE->PUPDR |= (0b01 << 8);    //liga o resistor de pull-up no pino PE4 (para garantir nível alto quando a chave estiver solta)


	    //o LED em PA6 só deve acender ao pressionar primeiro K0 e depois K1
	    while(1){
	    	LED_OFF_D2;
		LED_OFF_D3;
			if(!K0 && K1){	// condição para testar se k1 tiver pressionado
				LED_OFF_D2;  // desliga leds enquanto o k1 tiver pressionado
				LED_OFF_D3;
				while(K1);
			}
			if(K0 && !K1){ // condição para testar se k0 tiver pressionado
				LED_OFF_D2;
				LED_OFF_D3;
				while(K0){ //Enquanto o K0 estiver pressionado
					if(K1){	 //se pressionar k1 liga os leds
						LED_ON_D2;
						LED_ON_D3;
					}
					else{ //se não pressionar k1 os leds continuam desligados
						LED_OFF_D2;										LED_OFF_D3;
					}}
			}
	    }
	}

