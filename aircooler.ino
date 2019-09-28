#include <ESP8266WiFi.h>
#include "src/gree/devices.h"

#include "constants.h"

Devices devices;
void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }

    devices.listen();
    devices.scan();
}

void loop() {
  delay(1000);
}