#include "ra8806.h"
#include "stdio.h"
#include "delay.h"

//��λ
void SOFTRST()
{
    delay_ms(2);
    CS=0;
    RD=1;
    RST=0;
    delay_ms(5);
    RST=1;
    delay_ms(5);
}
//д�Ĵ������
void LCD_WR_REG(u8 data)
{
      CS=0;//ѡ��Ƭ
      RD=1;//�������ݶ���
      RS=1;//ָ��
      DATAOUT(data);
      WR=0;//����д��
      WR=1;//����д�����
      CS=1;//ȡ��Ƭѡ
      
}
//д�Ĵ�����ֵ
void LCD_WR_DATA(u8 data)
{
      CS=0;
      RD=1;
      RS=0;//����
      DATAOUT(data);
      WR=0;
      WR=1;
      CS=1;
}
//д�Ĵ���
void LCD_WriteReg(u8 LCD_Reg,u8 LCD_RegValue)
{
      LCD_WR_REG(LCD_Reg);
      LCD_WR_DATA(LCD_RegValue);
}

//����
void LCD_Clear(void)
{
    LCD_WriteReg(WLCR,0X40);//ѡ���ͼģʽ
    LCD_WriteReg(MISC,0X40);//�ر�����ѩ������
    LCD_WriteReg(PNTR,0X00);//����
    LCD_WriteReg(FNCR,0XA8);
    delay_ms(3);
}

//��������
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{
     LCD_WR_REG(0X60);
     LCD_WR_DATA(Xpos);
     LCD_WR_REG(0X70);
     LCD_WR_DATA(Ypos);
      
}

//��ʾһ���ַ�
void LCD_ShowChar(u16 Xpos,u16 Ypos,u8 chr)
{
      LCD_WriteReg(WLCR,0x0c);//�ı���ʾ
      LCD_WriteReg(MISC,0X84);//����ѩ��ģʽ
			LCD_WriteReg(WCCR,0X20);//������ʾ 
			LCD_SetCursor(Xpos,Ypos);//����
      LCD_WriteReg(MWCR,chr);
}

//��ʾ�ַ���
void LCD_ShowString(u16 Xpos,u16 Ypos,const u8 *p)
{
#define MAX_CHAR_POSX  314
#define MAX_CHAR_POSY  234      
    while(*p!='\0')
    {
          if(Xpos>MAX_CHAR_POSX){Xpos=0;Ypos+=16;}
          if(Ypos>MAX_CHAR_POSY){Ypos=Xpos=0;LCD_Clear();}
          LCD_ShowChar(Xpos,Ypos,*p);
					delay_ms(1);//���������ʱ��ʾ���������Ժ�Ҫ�ĳɲ�BUSY���ܻ��Щ
          Xpos+=1;
          ++p;
      }
}
//��ʾ�ַ���
void LCD_ShowNchar(u16 Xpos,u16 Ypos,u8 *p,u16 Length)
{
#define MAX_CHAR_POSX  314
#define MAX_CHAR_POSY  234
    u8 *pstart = NULL;
	  pstart = p;
    while((p-pstart)<Length)
    {
          if(Xpos>MAX_CHAR_POSX){Xpos=0;Ypos+=16;}
          if(Ypos>MAX_CHAR_POSY){Ypos=Xpos=0;LCD_Clear();}
          LCD_ShowChar(Xpos,Ypos,*p);
					delay_ms(1);//���������ʱ��ʾ���������Ժ�Ҫ�ĳɲ�BUSY���ܻ��Щ
          Xpos+=1;
          ++p;
      }
}
//��ʼ��RA8806
void LCD_Init(void)
{
      RCC->APB2ENR|=1<<5;//����PORTDʱ��
      RCC->APB2ENR|=1<<4;//����PORTCʱ��
//8080ģʽ
 //     JTAG_Set(SWD_ENABLE);
      GPIOD->CRL=0X33333333;
      GPIOD->ODR|=0XFFFF;
      
      GPIOC->CRH&=0XFFF00000;
      GPIOC->CRL&=0X00FFFFFF;
      GPIOC->CRH|=0X00033333;
      GPIOC->CRL|=0X33000000;//�������
      GPIOC->ODR|=0X1FC0;//����ߵ�ƽ
      
       LCD_WriteReg(WLCR,0x04);
       LCD_WriteReg(MISC,0x08);
       LCD_WriteReg(ADSR,0x00);
       LCD_WriteReg(INTR,0x00);
       LCD_WriteReg(WCCR,0x00);
       LCD_WriteReg(CHWI,0x00);
       LCD_WriteReg(MAMR,0x11);
       LCD_WriteReg(AWRR,0x27);
       LCD_WriteReg(DWWR,0x27);
       LCD_WriteReg(AWBR,0xef);
       LCD_WriteReg(DWHR,0xef);
       LCD_WriteReg(AWLR,0x00);
       LCD_WriteReg(AWTR,0x00);
       LCD_WriteReg(CURX,0x00);
       LCD_WriteReg(BGSG,0x00);
       LCD_WriteReg(EDSG,0x00);
       LCD_WriteReg(CURY,0x00);
       LCD_WriteReg(BGCM,0x00);
       LCD_WriteReg(EDCM,0x00);
       LCD_WriteReg(BTMR,0x00);
       LCD_WriteReg(ITCR,0x80);
       LCD_WriteReg(PNTR,0x00);
       LCD_WriteReg(FNCR,0x00);
       LCD_WriteReg(FVHT,0x00);
 }
