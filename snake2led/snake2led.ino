void setup()
{
  for (int i = 0; i <= 7; i++)
    pinMode(i, OUTPUT) ;
}

void loop()
{
  for (int i = 0; i <= 1; i++)
  {
    digitalWrite(i, HIGH) ;

  } delay(1000) ;
  for (int i = 2; i <= 3; i++)
  { digitalWrite(i, HIGH) ;
    digitalWrite(i - 2, LOW) ;
    delay(1000) ;


  }
  for (int i = 4; i <= 5; i++)
  { digitalWrite(i, HIGH) ;
    digitalWrite(i - 2, LOW) ;
    delay(1000) ;
  }
  for (int i = 6; i <= 7; i++)
  { digitalWrite(i, HIGH) ;
    digitalWrite(i - 2, LOW) ;
    delay(1000) ;

  }
  low() ;

}
void low()

{
  for (int i = 6; i <= 7; i++)
  {
    digitalWrite(i, LOW);
  }
}


