void setup()
{
  Serial.begin(9600);
  for (int i = 2; i <= 10; i++)
  { pinMode(i, OUTPUT) ;
    digitalWrite(i, 0) ;
  }


  digitalWrite(10, 1) ;
  // put your setup code here, to run once:

}
int data[10][8] =
{
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1, 0}, //2
  {1, 1, 1, 1, 0, 0, 1, 0}, //3
  {0, 1, 1, 0, 0, 1, 1, 0}, //4
  {1, 0, 1, 1, 0, 1, 1, 0}, //5
  {1, 0, 1, 1, 1, 1, 1, 0}, //6
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 0}, //9
};

void loop() {
  int x;
  // Serial.available();
  if (Serial.available() > 0)
  {
    x = Serial.read();
    Serial.write(x) ;

  }
  {


    if (x =='1')
      oneon();
    if (x == '2')
      twoon();
    if (x == '3')
      threeon();
    if (x == '4')
      fouron();

  }


  // put your main code here, to run repeatedly:

}
void oneon()
{
  for (int i = 2, j = 0; i <= 9, j <= 7; i++, j++)

  { digitalWrite (i, data[1][j]);
    while (Serial.read() == '1');
  }
  delay(5) ;
}

void twoon()
{
   for (int i = 2, j = 0; i <= 9, j <= 7; i++, j++)

  {
    digitalWrite (i, data[2][j]);
    while (Serial.read() == '2');
  }
  delay(5) ;

} void threeon()
{
   for (int i = 2, j = 0; i <= 9, j <= 7; i++, j++)

  {
    digitalWrite (i, data[3][j]);
    while (Serial.read() == '3');

  }
  delay(5) ;
} void fouron()
{
   for (int i = 2, j = 0; i <= 9, j <= 7; i++, j++)

  {
    digitalWrite (i, data[4][j]);
    while (Serial.read() == '4');
  }
  delay(5) ;
}


