#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "peripherals.h"
#include "html_page.h"

WiFiServer server(80);
bool lamp_state = 0;
uint32_t button_timer = 0;
bool risen = 0;  // rising edge detection
bool event_detected = 0;

#define DEBOUNCE_DELAY 100

// // server functions

const char* ssid     = "MyWifi";
const char* password = "MyWifiPassword";

void setup() {
  setup_pins();
  digitalWrite(LAMPPIN, lamp_state);
  flash_led(GREENLEDPIN, 1, 500);
  
  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println(WiFi.macAddress());
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.hostname(HOSTNAME);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(350);
    flash_led(REDLEDPIN, 3, 50);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  flash_led(GREENLEDPIN, 1, 500);
}

void loop(){
  // wifi client handling
  WiFiClient client = server.accept();

  if (client){
    Serial.print("New Client: ");
    Serial.println(client.remoteIP().toString());
    String request = client.readStringUntil('\n');

    if (request.startsWith("GET /LIGHTOFF")){
      lamp_state = 0;
      digitalWrite(LAMPPIN, lamp_state);
      client.write(offPage);
      flash_led(GREENLEDPIN, 2, 50);
      Serial.println("Lamp turned off");
    } 
    else if (request.startsWith("GET /LIGHTON")){
      lamp_state = 1;
      digitalWrite(LAMPPIN, lamp_state);
      client.print(onPage);
      flash_led(GREENLEDPIN, 2, 50);
      Serial.println("Lamp turned on");
    }
    else if (request.startsWith("GET /")){
      if (lamp_state) client.write(onPage);
      else client.print(offPage);
      flash_led(GREENLEDPIN, 2, 50);
    }
    client.stop();
    Serial.println("Fuck this client");
  }

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    flash_led(REDLEDPIN, 3, 50);
  } 

  // button logic - detect pressed button for DEBOUNCE_DELAY milliseconds, then change state once
  bool button_pressed = !digitalRead(BUTTONPIN); // read button state (pull up)
  if (button_pressed && !risen){  // rising edge detection
    button_timer = millis();
    risen = 1;
  }

  if (button_pressed && (millis() - button_timer) > DEBOUNCE_DELAY && !event_detected){
    lamp_state = !lamp_state;
    digitalWrite(LAMPPIN, lamp_state);
    event_detected = 1;  // event detected flag
    if (lamp_state) Serial.println("Lamp turned on");
    else Serial.println("Lamp turned off");
  }

  if (!button_pressed) {
    risen = 0;  // reset risen
    event_detected = 0;  // reset event
  }

}