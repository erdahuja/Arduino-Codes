int row_pins[4]={2,3,4,5};
int col_pins[4]={6,7,8,9};
int data[4][4]=
{
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','a','b'},
  {'c','d','e','f'}
};
int input_passwd[4];
int true_passwd[]={'1','5','1','2'};
int flag=0;
int k=0;

//====================================================================================
void setup()
{
  for(int i=0;i<=3;i++)
  {
    pinMode(row_pins[i],OUTPUT);
    pinMode(col_pins[i],INPUT);
    digitalWrite(row_pins[i],HIGH);
    digitalWrite(col_pins[i],HIGH);
    
  }
  Serial.begin(9600);
  
}

int check_passwd()
{
  if(k==3)                // password checking starts here when there is 4 characters in input_passwd
  {       
    for(int i=0;i<=3;i++)
    {
      if((input_passwd[i])!=(true_passwd[i]))
      {
        Serial.println("\nINCORRECT PASSWORD");
        k=0;           //resetting k to 0 for next turn
        return 1;
      }
      flag=i;  //flag will be 3 when this for loop completes without going through if statement
    }
    if (flag==3) // flag =3 means all characters matches with passwd characters
    {
      Serial.println("\nCORRECT PASSWORD");
      k=0;            //resetting k to 0 for next turn
      return 1;
    }
  }        // password checkig ends here 
return 0;
}


//=====================================================================================


void loop()
{
  label:
  Serial.println("ENTER PASSWORD");
  while(1){
  for (int i=0;i<=3;i++)
  {
    digitalWrite(row_pins[i],LOW);
    for(int j=0;j<=3;j++)
    {
      if (digitalRead(col_pins[j])==LOW)
      { 
        delay(15);
        while(digitalRead(col_pins[j])==LOW);
        delay(15);
        input_passwd[k]=data[i][j];
        Serial.print("*");
        if(check_passwd()==1)
        {
          delay(1000);
          goto label ;
        }
        k++;
      }
    }
     digitalWrite(row_pins[i],HIGH);   
  
  
  }
  
  }
}

