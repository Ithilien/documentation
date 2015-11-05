# Intel Edison RCA IoT Tech Intro

This repo contains all the instruction and needed code for the RCA IoT Tech Intro. It was forked from IntelEdisonDemoDay from a Hackday Event that took place in November 2014.

## Repository contents

  * Arduino
   - EdisonIntroExamples - All the examples used in this intro
   - Libraries - Some libraries used in the examples that are not included in the default install of the Arduino IDE
  * README.md - This guide

## Order of the day

##### Day1
 * 11:00 Introductions for "Lab TAs"
 * 11:05 Introduction to Intel Edison presentation
 * 11:15 Starting with Intel Edison
  - Installing Intel Edison environment and tools
  - The blink example
  - Hooking up sensors
  - Controlling a servo
  - Using the LCD
 * 13:15 Lunch break
 * 14:15 Getting the "I" in IoT going
  - Downloading a web page
  - Being a web server
  - Publishing sensor data to the Internet
 * ??:?? Done for the day

## Getting set up

> <strong>Note:</strong> Read through the entire step before following its instructions; there might be some important details later on for how to perform that step!

 1. If you don't already have the Arduino IDE installed (version 1.6.1 or greater), go to https://www.arduino.cc/en/Main/Software and install the latest version.
 1. Open the Arduino IDE and check the boards list (Tools -> Board: ...) to be sure Intel Edison is on the list.  If not, open the Boards Manager (Tools -> Board: ... -> Boards Manager...) and find the Intel i686 Boards on the list, select it and hit Install.
 1. Below is a link to set up your Edison board. Follow along Step 1 and select your OS in Step 2.  However, do NOT download the installer. The installer linked on this step contains several tools (such as a firmware flasher) that you don't need for this tutorial, the Arduino IDE is plenty good.  If you want to get these extra tools, feel free to download this installer later.  Move on to Step 3, which is the last step from the instructions page you need to follow.
    
    https://software.intel.com/en-us/iot/library/edison-getting-started
     
 1. Download the files from this page by clicking the "Download ZIP" to the right of these instructions.  Once it's downloaded, unzip it (it doesn't matter where to, but somewhere you can find it again - for example, to your Desktop)
 1. In the Arduino IDE, open File -> Preferences.  Make a note of the sketchbook location (it's most likely to be an Arduino folder in your home directory).
 1. Copy the entire EdisonIntroExamples folder (from the zip file you unpacked in step 1) into the sketchbook location on your machine.
 1. Install the libraries from the Libraries folder (from the zip file you unpacked in step 1) by going to Sketch -> Include Library -> Add ZIP Library and selecting one of the zip files from the Libraries folder. Do this for each zip file.
 1. Be sure you have the Intel Edison board selected (Tools -> Board: Intel Edison). If not, select the Edison board from the list.  Be sure to also select the correct port for your Edison board (Tools -> Port).
 1. Restart the Arduino IDE so it applies all the changes.  Once done you will have a new set of sketches available in the File -> Sketchbook menu, called EdisonIntroExamples, and all the needed libraries and board configuration should be available.
 1. Open up your Grove Starter Kit Plus.  This has a number of basic input and output electronics, which can easily be hooked up to your Edison via the supplied ribbon cables (the black/red/white/yellow wires) and the Grove shield.
 1. The shield is the circuit board with a grid of white connectors hiding under the LCD display.  Take it out and carefully but firmly push it onto the black headers on your Edison breakout board.  It will only fit one way round, so check you've got everything lined up before forcing it.
 
## The blink example
 
 1. Find the LED socket board, an LED, and a ribbon cable from your Grove kit.  Place the LED into the socket on the board (the longer leg of the LED goes into the hole marked +) and connect it with a ribbon cable to one of the sockets on the shield labelled with a D.  For example, D3.
    The sockets labelled with D are for digital inputs and outputs - things that are either on or off.  Those labelled with A are for analogue inputs - things that can vary.  We'll come to the analogue inputs shortly.
 1. To have the LED you just wired up do anything you need to tell your code to use it.  Open the code for the Blink example in the Arduino IDE (File -> Sketchbook -> EdisonIntroExamples -> 01. Blink -> Blink). Find the following line in the example code:
 
 ```
 const int led = 13;
 ```
 
    Replace the `13` with the number of the D socket in which you plugged in the LED. For example, if you plugged the LED into socket D3, replace the `13` with `3`.
 1. Upload your modified code to your Edison and the LED should start blinking.

> <strong>Extra credit:</strong> Try modifying the values in the `delay` calls to vary how quickly the LED blinks.

## Hooking up sensors

 1. Now let's look at some inputs.  The Grove kit has a few different ones - the button and touch sensor are digital inputs, which can only be on or off.  We're going to look at the rotary angle, temperature and light sensors.  These turn what they measure into a voltage that varies between 0 and 5 volts.  The analogue input sockets (and associated analogRead code) let you read these values on your Edison.  Find the rotary angle sensor and a ribbon cable.
 1. Connect it up to the A0 socket
 1. Open the Sensor example in the Arduino IDE (File -> Sketchbook -> EdisonIntroExamples -> 02. Sensor -> Sensor).
 1. As you'll see in the `loop` function, this uses `analogRead` to read in the value of the sensor and then prints it out to the serial port.  The values will range from 0 to 1023, with 0 corresponding to 0V and 1023 to 5V.  Upload the sketch to your Edison.
 1. Now open the serial monitor in the Arduino IDE - the little magnifying glass icon in the top right corner.  This will open a new window and start printing out a stream of numbers as the Edison takes readings and reports them.
 1. Twisting the control on the rotary angle sensor (or potentiometer, as they're known in electronics circles) and you'll see the value changing.

> <strong>Extra credit:</strong> Try plugging in the other sensors and see what range of numbers they report.

## Controlling a servo

 1. Here we'll bring together both input and output in a single example.  Find the servo in your Grove kit.  It's a small black box with a ribbon cable attached.
 1. Find the small bag of servo horns - white disc and rods.  Choose one and attach it to the servo.
 1. Connect the servo to the socket D3 (Leave the rotary angle sensor connected to A0 from the previous section).
 1. Because the servo draws a bit more current than the LED we've used so far, we need to provide some extra power to the Edison board.  Plug in an external power supply to the black barrel jack in the corner of the board.
 1. Open the Servo sketch (File -> Sketchbook -> EdisonIntroExamples -> 03. Servo -> Servo).
 1. Upload it to your Edison.
 1. Use the control on the rotary angle sensor to move the servo position.

> <strong>Extra credit:</strong> Using the range of values you could see when hooking up different sensors in the previous exercise, rework the `map` line in the sketch to give the full range of movement of the servo when using a different sensor.

## Using the LCD

 1. The LCD will let us display two lines of 16 characters.  It communicates with the Edison board via the [I2C protocol](http://en.wikipedia.org/wiki/I%C2%B2C).  Connect the LCD board up to one of the I2C sockets with a ribbon cable.
 1. Communicating with the LCD has been abstracted into the rgb_lcd library, so you don't need to worry about using the I2C protocol directly (although that would just need you to read through the datasheet for the LCD to work out what commands to send it).  Open the LCD sketch.  File -> Sketchbook -> EdisonIntroExamples -> 04. LCD -> LCD.
 1. The sketch uses the `system`, `fopen`, `fgets` and `fclose` to access the time from the Linux side of the Edison, and then displays it on the LCD.  Upload the sketch to your Edison and you'll have a rather over-engineered electronic clock.
    Note that if the time displayed is not correct, you can open a serial terminal connection to your Edison and type `rdate wwv.nist.gov` (Note the wwv is not a typo!)
 
> <strong>Extra credit:</strong> Modify the sketch so that the screen backlight turns green when it's lunchtime or hometime.

## Downloading a web page

 1. Open the WebClient sketch (File -> Sketchbook -> EdisonIntroExamples -> 05. WebClient-> WebClient).
 1. We need to tell it the details of the WiFi network we want to connect to.  Find the lines
 
 ```
 char ssid[] = "yourNetwork";      //  your network SSID (name) 
 char pass[] = "secretPassword";   // your network password
 ```

    And change them to match the network and password for the venue's WiFi.
 1. Upload the sketch to your Edison, then open the serial monitor.
 1. You'll see it print out its progress as it connects to the WiFi, and then connecting to the server and displaying the response that it receives.

> <strong>Extra credit:</strong> Read through the response that you get from www.google.com and modify the sketch so that it makes the request to the alternate URL that Google tries to redirect you to.

## Being a web server

 1. Open the WebServer sketch (File -> Sketchbook -> EdisonIntroExamples -> 06. WebServer -> WebServer).
 1. Connect the light sensor to socket A0.
 1. Connect the temperature sensor to socket A1.
 1. Find the `ssid` and `pass` lines in the sketch, and update them to the relevant WiFi network.
 1. Upload the sketch to your Edison, then open the serial monitor.
 1. Once connected to the WiFi, your Edison will print out the URL you can use to connect to it.  Copy that into the address bar on your browser and it show a page with details of the light level and temperature.
 1. Vary the amount of light hitting the sensor and you will see both the light level value and the background colour of the web page change.

> <strong>Note:</strong> The Edison board already has a web server running on it, which is why your web server URL ends in ":8080".  That tells your browser to look for the web server on port 8080 rather than the default port 80.  If you try removing the ":8080" you'll see the Edison's default web server page.

## Publishing sensor data to the Internet

 1. Intel have a service called IoTKit which lets you store and graph simple sensor data.  Go to the [IoTKit website](https://dashboard.us.enableiot.com/) and create an account so that you can use it.
 1. Next we need to run a few commands on your Edison through its console to set up the IoTKit agent.  Connect up the second micro-USB cable to your Edison and run `PuTTY` or `screen` like you did in step 3 of the initial installation instructions to connect to your Edison's console.
 1. Run `iotkit-admin test` to check that the Edison connectivity is okay.  You shouldn't see any errors output.
 1. Get the Device ID for your Edison by running `iotkit-admin device-id`.
 1. Click on your account name (next to "IoT Analytics" in the bar across the top) and click the eye icon to show your Activation Code.
 1. Back in the Edison console, type `iotkit-admin activate <activation code>`, replacing `<activation code>` with the code from your IoTKit account.
 1. Now you're ready to start pushing data to IoTKit, so start the IoTKit agent by typing `systemctl start iotkit-agent`.
 1. Open the IoTAnalytics example (File -> Sketchbook -> EdisonIntroExamples -> 07. IoTAnalytics -> IoTAnalytics).
 1. Find the `ssid` and `pass` lines in the sketch, and update them to the relevant WiFi network.
 1. Connect the temperature sensor to socket A0.
 1. Upload the sketch to your Edison.
 1. On your IoTKit Dashboard in your web browser (click the "IoT Analytics" link to get back to it if need be) you should see the "Last hour observations" counter go up as the readings are pushed up to the cloud.
 1. If you click the "burger menu" in the top left corner of the dashboard, and choose "Charts" you will then be able to select your device and the temperature component and graph the data being recorded.

# Links

 * [Arduino language reference](http://arduino.cc/en/Reference/HomePage)
 * [The Grove Starter Kit Plus](http://www.seeedstudio.com/wiki/Grove_-_Starter_Kit_V2.0) website, and [the official location for the example code](https://github.com/Seeed-Studio/Sketchbook_Starter_Kit_V2.0)
 * [Edison Arduino expansion board hardware guide](https://communities.intel.com/docs/DOC-23161) - includes details of the jumper settings, pin-out diagram, etc. for the expansion board
 * [Intel IoTKit sample code](https://github.com/enableiot/iotkit-samples)
 * [Intel IoT Developer Zone](https://software.intel.com/en-us/iot)
 * [Edison community forum](https://communities.intel.com/community/makers/edison)

And if you want to skip the Arduino IDE and play around with Node.js or Python and the Edison then these links might help

 * [mraa](https://github.com/intel-iot-devkit/mraa) is the low-level API to access the GPIO pins, etc. from languages like Node.js
 * [upm](https://github.com/intel-iot-devkit/upm) sits on top of mraa and provides a set of libraries for common sensors, IO chips, etc.
 * [Getting started with Intel DevKit and XDK](https://software.intel.com/en-us/html5/documentation/getting-started-with-intel-xdk-iot-edition) - if you want to try out the Intel XDK development environment


