void setup() {
  for(int i=0;i<=7;i++)
  pinMode(i,OUTPUT) ;
  pinMode(9,INPUT);
  // put your setup code here, to run once:

}

void loop() {
 int flag=0;
  for(;;)
  {
  if(digitalRead(9)==HIGH)
  {
    if(flag==0)
    {digitalWrite(0,HIGH);
    flag=1;
    while(digitalRead(9)==HIGH);
    
    } 
   else
    {
    digitalWrite(0,LOW);
    flag=0;
    while(digitalRead(9)==HIGH);
    }
  }
  }
}

