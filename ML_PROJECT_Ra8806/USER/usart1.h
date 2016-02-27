#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>

void USART1_Config(void);
void NVIC_Configuration(void);
int fputc(int ch, FILE *f);
void USART3_Config(void);
void NVIC_Configuration1(void);
void Uart1_PutChar(u8 ch);
void Uart3_PutChar(u8 ch1);
#endif /* __USART1_H */
