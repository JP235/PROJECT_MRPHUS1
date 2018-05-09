/**
 * @Author: carlosgilgonzalez
 * @Date:   2018-05-09T01:35:49+02:00
 * @Last modified by:   carlosgilgonzalez
 * @Last modified time: 2018-05-09T20:18:21+02:00
 */



/******************************************************************************
Analog Test
******************************************************************************/
/*
Here goes  the librariesaaa
a
a*/

/*
void setup() {
  // initialize the serial communication:
  Serial.begin(115200);


}

void loop() {aa



  // send the value of analog input 0:
  int val = analogRead(A2);
  Serial.println(val);

  //Wait for a bit to keep serial data from saturating
  delay(8);
}
*/

#include <RTCZero.h>




/* Create an rtc object */
RTCZero rtc;

/* Change these values to set the current initial time */
//const byte seconds = 0;
int seconds = 0;
//const byte minutes = 0;
int minutes = 0;
//const byte secs= seconds;
//const byte hours = 0;
int hours = 0;
int counter = 0;
/* Change these values to set the current initial date */
const byte day = 25;
const byte month = 9;
const byte year = 15;

int hour_time = 0;
int hourval = 0;
int minuteval = 0;
int secondval = 0;

int set_Timer = 0;


// FILTER SET UP

// filters out changes faster that 5 Hz.


// create a one pole (RC) lowpass filter


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("Ready");



  //rtc.attachInterrupt(alarmMatch);


}

void loop() {

  if (set_Timer == 0) {
    if(Serial1.available()>=1){
      char entrada = Serial1.read(); //Leer un caracter

      if(entrada == 'h' or entrada == 'H') //Si es 'H', encender el LED
      {
        digitalWrite(32, HIGH);
        Serial.println('Setting clock..');
        rtc.begin(); // initialize RTC 24H format
        hourval = Serial1.parseInt();
        Serial.print(hourval);
        minuteval = Serial1.parseInt();
        Serial.print(":");
        Serial.print(minuteval);
        secondval = Serial1.parseInt();
        Serial.print(":");
        Serial.println(secondval);

        const byte minutes = minuteval;
        const byte hours = hourval;
        const byte seconds = secondval;
        rtc.setTime(hourval, minuteval, seconds);
        rtc.setDate(day, month, year);

        rtc.setAlarmTime(1, 3, 10);
        rtc.enableAlarm(rtc.MATCH_HHMMSS);

        rtc.attachInterrupt(alarmMatch);
        set_Timer = 1;
      }
    }
  }

  // send the value of analog input 0:
  int val = analogRead(A2);
  int val2 = analogRead(A1);
  //int val2 = analogRead(A1);
  //Serial.print(val);
  //Serial.print(",");
  //Serial.println(val2);

  if(Serial1.available()>=1){
    char entrada = Serial1.read(); //Leer un caracter

    if(entrada == 'h' or entrada == 'H') //Si es 'H', encender el LED
    {
       digitalWrite(32, HIGH);

       hourval = Serial1.parseInt();
       Serial.print("Alarm set at: ");
       Serial.print(hourval);
       minuteval = Serial1.parseInt();
       Serial.print(":");
       Serial.println(minuteval);
       rtc.setAlarmTime(hourval, minuteval, 0);

       //Serial.println("LED encendido");
       //Serial.println(entrada);
       //Serial1.println("LED encendido\r\n");
       //Serial1.println(val);
    }

    else if(entrada == 'l' or entrada == 'L') //Si es 'L', apagar el LED
    {
       digitalWrite(32, LOW);
       //Serial.println("LED apagado");
       Serial.print(hourval);
       Serial.print(":");
       Serial.println(minuteval);

    }

    else if(entrada == 'i' or entrada == 'I') //Si es 'I', mostrar un mensaje de ayuda
    {
       //Serial.println("Comandos:/n (i) - abrir esta lista/n (h)- encender led/n (l) - apagar ledn");
    }

  }

  //Serial1.println(val);
  //Wait for a bit to keep serial data from saturating
  if (set_Timer == 1 & counter == 100) {
  print2digits(rtc.getHours());
  Serial.print(":");
  print2digits(rtc.getMinutes());
  Serial.print(":");
  print2digits(rtc.getSeconds());

  Serial.println();
  counter = 0;}

  if (set_Timer == 1 & counter < 100) {
  counter += 1;
  //Serial.println(counter);
  Serial1.println(val);
}
  delay(10);
  //delay(10);
}
void alarmMatch()
{
  Serial.println("Alarm Match!");
  Serial1.println(1);
}
void print2digits(int number) {
  if (number < 10) {
    Serial.print("0"); // print a 0 before if the number is < than 10
  }
  Serial.print(number);
}
