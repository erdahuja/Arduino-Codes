#define analogoutput 3
#define analoginput A0

void setup() {
  Serial.begin(9600);
  digitalWrite(1, 0);
  for(int i=2;i<=9;i++)
  {
    pinMode(i,OUTPUT);
    }// put your etup code here, to run once:

}

void loop() 
{

  int  sensorvalue = analogRead(analoginput);
int  x = map(sensorvalue, 0, 1023, 2, 9);

      Serial.println(sensorvalue);
       
      Serial.print(x);
      Serial.print(",");
      
      for(int i=2;i<=x;i++)
      {
        digitalWrite(i,1);
      }

 for(int i=x+1;i<10;i++)
      {
        digitalWrite(i,0);
      }
      
  // put your main code here, to run repeatedly:

}
