//6. Mostrar um LED aceso com diferentes intensidades de brilho, selecionadas em tempo de compilação,
//utilizando uma técnica de PWM por meio de software (utilize uma frequência PWM de 100Hz).
#include "stm32f4xx.h"
#include "Utility.h"


#define LED_ON_D3 GPIOA -> ODR &= ~(1 << 7)			//define D3 como saída e ligar led
#define LED_OFF_D3 GPIOA -> ODR |= (1 << 7)			//define D3 como saida e desliga led

int main(void){
	Configure_Clock();								//deixando o clock mais rapido
	Delay_Start();									//inicia as funções de delay

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;            //habilita o clock do GPIOA
    GPIOA->MODER |=(0B01 <<14);

    while(1){
    	LED_ON_D3;
        Delay_us(100);
        LED_OFF_D3;
        Delay_us(9900);

    }
}


