int row_pins[4] = {2, 3, 4, 5};
int col_pins[4] = {6, 7, 8, 9};
int data[4][4] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'a', 'b', 'c'},
  {'d', 'e', 'f', 'g'}
};



void setup() {

  for (int i = 0; i < 4; i++)
  {
    pinMode(row_pins[i], OUTPUT) ;
    pinMode(col_pins[i], INPUT) ;
    digitalWrite(row_pins[i], HIGH) ;
    digitalWrite(col_pins[i], HIGH) ;

    Serial.begin(9600) ;
  }
  // put your setup code here, to run once:

}

void loop() {


  for (int i = 0; i < 4; i++)
  {
    digitalWrite(row_pins[i], LOW) ;


    for (int j = 0; j < 4; j++)
    {

      if (digitalRead(col_pins[j]) == LOW)
      {
        delay(15);
        while (digitalRead(col_pins[j]) == LOW);
        delay(15);

        Serial.write(data[i][j]);
      }
    }

    delay(50);
    digitalWrite(row_pins[i], HIGH);

  }


  // put your main code here, to run repeatedly:

}
