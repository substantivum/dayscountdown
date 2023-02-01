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
            //out = in;
            int nd = in;// in["numberOfDays"];
            int ad = 1; //in["arrowDir"];
            Serial.print(" Number of days: ");
            Serial.print(nd);
            Serial.print(" Arrow direction: ");
            Serial.println(ad);
            
            NewCountdownRecieved(nd, ad);
            out = in;
            //out = "Success";
        }
    };

    Serial.print("Connecting to WiFi");
    thing.handle();
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
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