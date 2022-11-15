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

#ifndef __LCD_H__
#define __LCD_H__

void lcd_init();
void lcd_printc(char a_char);
void lcd_prints(char *string);
void lcd_clear_row(char row);
void lcd_clear(void);
void lcd_cursor_on(void);
void lcd_cursor_off(void);
void lcd_move_cursor(unsigned char row, unsigned char column);
void lcd_move_cursor_left(void);
void lcd_move_cursor_right(void);
void lcd_printl(char lineno, char *msg);

#endif
