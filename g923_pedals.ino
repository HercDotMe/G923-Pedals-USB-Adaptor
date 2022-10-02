// Frequency to update the pedals values at (100Hz -> 100 times a second). Must be between 10Hz and 100Hz
int UPDATE_FREQUENCY_HZ = 50;

#include <Joystick.h> // Include required underlying Joystick library
 
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // Indicates the joystick's HID report ID (0x03)
  JOYSTICK_TYPE_GAMEPAD, // Multi-axis Controller (0x08)
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

unsigned long LOOP_COUNT = 0; // Loop counter
int RXLED = 17; // The RX LED has a defined Arduino pin
int TXLED = 30; // The TX LED has a defined Arduino pin

void setup()
{  
  // Set TXLED and RXLED as outputs
  pinMode(TXLED, OUTPUT); //TXLED Will be turned off
  pinMode(RXLED, OUTPUT); // RXLED Will blink depending on the update frequency
  
  // Initialize joystick object with auto send false
  Joystick.begin(false);
  
  // Set axis range
  Joystick.setThrottleRange(0,1023);
  Joystick.setBrakeRange(0,1023);
  Joystick.setZAxisRange(0,1023);
  
  // Init axis values
  Joystick.setThrottle(0);
  Joystick.setBrake(0);
  Joystick.setZAxis(0);
  
  // Validate update frequency setting
  if (UPDATE_FREQUENCY_HZ > 100)
  {
    UPDATE_FREQUENCY_HZ = 100;
  }
  if (UPDATE_FREQUENCY_HZ < 10)
  {
    UPDATE_FREQUENCY_HZ = 10;
  }
}

void loop(){
  // Update Throttle value from pin A2
  Joystick.setThrottle(analogRead(A2));
  
  // Update Brake value from pin A1
  Joystick.setBrake(analogRead(A1));
  
  // Update Clutch value from pin A0
  Joystick.setZAxis(analogRead(A0));
  
  // Send updated values to host
  Joystick.sendState();
  
  // If you don't want the leds to blink, delete the block between [LED_BLINK] and  [/LED_BLINK]
  // [LED _BLINK]
    if (LOOP_COUNT % 20 < 5)
    { digitalWrite(RXLED, LOW); } // set the TXLED off
    else
    { digitalWrite(RXLED, HIGH); } // set the TXLED on
  // [/LED _BLINK]
  
  delay(1000 / UPDATE_FREQUENCY_HZ);
  LOOP_COUNT++;
  
  // Reset LOOP counter to 0 after 5000 itterations to prevent it running out of memory
  if (LOOP_COUNT > 5000) {
    LOOP_COUNT = 0;
  }
}
