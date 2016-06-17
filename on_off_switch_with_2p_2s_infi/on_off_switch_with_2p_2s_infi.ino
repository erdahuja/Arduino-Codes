void setup() {
  for (int i = 0; i <= 7; i++)
    pinMode(i, OUTPUT) ;
  for (int j = 8; j <= 11; j++)
    pinMode(j, INPUT);
  // put your setup code here, to run once:

}


void pattern_1()
{
  {
    for (;;)
    {
      for (int i = 0; i <= 7; i++)
      {
        digitalWrite(i, HIGH) ;
      }
      Delay(1000) ;
      check();
      for (int i = 0; i <= 7; i++)
      {
        digitalWrite(i, LOW) ;
      }
      Delay(1000);
      check() ;

    }
  }
}
//*****************pattern1


void pattern_2()
{
  for (;;)
  {
    for (int i = 0; i <= 7; i++)
    {
      digitalWrite(i, HIGH) ;

      digitalWrite(7 - i, HIGH) ;
      Delay(150) ;
      check() ;
      digitalWrite(i, LOW) ;
      digitalWrite(7 - i, LOW) ;

    }
  }
}
//*************************pattern2
void loop()
{
  for (int i = 0; i <= 7; i++)
    digitalWrite(i, LOW);
  if (digitalRead(8) == HIGH)
    pattern_1() ;
  if (digitalRead(9) == HIGH)
    pattern_2() ;

}

//=================check=============
void check()
{
  if (digitalRead(8) == HIGH)
  {
    low() ;
    pattern_1() ;
  }

  else if (digitalRead(9) == HIGH)
  {
    low() ;
    pattern_2() ;
  }

  else if (digitalRead(10) == HIGH)
  {
    while (digitalRead(10) == HIGH);
    off() ;
  }

}


void off()
{int flag=0 ;
  for (;;)
  {
    {
      if (digitalRead(10) == HIGH)
      { 
        while (digitalRead(10) == HIGH) ;
        flag=!flag ;
      }
      if(flag==1)
      {
      loop() ;
      }
      else if(flag==0)
      {
        low();
      }
    }
  }
}






void low()

{
  for (int i = 0; i <= 7; i++)
    digitalWrite(i, LOW);
}


void Delay(int x)

{
  for (int i = 0; i <= x; i++)
  {
    delay(1);
    check() ;
  }
}












