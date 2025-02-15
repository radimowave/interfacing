/*MOSI (Master Out Slave In): Connect D11 on the Master to D11 on the Slave.
  MISO (Master In Slave Out): Connect D12 on the Master to D12 on the Slave.
  SCK (Serial Clock): Connect D13 on the Master to D13 on the Slave.
  SS (Slave Select): Connect D10 on the Master to D10 on the Slave.
 GND: Connect the GND pins of both Arduinos together.
*/

//Master side 
#include <SPI.h>

void setup() {
  // Set SS pin as output
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH); // Ensure SS is high to start (inactive)

  // Initialize SPI as Master
  SPI.begin();
  Serial.begin(9600);
}

void loop() {
  char message[] = "ESE@KKU"; // Message to send
  digitalWrite(SS, LOW); // Activate Slave by setting SS low

  for (int i = 0; i < sizeof(message); i++) {
    SPI.transfer(message[i]); // Send each character
    Serial.print("Sent: ");
    Serial.println(message[i]);
  }

  digitalWrite(SS, HIGH); // Deactivate Slave by setting SS high
  delay(1000); // Wait for 1 second before sending again
}
