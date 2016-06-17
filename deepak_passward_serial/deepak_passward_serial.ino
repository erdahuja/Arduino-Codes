void setup()
{
  Serial.begin(9600);
  pinMode(6,INPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  pinMode(13,INPUT);

}

void loop ()
{
  Serial.print(" \n enter the password\n ");
  
  int A[4];
  for(int i=0;i<4;i++)
  {
    while((digitalRead(6)==0)&&(digitalRead(7)==0)&&(digitalRead(8)==0)&&(digitalRead(13)==0));
    if(digitalRead(6)==1)
    { A[i]=1; 
    while(digitalRead(6)==1);
    Serial.print("*"); }
    if(digitalRead(7)==1)
    { A[i]=2; 
     while(digitalRead(7)==1);Serial.print("*"); }
    if(digitalRead(8)==1)
    { A[i]=3; while(digitalRead(8)==1);  Serial.print("*"); }
    if(digitalRead(13)==1)
    { A[i]=4;  while(digitalRead(13)==1); Serial.print("*"); }
    delay(100);
  }  
  
 
  
  
  if((A[0]==1)&&(A[1]==2)&&(A[2]==3)&&(A[3]==4))
  {
  
            Serial.print("\n correct password");
            delay(15);  
           }
         
       
     
else
{
  Serial.print("\n incorrect password");
}
  
   while((digitalRead(6)==0)&&(digitalRead(7)==0)&&(digitalRead(8)==0)&&(digitalRead(13)==0));
   delay(100);
   
}
