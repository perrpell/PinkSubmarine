#ifndef Test_h
#define Test_h

#include "Arduino.h"

class PinkSubmarine {

  bool horizontalDriveMode;

 public:
  PinkSubmarine();
  void initializeROV();
  void changeDriveMode();
  void receiveWiiChuckXY(int x, int y);

 private:
  void rotateRight(); 
  void rotateLeft();
  void up();
  void down(); 
  void reverseOrUp(); 
  void forwardOrDown();
  void stopROV();

  bool joystickIsLeft(int x, int y);
  bool joystickIsRight(int x, int y);
  bool joystickIsForward(int x, int y);
  bool joystickIsBack(int x, int y);
 
};

#endif
