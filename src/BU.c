#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x.h>
#include <BU.h>
void SetupRCC()
{
	RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CR &= ~RCC_CR_PLLON;
    RCC->CFGR &= ~(1 << 18 | 1 << 19 | 1 << 20 |1 << 21);
    RCC->CFGR |= RCC_CFGR_PLLMULL6;
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_DIV16;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
}

void Init_DMA_5(uint8_t* buff)
{
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR &= ~DMA_CCR5_MSIZE;
    DMA1_Channel5->CCR &= ~DMA_CCR5_PSIZE;
    DMA1_Channel5->CCR |= DMA_CCR5_MINC;
    DMA1_Channel5->CCR &= ~DMA_CCR5_PINC;
    DMA1_Channel5->CCR |= DMA_CCR5_CIRC;
    DMA1_Channel5->CCR &= ~DMA_CCR5_DIR;
    DMA1_Channel5->CNDTR = 20;
    DMA1_Channel5->CPAR = &USART1->DR;
    DMA1_Channel5->CMAR = &buff[0];
    DMA1_Channel5->CCR |= DMA_CCR5_EN;
}

void Init_UART()
{
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    GPIOA->CRH &= ~GPIO_CRH_CNF9;
    GPIOA->CRH |= GPIO_CRH_MODE9;
    GPIOA->CRH |= GPIO_CRH_CNF9_1;
    GPIOA->CRH &= ~GPIO_CRH_CNF10;
    GPIOA->CRH &= ~GPIO_CRH_MODE10;
    GPIOA->CRH |= GPIO_CRH_CNF10_1;
    GPIOA->BSRR |= GPIO_ODR_ODR10;
    USART1->CR1 = USART_CR1_UE;
    USART1->BRR = 7500;
    USART1->CR1 |= USART_CR1_RE;
    USART1->CR1 |= USART_CR1_TE;
    USART1->CR2 = 0;
    USART1->CR3 |= USART_CR3_DMAR;
}

void Multiplexor_On_Chanell(int number_chanell)
{
	switch(number_chanell)
	{
	case 0:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;    				//s0_off
		GPIOE->ODR &= ~GPIO_ODR_ODR6;    				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;    				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;    				//s3_off
		break;

	case 1:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;   				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;    				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;    				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;    				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;    				//s3_off
		break;

	case 2:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 3:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 4:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 5:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 6:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 7:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR &= ~GPIO_ODR_ODR4;     				//s3_off
		break;

	case 8:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 9:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 10:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 11:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR &= ~GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 12:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 13:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR &= ~GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 14:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR &= ~GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;

	case 15:
		GPIOE->ODR &= ~GPIO_ODR_ODR2;    				//en_on
		GPIOE->ODR |= GPIO_ODR_ODR5;     				//s0_on
		GPIOE->ODR |= GPIO_ODR_ODR6;     				//s1_off
		GPIOE->ODR |= GPIO_ODR_ODR3;     				//s2_off
		GPIOE->ODR |= GPIO_ODR_ODR4;     				//s3_off
		break;
	}
}

void Set_Amplituda_Chanell(int number_chanell, int hight_bit, int low_bit)
{
    Multiplexor_On_Chanell(number_chanell);
    BU_I2C2_Enable();
    Write_DAC(hight_bit, low_bit);
}

void BU_I2C2_Enable()
{
	GPIOB->CRL |= GPIO_CRL_MODE6_1;
	GPIOB->CRL |= GPIO_CRL_CNF6_1;
	GPIOB->CRL |= GPIO_CRL_MODE7_1;
	GPIOB->CRL |= GPIO_CRL_CNF7_1;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	I2C1->CR1 |= I2C_CR1_SWRST;
	I2C1->CR1 &= ~I2C_CR1_SWRST;
	I2C1->TRISE = 0;
	I2C1->TRISE = 36;
	I2C1->CR2 |= 36;
	I2C1->CCR &= ~I2C_CCR_FS;
	I2C1->CCR &= ~I2C_CCR_CCR;
	I2C1->CCR |= 179;
	for (int i = 0; i < 100; i++);
	I2C1->CR1 |= I2C_CR1_PE;
	I2C1->CR1 |= I2C_CR1_ACK;
}

