#define THINGER_SERIAL_DEBUG

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void ThingerSetupFunction () {
    WiFi.mode(WIFI_STA);
    while (WiFi.getMode() != WIFI_STA) {
        delay(50);
    }

    thing.add_wifi(SSID, SSID_PASSWORD);

    thing["dateIn"] = [](pson& in, pson& out){
        if(!in.is_empty()) {
            int nd = (int) in["date"];
            int ad = (int) in["arrow"];

            out["status"] = "Success";
            out["inDate"] = nd; // Send back recieved data
            out["inArrow"] = ad;
            
            NewCountdownRecieved(nd, ad);
        } else {
          out["status"] = "Error";
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
    "date": 16,
    "arrow": 1
} 
*/