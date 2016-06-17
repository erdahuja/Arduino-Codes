void setup()
{
  for ( int i = 0; i < 10; i++)
  {
    pinMode(i, OUTPUT) ;

  }

}


int data[10][8] =
{
  {
    1, 1, 1, 1, 1, 1, 0, 0
  }
  ,  // 0
  {
    0, 1, 1, 0, 0, 0, 0, 0
  }
  ,  //1
  {
    1, 1, 0, 1, 1, 0, 1, 0
  }
  ,  //2
  {
    1, 1, 1, 1, 0, 0, 1, 0
  }
  ,  //3
  {
    0, 1, 1, 0, 0, 1, 1, 0
  }
  ,  //4
  {
    1, 0, 1, 1, 0, 1, 1, 0
  }
  ,  //5
  {
    1, 0, 1, 1, 1, 1, 1, 0
  }
  ,  //6
  {
    1, 1, 1, 0, 0, 0, 0, 0
  }
  ,  //7
  {
    1, 1, 1, 1, 1, 1, 1, 0
  }
  ,  //8
  {
    1, 1, 1, 1, 0, 1, 1, 0
  }
  ,  //9


};

void loop()
{
  int tens;
  int ones;
  for (int count = 0; count <= 99; count++)
  {
    tens = count / 10;
    ones = count % 10;
    for (int rep = 0; rep < 25; rep++)
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
}


