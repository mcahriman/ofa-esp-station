#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <functional>

#include <list>
#include <utility>

#include "util/Utils.hpp"


const char *ssid = "columbus";
const char *password = "purpurpur42";

String page = "";

ESP8266WebServer server(8088);
String header;

void setup()
{

  WiFi.mode(WIFI_STA);

  // Connect to Wi-Fi network with SSID and password
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Web server started!");

  server.on("/", []() {
    std::list<std::pair<String,String>> result;
    result.push_back(std::make_pair("result", "OK"));

    page = utils_json_object(result);
    server.send(200, "application/json", page);
  });
}

void loop()
{
  // put your main code here, to run repeatedly:
  server.handleClient();
}