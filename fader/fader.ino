/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 
 */
int brightness = 0;    // how bright the LED is
int fadeAmount = 2;    // how many points to fade the LED by

int blue0 = 3;
int blue1 = 5;

int pink0 = 10;
int pink1 = 11;

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(blue0, OUTPUT);
  pinMode(blue1, OUTPUT);

  pinMode(pink0, OUTPUT);
  pinMode(pink1, OUTPUT);
  
  Serial.begin(9600);
 
} 

void loop()  { 
  // set the brightness of pin 9:
  analogWrite(blue0, brightness);
  analogWrite(blue1, brightness);
    
  analogWrite(pink0, 255 - brightness);
  analogWrite(pink1, 255 - brightness);
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  Serial.print("fade amount: ");
  Serial.println(brightness, DEC);
  
  // reverse the direction of the fading at the ends of the fade: 
  if (brightness <= 0 || brightness >= 250) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(3);                            
}
