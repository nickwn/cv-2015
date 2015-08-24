#include <Servo.h>
#include <math.h>

#define PI 3.14159265

Servo ud;  // maybe not the best names
Servo lr;

int bytes[2];  // azimuth, distance, height
int i = 0;

int azimuth, altitude; 

void setup() 
{
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        
        lr.attach(12);
        ud.attach(13);
}

void loop() 
{

  if (Serial.available() > 0)
  {
    bytes[i] = Serial.read();
    Serial.print("i: ");
    Serial.println(i);
    i++;
  }
  
        
  if (i == 2)
  {
    azimuth = bytes[0];
    altitude = bytes[1];
    
    lr.write(azimuth);
    ud.write(altitude);
   
    Serial.println(azimuth);
    Serial.println(altitude);
    
    i=0;
  }
}
