#include "stm32f4xx.h"
void atraso(int delay){
	while(delay) --delay;}

int main(void)
{
	   RCC -> AHB1ENR |= 1;
		GPIOA -> MODER |= (0b01 << 12);
		while(1){
		GPIOA -> ODR |= (1 << 6);
		atraso(1000000);
		GPIOA -> ODR &= ~(1 << 6);
		atraso(1000000);

}

}
