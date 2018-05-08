/**
 * @Author: carlosgilgonzalez
 * @Date:   2018-01-22T22:27:23+01:00
 * @Last modified by:   carlosgilgonzalez
 * @Last modified time: 2018-05-08T17:29:21+02:00
 */



/******************************************************************************
Analog Test
******************************************************************************/

void setup() {
  // initialize the serial communication:aa
  Serial.begin(115200);


}

void loop() {



  // send the value of analog input 0:
  int val = analogRead(A2);
  Serial.println(val);

  //Wait for a bit to keep serial data from saturating
  delay(8);
}
