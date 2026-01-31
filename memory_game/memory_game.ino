#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,20,4);

const int LED_PINS[] = {2, 3, 4};
const int BUTTON_PINS[] = {8, 9, 10};
int buttonState = 0;
int tab[35];
int read[35];
int nread;
int n = 5;
int lastButtonState[3] = {HIGH, HIGH, HIGH};

void generate(int n) {
  Serial.println("Start nowej gry:");
  nread = 0;
  
  lcd.clear();
  lcd.print("Gra Memory");
  lcd.setCursor(0, 1);
  lcd.print("Licznik:");
  lcd.print(nread);

  for(int i = 0; i<n; i++){
    tab[i] = random(3);
    digitalWrite(LED_PINS[tab[i]], HIGH);
    delay(500);
    digitalWrite(LED_PINS[tab[i]], LOW);
    delay(500);
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  for(auto pin: LED_PINS)
  {
    pinMode(pin, OUTPUT);
  }
  for(auto pin: BUTTON_PINS)
  {
    pinMode(pin, INPUT_PULLUP);
  }
  generate(n);
}



void loop() {
  if(nread == n){
    bool win = true;
    for(int i =0; i<n; i++){
      Serial.print("Wylosowano: ") ;
      Serial.print(tab[i]);
      Serial.print(" memory: ");
      Serial.println(read[i]);
      if(read[i]!=tab[i])
        win = false;
    } 
    lcd.setCursor(0, 1);
    if(win){
      lcd.print("Wygrana :)");
    }
    else
    {
      lcd.print("PRZEGRANA :(");
    }
    delay(10000);

    generate(n);
  }

  for(int i = 0; i < 3; i++)
  {
    buttonState = digitalRead(BUTTON_PINS[i]);
    if(buttonState == LOW && lastButtonState[i] == HIGH)
    {    
      read[nread] = i;
      nread++;

      digitalWrite(LED_PINS[i], HIGH);
      delay(200);
      digitalWrite(LED_PINS[i], LOW);
      
      lcd.setCursor(8, 1);
      lcd.print(nread);
  
      Serial.print("Pressed: ");
      Serial.print(i);
      Serial.print("  nread: ");
      Serial.println(nread);
    } 
    lastButtonState[i] = buttonState;
  }
      
}
