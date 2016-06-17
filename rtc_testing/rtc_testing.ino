#include <Time.h>
#include <TimeAlarms.h>
#include <RTClib.h>#include <Wire.h>
RTC_Millis rtc;

void setup() {
  Serial.begin(57600); 
//  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  // put your setup code here, to run once:
Alarm.alarmRepeat(8,30,0, MorningAlarm);
}

void loop() {
 digitalClockDisplay();
  Alarm.delay(1000);
  
  // put your main code here, to run repeatedly:

}
void MorningAlarm(){
  Serial.println("Alarm: - turn lights off");    
}
void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

void printDigits(int digits)
{
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
