void setup() {
  for (int i = 8; i < 12; i++)
    pinMode(i, INPUT) ; // put your setup code here, to run once:
  for (int i = 4; i < 8; i++)
    pinMode(i, OUTPUT) ;
}

void loop() {
  if (digitalRead(8) == HIGH)
    forward();
  if (digitalRead(9) == HIGH)
    backward() ;
  if (digitalRead(10) == HIGH)
    left() ;
  if (digitalRead(11) == HIGH)
    right() ;
}
void forward()
{
  digitalWrite(7, 0);
  digitalWrite(6, 1); digitalWrite(5, 0); digitalWrite(4, 1);
  while (digitalRead(8) == HIGH);
}
void backward()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0); digitalWrite(5, 1); digitalWrite(4, 0); while (digitalRead(9) == HIGH);
}
void left()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0); digitalWrite(5, 0); digitalWrite(4, 1); while (digitalRead(10) == HIGH);
}
void right()
{
  digitalWrite(7, 0);
  digitalWrite(6, 1); digitalWrite(5, 1); digitalWrite(4, 0); while (digitalRead(11) == HIGH);
}

