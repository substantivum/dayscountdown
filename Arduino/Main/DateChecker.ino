#include <Arduino_JSON.h>
#include <HTTPClient.h>

unsigned long long dateTimer = millis();
unsigned long long dateTimerDelay = 3.6 * pow(10, 6);
bool HasDateChanged() {
  if ((millis() - dateTimer) > dateTimerDelay) {
    Serial.println("Getting current day!");
    int day = GetCurrentDay();
    
    if (day > -1 && day != currentDay) {
      currentDay = day;
      Serial.print("Day changed: ");
      Serial.println(day);
      return true;
    }

    Serial.println("Not a new day!");
    dateTimer = millis();
  }

  return false;
}

int GetCurrentDay() {
  // Returns the current day, if it cant returns -1
  const char* apiURL = "http://worldtimeapi.org/api/timezone/Europe/Stockholm";

  if (WiFi.status() == WL_CONNECTED) {//(thing.is_connected()) {
      //Client _client = thing.get_client();
      String request = HttpGETRequest(apiURL);

      JSONVar jsonRequest = JSON.parse(request);

      if (JSON.typeof(jsonRequest) == "undefined") {
        Serial.println("Parsing input failed!");
        return -1;
      }

      Serial.print("Retrieved day of the month: ");
      Serial.println(jsonRequest["day_of_year"]);

      return jsonRequest["day_of_year"];
    } else {
      Serial.println("WiFi Disconnected");
      return -1;
    }
}

String HttpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // If you need Node-RED/server authentication, insert user and password below
  //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}