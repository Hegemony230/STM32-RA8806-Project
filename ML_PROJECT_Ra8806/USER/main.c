#include "stm32f10x.h"
#include "stdio.h"
#include "usart1.h"
#include "delay.h"
#include "gpio.h"
#include "sys.h"
#include "ra8806.h"
#define ON 0
#define OFF 1
#define LED1(a) if(a) GPIO_SetBits(GPIOB,GPIO_Pin_0);else GPIO_ResetBits(GPIOB,GPIO_Pin_0)
#define LED0(a) if(a) GPIO_SetBits(GPIOB,GPIO_Pin_8);else GPIO_ResetBits(GPIOB,GPIO_Pin_8)
unsigned char string[80]={"曾经沧海难为水，除却巫山不是云。取次花丛懒回顾，半缘修道半缘君。"};
int main(void)
{
  SystemInit();
	GPIO_Configuration();
	//USART1_Config();
	//NVIC_Configuration();
	//NVIC_Configuration1();

	delay_init(72);	     //延时初始化											   
  SOFTRST();
	LCD_Init();   
	LCD_Clear();
	LCD_ShowString(0,0,"2015/4/22");
	
	LCD_ShowNchar(0,16,string,32);
	LCD_ShowNchar(0,32,string+32,32);
	while(1)
	{
      //	prinf("\r\n  LOVE   \r\n" );
	  LED0(ON);
//	  delay_ms(500);
	  delay_ms(500);
	  LED0(OFF);
//	  delay_ms(500);
	  delay_ms(500);
	 
	
	
	}


}

