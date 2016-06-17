void setup() 
{
  for (int i = 0; i < 11; i++)
  {
    pinMode(i, OUTPUT);
  }

  for (int i = 11; i < 13; i++)
  {
    pinMode(i, INPUT);
  }

}

int gear = 0;

void loop()
{ 
  
  
  if (digitalRead(11) == HIGH)
  inc() ;
  
  disp(gear) ;
  motor(gear);
  
  if (digitalRead(12) == HIGH)
    dec() ;
    
    disp(gear);
    motor(gear) ;

 
}
 void motor(int)
 {
  int x ;
 int value= map(x, 0, 20, 255, 0);
  analogWrite(10,value) ;
  }

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


void inc()
{ 
  if (gear < 20)
    gear = gear + 1;
}

void dec()
{ if (gear > 0)
    gear = gear - 1;
}

void disp(int x)
{ x = gear;
  int tens;
  int ones;
  tens = gear / 10;
  ones = gear % 10;
  for (int rep = 0; rep < 50; rep++)
  {


    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    for (int i = 0; i <= 7; i++)
    {
      digitalWrite(i, data[tens][i]);
    }
    delay(5);

    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    for (int i = 0; i <= 7; i++)
    {
      digitalWrite(i, data[ones][i]);
    }
    delay(5);
  }
}


