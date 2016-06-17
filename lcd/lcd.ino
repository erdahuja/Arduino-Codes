int rs = 8 ;
int e = 9 ;

void setup()
{
 for (int i = 0; i < 10; i++)
 {
 pinMode(i,OUTPUT) ;
 }
  
}

char d1[] = {"HIMANSHI"} ;
char d2[a] = {"DEEPAK"} ;

void command(int x)
{
  digitalWrite(rs, 0) ;
  PORTD = x ;
  enable() ;
}

void data(int x)
{
  digitalWrite(rs, 1) ;
  PORTD = x ;
  enable() ;
}
void loop()
{
  command(0x01);
  delay(15) ;
  command(0x38);
  delay(15) ;
  command(0x0E);
  digitalWrite(8, 1) ;
  delay(15) ;
  
  for (int i = 0; d1[i]!='\0'; i++)
  {
    data(d1[i]);
    delay(100) ;
  }
  delay(1000) ;
   command(0x01);
  delay(15) ;
  for (int i = 0; d2[i]!='\0'; i++)
  { 
    data(d2[i]);
    delay(100) ;
  }

  delay(1000) ;
 
}

void enable()
{
  digitalWrite(9, 1) ;
  delay(20) ;
  digitalWrite(9, 0) ;
}
