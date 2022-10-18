
//7-Acender um LED com diferentes intensidades de brilho, alterando a intensidade em tempo de execução,
//utilizando uma técnica de PWM por meio de software (utilize uma frequência PWM de 100Hz). O LED deve
//iniciar apagado, aumentar gradativamente o brilho até o máximo e em seguida reduzir gradativamente o brilho
//até se apagar, repetindo o processo indefinidamente.
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
    	for(int i=0;i<=10000;i+=100){
			LED_ON_D2;
			Delay_us(i);
			LED_OFF_D2;
			Delay_us(10000-i);
    	}
    	for(int i=0;i<=10000;i+=100){
			LED_ON_D2;
			Delay_us(10000-i);
			LED_OFF_D2;
			Delay_us(i);

						}

    }
}

