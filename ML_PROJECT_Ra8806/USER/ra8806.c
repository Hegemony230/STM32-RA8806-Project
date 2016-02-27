#include "ra8806.h"
#include "stdio.h"
#include "delay.h"

//软复位
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
//写寄存器编号
void LCD_WR_REG(u8 data)
{
      CS=0;//选中片
      RD=1;//不是数据读出
      RS=1;//指令
      DATAOUT(data);
      WR=0;//数据写入
      WR=1;//数据写入完成
      CS=1;//取消片选
      
}
//写寄存器的值
void LCD_WR_DATA(u8 data)
{
      CS=0;
      RD=1;
      RS=0;//数据
      DATAOUT(data);
      WR=0;
      WR=1;
      CS=1;
}
//写寄存器
void LCD_WriteReg(u8 LCD_Reg,u8 LCD_RegValue)
{
      LCD_WR_REG(LCD_Reg);
      LCD_WR_DATA(LCD_RegValue);
}

//清屏
void LCD_Clear(void)
{
    LCD_WriteReg(WLCR,0X40);//选择绘图模式
    LCD_WriteReg(MISC,0X40);//关闭消除雪花功能
    LCD_WriteReg(PNTR,0X00);//清屏
    LCD_WriteReg(FNCR,0XA8);
    delay_ms(3);
}

//设置坐标
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{
     LCD_WR_REG(0X60);
     LCD_WR_DATA(Xpos);
     LCD_WR_REG(0X70);
     LCD_WR_DATA(Ypos);
      
}

//显示一个字符
void LCD_ShowChar(u16 Xpos,u16 Ypos,u8 chr)
{
      LCD_WriteReg(WLCR,0x0c);//文本显示
      LCD_WriteReg(MISC,0X84);//消除雪花模式
			LCD_WriteReg(WCCR,0X20);//反向显示 
			LCD_SetCursor(Xpos,Ypos);//坐标
      LCD_WriteReg(MWCR,chr);
}

//显示字符串
void LCD_ShowString(u16 Xpos,u16 Ypos,const u8 *p)
{
#define MAX_CHAR_POSX  314
#define MAX_CHAR_POSY  234      
    while(*p!='\0')
    {
          if(Xpos>MAX_CHAR_POSX){Xpos=0;Ypos+=16;}
          if(Ypos>MAX_CHAR_POSY){Ypos=Xpos=0;LCD_Clear();}
          LCD_ShowChar(Xpos,Ypos,*p);
					delay_ms(1);//不加这个延时显示不正常，以后要改成查BUSY可能会好些
          Xpos+=1;
          ++p;
      }
}
//显示字符串
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
					delay_ms(1);//不加这个延时显示不正常，以后要改成查BUSY可能会好些
          Xpos+=1;
          ++p;
      }
}
//初始化RA8806
void LCD_Init(void)
{
      RCC->APB2ENR|=1<<5;//开启PORTD时钟
      RCC->APB2ENR|=1<<4;//开启PORTC时钟
//8080模式
 //     JTAG_Set(SWD_ENABLE);
      GPIOD->CRL=0X33333333;
      GPIOD->ODR|=0XFFFF;
      
      GPIOC->CRH&=0XFFF00000;
      GPIOC->CRL&=0X00FFFFFF;
      GPIOC->CRH|=0X00033333;
      GPIOC->CRL|=0X33000000;//推挽输出
      GPIOC->ODR|=0X1FC0;//输出高电平
      
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
