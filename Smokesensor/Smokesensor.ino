/* To sense the amount of smoke in the room using a MQ2 Sensor and if the smoke sensed in above a particular limit then a call is given to the fire department or else a message is the sent to the requires person */

#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
// Variable Setup
int ledPin = 8;
int smokePin=A0;  //the analog pin connected to the smoke sensor's output
#define SMOKEMAX=400;
//////////////////////////
//SETUP

void setup() {
  // Start Serial for debugging on the Serial Monitor
   mySerial.begin(9600);
  Serial.begin(9600);

  pinMode(smokePin, INPUT);
  pinMode(ledPin, OUTPUT);
Serial.println("SENSOR ACTIVE");
}

//////////////////////////
//LOOP
void loop() {
 
   if(analogRead(smokePin) == HIGH){
    Serial.println("Sensor working");  //To check is the sensor is working the gasPin has to give a 
//value HIGH
    digitalWrite(ledPin,HIGH);
    Serial.println(analogRead(smokePin));
    if(analogRead(smokePin)>SMOKEMAX)
    {
    Serial.print("Calling the Fire Brigade");   //Excess smoke in the house
    SendMessage2();
    }
    else
    {
      Serial.print("Sending Message no 1.....");  //Limited smoke in the house
      SendMessage1();
    }
    delay(50000);
}
void SendMessage1()
  {
    if(Serial.available()>0)
      {
    Serial.println("ready...");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  Serial.print("0");
  mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");  //sends a message to the person incharge
  delay(1000);
  Serial.print("1");
  mySerial.println("There is smoke in the house.");
  //mySerial.println(analogRead(gasPin));
  Serial.print("2");
  delay(100);
  Serial.print("3");
  mySerial.println((char)26);
  delay(1000);
 }
 
  }
  void SendMessage2()
  {
    if(Serial.available()>0)
     {
    Serial.println("ready...");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  Serial.print("0");
  mySerial.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");    //sends a message to the fire brigade
  delay(1000);
  Serial.print("1");
  mySerial.println("There is smoke in the house. Calling fire brigade.");
  //mySerial.println(analogRead(gasPin));
  Serial.print("2");
  delay(100);
  Serial.print("3");
  mySerial.println((char)26);
  delay(1000);
   }
  }

