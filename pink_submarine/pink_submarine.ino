#include <Wire.h>

#include <PinkSubmarine.h>

PinkSubmarine pinkSubmarine = PinkSubmarine();

void setup() {
  pinkSubmarine.initializeROV();  
}

void loop() {
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
  delay(1000);
}

