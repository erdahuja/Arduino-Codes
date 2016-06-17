void setup() {
  Serial.begin(9600);
 
  for(int i=0;i<8;i++)
 {
  pinMode(i, OUTPUT);
 }
 
 
}
int a[] = {0x0C};
int b[] = {0x06};
int c[] = {0x03};
int d[] = {0x09};
void loop()
{

  PORTD= a[];
  delay(2);
  PORTD= b[];
  delay(2);
  PORTD=C[];
  delay(2);
  PORTD=[];
  delay(2);
  
}
