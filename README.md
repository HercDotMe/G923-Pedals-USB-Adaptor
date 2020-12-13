# G923 Pedals USB Adaptor

Below you can find all the instructions you need to make your own USB adaptor for Logitech Pedals. I have only tested it with the G923 Pedals but it should work with previous generations too (G920, G29, G27, etc) as long as they use a DB9 connector.

# Bill of materials

**Arduino Nano Board**  
You will need an arduino board of your own choosing. I went with arduino nano due to their size and price. You can find the ones I've used [here](https://www.amazon.co.uk/gp/product/B07FQBQ4Z6/ref=ppx_yo_dt_b_asin_title_o00_s00).

**DB9 Connector**  
The G923 pedals have a DB9 Connector (male) on their end. Since I didn't want an intrusive mode, I had to be able to connect in line with this one. As such, you will need to get some DB9 (female) connectors. I've got mine from [here](https://www.amazon.co.uk/gp/product/B07LCN1VBM/ref=ppx_yo_dt_b_asin_title_o01_s01).

**Cables**  
You will need one Micro USB to USB A cable, can even be USB 2 as there isn't a lot of data going through.

**Tools**  
You will need a soldering gun, some cables to run the connections, solder, flux and some insulating tape, preferably some shrink wrap too.

# Assembly

First, let's solder the bits and bobs together. You will need to make 6 connections from the DB9 plug to the Arduino board according to the table below:
|Plug Pin|Arduino Pin|Function|
|---|---|---|
|Pin 1|Ground|GND|
|Pin 2|A2|Throttle|
|Pin 3|A1|Break|
|Pin 4|A0|Clutch|
|Pin 6|5V|VCC|
|Pin 9|5V|VCC|

The image below shows you which pin is which. Keep in mind this is taken from behind (the side the soldering takes place on).


![alt text](https://www.aggsoft.com/rs232-pinout-cable/images/9-pinout.gif)

# Code

You will need to download Arduino IDE or create an Arduino Create account. Once you've done that you'll need to import the Joystick library found [here](https://github.com/MHeironimus/ArduinoJoystickLibrary).
Finally, load the g923_pedals.ino into your editor, Verify & Save then upload.

# Calibration

Once you connect your device now, you should be able to see it as a joystick in the Gamepad Setup in Windows. Click on "Properties" then calibrate the axis shown.
|Axis|Function|
|---|---|
|Z Axis|Clutch|
|Throttle|Throttle|
|Brake|Brake|

# Use

After calibration, your games should recognize the controller. Obviously, you won't have the benefit of Logitech's automatic profile switch so you will need to configure the pedals by yourself in the game's settings.
