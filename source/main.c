// Most common headers from C Standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main libnx system header
#include <switch.h>

//Main program entrypoint
int main(int argc, char* argv[])
{
	//This uses a text console
	consoleInit(NULL);
	
	// Other initialization
	printf("Hello World!\n");
	
	// Marin loop
	while (appletMainLoop())
	{
		// Scan all inputs. This should be done once for each frame
		hidScanInput();

		// hiskeysdown returns information about what buttons are being pressed
		// just pressed in this frame compared to the previous one
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		// i assume controller_p1_auto means automatically detect the controller for player 1

		if (kDown & KEY_PLUS)
			break; // break returns to hbmenu

		// The rest of the code would go here

		// Update the console, sending a new frame to the display
		consoleUpdate(NULL);
	}
	// Deinitialize and clean up reasources, this way it wont lag console (very important!!!!)
	consoleExit(NULL);
	return 0;
}