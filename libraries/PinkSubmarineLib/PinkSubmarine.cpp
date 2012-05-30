#include "PinkSubmarine.h"

const int outputPins [] = {2,3,4,5,6,7};

void PinkSubmarine::initializeROV() {
  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
    Serial.print("pin OUTPUT: ");
    Serial.println(outputPins[i]);
  }
}

void PinkSubmarine::stopROV() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(outputPins[i], LOW);
  }
}

void PinkSubmarine::rotateRight() {
  this->stopROV();
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);
}

void PinkSubmarine::rotateLeft() {
  this->stopROV();
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
}

void PinkSubmarine::up() {
  this->stopROV();
  digitalWrite(6, HIGH);
}

void PinkSubmarine::down() {
  this->stopROV();
  digitalWrite(7, HIGH);
}
  
void PinkSubmarine::reverse() {
  this->stopROV();
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void PinkSubmarine::forward() {
  this->stopROV();  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}

void PinkSubmarine::receiveWiiChuckXY(int x, int y)
{
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");

  if ((x > -110 && x < -90) && (y > -10 && y < 10)) {
    Serial.print("LEFT");
    this->rotateLeft();
  } else if (( x > 80 && x < 100) && (y > -10 && y < 10)) {
    Serial.print("RIGHT");
    this->rotateRight();
  } else if (( x > -10 && x < 10) && (y > 80 && y < 100)) {
    Serial.print("FORWARD");
    this->forward();
  } else if (( x > -10 && x < 10) && (y > -110 && y < -90 )) {
    Serial.print("BACKWARD");
    this->reverse();
  } else {
    Serial.print("UNKNOWN");
    this->stopROV();
  }

  Serial.println();
}

