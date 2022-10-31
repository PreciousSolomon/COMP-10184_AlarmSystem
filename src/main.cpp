// COMP-10184 – Mohawk College
// PIR SENSORStatusON Test Application
// This program is to stimulate an alarm system,
// when motion is detected user has 10 second to switch it off
// else the alarm keeps on looping whem motion is detected 
// Full Name Precious Solomon
// Student id 000813595
//I created this work and I have not shared it with anyone else. 

#include <Arduino.h>
// digital input pin definitions
#define sensor D5
#define button D6 

// *************************************************************
void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
  // configure the LED output
  pinMode(LED_BUILTIN, OUTPUT);
  // PIR sensor is an INPUT
  pinMode(sensor, INPUT);
  // Button is an INPUT
  pinMode(button, INPUT_PULLUP);
 

  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
}
// *************************************************************

// *************************************************************
int buttonPushed()
{
  int x = 0;
 
  if (digitalRead(button) == 0)
  {
    
    x = 22;
  }

  return x;
}
// *************************************************************

// *************************************************************
void loop()
{



  bool bMotionDetected = false;
  bool AlarmState = true;
  Serial.println("Alarm is on 1");

  if (digitalRead(sensor) == HIGH)
  { 
    bMotionDetected = true;
    AlarmState = true;
  }

  if (bMotionDetected == true)
  {

    for (int x = 0; x < 40; x++)
    {
     

      if (buttonPushed() != 22)
      {
        digitalWrite(LED_BUILTIN, LOW);
        delay(125);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(125);
      }
      else
      {
        //x = 20;
       
       
       
        AlarmState = false;
        delay(200);
        break;
      }
    }
  }
  else
  {
    AlarmState = true;
    bMotionDetected = false;
  }

  while (bMotionDetected == true)
  {


    Serial.println("Alarm is on 2");

   while( AlarmState  ==  false){
    Serial.println("Alarm is off");
    if (buttonPushed() == 22)
      {

       AlarmState = true;
        break;
        }
        continue;
   } 


    digitalWrite(LED_BUILTIN, HIGH);

    while (digitalRead(sensor) == HIGH)
    {
      bMotionDetected = false;
    }
    continue;
  }
}

  