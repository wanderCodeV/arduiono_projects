#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

uint8_t heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};

void setup() {
  lcd.createChar(3, heart);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("  I \x03 Arduino");
}

void loop() { }