void Write_DAC(int high_bit, int low_bit)
{
	I2C1->CR1 |= I2C_CR1_START;
	while (!(I2C1->SR1 & I2C_SR1_SB)) ;
	I2C1->SR1;
	I2C1->DR = 192;
	for (int i = 0; i < 700; i++) ;
	I2C1->SR1;
	I2C1->SR2;
	I2C1->DR = 80;
	for (int i = 0; i < 800; i++) ;
	I2C1->DR = high_bit;
	for (int i = 0; i < 800; i++) ;
	I2C1->DR = low_bit;
	for (int i = 0; i < 800; i++) ;
	I2C1->CR1 |= I2C_CR1_STOP;
}

void Init_Timer_2()
{
    TIM2->PSC = 36-1;
	TIM2->ARR = 2000;
	TIM2->CCR1 = 20;
	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->DIER |= TIM_DIER_CC1IE;
    TIM2->CR1 |= TIM_CR1_ARPE;
}

void Init_Timer_3()
{
    TIM3->PSC = 18-1;
	TIM3->ARR = 40000;
	TIM3->CCR1 = 1;
	TIM3->CCR2 = 2;
	TIM3->CCR3 = 3;
	TIM3->CCR4 = 4;
	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->DIER |= TIM_DIER_CC1IE;
	TIM3->DIER |= TIM_DIER_CC2IE;
	TIM3->DIER |= TIM_DIER_CC3IE;
	TIM3->DIER |= TIM_DIER_CC4IE;
    TIM3->CR1 |= TIM_CR1_ARPE;
    NVIC_EnableIRQ(TIM3_IRQn);

}

void Init_Timer_4()
{
    TIM4->PSC = 18-1;
	TIM4->ARR = 40000;
	TIM4->CCR1 = 1;
	TIM4->CCR2 = 40;
	TIM4->CCR3 = 70;
	TIM4->CCR4 = 39000;
	TIM4->DIER |= TIM_DIER_UIE;
	TIM4->DIER |= TIM_DIER_CC1IE;
	TIM4->DIER |= TIM_DIER_CC2IE;
	TIM4->DIER |= TIM_DIER_CC3IE;
	TIM4->DIER |= TIM_DIER_CC4IE;
    TIM4->CR1 |= TIM_CR1_ARPE;
    NVIC_EnableIRQ(TIM4_IRQn);
    //NVIC_SetPriority(TIM4_IRQn, 1);
}

void Send_Byte()
{

}

