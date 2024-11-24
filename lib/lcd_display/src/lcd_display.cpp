#include <LiquidCrystal_I2C.h>

#define LCD_COLUMNS 16
#define LCD_ROWS 2

static LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);

void lcd_init() 
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void lcd_clear() 
{
    lcd.clear();
}

void lcd_print(int row, int col, const char* text) 
{
    lcd.setCursor(col, row);
    lcd.print(text);
}

void lcd_print(int row, int col, int number) 
{
    lcd.setCursor(col, row);
    lcd.print(number);
}