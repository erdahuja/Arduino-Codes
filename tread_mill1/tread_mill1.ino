void setup()
{
  for (int  i = 0; i <= 7; i++)
  {
    pinMode(i, OUTPUT) ;
  }
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  for (int  i = 11; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
 
}

  
void loop()
{

  while (digitalRead(9) == 1)
    inc();
  while (digitalRead(10) == 1)
    dec();

}
//DATA+++++++++++
int data[10][8] =
{
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1, 0}, //2
  {1, 1, 1, 1, 0, 0, 1, 0}, //3
  {0, 1, 1, 0, 0, 1, 1, 0}, //4
  {1, 0, 1, 1, 0, 1, 1, 0}, //5
  {1, 0, 1, 1, 1, 1, 1, 0}, //6
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 0}, //9


};
int gear = 0 ;
//INCREMENT++++++++++
void inc()
{
  if (gear < 20)
    {gear =gear + 1;
  disp(gear) ;  }
    
  motor() ;



}

//DECREMENT++++++++++
void dec()
{ if (gear > 0)
    {gear = gear - 1;
  disp(gear) ;
    }
  motor() ;
}

//==display===========
int disp(int x)
{
  int tens;
  int ones;
{
    tens = x / 10;
    ones = x % 10;
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

void motor()
{   
  int value=map(gear,0,20,255,0);
  analogWrite(11,value);
}
