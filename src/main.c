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
#include "BU.h"

int* PORT_1 = &(GPIOA->ODR);
int* PORT_2 = &(GPIOB->ODR);
uint32_t number_pin_1 = 0;
uint32_t number_pin_2 = 0;
uint8_t condition = 0;
uint8_t flag_interrupt = 0;

int main(void)
{
    char chanell_work_flag[16];
    char chanell_worked_flag[16];
    int duration_count_impulse_chanell[16];
    int period_count_impulse_chanell[16];
    for(int i = 0; i < 16; i++)
    {
        chanell_work_flag[i] = 0;
        chanell_worked_flag[i] = 0;
        duration_count_impulse_chanell[i] = 100;
        period_count_impulse_chanell[i] = 40000;
    }
    int hight_bit = 128;
    int low_bit = 0;
    int delay_impulse_camera = 100;
    int duration_impulse_camera = 500;
    int duration_impulse_backlight = 4;
    int delay_impulse_backlight = 200;
    int condition_sinhro = 0;
    int delitel = 0;
    int chanell = 0;
    int datacode = 0;
    uint8_t k = 0;
    uint8_t len = 20;
    uint8_t buffer[len];
    for(int i = 0; i < len; i++)
    {
        buffer[i] = 0;
    }
    SetupRCC();
    Init_DMA_5(buffer);
    Init_UART();
    Init();
    Init_Timer_2();
    Init_Timer_3();
    Init_Timer_4();
    while (1)
    {
        if(buffer[19] != 0)
        {
            datacode = buffer[0] - 48;
            if(datacode == 1 || datacode == 2)
            {
                k = 2;
                while(delitel != 1)
                {
                    chanell *= 10;
                    chanell += buffer[k] - 48;
                    k++;
                    if(buffer[k+1] != 32 && buffer[k+1] != 44 && buffer[k+1] != 46 && buffer[k+1] != 45)
                    {
                        delitel++;
                    }
                }
                k = 0;
            }
            if(datacode == 3)
            {
                for(int i = 0; i < len-1; i++)
                {
                    if(buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46 && buffer[i] != 45)
                    {
                        if(delitel == 1)
                        {
                            chanell *= 10;
                            chanell += buffer[i] - 48;
                        }
                        if(delitel == 2)
                        {
                            hight_bit *= 10;
                            hight_bit += buffer[i] - 48;
                        }
                        if(delitel == 3)
                        {
                            low_bit *= 10;
                            low_bit += buffer[i] - 48;
                        }
                    }
                    if(buffer[i] == 32 || buffer[i] == 44 || buffer[i] == 46 || buffer[i] == 45)
                    {
                    delitel++;
                    }
                }
                Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                datacode = 0;
                chanell = 0;
                hight_bit = 0;
                low_bit = 0;
            }
            if(datacode == 4)
            {
                for(int i = 0; i < len-1; i++)
                {
                    if(buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46 && buffer[i] != 45)
                    {
                        if(delitel == 1)
                        {
                            chanell *= 10;
                            chanell += buffer[i] - 48;
                        }
                        if(delitel == 2)
                        {
                            switch(chanell)
                            {
                                case 0:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 1:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 2:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 3:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 4:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 5:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 6:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 7:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 8:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 9:     duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 10:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 11:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 12:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 13:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 14:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 15:    duration_count_impulse_chanell[chanell] *= 10;
                                            duration_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;
                            }
                        }
                        if(delitel == 3)
                        {
                            switch(chanell)
                            {
                                case 0:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 1:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 2:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 3:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 4:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 5:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 6:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 7:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 8:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 9:     period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 10:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 11:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 12:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 13:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 14:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;

                                case 15:    period_count_impulse_chanell[chanell] *= 10;
                                            period_count_impulse_chanell[chanell] += buffer[i] - 48;
                                            break;
                            }
                        }
                    }
                    if(buffer[i] == 32 || buffer[i] == 44 || buffer[i] == 46 || buffer[i] == 45)
                    {
                        delitel++;
                        if(delitel == 2)
                        {
                            duration_count_impulse_chanell[chanell] = 0;
                            period_count_impulse_chanell[chanell] = 0;
                        }
                    }
                }
                datacode = 0;
                chanell = 0;
            }
            if(datacode == 5)
            {
                if(buffer[2] == 49)
                {
                    condition_sinhro = 0;
                    delay_impulse_camera = 0;
                    duration_impulse_camera = 0;
                    delay_impulse_backlight = 0;
                    duration_impulse_backlight = 0;
                    for(int i = 0; i < len-1; i++)
                    {
                        if(buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46 && buffer[i] != 45)
                        {
                            if(delitel == 2)
                            {
                                delay_impulse_camera *= 10;
                                delay_impulse_camera += buffer[i] - 48;
                            }
                            if(delitel == 3)
                            {
                                duration_impulse_camera *= 10;
                                duration_impulse_camera += buffer[i] - 48;
                            }
                            if(delitel == 4)
                            {
                                delay_impulse_backlight *= 10;
                                delay_impulse_backlight += buffer[i] - 48;
                            }
                            if(delitel == 5)
                            {
                                duration_impulse_backlight *= 10;
                                duration_impulse_backlight += buffer[i] - 48;
                            }
                        }
                        if(buffer[i] == 32 || buffer[i] == 44 || buffer[i] == 46 || buffer[i] == 45)
                        {
                            delitel++;
                        }
                    }
                    TIM3->CCR1 = delay_impulse_camera;
                    TIM3->CCR2 = delay_impulse_backlight;
                    TIM3->CCR3 = (duration_impulse_backlight + delay_impulse_backlight);
                    TIM3->CCR4 = (duration_impulse_camera + delay_impulse_camera);
                    condition = 1;
                }
                else
                {
                    condition = 0;
                }
            }
            delitel = 0;
            buffer[19] = 0;
        }
        if(datacode == 1)
        {
            switch(chanell)
            {
                case 0:     chanell_work_flag[chanell] = Chanell_On_0();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 1:     chanell_work_flag[chanell] = Chanell_On_1();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 2:     chanell_work_flag[chanell] = Chanell_On_2();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 3:     chanell_work_flag[chanell] = Chanell_On_3();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 4:     chanell_work_flag[chanell] = Chanell_On_4();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 5:     chanell_work_flag[chanell] = Chanell_On_5();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 6:     chanell_work_flag[chanell] = Chanell_On_6();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 7:     chanell_work_flag[chanell] = Chanell_On_7();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 8:     chanell_work_flag[chanell] = Chanell_On_8();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 9:     chanell_work_flag[chanell] = Chanell_On_9();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 10:    chanell_work_flag[chanell] = Chanell_On_10();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 11:    chanell_work_flag[chanell] = Chanell_On_11();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 12:    chanell_work_flag[chanell] = Chanell_On_12();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 13:    chanell_work_flag[chanell] = Chanell_On_13();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 14:    chanell_work_flag[chanell] = Chanell_On_14();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;

                case 15:    chanell_work_flag[chanell] = Chanell_On_15();
                            Set_Amplituda_Chanell(chanell, hight_bit, low_bit);
                            flag_interrupt = 0;
                            break;
            }
            chanell = 0;
            datacode = 0;
            hight_bit = 0;
            low_bit = 0;
        }
        if(datacode == 2)
        {
            switch(chanell)
            {
                case 0:     chanell_work_flag[chanell] = Chanell_Off_0();
                            break;

                case 1:     chanell_work_flag[chanell] = Chanell_Off_1();
                            break;

                case 2:     chanell_work_flag[chanell] = Chanell_Off_2();
                            break;

                case 3:     chanell_work_flag[chanell] = Chanell_Off_3();
                            break;

                case 4:     chanell_work_flag[chanell] = Chanell_Off_4();
                            break;

                case 5:     chanell_work_flag[chanell] = Chanell_Off_5();
                            break;

                case 6:     chanell_work_flag[chanell] = Chanell_Off_6();
                            break;

                case 7:     chanell_work_flag[chanell] = Chanell_Off_7();
                            break;

                case 8:     chanell_work_flag[chanell] = Chanell_Off_8();
                            break;

                case 9:     chanell_work_flag[chanell] = Chanell_Off_9();
                            break;

                case 10:    chanell_work_flag[chanell] = Chanell_Off_10();
                            break;

                case 11:    chanell_work_flag[chanell] = Chanell_Off_11();
                            break;

                case 12:    chanell_work_flag[chanell] = Chanell_Off_12();
                            break;

                case 13:    chanell_work_flag[chanell] = Chanell_Off_13();
                            break;

                case 14:    chanell_work_flag[chanell] = Chanell_Off_14();
                            break;

                case 15:    chanell_work_flag[chanell] = Chanell_Off_15();
                            break;
            }
            chanell = 0;
            datacode = 0;
            TIM4->CR1 &= ~TIM_CR1_CEN;
            TIM4->CNT = 0;
        }
        if(chanell_work_flag[0] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[0]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[0]-1;
            TIM4->CCR4 = period_count_impulse_chanell[0]-1-200;
            TIM4->ARR = period_count_impulse_chanell[0]-1;
            flag_interrupt = 1;
            chanell_worked_flag[0] = 1;
            PORT_1 = &(GPIOC->ODR);
            PORT_2 = &(GPIOC->ODR);
            number_pin_1 = GPIO_ODR_ODR7;
            number_pin_2 = GPIO_ODR_ODR9;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[1] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[1]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[1]-1;
            TIM4->CCR4 = period_count_impulse_chanell[1]-1-200;
            TIM4->ARR = period_count_impulse_chanell[1]-1;
            flag_interrupt = 1;
            chanell_worked_flag[1] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOC->ODR);
            number_pin_1 = GPIO_ODR_ODR14;
            number_pin_2 = GPIO_ODR_ODR6;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[2] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[2]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[2]-1;
            TIM4->CCR4 = period_count_impulse_chanell[2]-1-200;
            TIM4->ARR = period_count_impulse_chanell[2]-1;
            flag_interrupt = 1;
            chanell_worked_flag[2] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOD->ODR);
            number_pin_1 = GPIO_ODR_ODR11;
            number_pin_2 = GPIO_ODR_ODR13;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[3] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[3]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[3]-1;
            TIM4->CCR4 = period_count_impulse_chanell[3]-1-200;
            TIM4->ARR = period_count_impulse_chanell[3]-1;
            flag_interrupt = 1;
            chanell_worked_flag[3] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOD->ODR);
            number_pin_1 = GPIO_ODR_ODR8;
            number_pin_2 = GPIO_ODR_ODR10;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[4] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[4]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[4]-1;
            TIM4->CCR4 = period_count_impulse_chanell[4]-1-200;
            TIM4->ARR = period_count_impulse_chanell[4]-1;
            flag_interrupt = 1;
            chanell_worked_flag[4] = 1;
            PORT_1 = &(GPIOB->ODR);
            PORT_2 = &(GPIOB->ODR);
            number_pin_1 = GPIO_ODR_ODR13;
            number_pin_2 = GPIO_ODR_ODR15;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[5] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[5]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[5]-1;
            TIM4->CCR4 = period_count_impulse_chanell[5]-1-200;
            TIM4->ARR = period_count_impulse_chanell[5]-1;
            flag_interrupt = 1;
            chanell_worked_flag[5] = 1;
            PORT_1 = &(GPIOE->ODR);
            PORT_2 = &(GPIOB->ODR);
            number_pin_1 = GPIO_ODR_ODR15;
            number_pin_2 = GPIO_ODR_ODR11;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[6] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[6]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[6]-1;
            TIM4->CCR4 = period_count_impulse_chanell[6]-1-200;
            TIM4->ARR = period_count_impulse_chanell[6]-1;
            flag_interrupt = 1;
            chanell_worked_flag[6] = 1;
            PORT_1 = &(GPIOE->ODR);
            PORT_2 = &(GPIOE->ODR);
            number_pin_1 = GPIO_ODR_ODR12;
            number_pin_2 = GPIO_ODR_ODR14;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[7] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[7]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[7]-1;
            TIM4->CCR4 = period_count_impulse_chanell[7]-1-200;
            TIM4->ARR = period_count_impulse_chanell[7]-1;
            flag_interrupt = 1;
            chanell_worked_flag[7] = 1;
            PORT_1 = &(GPIOE->ODR);
            PORT_2 = &(GPIOE->ODR);
            number_pin_1 = GPIO_ODR_ODR9;
            number_pin_2 = GPIO_ODR_ODR11;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[8] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[8]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[8]-1;
            TIM4->CCR4 = period_count_impulse_chanell[8]-1-200;
            TIM4->ARR = period_count_impulse_chanell[8]-1;
            flag_interrupt = 1;
            chanell_worked_flag[8] = 1;
            PORT_1 = &(GPIOB->ODR);
            PORT_2 = &(GPIOE->ODR);
            number_pin_1 = GPIO_ODR_ODR2;
            number_pin_2 = GPIO_ODR_ODR8;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[9] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[9]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[9]-1;
            TIM4->CCR4 = period_count_impulse_chanell[9]-1-200;
            TIM4->ARR = period_count_impulse_chanell[9]-1;
            flag_interrupt = 1;
            chanell_worked_flag[9] = 1;
            PORT_1 = &(GPIOC->ODR);
            PORT_2 = &(GPIOB->ODR);
            number_pin_1 = GPIO_ODR_ODR5;
            number_pin_2 = GPIO_ODR_ODR1;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[10] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[10]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[10]-1;
            TIM4->CCR4 = period_count_impulse_chanell[10]-1-200;
            TIM4->ARR = period_count_impulse_chanell[10]-1;
            flag_interrupt = 1;
            chanell_worked_flag[10] = 1;
            PORT_1 = &(GPIOA->ODR);
            PORT_2 = &(GPIOC->ODR);
            number_pin_1 = GPIO_ODR_ODR6;
            number_pin_2 = GPIO_ODR_ODR4;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[11] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[11]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[11]-1;
            TIM4->CCR4 = period_count_impulse_chanell[11]-1-200;
            TIM4->ARR = period_count_impulse_chanell[11]-1;
            flag_interrupt = 1;
            chanell_worked_flag[11] = 1;
            PORT_1 = &(GPIOA->ODR);
            PORT_2 = &(GPIOA->ODR);
            number_pin_1 = GPIO_ODR_ODR0;
            number_pin_2 = GPIO_ODR_ODR2;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[12] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[12]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[12]-1;
            TIM4->CCR4 = period_count_impulse_chanell[12]-1-200;
            TIM4->ARR = period_count_impulse_chanell[12]-1;
            flag_interrupt = 1;
            chanell_worked_flag[12] = 1;
            PORT_1 = &(GPIOB->ODR);
            PORT_2 = &(GPIOE->ODR);
            number_pin_1 = GPIO_ODR_ODR8;
            number_pin_2 = GPIO_ODR_ODR0;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[13] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[13]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[13]-1;
            TIM4->CCR4 = period_count_impulse_chanell[13]-1-200;
            TIM4->ARR = period_count_impulse_chanell[13]-1;
            flag_interrupt = 1;
            chanell_worked_flag[13] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOB->ODR);
            number_pin_1 = GPIO_ODR_ODR7;
            number_pin_2 = GPIO_ODR_ODR4;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[14] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[14]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[14]-1;
            TIM4->CCR4 = period_count_impulse_chanell[14]-1-200;
            TIM4->ARR = period_count_impulse_chanell[14]-1;
            flag_interrupt = 1;
            chanell_worked_flag[14] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOD->ODR);
            number_pin_1 = GPIO_ODR_ODR4;
            number_pin_2 = GPIO_ODR_ODR6;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
        if(chanell_work_flag[15] && flag_interrupt == 0)
        {
            TIM4->CCR2 = duration_count_impulse_chanell[15]-70;
            TIM4->CCR3 = duration_count_impulse_chanell[15]-1;
            TIM4->CCR4 = period_count_impulse_chanell[15]-1-200;
            TIM4->ARR = period_count_impulse_chanell[15]-1;
            flag_interrupt = 1;
            chanell_worked_flag[15] = 1;
            PORT_1 = &(GPIOD->ODR);
            PORT_2 = &(GPIOD->ODR);
            number_pin_1 = GPIO_ODR_ODR1;
            number_pin_2 = GPIO_ODR_ODR3;
            TIM4->CNT = 0;
            TIM4->CR1 |= TIM_CR1_CEN;
        }
    }
}