void Init()
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;


	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	//sinhro_camera
	GPIOD->CRL |= GPIO_CRL_MODE0_0;
	GPIOD->CRL &= ~GPIO_CRL_CNF0;
	GPIOD->ODR &= ~GPIO_ODR_ODR0;

	//sinhro_backlight
	GPIOC->CRH |= GPIO_CRH_MODE12_0;
	GPIOC->CRH &= ~GPIO_CRH_CNF12;
	GPIOC->ODR &= ~GPIO_ODR_ODR12;

    //MU_E
	GPIOE->CRL |= GPIO_CRL_MODE2_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF2;
	//MU_S0
	GPIOE->CRL |= GPIO_CRL_MODE5_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF5;
	//MU_S1
	GPIOE->CRL |= GPIO_CRL_MODE6_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF6;
	//MU_S2
	GPIOE->CRL |= GPIO_CRL_MODE3_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF3;
	//MU_S3
	GPIOE->CRL |= GPIO_CRL_MODE4_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF4;

	//en_u0
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	//dur_0
	GPIOC->CRL |= GPIO_CRL_MODE7_0;
	GPIOC->CRL &= ~GPIO_CRL_CNF7;
	//do0
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	GPIOC->CRH &= ~GPIO_CRH_CNF9;

	//en_u1
	GPIOD->CRH |= GPIO_CRH_MODE15_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF15;
	//dur_1
	GPIOD->CRH |= GPIO_CRH_MODE14_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF14;
	//do1
	GPIOC->CRL |= GPIO_CRL_MODE6_0;
	GPIOC->CRL &= ~GPIO_CRL_CNF6;

	//en_u2
	GPIOD->CRH |= GPIO_CRH_MODE12_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF12;
	//dur_2
	GPIOD->CRH |= GPIO_CRH_MODE11_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF11;
	//do2
	GPIOD->CRH |= GPIO_CRH_MODE13_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF13;

	//en_u3
	GPIOD->CRH |= GPIO_CRH_MODE9_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF9;
	//dur_3
	GPIOD->CRH |= GPIO_CRH_MODE8_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF8;
	//do3
	GPIOD->CRH |= GPIO_CRH_MODE10_0;
	GPIOD->CRH &= ~GPIO_CRH_CNF10;

	//en_u4
	GPIOB->CRH |= GPIO_CRH_MODE14_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF14;
	//dur_4
	GPIOB->CRH |= GPIO_CRH_MODE13_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF13;
	//do4
	GPIOB->CRH |= GPIO_CRH_MODE15_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF15;

	//en_u5
	GPIOB->CRH |= GPIO_CRH_MODE10_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF10;
	//dur_5
	GPIOE->CRH |= GPIO_CRH_MODE15_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF15;
	//do5
	GPIOB->CRH |= GPIO_CRH_MODE11_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF11;

	//en_u6
	GPIOE->CRH |= GPIO_CRH_MODE13_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF13;
	//dur_6
	GPIOE->CRH |= GPIO_CRH_MODE12_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF12;
	//do6
	GPIOE->CRH |= GPIO_CRH_MODE14_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF14;

	//en_u7
	GPIOE->CRH |= GPIO_CRH_MODE10_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF10;
	//dur_7
	GPIOE->CRH |= GPIO_CRH_MODE9_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF9;
	//do7
	GPIOE->CRH |= GPIO_CRH_MODE11_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF11;

	//en_u8
	GPIOE->CRL |= GPIO_CRL_MODE7_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF7;
	//dur_8
	GPIOB->CRL |= GPIO_CRL_MODE2_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF2;
	//do8
	GPIOE->CRH |= GPIO_CRH_MODE8_0;
	GPIOE->CRH &= ~GPIO_CRH_CNF8;

	//en_u9
	GPIOB->CRL |= GPIO_CRL_MODE0_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
	//dur_9
	GPIOC->CRL |= GPIO_CRL_MODE5_0;
	GPIOC->CRL &= ~GPIO_CRL_CNF5;
	//do9
	GPIOB->CRL |= GPIO_CRL_MODE1_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF1;

	//en_u10
	GPIOA->CRL |= GPIO_CRL_MODE7_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF7;
	//dur_10
	GPIOA->CRL |= GPIO_CRL_MODE6_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF6;
	//do10
	GPIOC->CRL |= GPIO_CRL_MODE4_0;
	GPIOC->CRL &= ~GPIO_CRL_CNF4;

	//en_u11
	GPIOA->CRL |= GPIO_CRL_MODE1_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	//dur_11
	GPIOA->CRL |= GPIO_CRL_MODE0_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF0;
	//do11
	GPIOA->CRL |= GPIO_CRL_MODE2_0;
	GPIOA->CRL &= ~GPIO_CRL_CNF2;

	//en_u12
	GPIOB->CRH |= GPIO_CRH_MODE9_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF9;
	//dur_12
	GPIOB->CRH |= GPIO_CRH_MODE8_0;
	GPIOB->CRH &= ~GPIO_CRH_CNF8;
	//do12
	GPIOE->CRL |= GPIO_CRL_MODE0_0;
	GPIOE->CRL &= ~GPIO_CRL_CNF0;

	//en_u13
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_1;
	GPIOB->CRL |= GPIO_CRL_MODE3_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF3;
	//dur_13
	GPIOD->CRL |= GPIO_CRL_MODE7_0;
	GPIOD->CRL &= ~GPIO_CRL_CNF7;
	//do13
	GPIOB->CRL |= GPIO_CRL_MODE4_0;
	GPIOB->CRL &= ~GPIO_CRL_CNF4;

	//en_u14
	GPIOD->CRL |= GPIO_CRL_MODE5_0;
	GPIOD->CRL &= ~GPIO_CRL_CNF5;
	//dur_14
	GPIOD->CRL |= GPIO_CRL_MODE4_0;
	GPIOD->CRL &= ~GPIO_CRL_CNF4;
	//do14
	GPIOD->CRL |= GPIO_CRL_MODE6_0;
	GPIOD->CRL &= ~GPIO_CRL_CNF6;

	//en_u15
	GPIOD->CRL |= GPIO_CRL_MODE2;
	GPIOD->CRL &= ~GPIO_CRL_CNF2;
	//dur_15
	GPIOD->CRL |= GPIO_CRL_MODE1;
	GPIOD->CRL &= ~GPIO_CRL_CNF1;
	//do15
	GPIOD->CRL |= GPIO_CRL_MODE3;
	GPIOD->CRL &= ~GPIO_CRL_CNF3;
}

char Chanell_On_0()
{
	GPIOC->ODR |= GPIO_ODR_ODR8;   				//en_on
	GPIOC->ODR &= ~GPIO_ODR_ODR7;  				//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR9;  				//end_impulse_off
	return 1;
}

char Chanell_On_1()
{
	GPIOD->ODR |= GPIO_ODR_ODR15;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR14;  			//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR6;  				//end_impulse_off
	return 1;
}

