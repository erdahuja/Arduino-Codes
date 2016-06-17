void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }


}
int a[4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};


void loop()
{
  for (int i = 0; i < 4; i++)
  { 
    for (int j = 0; j < 4; j++)
    digitalWrite(j+4,a[i][j]);
    delay(2);
    }

  

}
