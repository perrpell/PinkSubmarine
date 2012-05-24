#include "PinkSubmarine.h"

const int outputPins [] = {0,1,2,3,4,5};

void initializeROV() {
  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i-1], OUTPUT);
  }
}

void stopROV() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(outputPins[i], LOW);
  }
}

void rotateRight() {
  digitalWrite(0, HIGH);
  digitalWrite(3, HIGH);
}

void rotateLeft() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
}

void up() {
  digitalWrite(4, HIGH);
}

void down() {
  digitalWrite(5, HIGH);
}
  
void reverse() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}

void forward() {
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
}



