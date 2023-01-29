#define THINGER_SERIAL_DEBUG

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void ThingerSetupFunction () {
    WiFi.mode(WIFI_STA);
    while (WiFi.getMode() != WIFI_STA) {
        delay(50);
    }

    thing.add_wifi(SSID, SSID_PASSWORD);

    thing["data"] = [](pson& in, pson& out){
        if(!in.is_empty()) {
            numberOfDays = (int)in["numberOfDays"];
            arrowDir = (int)in["arrowDir"];

            Serial.print((float)in["numberOfDays"]);
            Serial.print(" Number of days: ");
            Serial.print(numberOfDays);
            Serial.print(" Arrow direction: ");
            Serial.println(arrowDir);
            
            UpdateDigits();

            out = "Success";
        }
    };
}

void ThingerLoopFunction () {
    thing.handle();
}

/* Example data
{
"arrowDir": 0,
"numberOfDays": 5
}
*/