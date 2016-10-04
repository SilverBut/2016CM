/*
 * lcd.c
 *
 *  Created on: Sep 20, 2016
 *      Author: evidence
 */
#include "ee.h"
#include "lcd1602.h"

#define CGRAM_ADDR(ch,row) ((ch<<3)+row)

__INLINE__ void lcd_delay(int val){
	for ( int i = 0 ; i < 1 ; i++)
		for ( ; val>0; val--)
			;
	return;
}

void lcd_setrs(EE_UREG val){
	SIU_GPIO[LCD_RS] = val==1;
}

void lcd_setrw(EE_UREG val){
	SIU_GPIO[LCD_RW] = val==1;
}

void lcd_seten(EE_UREG val){
	SIU_GPIO[LCD_EN] = val==1;
}

void lcd_setport(EE_UINT8 val){
	SIU_PGPDI[5] = (val&0xff)<<24;
}

EE_UINT8 lcd_getport(void){
	return (SIU_PGPDI[5]&0xff000000)>>24;
}

__INLINE__ void lcd_waitbusy(void){
	lcd_setport(0xff);
	lcd_setrs(0);lcd_setrw(1);lcd_seten(1);
	int i = 10;
	while(i--);
	while(lcd_getport()&0x80);
	lcd_seten(0);
}

__INLINE__ void lcd_writecmd(EE_UINT8 val){
	lcd_setrs(0);lcd_setrw(0);
	lcd_setport(val);
	lcd_delay(5);
	lcd_seten(1);
	lcd_delay(5);
	lcd_seten(0);
}

__INLINE__ void lcd_set_cgram_addr(EE_UINT8 addr){
	lcd_writecmd(0x40+addr);
}

__INLINE__ void lcd_set_ddram_addr(EE_UINT8 addr){
	lcd_writecmd(0x80+addr);
}

__INLINE__ void lcd_read_ram_data(EE_UINT8 val){
	lcd_setrs(1);lcd_setrw(1);
	lcd_setport(val);
	lcd_delay(5);
	lcd_seten(1);
	lcd_delay(5);
	lcd_seten(0);
}

__INLINE__ void lcd_write_ram_data(EE_UINT8 val){
	lcd_setrs(1);lcd_setrw(0);
	lcd_setport(val);
	lcd_delay(5);
	lcd_seten(1);
	lcd_delay(5);
	lcd_seten(0);
}

void lcd_portinit(void){
	SIU_PCR_D0 = 0x200;
	SIU_PCR_D1 = 0x200;
	SIU_PCR_D2 = 0x200;
	SIU_PCR_D3 = 0x200;
	SIU_PCR_D4 = 0x200;
	SIU_PCR_D5 = 0x200;
	SIU_PCR_D6 = 0x200;
	SIU_PCR_D7 = 0x200;
	SIU_PCR_RS = 0x200;
	SIU_PCR_RW = 0x200;
	SIU_PCR_EN = 0x200;
	return;
}

void lcd_init(void){
	lcd_seten(0);
	lcd_writecmd(0x83);
	lcd_writecmd(0x0c);
	lcd_writecmd(0x06);
	lcd_writecmd(0x3f);
	lcd_writecmd(0x01);
	return;
}

void lcd_sendchar(EE_UINT8 ch, EE_UINT8 row, EE_UINT8 col){
	//in fact, we are setting ddram address and write data
	//lcd_writecmd(col + (row==0?0x80:0xc0));
	lcd_set_ddram_addr(col+(row<<6));
	lcd_write_ram_data(ch);
	return;
}

void lcd_set_custom_char(EE_UINT8 id, EE_UINT8* model){
	for ( int row = 0 ; row < 7 ; row++ ){
		lcd_set_cgram_addr(CGRAM_ADDR(id,row));
		lcd_write_ram_data((model[row])&0x1F);
	}
	return;
}
