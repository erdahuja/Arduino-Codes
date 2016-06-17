void setup() {
  for(int i=0;i<=7;i++)
  pinMode(i,OUTPUT) ;
  for(int j=8;j<=13;j++)
  pinMode(j, INPUT);
  // put your setup code here, to run once:

}


void pattern_1()
{{for(;;)
  for(int i=0;i<=7;i++)
  {
  digitalWrite(i,HIGH) ;
  delay(200) ;
  digitalWrite(i,LOW) ;
  delay(200);
  check() ;
  }
}
}
//*****************pattern1


void pattern_2()
{for(;;)
{
  for(int i=0;i<=7;i++)
  {
  digitalWrite(i,HIGH) ;
 
  digitalWrite(7-i,HIGH) ;
  delay(200) ;
  check() ; 
   digitalWrite(i,LOW) ;
  digitalWrite(7-i,LOW) ;
  
  }
} 
}
//*************************pattern2
void loop() 
{
   for(int i=0;i<=7;i++)
  digitalWrite(i,LOW);
 if(digitalRead(8)==HIGH)
 pattern_1() ;
 if(digitalRead(9)==HIGH)
 pattern_2() ;
 
}

//=================check=============
void check()
{
  if(digitalRead(8)==HIGH)
  {
  low() ;
  pattern_1() ;
  }
  
  else if(digitalRead(9)==HIGH)
 { 
low() ;
  pattern_2() ;
 }
  
  }

  void low()

 {
  for(int i=0;i<=7;i++)
 digitalWrite(i,LOW);
  }















