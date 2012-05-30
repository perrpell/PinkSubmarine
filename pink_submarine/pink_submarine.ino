#include <WiiChuck.h>
#include <Wire.h>
#include <PinkSubmarine.h>

#define SERIAL_BAUD_RATE 115200

WiiChuck chuck = WiiChuck();
PinkSubmarine pinkSubmarine = PinkSubmarine();

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  chuck.begin();
  chuck.update();
  pinkSubmarine.initializeROV();  
}

void loop() {
  /*
  pinkSubmarine.forward();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(1000);  
  
  pinkSubmarine.reverse();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(1000);
  
  pinkSubmarine.rotateLeft();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(1000);
 
  pinkSubmarine.rotateRight();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(1000);
  
  pinkSubmarine.up();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(1000);
  
  pinkSubmarine.down();
  delay(1000);
  pinkSubmarine.stopROV();
  delay(3000);
  */
  delay(500);
  chuck.update();
  pinkSubmarine.receiveWiiChuckXY(chuck.readJoyX(), chuck.readJoyY());
}

