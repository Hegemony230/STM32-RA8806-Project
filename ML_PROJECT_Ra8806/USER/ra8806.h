#ifndef __RA8806_H
#define __RA8806_H
#include "sys.h"
#include "stdlib.h"
#include "stm32f10x.h"
//�˿ڶ���
#define RD PCout(7)//�͵�ƽ���ݶ������ߵ�ƽ��Ч
#define WR PCout(6)//�͵�ƽ����д�룬�ߵ�ƽ��Ч
#define RS PCout(9)//�ߵ�ƽ����ָ��͵�ƽ��������
#define CS PCout(8)//ʹ���źţ��͵�ƽ��Ч
#define BUSY PCout(10)//ϵͳæ�ж��ź�
#define INT PCout(11)//ϵͳ�����ж��ź�
#define RST PCout(12)//��λ
//PB0~7��Ϊ������
#define DATAOUT(x) GPIOD->ODR=(GPIOD->ODR&0xff00)|(x&0x00ff);//���
//���ƺ���
void LCD_Init(void);//��ʼ��
void SOFTRST(void);
//void LCD_DisplayOn(void);//����ʾ
//void LCD_DisplayOff(void);//����ʾ
void LCD_Clear(void);//����	 
void LCD_SetCursor(u16 Xpos, u16 Ypos);//��������
void LCD_ShowChar(u16 Xpos,u16 Ypos,u8 chr);//��ʾһ���ַ�
void LCD_ShowString(u16 Xpos,u16 Ypos,const u8 *p);//��ʾ�ַ���
void display_word(const u8 *cha,u8 n);   //��ʾ��������  								    
void LCD_WriteReg(u8 LCD_Reg, u8 LCD_RegValue);//д�Ĵ��� �Ĵ������ Ҫд�����ֵ
void LCD_ShowNchar(u16 Xpos,u16 Ypos,u8 *p,u16 Length);
//RA8806�Ĵ���
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
