#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16,2);
    //lcd.print("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  lcd.print("Im");
  //lcd.display();
  delay(1000);

 //first is vertical, second is horizontal
  lcd.setCursor(2,1);
  lcd.print("Sorry :(");
  delay(2000);

  lcd.clear();

  //lcd.blink();
  //delay(2000);

  //lcd.setCursor(10,2);
  lcd.print("ur still silver");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("tho lol");
  delay(3000);

  lcd.clear();
  //lcd.noBlink();
  
}
