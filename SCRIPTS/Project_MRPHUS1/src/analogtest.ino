/**
 * @Author: carlosgilgonzalez
 * @Date:   2018-04-12T18:36:07+02:00
 * @Last modified by:   carlosgilgonzalez
 * @Last modified time: 2018-05-08T17:33:05+02:00
 */



/******************************************************************************
Analog Test
******************************************************************************/
/*
Here goes  the libraries
*/

/*
void setup() {
  // initialize the serial communication:
  Serial.begin(115200);


}

void loop() {
a


  // send the value of analog input 0:
  int val = analogRead(A2);
  Serial.println(val);

  //Wait for a bit to keep serial data from saturating
  delay(8);
}
*/

void setup() {
  // initialize the serial communication:
  //Serial.begin(115200);
  Serial1.begin(9600);


}

void loop() {



  // send the value of analog input 0:
  int val = analogRead(A2);
  int val2 = analogRead(A1);
  //Serial.print(val);
  //Serial.print(",");
  //Serial.println(val2);
  Serial1.println(val2);
  if(Serial1.available()>=1){
    char entrada = Serial1.read(); //Leer un caracter

    if(entrada == 'h' or entrada == 'H') //Si es 'H', encender el LED
    {
       digitalWrite(32, HIGH);
       //Serial.println("LED encendido");
       //Serial.println(entrada);
       Serial1.println("LED encendido\r\n");
    }

    else if(entrada == 'l' or entrada == 'L') //Si es 'L', apagar el LED
    {
       digitalWrite(32, LOW);
       //Serial.println("LED apagado");
    }

    else if(entrada == 'i' or entrada == 'I') //Si es 'I', mostrar un mensaje de ayuda
    {
       //Serial.println("Comandos:/n (i) - abrir esta lista/n (h)- encender led/n (l) - apagar ledn");
    }

  }

  //Wait for a bit to keep serial data from saturating
  delay(10);
}
