#include "stm32f4xx.h"

int main(void)
{
		RCC -> AHB1ENR |= 0b10001;

	    GPIOA -> MODER |= (0b01 << 12);
	    GPIOA -> MODER |= (0b01 << 14);

	    GPIOE -> MODER &= ~(0b11 << 6);
	    GPIOE -> MODER &= ~(0b11 << 8);

	    GPIOE -> PUPDR |= (0b01 <<8 );
	    GPIOE -> PUPDR |= (0b01 << 6);

	    while(1){
		 // Lendo os valores dos botões
	    	int K0 = (GPIOE -> IDR & (1<<4));
	           int K1 = (GPIOE -> IDR & (1<<3));

	    	if(K0){ // Botão tá solto
	    		GPIOA->ODR |= (1<<6); 	// Desliga o led D2
	    	}else{
	    		GPIOA->ODR &= ~(1<<6); 	//Liga o led D2
	    	}
		if(K1){ //Botão tá solto
			GPIOA->ODR |= (1<<7);  //Desliga o led D3
		}else{
			GPIOA->ODR &= ~(1<<7); //Liga o led D3
			}
	   }

}
