#ifndef Test_h
#define Test_h

#include "Arduino.h"

class PinkSubmarine {

 public:
  void initializeROV();
  void rotateRight(); 
  void rotateLeft();
  void up();
  void down(); 
  void reverse(); 
  void forward();
  void stopROV();
};

#endif
