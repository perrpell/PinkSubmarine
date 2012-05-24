#include <PinkSubmarine.h>

void setup() {
  initializeROV();  
}

void loop() {
  forward();
  delay(1000);
  stopROV();
  delay(1000);  
  
  reverse();
  delay(1000);
  stopROV();
  delay(1000);
   
  rotateLeft();
  delay(1000);
  stopROV();
  delay(1000);
  
  rotateRight();
  delay(1000);
  stopROV();
  delay(1000);
  
  up();
  delay(1000);
  stopROV();
  delay(1000);
  
  down();
  delay(1000);
  stopROV();
  delay(1000);
}

