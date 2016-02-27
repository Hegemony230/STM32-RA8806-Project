#ifndef __RA8806_H
#define __RA8806_H
#include "sys.h"
#include "stdlib.h"
#include "stm32f10x.h"
//端口定义
#define RD PCout(7)//低电平数据读出，高电平无效
#define WR PCout(6)//低电平数据写入，高电平无效
#define RS PCout(9)//高电平——指令，低电平——数据
#define CS PCout(8)//使能信号，低电平有效
#define BUSY PCout(10)//系统忙判断信号
#define INT PCout(11)//系统发生中断信号
#define RST PCout(12)//复位
//PB0~7，为数据线
#define DATAOUT(x) GPIOD->ODR=(GPIOD->ODR&0xff00)|(x&0x00ff);//输出
//控制函数
void LCD_Init(void);//初始化
void SOFTRST(void);
//void LCD_DisplayOn(void);//开显示
//void LCD_DisplayOff(void);//关显示
void LCD_Clear(void);//清屏	 
void LCD_SetCursor(u16 Xpos, u16 Ypos);//设置坐标
void LCD_ShowChar(u16 Xpos,u16 Ypos,u8 chr);//显示一个字符
void LCD_ShowString(u16 Xpos,u16 Ypos,const u8 *p);//显示字符串
void display_word(const u8 *cha,u8 n);   //显示正常汉字  								    
void LCD_WriteReg(u8 LCD_Reg, u8 LCD_RegValue);//写寄存器 寄存器编号 要写入的数值
void LCD_ShowNchar(u16 Xpos,u16 Ypos,u8 *p,u16 Length);
//RA8806寄存器
#define WLCR	0x00
#define MISC	0x01
#define ADSR	0x03
#define INTR	0x0F
#define WCCR	0x10
#define CHWI      0x11						//new(have change)
#define MAMR	0x12
#define AWRR	0x20
#define DWWR	0x21
#define AWBR	0x30
#define DWHR	0x31						//new(have change)
#define AWLR	0x40
#define AWTR	0x50
#define CURX	0x60						//new(have change)
#define BGSG	0x61
#define EDSG      0x62						//new
#define CURY	0x70						//new(have change)	
#define BGCM	0x71
#define EDCM	0x72
#define BTMR	0x80
#define ITCR	0x90						//new(have change)
#define KSCR1	0xA0
#define KSCR2	0xA1
#define KSDR0  	0xA2						//new(have change)
#define KSDR1  	0xA3
#define KSDR2  	0xA4
#define MWCR	0xB0						//new(have change)
#define MRCR	0xB1						//new
#define TPCR	0xC0
#define TPXR	0xC1
#define TPYR	0xC2
#define TPZR	0xC3
#define PCR       0xD0						//new(have change)
#define PDCR      0xD1						//new
#define PNTR	0xE0
#define FNCR	0xF0
#define FVHT	0xF1
#endif