char Chanell_On_2()
{
	GPIOD->ODR |= GPIO_ODR_ODR12;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR11;  			//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR13;  			//end_impulse_off
	return 1;
}

char Chanell_On_3()
{
	GPIOD->ODR |= GPIO_ODR_ODR9;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR8;  				//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR10;  			//end_impulse_off
	return 1;
}

char Chanell_On_4()
{
	GPIOB->ODR |= GPIO_ODR_ODR14;   				//en_on
	GPIOB->ODR &= ~GPIO_ODR_ODR13;  			//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR15;  			//end_impulse_off
	return 1;
}

char Chanell_On_5()
{
	GPIOB->ODR |= GPIO_ODR_ODR10;   				//en_on
	GPIOE->ODR &= ~GPIO_ODR_ODR15;  			//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR11;  			//end_impulse_off
	return 1;
}

char Chanell_On_6()
{
	GPIOE->ODR |= GPIO_ODR_ODR13;   				//en_on
	GPIOE->ODR &= ~GPIO_ODR_ODR12;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR14;  			//end_impulse_off
	return 1;
}

char Chanell_On_7()
{
	GPIOE->ODR |= GPIO_ODR_ODR10;   				//en_on
	GPIOE->ODR &= ~GPIO_ODR_ODR9;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR11;  			//end_impulse_off
	return 1;
}

char Chanell_On_8()
{
	GPIOE->ODR |= GPIO_ODR_ODR7;   				//en_on
	GPIOB->ODR &= ~GPIO_ODR_ODR2;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR8;  				//end_impulse_off
	return 1;
}

char Chanell_On_9()
{
	GPIOB->ODR |= GPIO_ODR_ODR0;   				//en_on
    GPIOC->ODR &= ~GPIO_ODR_ODR5;  				//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR1;  				//end_impulse_off
	return 1;
}

char Chanell_On_10()
{
	GPIOA->ODR |= GPIO_ODR_ODR7;   				//en_on
	GPIOA->ODR &= ~GPIO_ODR_ODR6;  				//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR4;  				//end_impulse_off
	return 1;
}

char Chanell_On_11()
{
	GPIOA->ODR |= GPIO_ODR_ODR1;   				//en_on
	GPIOA->ODR &= ~GPIO_ODR_ODR0;  				//begin_impulse_off
	GPIOA->ODR &= ~GPIO_ODR_ODR2;  				//end_impulse_off
	return 1;
}

char Chanell_On_12()
{
	GPIOB->ODR |= GPIO_ODR_ODR9;   				//en_on
	GPIOB->ODR &= ~GPIO_ODR_ODR8;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR0;  				//end_impulse_off
	return 1;
}

char Chanell_On_13()
{
	GPIOB->ODR |= GPIO_ODR_ODR3;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR7;  				//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR4;  				//end_impulse_off
	return 1;
}

char Chanell_On_14()
{
	GPIOD->ODR |= GPIO_ODR_ODR5;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR4;  				//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR6;  				//end_impulse_off
	return 1;
}

char Chanell_On_15()
{
	GPIOD->ODR |= GPIO_ODR_ODR2;   				//en_on
	GPIOD->ODR &= ~GPIO_ODR_ODR1;  				//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR3;  				//end_impulse_off
	return 1;
}

char Chanell_Off_0()
{
	GPIOC->ODR &= ~GPIO_ODR_ODR8;    				//en_off
	GPIOC->ODR &= ~GPIO_ODR_ODR7;  				//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR9;  				//end_impulse_off
	return 0;
}

char Chanell_Off_1()
{
	GPIOD->ODR &= ~GPIO_ODR_ODR15;  			//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR14;  			//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR6;  				//end_impulse_off
	return 0;
}

char Chanell_Off_2()
{
	GPIOD->ODR &= ~GPIO_ODR_ODR12;  			//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR11;  			//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR13;  			//end_impulse_off
	return 0;
}

char Chanell_Off_3()
{
	GPIOD->ODR &= ~GPIO_ODR_ODR9;  				//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR8;  				//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR10;  			//end_impulse_off
	return 0;
}

char Chanell_Off_4()
{
	GPIOB->ODR &= ~GPIO_ODR_ODR14;  			//en_off
	GPIOB->ODR &= ~GPIO_ODR_ODR13;  			//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR15;  			//end_impulse_off
	return 0;
}

