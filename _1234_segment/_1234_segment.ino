void setup()
{ 
  for( int i=0;i<13;i++)
  {
    pinMode(i,OUTPUT) ;
    digitalWrite(i,1) ;
  }  

}


int data[10][8]=
{
  {
    1,1,1,1,1,1,0,0    }
  ,  // 0
  {
    0,1,1,0,0,0,0,0    }
  ,  //1
  {
    1,1,0,1,1,0,1,0    }
  ,  //2
  {
    1,1,1,1,0,0,1,0    }
  ,  //3
  {
    0,1,1,0,0,1,1,0    }
  ,  //4
  {
    1,0,1,1,0,1,1,0    }
  ,  //5
  {
    1,0,1,1,1,1,1,0    }
  ,  //6
  {
    1,1,1,0,0,0,0,0    }
  ,  //7
  {
    1,1,1,1,1,1,1,0    }
  ,  //8
  {
    1,1,1,1,0,1,1,0    }
  ,  //9


};

void loop()
{

  {
    for(int i=8;i<12;i++)
    {
      if(i==8)
        oneon();
      if(i==9)
        twoon();
      if(i==10)
        threeon();
      if(i==11)
        fouron();

    }
  }

  //+++1+++




  //++2++


}


void    oneon()
{
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
  for (int i=0; i<=7; i++)
  {
    digitalWrite (i,data[1][i]);

  }   
  delay(5) ;

}


void twoon()

{
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(10,0);
  digitalWrite(11,0);
  for (int i=0; i<=7; i++)
  {
    digitalWrite (i,data[2][i]);
  }   
  delay(5);

}

void threeon()
{
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,1);
  digitalWrite(11,0);
  
    for (int i=0; i<=7; i++)
  {
    digitalWrite (i,data[3][i]);
  }   
  delay(5);

}

void fouron()
{
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,1);
  
    for (int i=0; i<=7; i++)
  {
    digitalWrite (i,data[4][i]);
  }   
  delay(5);

}

