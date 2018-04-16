/******************************************************************************
Project Morpheus One:
-Sensors:
  * Myoware Muscle Sensor
  * Electret Michropone BOB 12758
-Timer:
  * RTC DS1307
- Bluetooth:
  * HC05


******************************************************************************/

void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  Serial1.begin(115200); // initialize bluetooth communication


}

void loop() {


  // Connect to Bluetooth

  // In bt mobile app set alarm

  // store alarm in a cte var

  //


  //
  // send the value of analog input 0:
  int val = analogRead(A2);
  Serial.println(val);

  //Wait for a bit to keep serial data from saturating
  delay(8);
}


void EOG_dsp(){

  // Function that read EOG signal and output REM or NOT REM

}


void FIRE_ALARM(){

  // WORST CASE SCENARIO --> LONGEST REM TIME

  // Function that decides wether send the alarm signal or NOT

  // if NOT REM and ALARM == TIME.NOW() --> FIREs alarm ??

  // if NOT REM AND ALARM - TIME.NOW() < LONGEST REM TIME --> FIREs ALARM ??

  // ¿?
}

void LOG_EOG(){
  // Save the EOG signal in the microSD

}

void LOG_SNORE(){
// Save the sound signal in the microSD

}

void SOUND_dsp(){
// Analyze sound signal and output SNORE or NOT SNORE

}
