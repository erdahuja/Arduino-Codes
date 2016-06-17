int arr1[] = {1, 0, 0, 0};

int arr2[] = {0, 1, 0, 0};
int arr3[] = {0, 0, 1, 0};
int arr4[] = {0, 0, 0, 1};

void setup() {
  for (int i = 2; i < 6; i++)
  {
    pinMode(i, OUTPUT); // put your setup code here, to run once:
  }
  Serial.begin(9600) ;
}

void loop()
{

  int x;
  if (Serial.available())
  { 
    x = Serial.read() ;
    Serial.println(x);
  }
  if (x == '1')
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, arr1[i - 2]);
    }
    
  if (x == '2')
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, arr2[i - 2]);
    }
    
  if (x == '3')
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, arr3[i - 2]);
    }
  if (x == '4')
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, arr4[i - 2]);
    }
  // put your main code here, to run repeatedly:

}
