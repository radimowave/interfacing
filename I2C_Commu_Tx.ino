//SDA (Serial Data Line): Connect A4 on both Arduinos.
//SCL (Serial Clock Line): Connect A5 on both Arduinos.
#include <Wire.h>

void setup() {
  Wire.begin(); // Initialize I2C communication as Master
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  String message = "ESE@KKU"; // Message to send
  Wire.beginTransmission(8); // Start transmission to Slave with address 8
  for (int i = 0; i < message.length(); i++) {
    Wire.write(message[i]); // Send each character of the message
  }
  Wire.endTransmission(); // End transmission
  Serial.println("Message sent: " + message); // Print sent message to Serial Monitor
  delay(2000); // Wait 2 seconds before sending the message again
}
