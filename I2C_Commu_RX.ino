//SDA (Serial Data Line): Connect A4 on both Arduinos.
//SCL (Serial Clock Line): Connect A5 on both Arduinos.
#include <Wire.h>

void setup() {
  Wire.begin(8); // Initialize I2C communication as Slave with address 8
  Wire.onReceive(receiveEvent); // Register event for receiving data
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Nothing to do here
}

void receiveEvent(int bytes) {
  String message = "";
  while (Wire.available()) {
    char c = Wire.read(); // Read each character
    message += c; // Append to the message string
  }
  Serial.println("Received: " + message); // Print received message to Serial Monitor
}
