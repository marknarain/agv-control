#pragma once

void lcd_init();
void lcd_clear();
void lcd_print(int row, int col, const char* text);
void lcd_print(int row, int col, int number);