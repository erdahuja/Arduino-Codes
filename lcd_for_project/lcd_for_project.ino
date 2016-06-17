
#include <LiquidCrystal.h>
#define trig 9
#define echo 10
#define max_distance 400
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
  Serial.begin(9600) ;
  lcd.begin(16, 2);
  lcd.clear() ;
  pinMode(trig, OUTPUT) ;
  pinMode(echo, INPUT) ;
  lcd.createChar(0, heart);
}

void loop()
{
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
    delay(500);
    lcd.setCursor(1, 1) ;
    lcd.print(" PVT LTD") ;
    lcd.write(byte(0));
    lcd.scrollDisplayLeft() ;
    delay(500);
  }



  /*screensaver 2*/

  {
    lcd.setCursor(1, 0);
    lcd.write(byte(0));
    lcd.print("OPTIMUS LABS") ;
    lcd.scrollDisplayLeft() ;
    delay(500);
    lcd.setCursor(1, 1) ;
    lcd.print(" PVT LTD") ;
    lcd.write(byte(0));
    lcd.scrollDisplayRight() ;
    delay(500);
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
    lcd.print("N.C") ;
    delay(1000) ;
    lcd.clear() ;
  }

  else if ( digitalRead(8) == 1)
  { lcd.clear() ;
    lcd.print("N.C") ;
    delay(1000) ;
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
    delay(1000);
    if (digitalRead(6) == 1 || digitalRead(7) == 1 || digitalRead(8) == 1)
    
    {
      delay(50);
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
    delay(1) ;
  check() ;
}



