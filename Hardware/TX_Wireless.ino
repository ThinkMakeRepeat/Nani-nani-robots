#include <VirtualWire.h>
int fwdpin = 2;
int leftpin = 3;
int rightpin = 4;
int led = 13;

void setup()
{
  // Button Pin Modes

  pinMode(fwdpin, INPUT_PULLUP);
  pinMode(leftpin, INPUT_PULLUP);
  pinMode(rightpin, INPUT_PULLUP);

  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
}
void loop() {

  int fwd = digitalRead(fwdpin);
  int left = digitalRead(leftpin);
  int right = digitalRead(rightpin);
  if (fwd == LOW) {
    Serial.println("Forward");
    send("1");
    digitalWrite(led, HIGH);
  }

  if (left == LOW) {
    Serial.println("Left Turn");
    send("2");
    digitalWrite(led, HIGH);
  }

  if (right == LOW) {
    Serial.println("Right Turn");
    send("3");
    digitalWrite(led, HIGH);
  }
  delay(10);

}
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); // Wait until the whole message is gone
}
