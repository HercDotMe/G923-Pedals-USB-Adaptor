int RXLED = 17; // The RX LED has a defined Arduino pin
int TXLED = 30; // The TX LED has a defined Arduino pin

int TIME = 0; // Time loop

int STEP_DELAY = 50; // Loop step delay

#include <Joystick.h>

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // Indicates the joystick's HID report ID (0x03)
  JOYSTICK_TYPE_MULTI_AXIS, // Multi-axis Controller (0x08)
  0, // Indicates how many buttons will be available on the joystick.
  0, // Indicates how many hat switches will be available on the joystick.
  false, // Indicates if the X Axis is available on the joystick.
  false, // Indicates if the Y Axis is available on the joystick.
  true, // Indicates if the Z Axis (in some situations this is the right X Axis) is available on the joystick. [Clutch]
  false, // Indicates if the X Axis Rotation (in some situations this is the right Y Axis) is available on the joystick.
  false, // Indicates if the Y Axis Rotation is available on the joystick.
  false, // Indicates if the Z Axis Rotation is available on the joystick.
  false, // Indicates if the Rudder is available on the joystick.
  true, // Indicates if the Throttle is available on the joystick.[Acceleration]
  false, // Indicates if the Accelerator is available on the joystick. 
  true, // Indicates if the Brake is available on the joystick. [Brake]
  false // Indicates if the Steering is available on the joystick.
);

int Throttle_ = 0;
int Brake_ = 0; 
int Clutch_ = 0; 

const bool initAutoSendState = true; 

void setup()
{
  Joystick.begin();
  
  pinMode(TXLED, OUTPUT); // Set TX LED as an output
  
  digitalWrite(TXLED, HIGH); // set the LED on
  digitalWrite(RXLED, LOW); // set the LED on
}

void loop(){
  Throttle_ = analogRead(A2);
  Throttle_ = map(Throttle_,1023,0,255,0);         
  Joystick.setThrottle(Throttle_);
  
  Brake_ = analogRead(A1);
  Brake_ = map(Brake_,1023,0,255,0);         
  Joystick.setBrake(Brake_);
  
  Clutch_ = analogRead(A0);
  Clutch_ = map(Clutch_,1023,0,255,0);         
  Joystick.setZAxis(Clutch_);
  
  // If you don't want the leds to blink, delete the block between [LED_BLINK] and  [/LED_BLINK]
  // [LED _BLINK]
  TIME += STEP_DELAY;
  
  if (TIME < 500)
  {
    digitalWrite(TXLED, LOW); // set the LED off
    digitalWrite(RXLED, HIGH); // set the LED off
  }
  if (TIME >= 500)
  {
    digitalWrite(TXLED, HIGH); // set the LED off
    digitalWrite(RXLED, LOW); // set the LED off
  }
  
  if (TIME >= 1000)
  {
    TIME = 0;
  }
  // [/LED _BLINK]
  
  delay(STEP_DELAY);
}
