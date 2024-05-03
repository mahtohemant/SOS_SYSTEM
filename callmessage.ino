//HEMANT PROJECT V.A.J.R
#include <SoftwareSerial.h>

static const int RXPin = 6, TXPin = 5;
static const uint32_t A9GBaud = 115200; // Default baud rate for A9G module

SoftwareSerial ss(RXPin, TXPin); // The serial connection to the A9G module

void setup() {
  Serial.begin(9600);
  ss.begin(A9GBaud);
  delay(1000); // Delay to allow the A9G module to initialize
  
  Serial.println("Setup Executed");
  
  sendSMS();
}

void loop() {
  receiveCall(); // Continuously monitor for incoming calls
}

void sendSMS() {
  Serial.println("Sending SMS...");
  
  //ss.println("AT+CMGS=\"+917761952503\""); // Command to send SMS to the desired number
  //delay(1000);
  ss.print("This is a test message sent from Arduino."); // Message content
  delay(100);
  ss.write(26); // CTRL+Z to send the message
  delay(1000); // Delay for the message to be sent
  
  Serial.println("SMS sent, making call...");
  
  makeCall(); // After sending the SMS, make the call immediately
}

void makeCall() {
  Serial.println("Making a call...");
  
  ss.println("ATD+917761952503;"); // Replace with the phone number you want to call
  delay(100000); // Delay to give time for the call to connect (adjust as needed)
  ss.println("ATH"); // Hang up the call
  
  Serial.println("Call completed");
}

void receiveCall() {
  if (ss.available()) {
    String response = ss.readStringUntil('\n');
    if (response.indexOf("RING") != -1) {
      Serial.println("Incoming call detected!");
      // Add your desired action when receiving a call, e.g., answer the call
      // Example: ss.println("ATA"); // Answer the call
    }
  }
}
