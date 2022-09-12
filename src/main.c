/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/

#include "main.h"

void Setup_RCC()
{
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CR &= ~RCC_CR_PLLON;
    RCC->CFGR &= ~(1 << 18 | 1 << 19 | 1 << 20 |1 << 21);
    RCC->CFGR |= RCC_CFGR_PLLMULL6;
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY));
    RCC->CFGR |= RCC_CFGR_SW_PLL;
}

void Init_DMA_5(uint16_t* buff)
{
    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    DMA1_Channel5->CCR |= DMA_CCR5_MSIZE_0;
    DMA1_Channel5->CCR &= ~DMA_CCR5_PSIZE;
    DMA1_Channel5->CCR |= DMA_CCR5_MINC;
    DMA1_Channel5->CCR &= ~DMA_CCR5_PINC;
    DMA1_Channel5->CCR |= DMA_CCR5_CIRC;
    DMA1_Channel5->CCR &= ~DMA_CCR5_DIR;
    DMA1_Channel5->CNDTR = 5;
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


int main(void)
{
    Setup_RCC();
    uint16_t buff[5];
    Init_DMA_5(buff);
    Init_UART();






    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH |= GPIO_CRH_MODE10;
    GPIOC->CRH &= ~GPIO_CRH_CNF10;
    while(1)
    {
        GPIOC->ODR ^= GPIO_ODR_ODR10;
//while ((USART1->SR & USART_SR_RXNE) == 0) {}
        //uint8_t d = USART1->DR;

    }
}