char Chanell_Off_5()
{
	GPIOB->ODR &= ~GPIO_ODR_ODR10;  				//en_off
	GPIOE->ODR &= ~GPIO_ODR_ODR15;  			//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR11;  			//end_impulse_off
	return 0;
}

char Chanell_Off_6()
{
	GPIOE->ODR &= ~GPIO_ODR_ODR13;  			//en_off
	GPIOE->ODR &= ~GPIO_ODR_ODR12;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR14;  			//end_impulse_off
	return 0;
}

char Chanell_Off_7()
{
	GPIOE->ODR &= ~GPIO_ODR_ODR10;  			//en_off
	GPIOE->ODR &= ~GPIO_ODR_ODR9;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR11;  			//end_impulse_off
	return 0;
}

char Chanell_Off_8()
{
	GPIOE->ODR &= ~GPIO_ODR_ODR7;  				//en_off
	GPIOB->ODR &= ~GPIO_ODR_ODR2;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR8;  				//end_impulse_off
	return 0;
}

char Chanell_Off_9()
{
	GPIOB->ODR &= ~GPIO_ODR_ODR0;  				//en_off
    GPIOC->ODR &= ~GPIO_ODR_ODR5;  				//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR1;  				//end_impulse_off
	return 0;
}

char Chanell_Off_10()
{
	GPIOA->ODR &= ~GPIO_ODR_ODR7;  				//en_off
	GPIOA->ODR &= ~GPIO_ODR_ODR6;  				//begin_impulse_off
	GPIOC->ODR &= ~GPIO_ODR_ODR4;  				//end_impulse_off
	return 0;
}

char Chanell_Off_11()
{
	GPIOA->ODR &= ~GPIO_ODR_ODR1;  				//en_off
	GPIOA->ODR &= ~GPIO_ODR_ODR0;  				//begin_impulse_off
	GPIOA->ODR &= ~GPIO_ODR_ODR2;  				//end_impulse_off
	return 0;
}

char Chanell_Off_12()
{
	GPIOB->ODR &= ~GPIO_ODR_ODR9;  				//en_off
	GPIOB->ODR &= ~GPIO_ODR_ODR8;  				//begin_impulse_off
	GPIOE->ODR &= ~GPIO_ODR_ODR0;  				//end_impulse_off
	return 0;
}

char Chanell_Off_13()
{
	GPIOB->ODR &= ~GPIO_ODR_ODR3;  				//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR7;  				//begin_impulse_off
	GPIOB->ODR &= ~GPIO_ODR_ODR4;  				//end_impulse_off
	return 0;
}

char Chanell_Off_14()
{
	GPIOD->ODR &= ~GPIO_ODR_ODR5;  				//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR4;   				//begin_impulse_on
	GPIOD->ODR &= ~GPIO_ODR_ODR6;   				//end_impulse_on
	return 0;
}

char Chanell_Off_15()
{
	GPIOD->ODR &= ~GPIO_ODR_ODR2;  				//en_off
	GPIOD->ODR &= ~GPIO_ODR_ODR1;  				//begin_impulse_off
	GPIOD->ODR &= ~GPIO_ODR_ODR3;  				//end_impulse_off
	return 0;
}

void Duration_Impulse_Chanell_15(int duration_impulse_chanell, int period, int condition_sinhro, int delay_count_impulse_camera, int duration_count_impulse_sinhro_camera, int delay_count_impulse_backlight, int duration_count_impulse_sinhro_backlight)
{
        int count_sinhro = 0;
        int i = 0;

        if(condition_sinhro == 1)
        {
            for(i = 0; i < delay_count_impulse_backlight; i++);
            count_sinhro += i;
            GPIOC->ODR |= GPIO_ODR_ODR12;
            //for(i = 0; i < delay_count_impulse_camera; i++);
            count_sinhro += i;
            GPIOD->ODR |= GPIO_ODR_ODR0;
            //for(i = 0; i < duration_count_impulse_sinhro_camera; i++);
            count_sinhro += i;
            GPIOD->ODR &= ~GPIO_ODR_ODR0;
            //for(i = 0; i < duration_count_impulse_sinhro_backlight; i++);
            count_sinhro += i;
            GPIOC->ODR &= ~GPIO_ODR_ODR12;
        }
        for(int i = 0; i < duration_impulse_chanell; i++);
        GPIOD->ODR &= ~GPIO_ODR_ODR1;   					//begin_impulse_off
        for(int i = 0 ; i < 60 ; i++);
        GPIOD->ODR |= GPIO_ODR_ODR3;       				    //end_impulse_on
        for(int i = 0; i < period-count_sinhro; i++);
}
