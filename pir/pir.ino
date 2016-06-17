/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <RTClib.h>
#include <Time.h>
#include <TimeAlarms.h>

int e_fan = 9;
int bulb = 10;
int sensor1 = 11;
int sensor2 = 12;
int gyser = 13;

//Real Time Clock
RTC_DS1307 RTC;

/*-----( Declare Variables )-----*/
int light1onhour1 = 10;
int light1onmin1 = 59;
int light1onsec1 = 0;
int light1offhour1 = 11;
int light1offmin1 = 00;
int light1offsec1 = 0;

//**************************************************************************************************************************************************************************************


void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Alarm.delay(4000);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  Alarm.delay(1000);
  Serial.begin(9600);
  Wire.begin();        // Start the Wire (I2C communications)
  RTC.begin();         // Start the RTC Chip

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(e_fan, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(gyser, OUTPUT);

  digitalWrite(bulb, LOW);
  digitalWrite(e_fan, LOW);
  digitalWrite(gyser, LOW);
  Alarm.delay(5000);

  //**************************************************

  // Notify if the RTC isn't running
  if (! RTC.isrunning())
  {
    Serial.println("RTC is NOT running");
  }
  // Get time from RTC
  DateTime current = RTC.now();
  //RTC.adjust(DateTime(__DATE__, __TIME__));
  // Use RTC time to set the current time
  setTime(current.hour(), current.minute(), current.second(), current.day(), current.month(), current.year());
  //Lights
  Alarm.alarmRepeat(light1onhour1, light1onmin1, light1onsec1, Light1On);
  Alarm.alarmRepeat(light1offhour1, light1offmin1, light1offsec1, Light1Off);
}


void fan()
{
  Serial.println("in fan");

  digitalWrite(e_fan, HIGH);
  int l = 0;
  while (l < 100)
  {
    Alarm.delay(100);
    if ((digitalRead(sensor1) == HIGH) || (digitalRead(sensor2) == HIGH))
    {
      digitalWrite(bulb, HIGH);
    }
    l++;
  }
  digitalWrite(e_fan, LOW);
}

void motion()
{
  Serial.println("in motion");
  digitalWrite(bulb, HIGH);
  int k = 0;
  while (k < 120)
  {
    if ((digitalRead(sensor1) == HIGH) || (digitalRead(sensor2) == HIGH))
    {
      k = 0;
    }
    Alarm.delay(100);
    Serial.println(k);
    k++;
  }
  digitalWrite(bulb, LOW);
  Alarm.delay(3000);


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
  
  if ((digitalRead(sensor1) == HIGH) || (digitalRead(sensor2) == HIGH))
  {
    motion();
    Alarm.delay(3000);
    fan();

  }
  //**********************************************************************************************************************************
}

void Light1On()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: ON");
  digitalWrite(gyser, HIGH);  // Sets the LIGHT1 "ON"
}

/*----( LIGHT1ON: TURN OFF )----*/
void Light1Off()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: OFF");
  digitalWrite(gyser, LOW);  // Sets LIGHT1 "OFF"
}
//*******************************************************************


