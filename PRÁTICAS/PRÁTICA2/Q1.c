#include "stm32f4xx.h"	//bibliotecas padrão STM32F4
#include "Utility.h"	//biblioteca de funções utilitárias


//função principal
int main(void)
{
	Configure_Clock();								//configura o sistema de clock
	Delay_Start();									//inicializa funções de Delay

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;			//habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 8;						//inicialização do pino PA4 no modo analógico

	RCC->APB1ENR |= RCC_APB1ENR_DACEN;				//habilita o clock da interface digital do DAC

	//DAC->CR |= DAC_CR_BOFF1;						//desabilita o buffer analógico do DAC1
	DAC->CR |= DAC_CR_EN1;		//habilita o canal 1 do DAC

	while(1)
	{
		for(int i = 0; i < 255; i++){
			DAC->DHR8R1 =i;						//realiza uma conversão
			Delay_ms(20);							//aguarda a próxima conversão
		}
		for(int i = 0; i < 255; i++){
			DAC->DHR8R1 =255-i;						//realiza uma conversão
			Delay_ms(20);							//aguarda a próxima conversão
				}

	}
}

