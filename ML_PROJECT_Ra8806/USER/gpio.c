#include "stm32f10x.h"
#include "gpio.h"


void GPIO_Configuration(void)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;        //定义GPIO初始化结构体
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);  //允许GPIOB、AFIO时钟

  /* Configure PE.0,PE.1,PE.2,PE.3,PE.4,PE.5,PE.6,PE.7 as Output push-pull */ 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_8  ; 
 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOB, &GPIO_InitStructure); 
}

