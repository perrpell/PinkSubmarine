/*
 * Nunchuck -- Use a Wii Nunchuck
 * Tim Hirzel http://www.growdown.com
 * 
 notes on Wii Nunchuck Behavior.
 This library provides an improved derivation of rotation angles from the nunchuck accelerometer data.
 The biggest different over existing libraries (that I know of ) is the full 360 degrees of Roll data
 from teh combination of the x and z axis accelerometer data using the math library atan2. 

 It is accurate with 360 degrees of roll (rotation around axis coming out of the c button, the front of the wii),
 and about 180 degrees of pitch (rotation about the axis coming out of the side of the wii).  (read more below)

 In terms of mapping the wii position to angles, its important to note that while the Nunchuck
 sense Pitch, and Roll, it does not sense Yaw, or the compass direction.  This creates an important
 disparity where the nunchuck only works within one hemisphere.  At a result, when the pitch values are 
 less than about 10, and greater than about 170, the Roll data gets very unstable.  essentially, the roll
 data flips over 180 degrees very quickly.   To understand this property better, rotate the wii around the
 axis of the joystick.  You see the sensor data stays constant (with noise).  Because of this, it cant know
 the difference between arriving upside via 180 degree Roll, or 180 degree pitch.  It just assumes its always
 180 roll.


 * 
 * This file is an adaptation of the code by these authors:
 * Tod E. Kurt, http://todbot.com/blog/
 *
 * The Wii Nunchuck reading code is taken from Windmeadow Labs
 * http://www.windmeadow.com/node/42
 * 
 * Conversion to Arduino 1.0 by Danjovic
 * http://hotbit.blogspot.com 
 * 
 */

#ifndef WiiChuck_h
#define WiiChuck_h


#include "Arduino.h"
#include <Wire.h>
#include <math.h>


// these may need to be adjusted for each nunchuck for calibration
#define ZEROX 510  
#define ZEROY 490
#define ZEROZ 460
#define RADIUS 210  // probably pretty universal

#define DEFAULT_ZERO_JOY_X 125
#define DEFAULT_ZERO_JOY_Y 127



class WiiChuck {
 private:
  uint8_t cnt;
  uint8_t status[6];// array to store wiichuck output
  uint8_t averageCounter;
  //int accelArray[3][AVERAGE_N];  // X,Y,Z
  int i;
  int total;
  uint8_t zeroJoyX;   // these are about where mine are
  uint8_t zeroJoyY; // use calibrateJoy when the stick is at zero to correct
  int lastJoyX;
  int lastJoyY;
  int angles[3];

  bool lastZ, lastC;


 public:

  uint8_t joyX;
  uint8_t joyY;
  bool buttonZ;
  bool buttonC;

  WiiChuck();

  void begin();
  

  void calibrateJoy();

  void update();


  byte * getStatus();

  float readAccelX();
  float readAccelY();
  float readAccelZ();

  bool zPressed();
  bool cPressed();

  // for using the joystick like a directional button
  bool rightJoy(int thresh);

  // for using the joystick like a directional button
  bool leftJoy(int thresh);


  int readJoyX();

  int readJoyY();


  // R, the radius, generally hovers around 210 (at least it does with mine)
  int R();


  // returns roll degrees
  int readRoll();

  // returns pitch in degrees
  int readPitch();

 private:
  uint8_t _nunchuk_decode_byte (uint8_t x);
  void _send_zero();

};


#endif
