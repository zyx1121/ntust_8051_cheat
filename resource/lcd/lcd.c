/*
 * Copyright (c) 2009, Zilogic Systems <code@zilogic.com>
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose with or without fee is hereby granted, provided
 * that the above copyright notice and this permission notice appear
 * in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* Implement all functions on LCD */

#include <REGX51.H>

#include "lcd.h"
#include "delay.h"

#define LCD_RS P3_3
#define LCD_WR P3_4
#define LCD_EN P3_5
#define LCD_D7		P2_3
#define LCD_D6		P2_2
#define LCD_D5		P2_1
#define LCD_D4		P2_0

#define LCD_MAX_ROWS	2
#define LCD_MAX_COLS	18

#define LCD_CMD_CLEAR		0x01
#define LCD_CMD_CURSOR_HOME	0x02
#define LCD_CMD_CURSOR_LEFT	0x10
#define LCD_CMD_CURSOR_RIGHT 	0x14
#define LCD_CMD_CURSOR_ON	0x0D
#define LCD_CMD_CURSOR_OFF	0x0C



void lcd_define_char(unsigned char address, unsigned char *pattern);
void lcd_write_data(unsigned char val);
void lcd_write_cmd(unsigned char cmd);
void lcd_write_cmd_4bit(unsigned char cmd);


code unsigned char LCD_CHAR_UP_ARROW[] = {
	0x1f, 0x1b, 0x11, 0x0a, 0x1b, 0x1b, 0x1b, 0x1f
};

code unsigned char LCD_CHAR_DOWN_ARROW[] = {
	0x1f, 0x1b, 0x1b, 0x1b, 0x0a, 0x11, 0x1b, 0x1f
};

code unsigned char LCD_CHAR_BAR5[] = {
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f
};

void lcd_init(void)
{
	DelayX1ms(40);		// LCD Power on delay
	lcd_write_cmd_4bit(0x20);	// 8BIT, 2 LINE , 5x7 DOT Format font
	DelayX1ms(5);		// Small dealy
	lcd_write_cmd(0x28);
	DelayX1ms(1);
	lcd_write_cmd(0x28);
	DelayX1ms(1);
	lcd_write_cmd(0x08);
	DelayX1ms(1);
	lcd_write_cmd(0x06);
	DelayX1ms(1);
	lcd_write_cmd(0x0c);
	DelayX1ms(1);
	lcd_clear_row(0);
	lcd_clear_row(1);
	//lcd_define_char(0, LCD_CHAR_UP_ARROW);
	//lcd_define_char(1, LCD_CHAR_DOWN_ARROW);
	//lcd_define_char(2, LCD_CHAR_BAR5);
}

void lcd_printc(unsigned char a_char)
{
	lcd_write_data(a_char);
}

void lcd_prints(char *string)
{
	while (*string)
		lcd_printc(*string++);
}

void lcd_clear(void)
{
	lcd_write_cmd(LCD_CMD_CLEAR);
	DelayX1ms(2);
}

void lcd_clear_row(char row)
{
	char i = 0;
	lcd_move_cursor(row, 0);
	while (i < LCD_MAX_COLS) {
		lcd_printc(' ');
		i++;
	}
	lcd_move_cursor(row, 0);
}

void lcd_cursor_on(void)
{
	lcd_write_cmd(LCD_CMD_CURSOR_ON);
}

void lcd_cursor_off(void)
{
	lcd_write_cmd(LCD_CMD_CURSOR_OFF);
}

void lcd_move_cursor(unsigned char row, unsigned char column)
{
	switch (row) {
	case 0:
		lcd_write_cmd(0x80 + column);
		break;
	case 1:
		//lcd_write_cmd(0xc0 + column);
		lcd_write_cmd(0x90 + column);   //for chinese LCD
		break;
	default:
		break;
	}
}

void lcd_move_cursor_left(void)
{
	lcd_write_cmd(LCD_CMD_CURSOR_LEFT);
}

void lcd_move_cursor_right(void)
{
	lcd_write_cmd(LCD_CMD_CURSOR_RIGHT);
}

void lcd_move_cursor_home(void)
{
	lcd_write_cmd(LCD_CMD_CURSOR_HOME);
}

void lcd_write_cmd_4bit(unsigned char cmd)
{

	LCD_RS=0;
	LCD_WR=0;
	LCD_EN=0;
	LCD_D4=(cmd&0x10)?1:0;
	LCD_D5=(cmd&0x20)?1:0;
	LCD_D6=(cmd&0x40)?1:0;
	LCD_D7=(cmd&0x80)?1:0;
	LCD_EN=0;
	LCD_EN=1;
	DelayX10us(10);	
	LCD_EN=0;	
}

void lcd_write_cmd(unsigned char cmd)
{

	LCD_RS=0;
	LCD_WR=0;
	LCD_EN=0;
	LCD_D4=(cmd&0x10)?1:0;
	LCD_D5=(cmd&0x20)?1:0;
	LCD_D6=(cmd&0x40)?1:0;
	LCD_D7=(cmd&0x80)?1:0;
	LCD_EN=0;
	LCD_EN=1;
	DelayX10us(10);	
	LCD_EN=0;
	LCD_D4=(cmd&0x01)?1:0;
	LCD_D5=(cmd&0x02)?1:0;
	LCD_D6=(cmd&0x04)?1:0;
	LCD_D7=(cmd&0x08)?1:0;
	LCD_EN=0;
	LCD_EN=1;	
	DelayX10us(10);
	LCD_EN=0;
}


void lcd_write_data(unsigned char val)
{
	LCD_RS=1;
	LCD_WR=0;
	LCD_EN=0;
	LCD_D4=(val&0x10)?1:0;
	LCD_D5=(val&0x20)?1:0;
	LCD_D6=(val&0x40)?1:0;
	LCD_D7=(val&0x80)?1:0;
	LCD_EN=0;
	LCD_EN=1;
	DelayX10us(10);		
	LCD_EN=0;
	LCD_D4=(val&0x01)?1:0;
	LCD_D5=(val&0x02)?1:0;
	LCD_D6=(val&0x04)?1:0;
	LCD_D7=(val&0x08)?1:0;
	LCD_EN=0;
	LCD_EN=1;	
	DelayX10us(10);	
	LCD_EN=0;
}

void lcd_define_char(unsigned char address, unsigned char *pattern)
{
	char i;
	lcd_write_cmd(0x40 + (address << 3));
	for (i = 0; i < 8; i++) {
		lcd_write_data(*pattern++);
	}
}

void lcd_printl(char lineno, char *msg)
{
	lcd_move_cursor(lineno, 0);
	lcd_clear_row(lineno);
	lcd_prints(msg);
}
