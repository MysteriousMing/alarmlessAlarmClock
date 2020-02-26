#include <Stepper.h>
#include <TimeLib.h>
#include <TimeAlarms.h>


const int stepsPerRevolution = 200;

const byte seconds = 30;
const byte minutes = 59;
const byte hours = 7;

const byte days = 16;
const byte months = 2;
const byte years = 20;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 9, 10, 11);


void setup() {
  Serial.begin(9600);
  
  //Set the time
  setTime(hours, minutes, seconds, days, months, years);
  
  //Set the motor speed (RPMs):
  myStepper.setSpeed(100);
  
  Alarm.alarmRepeat(8, 0, 0, alarmMatch);
  Alarm.alarmRepeat(8, 0, 0, alarmMatch2);
  
}

void loop() {
  digitalClockDisplay();
  Alarm.delay(500);
}

void alarmMatch(){
  //Stepper motor
  myStepper.step(-5800);
}

void alarmMatch2(){
  Serial.println("it works!");
}

void digitalClockDisplay(){
  //digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}

void printDigits(int digits){
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
