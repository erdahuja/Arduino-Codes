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

float x=3.0,y=0;

int count=0,c=0;


/*int check()
{
  if ((digitalRead(10)==HIGH))
  return 1;
  if ((digitalRead(11)==HIGH))
  return 1;
  return 0;
}

void Delay(int time)
{
  for(int i=0;i<=time;i++)
  {
  delay(1);
  if(check())
  break;
  } 
}
*/
//===================================================
void display()
{
  int tens;
  int ones;
    tens = count / 10;
    ones = count % 10;
    for (int rep=0; rep < 25; rep++)
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

    //=====================================================================

void display_()
{
  int tens;
  int ones;
    tens = count / 10;
    ones = count % 10;
    for (int rep=0; rep <=0; rep++)
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

//========================

void loop()
{
  display();
  y=0;
  x=3.0;
    if (digitalRead(10)==HIGH)
    {
      while(digitalRead(10)==HIGH)
      {
        count++;
        display();
        y++;
        //==============
        for (int i=0,j=1;i<=x*1000;i++,j++)
        {
          delay(1);
          if(j==50)
          {
            j=1;
            display_();
          
          }
          
          if (digitalRead(10)==LOW)
          break;
        }
        while(1)
        {
        if((y/3.0)<=1.0)
        x=x/2;break;
        if((y/3)<=2.0)
        x=x/2;break;
        if((y/3.0)<=3.0)
        x=x/2;break;
        if((y/3)<=4.0)
        x=x/2;break;
        }
        
    }
    }
    //=================decrmnt=================
         y=0;
         x=3.0;
    
        if (digitalRead(11)==HIGH)
    {
      while(digitalRead(11)==HIGH)
      {
        count--;
        display_();
        y++;
        //===============
         for (int i=0,j=1;i<=x*1000;i++,j++)
        {
          delay(1);
          if(j==50)
          {
            j=1;
            display();
          }
          if (digitalRead(10)==LOW)
          break;
          }
        //==================
        while(1)
        {
        if((y/3.0)<=1.0)
        x=x/2;break;
        if((y/3)<=2.0)
        x=x/2;break;
        if((y/3.0)<=3.0)
        x=x/2;break;
        if((y/3)<=4.0)
        x=x/2;break;
        }
        
    }
    }
}
//===========================================================






