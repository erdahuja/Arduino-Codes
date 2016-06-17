#define analoginput A0
const int arr[] = {3, 5, 6, 9, 10, 11};
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 7; i++)
  {
    pinMode(arr[i], OUTPUT);
  }

}

void loop() {
  for (int i = 0; i < 14; i++)
  {
    digitalWrite(i, 0);
  }
  int sensorvalue = analogRead(analoginput);
  int x = map(sensorvalue, 0, 1023, 0, 5) ;
  int y = map(sensorvalue, 0, 1023, 0, 255) ;

  for (int i = 0; i <= x; i++)
  {
    digitalWrite(arr[i], 1);
    Serial.println(sensorvalue);
    Serial.println("'");
 
  }
   analogWrite(arr[x], y);
delay(15);




}
