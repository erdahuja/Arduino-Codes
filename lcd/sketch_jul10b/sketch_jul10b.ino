void setup()
{
  DDRD=0b11111111;
  DDRB=0b11111111;
}

void command(int code);
{
  digitalWrite(rs,LOW);
  PORTD=x;
  digitalWrite(E,HIGH);
  delay(15);
  digitalWrite(E,LOW);
}

void disp_char(int character)
{
  digitalWrite(rs,HIGH);
  PORTD=character;
  digitalWrite(E,HIGH);
  delay(15);
  digitalWrite(E,LOW);
}

void disp_string(int* string)
{
  while(
  digitalWrite(rs,HIGH)
  PORTD=string;
  
}

