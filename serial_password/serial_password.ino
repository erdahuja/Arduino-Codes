void setup()
{
  Serial.begin(9600) ;
  for (int i = 2; i < 6; i++)
  { pinMode(i, INPUT) ;

  }
  pinMode(6, OUTPUT) ;

  

}

void loop()
{
  Serial.println("Enter the password : ") ;
int a[4], b[4] = {1, 2, 3, 4} , i = 0;

  while ((digitalRead(2) == 0) && (digitalRead(3) == 0) && (digitalRead(4) == 0) && (digitalRead(5) == 0) );
  for (int x = 0; x < 4; x++)
  {
    if (digitalRead(2) == 1)
    {
      while (digitalRead(2) == 1) ;
      a[i] = 1 ; i++ ;

      Serial.print("* ") ;
    }
    if (digitalRead(3) == 1)
    {
      while (digitalRead(3) == 1) ;
      a[i] = 2 ; Serial.print("* ") ;
      i++ ;
    }

    if (digitalRead(4) == 1)
    {
      while (digitalRead(4) == 1) ;
      a[i] = 3 ; Serial.print("* ") ;
      i++;
    }
    if (digitalRead(5) == 1)
    {
      while (digitalRead(5) == 1) ;
      a[i] = 4 ; Serial.print("* ") ;
      i++ ;
    }

  }


  for (int i = 0; i < 4; i++)

  { if (a[i] == b[i])

      break ;
  }
  Serial.println("correct!! \n") ;
  for (int i = 0; i < 4; i++)

    if (a[i] != b[i])
      Serial.println("INcorrect!! \n");


}

