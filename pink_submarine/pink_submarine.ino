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
  delay(250);
  
  chuck.update();
  
  if (chuck.zPressed()) {
    pinkSubmarine.changeDriveMode();
  }
  
  pinkSubmarine.receiveWiiChuckXY(chuck.readJoyX(), chuck.readJoyY());
}

