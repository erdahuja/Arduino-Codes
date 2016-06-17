void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
 PORTC=0x00;
 // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
