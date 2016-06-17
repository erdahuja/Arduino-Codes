#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define button1 6
#define button2 7
#define button3 8

void setup()
{
  Serial.begin(9600) ;
  lcd.begin(16, 2);
  lcd.clear() ;
  pinMode(button1, OUTPUT);
  pinMode(button2, OUTPUT);
  pinMode(button3, OUTPUT);

  // put your setup code here, to run once:

}
int value = 0;
void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTER THE VALUE :");

  while (digitalRead(6) == 0 && digitalRead(7) == 0 && digitalRead(8) == 0);
  if (digitalRead(6) == 1)
  {
    delay(5);
    lcd.clear();
    lcd.print("VALUE :");
    while (digitalRead(6) == 1);
    set_value();
  }
}

void set_value()
{
  while (digitalRead(6) == 0)
  {
    while (digitalRead(6) == 0 && digitalRead(7) == 0 && digitalRead(8) == 0);
    lcd.setCursor(1, 1);
    check();
    lcd.print(value);
    DELAY(500);

  };

}
void increment()
{
  if (value < 20)
  {
    value = value + 1;
    Serial.print(value);
  }

}

void decrement()
{
  if (value > 0)
  {
    value = value - 1;
    Serial.print(value);
  }
}

void DELAY(int x)
{
  for (int i = 0; i < x; i++)
  {
    delay(1) ;

  }
}
void check()
{

  if (digitalRead(7) == 1)
  {
    delay(5);
    increment();


  }

  if (digitalRead(8) == 1)
  {
    delay(5);
    decrement();

  }
  if (digitalRead(6) == 1)
  {
    task(value);
  }
}

void task(int x)
{
  for (int i = 0; i <= x - 1; i++)
  {
    Serial.println("hello");
  }


}

