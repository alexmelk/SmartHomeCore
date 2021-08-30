#include <Arduino.h>

//for temp sensor
//core by alexmelk
#include <SmartHomeCore.h>
using namespace shCore;

int tempPin = 4;
//OneWire oneWire(tempPin);
//DallasTemperature sensors(&oneWire);

void getTemperature() {
	//sensors.requestTemperatures();
	//String temp = String(sensors.getTempCByIndex(0));
	//Serial.println(temp);
	sendToServer(200, "text/html", "10");
	blink(1, 100);
}

void setup(void) {
	setSSIDwifiAP("WiFi Toggle");
	registrateEvent("/getTemperature",getTemperature);
	
	coreInit();
}

void loop(void) {
	coreHandle();
	delay(1);
}
