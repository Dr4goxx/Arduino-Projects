//By Matthew Wong
//Displays Time Weather Temperature
//Controlled using three buttons

#include <LiquidCrystal.h>

const int goLeft = 8;
const int goMid = 7;
const int goRight = 6;
const int tempSensor = A0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


bool leftOne = true;
bool midOne = true;
bool rightOne = true;


//set the time here
int h = 1; //hour
int m = 3; //minutes
int s = 50; //seconds
int d = 20; //date
int flag = 13; //24 hour time
int TIME;
int state1;

int temper;
double temp;


void setup() {
  // put your setup code here, to run once:
  pinMode(goLeft, INPUT_PULLUP);
  pinMode(goRight, INPUT_PULLUP);
  pinMode(goMid, INPUT_PULLUP);
  Serial.begin(9600);

  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.print("This is a mini");
  lcd.setCursor(0, 1);
  lcd.print("weather app!");




  //lcd.print("Hello friends");
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.display();

  buttonSelection();
  incrementSecs();

  if (leftOne == false)
  {
    lcd.clear();
    clockthing();
  }

  else if (midOne == false)
  {
    lcd.clear();
    datething();
  }
  else if (rightOne == false)
  {
    lcd.clear();
    temperaturething();
  }

  if (s == 59) {
    s = -1;
    m = m + 1;
  }
  if (m == 59)
  {
    m = -1;
    h = h + 1;
    flag = flag + 1;
  }
  if (h == 13)
  {
    h = 1;
  }

  if (flag == 24) {
    d = d + 1;
    flag = 0;
  }

  //this it the temperature reading part
  temper = analogRead(A0);
  temp = tempthing(temper);
}

void incrementSecs() {
  s = s + 1;
  delay(1000);
}

void buttonSelection() {
  int goLeftState, goRightState, goMidState;

  goLeftState = digitalRead(goLeft);
  goRightState = digitalRead(goRight);
  goMidState = digitalRead(goMid);

  //s = s + 1;
  if (goLeftState == LOW)
  {
    leftOne = false;
    midOne = true;
    rightOne = true;

  }
  else if (goMidState == LOW)
  {
    midOne = false;
    leftOne = true;
    rightOne = true;

  }
  else if (goRightState == LOW)
  {
    rightOne = false;
    midOne = true;
    leftOne = true;
  }

  //delay(1000);
}

void clockthing()
{
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("TIME:");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);

  if (flag < 12)lcd.print("AM");
  if (flag == 12)lcd.print("PM");
  if (flag > 12)lcd.print("PM");
  if (flag == 24)flag = 0;


}

void datething()
{
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("DATE:");
  lcd.print("2018/7/");
  lcd.print(d);
}

double tempthing(int RawTemp) {  //Function to perform the fancy math of the Steinhart-Hart equation
  double Temp;
  Temp = log(10000.0 * ((1024.0 / RawTemp - 1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;// Convert Kelvin to Celcius
  Temp = Temp + 32;
  return Temp;
}

void temperaturething()
{
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("TEMP:");
  lcd.print(temp);
  lcd.print("C");
}
