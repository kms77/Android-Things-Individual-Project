# Android-Things-Individual-Project

# 1. Project Description

    This projects aims to implement an object detection mechanism using an ultrasonic sensor and LEDs. It is able to detect if an object is close or near the sensor, and also if there is no object at all. This type of project can be useful in a lot of everyday situations, for example assistive parking, where distance sensors are required in order to guide the parking of a car or for home automation, so that when a person reaches home they are detected.

    The present project uses an Ultrasonic Sensors, which captures the distance of objects, 3 red, yellow and green LEDs, used to signal the distance of the object. Moreover, it is also integrated with a voice controller app via a Bluetooth module, so that the user can turn on and off the application using voice commands.
	
	
# 2. Schematics

![Schematics of the project](https://github.com/kms77/Android-Things-Individual-Project/blob/main/Schematics_KomsaAttila_IndividualProject.png)
	
# 3. Pre-Requisites
	- Arduino UNO R3 Controller Board
		○ https://docs.arduino.cc/hardware/uno-rev3
	- Breadboard 830
		○ https://www.digikey.com/catalog/en/partgroup/full-size-breadboard-830-tie-points/68965
	- Red, Yellow and Green LEDs (3 pieces)
	- Bluetooth HC-05 Module
		○ https://www.rhydolabz.com/wireless-bluetooth-ble-c-130_132/hc05-bluetooth-module-masterslave-p-1169.html
	- 3 x Resistors 220 ohm
		○ https://protosupplies.com/product/resistor-220-ohm-5-14w25-pack/
	- Jumper Wires
    - Ultrasonic Sensor HC-SR04
        ○ https://www.sparkfun.com/products/15569
	- Voice recognition app on an Android phone (there are similar apps for iOS)
		○ https://play.google.com/store/apps/details?id=appinventor.ai_ashishmarch12.Bluetooth_Voice&hl=en
	- Arduino IDE
		○ https://www.arduino.cc/en/software
# 4. Setup and build
	1. Connect all components following the circuit diagram
	2. Open the Arduino Bluetooth Voice Control App and click on the Bluetooth icon to connect to the Bluetooth module (when connecting for the first time the smartphone will ask for a passcode - use 0000 or 1234)
# 5. Running
	After the setup the project can be run as following:
		1. In the voice recognition app tap the button "click to speak" (the microphone button)
		2. The following commands are available:

            | Command       | Action                                              |
            | ------------- | --------------------------------------------------- |
            | turn on       | Turn all LEDs on to signal the application is on    |
            | turn off	    | Turn all LEDs off to signal the application is off  |
        3. When the application is turned on after signalling the "turn on" command, the ultrasonic sensor will detect  the proximity of objects in the following ways:
            3.1. if an object is in the range 0 and 50 cm from the sensor, the application will print "Close to the object!" and
            the RED LED will turn on and the other two off, signaling that the object is close to the sensor
            3.2. if an object is in the range 50 and 100 cm from the sensor, the application will print "There is an object near!" and
            the YELLOW LED will turn on and the other two off, signaling that the object is near to the sensor, but not close enough
            3.3. if an object is at a distance greater than 100 cm from the sensor, the application will print "No object detected!" and
            the GREEN LED will turn on and the other two off, signaling that the object is not near enough to the sensor  

		4. When the application is turned off after signalling the "turn off" command, the ultrasonic sensor will stop detecting the proximity of objects, and will no longer print to the screen
# 6. Demo
