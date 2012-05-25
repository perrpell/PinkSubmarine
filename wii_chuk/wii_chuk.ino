#include <Wire.h>

#include <WiiChuck.h>

#include <math.h>


#define MAXANGLE 90
#define MINANGLE -90


WiiChuck chuck = WiiChuck();
int angleStart, currentAngle;
int tillerStart = 0;
double angle;

void setup() {
     Serial.begin(115200);
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