void TIM3_IRQHandler()
{
    if(TIM3->SR & TIM_SR_CC1IF)
    {
        GPIOD->ODR |= GPIO_ODR_ODR0;
        TIM3->SR &= ~TIM_SR_CC1IF;
    }
    if(TIM3->SR & TIM_SR_CC2IF)
    {
        GPIOC->ODR |= GPIO_ODR_ODR12;
        TIM3->SR &= ~TIM_SR_CC2IF;
    }
    if(TIM3->SR & TIM_SR_CC3IF)
    {
        GPIOC->ODR &= ~GPIO_ODR_ODR12;
        TIM3->SR &= ~TIM_SR_CC3IF;
    }
    if(TIM3->SR & TIM_SR_CC4IF)
    {
        GPIOD->ODR &= ~GPIO_ODR_ODR0;
        TIM3->SR &= ~TIM_SR_CC4IF;
    }
    if(TIM3->SR & TIM_SR_UIF)
    {
        TIM3->SR &= ~TIM_SR_UIF;
        TIM3->CR1 &= ~TIM_CR1_CEN;
    }
}

void TIM4_IRQHandler()
{
    if(TIM4->SR & TIM_SR_CC1IF)
    {
        TIM4->SR &= ~TIM_SR_CC1IF;
        *PORT_1 |= number_pin_1;
        if(condition)
        {
            TIM3->CNT = 0;
            TIM3->CR1 |= TIM_CR1_CEN;
        }
    }
    if(TIM4->SR & TIM_SR_CC2IF)
    {
        TIM4->SR &= ~TIM_SR_CC2IF;
        *PORT_1 &= ~number_pin_1;
    }
    if(TIM4->SR & TIM_SR_CC3IF)
    {
        TIM4->SR &= ~TIM_SR_CC3IF;
        *PORT_2 |= number_pin_2;
    }
    if(TIM4->SR & TIM_SR_CC4IF)
    {
        TIM4->SR &= ~TIM_SR_CC4IF;
        *PORT_2 &= ~number_pin_2;
    }
    if(TIM4->SR & TIM_SR_UIF)
    {
        TIM4->SR &= ~TIM_SR_UIF;
        TIM4->CR1 &= ~TIM_CR1_CEN;
        TIM4->CNT = 0;
        flag_interrupt = 0;
    }
}
