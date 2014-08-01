import uinput

# This file lays out which pin corresponds to which key on the keyboard,
# as layed out by the specification in "spec.txt",and also at 
# http://pastebin.com/9SQV5V8k

# Each pin is wired to a button on the device. These buttons are to
# serve as the main method of controlling the device.

# Pins are herein reffered to by their GPIO identities.

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
		  15 :uinput.KEY_DOWN,
		  18 : uinput.KEY_LEFT,
		  23 : uinput.KEY_RIGHT,
		   2 : uinput.KEY_Z,
		   3 : uinput.KEY_X,
		   4 : uinput.KEY_A,
		  17 : uinput.KEY_S,
		 }
		  
		
	
