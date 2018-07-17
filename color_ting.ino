/* ayy lmao
 *  
 */  
 

const int redPin = 9 ;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // put your setup code here, to run once:
   //pinMode(ledPin, OUTPUT);
   pinMode(redPin, OUTPUT);
   pinMode(greenPin,OUTPUT);
   pinMode(bluePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite (redPin, 0  );
  analogWrite(greenPin, 0  );
  analogWrite(bluePin, 255);

  
}
/*
void setup() {
  
  pinMode(13, OUTPUT);      // Set pin 13 to output
  
}


void loop() {
  
  digitalWrite(13, HIGH);   // Turn on the LED
  
  delay(2000);              // Wait for two seconds

  digitalWrite(13, LOW);    // Turn off the LED
  
  delay(2000);              // Wait for two seconds
  
}
*/
