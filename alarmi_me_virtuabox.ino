#include <virtuabotixRTC.h>


// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8);

int buttonState=0;
void setup()  {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  //myRTC.setDS1302Time(00, 58, 18, 7, 25, 12, 2021);
}
void loop()  {
  digitalWrite(13,LOW);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.print("U shtyp");
    digitalWrite(13, HIGH);
  } else {
    // turn LED off:
    digitalWrite(13, LOW);
  }
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  // Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
  // Delay so the program doesn't print non-stop
  delay(1000);

  if( myRTC.seconds == 40  || myRTC.seconds == 30 || myRTC.seconds == 50 || myRTC.seconds == 20 ){
    digitalWrite(13,HIGH);
    delay(1000);
    Serial.println("correct");
  }
  
}
