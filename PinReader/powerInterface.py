import os

try:
	import RPi.GPIO as GPIO
except RuntimeError:
	notOnRPi()

def onExit():
	GPIO.cleanup()

from errors import getTime

def startup():
	print("Startup at " + getTime())

def shutdown():
	print("Shutdown at " + getTime())
	onExit()
	os.system("./shutdown.sh")

def onExit():
	GPIO.cleanup()
	
def getTime():
	return time.strftime("%H:%M:%S  %d/%m/%Y");
