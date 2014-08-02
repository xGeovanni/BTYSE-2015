import uinput
import os

import errors
import powerInterface

# This file lays out which pin corresponds to which key on the keyboard,
# as layed out by the specification in "spec.txt".

# Each pin is wired to a button on the device. These buttons are to
# serve as the main method of controlling the device.

# Pins are herein referred to by their GPIO BCM identities.

errno = os.system("sudo modprobe -i uinput") #Load uinput kernel module.
	
if errno != 0:
	errors.loadModuleFail(errno)

KEYBOARD = uinput.Device([
	uinput.KEY_ENTER,
	uinput.KEY_BACKSPACE,
	uinput.KEY_ESC,
	uinput.KEY_UP,
	uinput.KEY_DOWN,
	uinput.KEY_LEFT,
	uinput.KEY_RIGHT,
	uinput.KEY_Z,
	uinput.KEY_X,
	uinput.KEY_A,
	uinput.KEY_S,
])

pinKey = {
	24 : uinput.KEY_ENTER,
	22 : uinput.KEY_BACKSPACE,
	27 : uinput.KEY_ESC,
	14 : uinput.KEY_UP,
	15 : uinput.KEY_DOWN,
	18 : uinput.KEY_LEFT,
	23 : uinput.KEY_RIGHT,
	2  : uinput.KEY_Z,
	3  : uinput.KEY_X,
	4  : uinput.KEY_A,
	17 : uinput.KEY_S,
}

pinFunc = { #Run functions when these input pins are active.
	8  : powerInterface.shutdown,
}
		  
		
	
