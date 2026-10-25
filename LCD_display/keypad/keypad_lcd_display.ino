#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { 1,  2,  3,  4},
  { 5,  6,  7,  8},
  { 9, 10, 11, 12},
  {13, 14, 15, 16}
};

byte rowPins[ROWS] = {12, 11, 10, 9};
byte colPins[COLS] = {5, 6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Nyzhnyk Mariia");

  lcd.setCursor(0, 1);
  lcd.print("Przycisk nr:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    int buttonNum = (int)key; 

    lcd.setCursor(12, 1);

    if (buttonNum >= 10) {
      lcd.print(buttonNum);
    } else {
      lcd.print(buttonNum);
      lcd.print(" "); 
    }
  }
}
