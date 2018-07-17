//Made by Matthew Wong

const int ledPin = 6;
const int sensorPin = A0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  Serial.println("#####     Light Sensor ########");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  Serial.print("Light Sensor =  ");
  Serial.print(sensorValue);
  //delay(200);

  int lightLevel = map( sensorValue, 250, 750, 0, 255);
  lightLevel = constrain(lightLevel, 0 ,255);
  Serial.print("    LED Value =  ");
  Serial.println(lightLevel);
  analogWrite(ledPin, lightLevel);
//  delay(2000);
}
