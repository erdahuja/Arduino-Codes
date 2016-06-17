#include <Wire.h>
#include <RTClib.h>
#include <Time.h>
#include <TimeAlarms.h>
#define bulb 13

RTC_DS1307 RTC;

/*-----( Declare Variables )-----*/
int light1onhour1 = 12;
int light1onmin1 = 25;
int light1onsec1 = 30;
int light1offhour1 = 12;
int light1offmin1 = 26;
int light1offsec1 = 30;

void setup()
{ digitalWrite(bulb, LOW);
  pinMode(bulb, OUTPUT);
  Serial.begin(9600);

  Serial.println("checkpoint 1");

 delay(100);
  Wire.begin();// Start the Wire (I2C communications)
  RTC.begin();// Start the RTC Chip
  
  if (! RTC.isrunning())
  {
    Serial.println("RTC is NOT running");
  }
  delay(100);
  Serial.println("checkpoint 2");
  DateTime current = RTC.now();
  setTime(current.hour(), current.minute(), current.second(), current.day(), current.month(), current.year());
  //Lights
  Alarm.alarmRepeat(light1onhour1, light1onmin1, light1onsec1, Light1On);
  Alarm.alarmRepeat(light1offhour1, light1offmin1, light1offsec1, Light1Off);

  Serial.println("checkpoint 3");

  
}

void loop()
{
  Serial.println("in loop");
  //*********************************************************MAIN CODE***************************************************************
  Serial.print(hour());
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.print(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
  Alarm.delay(1000);
}
void Light1On()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: ON");
  digitalWrite(bulb, HIGH);  // Sets the LIGHT1 "ON"
}

/*----( LIGHT1ON: TURN OFF )----*/
void Light1Off()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: OFF");
  digitalWrite(bulb, LOW);  // Sets LIGHT1 "OFF"
}
