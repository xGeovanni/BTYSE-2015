import time

def getTime():
	return time.strftime("%H:%M:%S  %d/%m/%Y");

def loadModuleFail(errno):
	text = ("Error: Could not load uinput module. Failed with return" +
		    "code " + errno + ". Make sure you are" 			      +
		    "using a GNU/Linux system. Ensure you have" 		  	  + 
		    "module-init-tools installed if using kernel 2.6"  		  +
		    "or later, or have modutils installed if using "   		  +
	   	    "Kernel version 2.2 or 2.4. These should usually"  		  +
		    "be preinstalled.")
	
	print(getTime() + ": " + text)
	
	raise OSError(text)
				  
def notOnRPi():
	text = ("Error: This script must be run on a Raspberry Pi "  	  +
		    "(or you could find some way to fake it.)")
	
	print(getTime() + ": " + text)
	
	raise RuntimeError(text)
	
def notRoot():
	text = ("Error: This script must be run as root." +
			"(Use the sudo command)")
			
	print(getTime() + ": " + text)
	
	raise OSError(text)
