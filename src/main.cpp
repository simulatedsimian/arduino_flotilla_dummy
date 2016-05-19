#include "Arduino.h"
#include "dock.h"
#include "moduletouch.h"
#include "modulerainbow.h"

Dock dock;
ModuleTouch modTouch;
ModuleRainbow modRainbow;

void setup() {
	Serial.begin(115200);

	modTouch.Init(1);
	modRainbow.Init(2);

	dock.AddModule(&modTouch);
	dock.AddModule(&modRainbow);
}

void loop() {
	if (Serial) {
		dock.Update(&Serial);
		dock.ProcessInput(&Serial);
	}
	delay(100);
}
