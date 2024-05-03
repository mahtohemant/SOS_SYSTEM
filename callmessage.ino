//HEMANT PROJECT V.A.J.R
#include <SoftwareSerial.h>

static const int RXPin = 6, TXPin = 5;
static const uint32_t A9GBaud = 115200; 

SoftwareSerial ss(RXPin, TXPin); 
void setup() {
  Serial.begin(9600);
  ss.begin(A9GBaud);
  delay(1000); 
  
  Serial.println("Setup Executed");
  
  sendSMS();
}

void loop() {
  receiveCall(); 
}

void sendSMS() {
  Serial.println("Sending SMS...");
  
  //ss.println("AT+CMGS=\"+917761952503\""); 
  //delay(1000);
  ss.print("This is a test message sent from Arduino."); 
  delay(100);
  ss.write(26); 
  delay(1000); 
  
  Serial.println("SMS sent, making call...");
  
  makeCall(); 
}

void makeCall() {
  Serial.println("Making a call...");
  
  ss.println("ATD+917761952503;"); 
  delay(100000); 
  ss.println("ATH");
  
  Serial.println("Call completed");
}

