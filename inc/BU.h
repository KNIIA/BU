#pragma once



void SetupRCC();
void Init_UART();
void Init_DMA_5(uint8_t*);
void Multiplexor_On_Chanell(int);
void Multiplexor_Off_Chanell(int);
void Set_Amplituda_Chanell(int, int, int);
void BU_I2C3_Enable();
void Write_DAC(int, int);
void Send_Byte();
void Init();
void Init_Timer_2();
void Init_Timer_3();
void Init_Timer_4();
char Chanell_On_0();
char Chanell_On_1();
char Chanell_On_2();
char Chanell_On_3();
char Chanell_On_4();
char Chanell_On_5();
char Chanell_On_6();
char Chanell_On_7();
char Chanell_On_8();
char Chanell_On_9();
char Chanell_On_10();
char Chanell_On_11();
char Chanell_On_12();
char Chanell_On_13();
char Chanell_On_14();
char Chanell_On_15();
char Chanell_Off_0();
char Chanell_Off_1();
char Chanell_Off_2();
char Chanell_Off_3();
char Chanell_Off_4();
char Chanell_Off_5();
char Chanell_Off_6();
char Chanell_Off_7();
char Chanell_Off_8();
char Chanell_Off_9();
char Chanell_Off_10();
char Chanell_Off_11();
char Chanell_Off_12();
char Chanell_Off_13();
char Chanell_Off_14();
char Chanell_Off_15();
void Duration_Impulse_Chanell_15(int, int, int, int, int, int, int);
