#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear() ;
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(13, INPUT);

  // put yur setup code here, to run once:

}
int password[4] = {1, 2, 3, 4}, a[4];
void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ENTER PASSWORD : ");
  while ((digitalRead(6) == 0) && (digitalRead(7) == 0) && (digitalRead(8) == 0) && (digitalRead(13) == 0) );
  lcd.setCursor(0, 1);
  for (int i = 0; i < 4; i++)
  {
    if (digitalRead(6) == 1)
    {
      while (digitalRead(6) == 1) ;
      a[i] = 1 ; i++ ;
     lcd.print("* ") ;
      delay(1000);
    }
    if (digitalRead(7) == 1)
    {
      while (digitalRead(7) == 1) ;
      a[i] = 2 ;  lcd.print("* ") ;
      i++ ; delay(1000);
    }

    if (digitalRead(8) == 1)
    {
      while (digitalRead(8) == 1) ;
      a[i] = 3 ;  lcd.print("* ") ; delay(1000);
      i++;
    }
    if (digitalRead(13) == 1)
    {
      while (digitalRead(13) == 1) ;
      a[i] = 4 ;  lcd.print("* ") ; delay(1000);
      i++ ;
    }
    lcd.clear();
  }
  for (int i = 0; i < 4; i++)
  {
    if (password[i] == a[i])
     break ;
  } lcd.print("correct");
    delay(1000);
  for (int i = 0; i < 4; i++)
  {
   if(password[i] != a[i])
      break ;
  }
  lcd.print("incoreect");
    delay(1000);

}
