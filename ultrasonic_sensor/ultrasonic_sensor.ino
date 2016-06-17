#define trig 9
#define echo 10
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {

  lcd.begin(16, 2);
  lcd.clear() ;
  pinMode(trig, OUTPUT) ;
  pinMode(led1, OUTPUT) ;
  pinMode(led2, OUTPUT) ;
  pinMode(led3, OUTPUT) ;
  pinMode(led4, OUTPUT) ;


  pinMode(echo, INPUT) ;
  Serial.begin(9600) ;
  ;
}

void loop() {
  digitalWrite(trig, 0) ;
  delay(5) ;
  digitalWrite(trig, 1) ;
  delay(100) ;
  digitalWrite(trig, 0) ;
  delay(5) ;//echo

  long  duration = pulseIn(echo, HIGH);

  // convert the time into a distance
  long inches = microsecondsToInches(duration);
  Serial.print(inches);
  Serial.print("in, ");
  lcd.print(duration) ;
  delay(1000) ;

  if (inches < 2)
  {
    digitalWrite(led1, 1) ;
    delay(50);
    digitalWrite(led1, 0) ;
    delay(50) ;
    Serial.print("OVERFLOW!") ;
  }
  else if ((inches >= 2) && (inches < 5))
  {
    digitalWrite(led2, 1) ;
    delay(50);
    digitalWrite(led2, 0) ;
    delay(50) ;


  }
  else if (inches >= 5 && inches < 8)
  {
    digitalWrite(led3, 1) ;
    delay(50);
    digitalWrite(led3, 0) ;
    delay(50) ;
    Serial.println("led3333");
  }
  else if (inches >= 8)
  {
    digitalWrite(led4, 1) ;
    delay(50);
    digitalWrite(led4, 0) ;
    delay(50) ;
  }


}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}
