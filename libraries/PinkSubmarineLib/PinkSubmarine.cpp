#include "PinkSubmarine.h"

const int outputPins [] = {0,1,2,3,4,5};

void PinkSubmarine::initializeROV() {
  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
  }
}

void PinkSubmarine::stopROV() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(outputPins[i], LOW);
  }
}

void PinkSubmarine::rotateRight() {
  digitalWrite(0, HIGH);
  digitalWrite(3, HIGH);
}

void PinkSubmarine::rotateLeft() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
}

void PinkSubmarine::up() {
  digitalWrite(4, HIGH);
}

void PinkSubmarine::down() {
  digitalWrite(5, HIGH);
}
  
void PinkSubmarine::reverse() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}

void PinkSubmarine::forward() {
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
}



