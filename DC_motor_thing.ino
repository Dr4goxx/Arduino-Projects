//By Matthew Wong
//Different options for motors
//serialSpeed includes Console interface for manual speed change


const int motorPin = 10;
void setup() {
  // put your setup code here, to run once:
 pinMode(motorPin, OUTPUT);
 Serial.begin(9600);
 Serial.println("########     Start     ########");
}

void loop() {
  // put your main code here, to run repeatedly:
  //motorOnThenOff();;;;  
  serialSpeed();
}

void motorOnThenOff(){
  int onTime = 3000;
  int offTime = 3000;

 digitalWrite(motorPin, HIGH);
 delay(onTime); 
 digitalWrite(motorPin, LOW);
 delay(offTime);
}

void motorOnThenOffWithSpeed(){
  int speed1 = 200;
  int time1 = 3000;

  int speed2 = 50;
  int time2 = 3000;

  analogWrite(motorPin, speed1);
  delay(time1);
  analogWrite(motorPin, speed2);
  delay(time2);
}

void motorAcceleration(){
  int speed;
  int time = 20;

  for (speed = 0; speed <= 255; speed++){
    analogWrite(motorPin, speed);
    delay(time);
  }

  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin, speed);
    delay(time);
  }
}


void serialSpeed(){
  int speed;
  Serial.println("Type a speed (0-255) into the box above, ");
  Serial.println("then click [send] or press [return]");
  Serial.println();

  while(true)
  {
    while(Serial.available() > 0)
    {
      speed = Serial.parseInt();
      speed = constrain(speed, 0, 255);
      Serial.print("Setting speed to  ");
      Serial.println(speed);
      analogWrite(motorPin, speed);
    }
  }
}


