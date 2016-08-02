#include <Wire.h>
#include <RTClib.h>
#include <Time.h>
#include <TimeAlarms.h>
#include <LiquidCrystal.h>
#define trig 9
#define echo 10
#define relay 13


/*-----( Declare Variables )-----*/
int light1onhour1 = 13;//timings to turn on light
int light1onmin1 =  40;
int light1onsec1 = 00;
int light1offhour1 = 13;
int light1offmin1 = 41;
int light1offsec1 = 00;
#define max_distance 400
RTC_DS1307 RTC;

#include <NewPing.h>
NewPing sonar(trig, echo, max_distance);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//character
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup()
{
  digitalWrite(relay, LOW);
  pinMode(relay, OUTPUT);
  Serial.begin(9600) ;
  lcd.begin(16, 2);
  lcd.clear() ;
  pinMode(trig, OUTPUT) ;
  pinMode(echo, INPUT) ;
  lcd.createChar(0, heart);

  Wire.begin();        // Start the Wire (I2C communications)
  RTC.begin(); // Start the RTC Chip
  if (! RTC.isrunning())
  {
    Serial.println("RTC is NOT running");
  }
  RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime current = RTC.now();
  setTime(current.hour(), current.minute(), current.second(), current.day(), current.month(), current.year());
  //Lights
  Alarm.alarmRepeat(light1onhour1, light1onmin1, light1onsec1, Light1On);
  Alarm.alarmRepeat(light1offhour1, light1offmin1, light1offsec1, Light1Off);
}

void loop()
{
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

  lcd.clear() ;
  while (digitalRead(6) == 0 && digitalRead(7) == 0 && digitalRead(8) == 0)
  {
    screensavers() ;
  } ;
  if (digitalRead(6) == 1 || digitalRead(7) == 1 || digitalRead(8) == 1)
    lcd.clear() ;
  menu() ;
}

void screensavers()
{
  /*screensaver 1*/
  { lcd.setCursor(1, 0);
    lcd.write(byte(0));
    lcd.print("OPTIMUS LABS") ;
    lcd.scrollDisplayRight() ;
    Alarm.delay(500);
    lcd.setCursor(1, 1) ;
    lcd.print(" PVT LTD") ;
    lcd.write(byte(0));
    lcd.scrollDisplayLeft() ;
    Alarm.delay(500);
  }



  /*screensaver 2*/

  {
    lcd.setCursor(1, 0);
    lcd.write(byte(0));
    lcd.print("OPTIMUS LABS") ;
    lcd.scrollDisplayLeft() ;
    Alarm.delay(500);
    lcd.setCursor(1, 1) ;
    lcd.print(" PVT LTD") ;
    lcd.write(byte(0));
    lcd.scrollDisplayRight() ;
    Alarm.delay(500);
  }

}

void menu()
{
  for (int i = 0; i < 3; i++)
  {
    lcd.setCursor(0, 0) ;
    lcd.print("Modes :") ;
    lcd.setCursor(0, 1) ;
    lcd.print("1.BORE") ;
    DELAY(1000) ;
    lcd.clear();
    lcd.setCursor(0, 0) ;
    lcd.print("2.SUPP") ;
    DELAY(1000) ;
    lcd.clear();
    lcd.setCursor(0, 0) ;
    lcd.print("3.TIMER") ;
    DELAY(1000) ;
    lcd.clear();
  }
  lcd.print("Enter Choice :") ;
  DELAY(5000) ;
  lcd.clear() ;
  lcd.print("NO CHOICE!");
  DELAY(1000) ;
  lcd.clear() ;

}


void check()
{
  if (digitalRead(6) == 1)
  {
    printwater_level() ;
    loop() ;
  }

  else if ( digitalRead(7) == 1)
  { lcd.clear() ;
    lcd.print("TIMER");
    DELAY(1000) ;
    timer();
    lcd.clear() ;
  }

  else if ( digitalRead(8) == 1)
  { lcd.clear() ;
    lcd.print("N.C") ;
    Alarm.delay(1000) ;
    lcd.clear() ;
  }
}
long x ;
void printwater_level()
{
  for (int i = 0; i < 40; i++)
  {
    lcd.clear() ;
    lcd.setCursor(0, 0) ;
    lcd.print("Water Level:") ;
    lcd.setCursor(0, 1) ;
    ultrasonic() ;
    lcd.print(x) ;
    Serial.println(x);
    Alarm.delay(1000);
    if (digitalRead(6) == 1 || digitalRead(7) == 1 || digitalRead(8) == 1)

    {
      Alarm.delay(50);
      loop() ;
    }
  }

}
int ultrasonic()
{
  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  x = (uS / US_ROUNDTRIP_CM);
  return x;
}


void DELAY(int x)
{
  for (int i = 0; i < x; i++)
    Alarm.delay(10) ;
  check() ;
}

void timer()
{
  DateTime now = RTC.now();
  lcd.print(" SET :");
  lcd.setCursor(0, 1);
  {
    lcd.print(now.hour(), DEC);
    Serial.print(now.hour(), DEC);

    lcd.print(':');
    Serial.print(':');
    lcd.print(now.minute(), DEC);
    Serial.print(now.minute(), DEC);

  }
  Alarm.delay(2000);

}
void Light1On()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: ON");
  digitalWrite(relay, HIGH);  // Sets the LIGHT1 "ON"
}

/*----( LIGHT1ON: TURN OFF )----*/
void Light1Off()
{
  DateTime now = RTC.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.println(" Light1: OFF");
  digitalWrite(relay, LOW);  // Sets LIGHT1 "OFF"
}

