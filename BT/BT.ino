#include <SoftwareSerial.h>

SoftwareSerial ABC(2, 3);
void setup() {
  ABC.begin(9600) ;
  Serial.begin(9600) ;
  for (int i = 8; i < 12; i++)
    pinMode(i, INPUT) ; // put your setup code here, to run once:
  for (int i = 4; i < 8; i++)
    pinMode(i, OUTPUT) ;

}

void loop() {
  int x;
  if (ABC.available())
  { x = ABC.read() ;
    Serial.write(x) ;
  }
  if (x == 'F')
    forward();
  if (x == 'B')
    backward() ;
  if (x == 'L')
    left() ;
  if (x == 'R')
    right() ;
  if (x == 'S')
    Stop() ;

}
void Stop()
{
  digitalWrite(7, 1);
  digitalWrite(6, 1); digitalWrite(5, 1); digitalWrite(4, 1);
  while (ABC.read() == 'S');
}
void forward()
{
  digitalWrite(7, 0);
  digitalWrite(6, 1); digitalWrite(5, 0); digitalWrite(4, 1);
  while (ABC.read() == 'F');
}
void backward()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0); digitalWrite(5, 1); digitalWrite(4, 0); while (ABC.read() == 'B');
}
void left()
{
  digitalWrite(7, 1);
  digitalWrite(6, 0); digitalWrite(5, 0); digitalWrite(4, 1); while (ABC.read() == 'L');
}
void right()
{
  digitalWrite(7, 0);
  digitalWrite(6, 1); digitalWrite(5, 1); digitalWrite(4, 0); while (ABC.read() == 'R');
}

