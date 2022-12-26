#include "stm32f4xx.h"	//bibliotecas padrão STM32F4
#include "Utility.h"	//biblioteca de funções utilitárias
#include <math.h>

//array com amostras do sinal
const uint16_t samples[200]={

2482, 2521, 2560, 2599, 2638, 2676, 2715, 2753, 2791, 2828, 2865, 2902, 2939, 2975, 3010, 3045, 3080, 3114, 3147, 3180, 3211, 3243, 3273, 3303, 3332, 3360, 3387, 3413, 3438, 3463, 3486, 3508, 3530, 3550, 3569, 3588, 3605, 3621, 3636, 3650, 3662, 3674, 3684, 3693, 3701, 3708, 3713, 3717, 3721, 3722, 3723, 3722, 3721, 3717, 3713, 3708, 3701, 3693, 3684, 3674, 3662, 3650, 3636, 3621, 3605, 3588, 3569, 3550, 3530, 3508, 3486, 3463, 3438, 3413, 3387, 3360, 3332, 3303, 3273, 3243, 3211, 3180, 3147, 3114, 3080, 3045, 3010, 2975, 2939, 2902, 2865, 2828, 2791, 2753, 2715, 2676, 2638, 2599, 2560, 2521, 2482, 2443, 2404, 2365, 2326, 2288, 2249, 2211, 2173, 2136, 2099, 2062, 2025, 1989, 1954, 1919, 1884, 1850, 1817, 1784, 1753, 1721, 1691, 1661, 1632, 1604, 1577, 1551, 1526, 1501, 1478, 1456, 1434, 1414, 1395, 1376, 1359, 1343, 1328, 1314, 1302, 1290, 1280, 1271, 1263, 1256, 1251, 1247, 1243, 1242, 1241, 1242, 1243, 1247, 1251, 1256, 1263, 1271, 1280, 1290, 1302, 1314, 1328, 1343, 1359, 1376, 1395, 1414, 1434, 1456, 1478, 1501, 1526, 1551, 1577, 1604, 1632, 1661, 1691, 1721, 1753, 1784, 1817, 1850, 1884, 1919, 1954, 1989, 2025, 2062, 2099, 2136, 2173, 2211, 2249, 2288, 2326, 2365, 2404, 2443};

int main(void)
{
	Configure_Clock(); //configura o sistema de clock
	Delay_Start(); //inicializa funções de Delay

	RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 8; //inicialização do pino PA4 no modo analógico
	RCC->APB1ENR |= 1 << 29; //habilita o clock da interface digital do DAC
	DAC->CR |= 1; //habilita o canal 1 do DAC

	uint8_t contador =0; //indexador do array de amostras do sinal
	while(1){

	DAC->DHR12R1 = samples[contador]; //escreve no DAC1
	++contador; //atualiza o indexador
	if(contador == 200) contador = 0; //verifica se chegou ao final do array
	Delay_us(33); //aguarda para a próxima amostra
	}
}

