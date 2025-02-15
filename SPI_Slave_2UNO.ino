/*MOSI (Master Out Slave In): Connect D11 on the Master to D11 on the Slave.
  MISO (Master In Slave Out): Connect D12 on the Master to D12 on the Slave.
  SCK (Serial Clock): Connect D13 on the Master to D13 on the Slave.
  SS (Slave Select): Connect D10 on the Master to D10 on the Slave.
 GND: Connect the GND pins of both Arduinos together.
*/

// Slave

#include <SPI.h>

volatile char receivedChar;
volatile bool messageReceived = false;
char messageBuffer[8]; // Buffer to store the received message
int index = 0;

void setup() {
  // Set MISO as output (optional for Slave)
  pinMode(MISO, OUTPUT);

  // Turn on SPI in Slave mode
  SPCR |= _BV(SPE);

  // Turn on interrupts for SPI
  SPCR |= _BV(SPIE);

  Serial.begin(9600);
}

// SPI interrupt routine
ISR(SPI_STC_vect) {
  receivedChar = SPDR; // Read the received byte
  if (index < 7) {
    messageBuffer[index++] = receivedChar; // Store the byte in the buffer
  } else {
    messageBuffer[index] = '\0'; // Null-terminate the string
    messageReceived = true; // Set flag to indicate message is complete
    index = 0; // Reset index for next message
  }
}

void loop() {
  if (messageReceived) {
    Serial.print("Received: ");
    Serial.println(messageBuffer); // Print the received message
    messageReceived = false; // Reset the flag
  }
}
