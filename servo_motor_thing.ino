//By Matthew Wong
//7/17/2018
//Module #8   

#include <Servo.h>

Servo servo1;
const int sensor1 = A0;

void setup() {
  // put your setup code here, to run once:
   servo1.attach(9);
   Serial.begin(9600);
   Serial.println("#####     Light Sensor ########");
   pinMode(sensor1, INPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorState;
  int sensorValue = analogRead(sensor1);
  Serial.print("Light Sensor =  ");
  Serial.print(sensorValue);
  //delay(200);

sensorState = analogRead(sensor1);

if (sensorState < 150){
  servo1.write(90);
  Serial.println("The light level is less than 150.");
}

else if (sensorState > 150 && sensorState < 700){
 servo1.write(-180) ;
 Serial.println("The light level is between 150 and 700.");
}

else{
  Serial.println("The light level is either too high or too low!");
}
}
/*
 servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo1.write(0);
  delay(1000);
*/
