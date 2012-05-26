#include <Wire.h>

#include <WiiChuck.h>

#include <math.h>


#define MAXANGLE 90
#define MINANGLE -90

// When using Serial Monitor in the Arduino IDE, make sure to select
// BAUD rate equal to what is set in this constant so that the serial
// output is not gibberish.
#define SERIAL_BAUD_RATE 115200

WiiChuck chuck = WiiChuck();
int angleStart, currentAngle;
int tillerStart = 0;
double angle;

void setup() {
     Serial.begin(SERIAL_BAUD_RATE);
     chuck.begin();
     chuck.update();
}


void loop() {
     delay(1000);
     chuck.update(); 


/*     Serial.print(chuck.readRoll());
     Serial.print(", ");  
     Serial.print(chuck.readPitch());
     Serial.print(", ");  

     Serial.print((int)chuck.readAccelX()); 
     Serial.print(", ");  
     Serial.print((int)chuck.readAccelY()); 
     Serial.print(", ");  

     Serial.print((char)chuck.readAccelZ()); 
*/
     Serial.print(chuck.readJoyX());
     Serial.print(", ");
     Serial.print(chuck.readJoyY());
     
     Serial.println();
     
     Serial.print(chuck.zPressed() ? "z pressed" : "z not pressed");
     Serial.print(", ");
     Serial.print(chuck.cPressed() ? "c pressed" : "c not pressed");

     Serial.println();
}
