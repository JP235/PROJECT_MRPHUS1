/******************************************************************************
Analog Test
******************************************************************************/
/*
Here goes  the libraries
*/


void setup() {
  // initialize the serial communication:
  Serial.begin(115200);


}

void loop() {



  // send the value of analog input 0:
  int val = analogRead(A2);
  Serial.println(val);

  //Wait for a bit to keep serial data from saturating
  delay(8);
}
