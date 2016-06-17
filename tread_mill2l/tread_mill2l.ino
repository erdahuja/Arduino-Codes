int gear=0;

void setup()
{
  //Serial.begin(9600);
  for (int  i = 0; i <= 7; i++)
  {
    pinMode(i, OUTPUT) ;
    digitalWrite(i,LOW);
  }
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  
  for (int  i = 11; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }

}

int data[10][8] =
{
  {
    1, 1, 1, 1, 1, 1, 0, 0  }, // 0
  {
    0, 1, 1, 0, 0, 0, 0, 0  }, //1
  {1, 1, 0, 1, 1, 0, 1, 0  }, //2
  {
    1, 1, 1, 1, 0, 0, 1, 0  }
  , //3
  {
    0, 1, 1, 0, 0, 1, 1, 0  }
  , //4
  {
    1, 0, 1, 1, 0, 1, 1, 0  }
  , //5
  {
    1, 0, 1, 1, 1, 1, 1, 0  }
  , //6
  {
    1, 1, 1, 0, 0, 0, 0, 0  }
  , //7
  {
    1, 1, 1, 1, 1, 1, 1, 0  }
  , //8
  {
    1, 1, 1, 1, 0, 1, 1, 0  }
  , //9


};

void inc()
{
  if (gear < 20)
  {
    gear =gear + 1;
    //Serial.println(gear);      
  }
}

//DECREMENT++++++++++
void dec()
{ 
  if (gear > 0)
  {
    gear = gear - 1;
    //Serial.println(gear);
  }
}

void disp(int x)
{
  int tens;
  int ones;
  {
    tens = x / 10;
    ones = x % 10;
    //Serial.println(tens);
    //Serial.println(ones);
    
    for (int rep = 0; rep < 25; rep++)
    {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      
      for (int i = 0; i <= 7; i++)
      {
        digitalWrite(i, data[tens][i]);
      }
      delay(5);

      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      for (int i = 0; i <= 7; i++)
      {
        digitalWrite(i, data[ones][i]);
      }
      delay(5);
    }
  }

}

void loop()
{
  if(digitalRead(9) == 1)
    inc();
  if(digitalRead(10) == 1)
    dec();
    
  disp(gear);  
}
