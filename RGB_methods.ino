const int redPin = 9 ;
const int greenPin = 10;
const int bluePin = 11;
 //By Matthew Wong
 //7/17/2018
 

void setup() {
  // put your setup code here, to run once:
   pinMode(redPin, OUTPUT);
   pinMode(greenPin,OUTPUT);
   pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  colourRainbow();
}

void colourRed() {
  digitalWrite(redPin, HIGH);
  analogWrite(greenPin , 0);
  digitalWrite(bluePin, LOW);
  //redHex = 255;
  //greenHex = 0;
  //blueHex = 0;
  
}

void colourRainbow(){
   colourRed();
  delay(1000);
  colourWhite();
  delay(1000);
  colourGreen();
  delay(1000);
  colourBlue();
  delay(1000);
  colourPurple();
  delay(1000);
  colourOff();
  delay(1000);
}

void colourWhite(){
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH); 
}

void colourOff(){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW); 
}

void colourGreen(){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW); 
}

void colourBlue(){
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH); 
}

void colourPurple(){
  analogWrite(redPin, 128);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 128); 
}




