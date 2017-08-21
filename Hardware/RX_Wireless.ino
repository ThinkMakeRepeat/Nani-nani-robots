// MOTOR DEFINITIONS -----------------------------------------------------------------------------
int i;

int leftMotor = 3; // right throttle motor pin
int rightMotor = 5; // right throttle motor pin

int maxSpeed = 255;
int turnSpeed = 64;
int minSpeed = 0;


// BUTTON STEERING DEFINITIONS -----------------------------------------------------------------------------

// MOVE FORWARD ----------
int forward = 2;
int forwardState = 0;

// RIGHT TURN ----------
int right = 4;
int rightState = 0;

// LEFT TURN ----------
int left = 7;
int leftState = 0;



// FOR DEBUGGING -----------------------------------------------------------------------------

int led = 13;

#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
void setup()
{
  Serial.begin(9600);
  Serial.println("Device is ready");
  // MOTOR PINMODES -----------------------------------------------------------------------------

  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);


  // BUTTON PINMODES -----------------------------------------------------------------------------

  pinMode(forward, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);



  // FOR DEBUGGING -----------------------------------------------------------------------------
  pinMode(led, OUTPUT);
  // Initialize the IO and ISR
  vw_setup(2000); // Bits per sec
  vw_rx_start(); // Start the receiver
}
void loop()
{

  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
      if (message[i] == 1) {

        Serial.println("Drive Forward");
        analogWrite(leftMotor, maxSpeed);
        analogWrite(rightMotor, maxSpeed);

        digitalWrite(led, HIGH);
      }

    if (message[i] == 2) {
      Serial.println("Right Turn");
      analogWrite(leftMotor, turnSpeed);
      analogWrite(rightMotor, maxSpeed);

      digitalWrite(led, HIGH);
    }

    if (message[i] == 3) {
      Serial.println("Left Turn");
      analogWrite(leftMotor, maxSpeed);
      analogWrite(rightMotor, turnSpeed);

      digitalWrite(led, HIGH);
    }
    delay(500);
    
   // else {
   //   Serial.println("Stopped");
   //   analogWrite(leftMotor, minSpeed);
   //   analogWrite(rightMotor, minSpeed);

      digitalWrite(led, LOW);
    }
    Serial.write(message[i]);
    delay(500);
  }
  Serial.println();
  
}
