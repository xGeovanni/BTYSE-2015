# This is a python script which reads the input from the Raspberry Pi
# pins, and translates those in to keyboard inputs which the emulators
# used in this project understand.

# Running run.sh will begin to run this script in the background, with
# input sent to pinReader.out

import errors

try:
	import RPi.GPIO as GPIO
except RuntimeError:
	errors.notOnRPi()
	
import pinKey
import powerInterface

import os
import uinput
	
def init():
	GPIO.setmode(GPIO.BCM) #Set to refer to pins by GPIO BCM identity.
	
	#Set the pins to input.
	
	for pin in pinKey.pinKey.keys(): #Could have planned that better.
		GPIO.setup(pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
	for pin in pinKey.pinFunc.keys():
		GPIO.setup(pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
		
	GPIO.setup(25, GPIO.OUT)

def main():
	init();
	
	powerInterface.startup()
	
	running = True
	
	while running:
		for pin in pinKey.pinKey.keys():
			if GPIO.input(pin):
				pinKey.KEYBOARD.emit_click(pinKey.pinKey[pin])
				
				#Send the signal that the key which corresponds to the
				#pin has been pressed.
				
		for pin in pinKey.pinFunc.keys():
			if GPIO.input(pin):
				pinKey.pinFunc[pin]()
				
				#Run the function which corresponds to the pin.
