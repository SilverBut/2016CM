/*
 * lcd1602.h
 *
 *  Created on: Sep 18, 2016
 *      Author: evidence
 */

#ifndef LCD1602_H_
#define LCD1602_H_

#include "ee.h"

#define SIU_BASE	0xc3f90000

#define SIU_PCRS	((volatile EE_UINT16 *)SIU_BASE)

/* Leds */
#define LCD_D0 160
#define LCD_D1 161
#define LCD_D2 162
#define LCD_D3 163
#define LCD_D4 164
#define LCD_D5 165
#define LCD_D6 166
#define LCD_D7 167
#define LCD_RW 179
#define LCD_RS 180
#define LCD_EN 181

#define SIU_PCR_D0  SIU_PCRS[LCD_D0]
#define SIU_PCR_D1  SIU_PCRS[LCD_D1]
#define SIU_PCR_D2  SIU_PCRS[LCD_D2]
#define SIU_PCR_D3  SIU_PCRS[LCD_D3]
#define SIU_PCR_D4  SIU_PCRS[LCD_D4]
#define SIU_PCR_D5  SIU_PCRS[LCD_D5]
#define SIU_PCR_D6  SIU_PCRS[LCD_D6]
#define SIU_PCR_D7  SIU_PCRS[LCD_D7]

#define SIU_PCR_RW  SIU_PCRS[LCD_RW]
#define SIU_PCR_RS  SIU_PCRS[LCD_RS]
#define SIU_PCR_EN  SIU_PCRS[LCD_EN]

#define SIU_PGPDO   ((volatile EE_UINT32 *)(SIU_BASE + 0x0C00))
#define SIU_PGPDI   ((volatile EE_UINT32 *)(SIU_BASE + 0x0C40))

#define SIU_GPIO	((volatile EE_UINT8 *)(SIU_BASE + 0x0600))

#define SIU_IREER	(*(volatile EE_UINT32 *)(SIU_BASE + 0x0028))
#define SIU_IFEER	(*(volatile EE_UINT32 *)(SIU_BASE + 0x002c))

#define SIU_EISR	(*(volatile EE_UINT32 *)(SIU_BASE + 0x0014))

#define SIU_DIRER	(*(volatile EE_UINT32 *)(SIU_BASE + 0x0018))

#define SIU_DIRSR	(*(volatile EE_UINT32 *)(SIU_BASE + 0x001c))

#define SIU_EIISR	(*(volatile EE_UINT32 *)(SIU_BASE + 0x0904))

void lcd_portinit(void);
void lcd_init(void);
void lcd_sendchar(EE_UINT8 ch, EE_UINT8 row, EE_UINT8 col);
void lcd_set_char(EE_UINT8 ch, EE_UINT8* graph);
void lcd_set_custom_char(EE_UINT8 id, EE_UINT8* model);

#endif /* LCD1602_H_ */
