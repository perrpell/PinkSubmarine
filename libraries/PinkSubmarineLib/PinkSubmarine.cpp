#include "PinkSubmarine.h"

const int outputPins [] = {2,3,4,5,6,7};

PinkSubmarine::PinkSubmarine()
{
  horizontalDriveMode = true;
}

void PinkSubmarine::initializeROV()
{
  for (int i = 0; i < 6; i++) {
    pinMode(outputPins[i], OUTPUT);
    Serial.print("pin OUTPUT: ");
    Serial.println(outputPins[i]);
  }
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(8, HIGH);
}

void PinkSubmarine::changeDriveMode()
{
  this->stopROV();
  horizontalDriveMode = !horizontalDriveMode;
  Serial.print("Change horiontalDriveMode to: ");
  Serial.println(horizontalDriveMode ? "horizontal" : "vertical");


  if (horizontalDriveMode) {
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  
}

void PinkSubmarine::stopROV()
{
  for (int i = 0; i < 6; i++) {
    digitalWrite(outputPins[i], LOW);
  }
}

void PinkSubmarine::rotateRight()
{
  if (horizontalDriveMode) {
    this->stopROV();
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
  }
}

void PinkSubmarine::rotateLeft() {
  this->stopROV();

  if (horizontalDriveMode) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
}

void PinkSubmarine::up() {
  this->stopROV();
  digitalWrite(6, HIGH);
}

void PinkSubmarine::down() {
  this->stopROV();
  digitalWrite(7, HIGH);
}
  
void PinkSubmarine::reverseOrUp() {
  this->stopROV();

  if (horizontalDriveMode) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else {
    this->up();
  }
}

void PinkSubmarine::forwardOrDown() {
  this->stopROV();
  
  if (horizontalDriveMode) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
  } else {
    this->down();
  }
}

void PinkSubmarine::receiveWiiChuckXY(int x, int y)
{
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");

  if (joystickIsLeft(x, y)) {
    Serial.print("LEFT");
    this->rotateLeft();
  } else if (joystickIsRight(x, y)) {
    Serial.print("RIGHT");
    this->rotateRight();
  } else if (joystickIsForward(x, y)) {
    Serial.print("FORWARD");
    this->forwardOrDown();
  } else if (joystickIsBack(x, y)) {
    Serial.print("BACKWARD");
    this->reverseOrUp();
  } else {
    Serial.print("UNKNOWN");
    this->stopROV();
  }

  Serial.println();
}

bool PinkSubmarine::joystickIsLeft(int x, int y) {
  return ( x > -110 && x < -90 ) && ( y > -10 && y < 10 );
}

bool PinkSubmarine::joystickIsRight(int x, int y)
{
  return ( x > 80 && x < 100 ) && ( y > -10 && y < 10);
}

bool PinkSubmarine::joystickIsForward(int x, int y)
{
  return ( x > -10 && x < 10 ) && ( y > 80 && y < 100 );
}

bool PinkSubmarine::joystickIsBack(int x, int y)
{
  return ( x > -10 && x < 10 ) && ( y > -110 && y < -90 );
}

