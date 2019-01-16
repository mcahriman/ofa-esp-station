#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <SampleCapability.hpp>
#include <CapabilityPool.hpp>

#include <Utils.hpp>
#include <map>

#include <functional>

const char *ssid = "columbus";
const char *password = "purpurpur42";
String page = "";

ESP8266WebServer server(8088);
String header;

CapabilityPool capabilityPool;

void setup()
{

  WiFi.mode(WIFI_STA),

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

  capabilityPool.addCapability(new SampleCapability);
  capabilityPool.addCapability(new SampleCapability("NonDefaultSampleCapability"));

  server.on("/", []() {

    std::list<pair<String,String>> result;
    result.push_back(make_pair("result", "OK"));
    
    page = utils_json_object(result);
    server.send(200, "application/json", page);
  });

  server.on("/capabilities", [] {
    std::list<pair<String,String>> result;
    String caps = utils_json_array(capabilityPool.getCapabilityList());
    result.push_back(make_pair("result", "OK"));
    result.push_back(make_pair("capabilities", caps));
    page = utils_json_object(result);
    server.send(200, "application/json", page);
  });
}

void loop()
{
  // put your main code here, to run repeatedly:
  server.handleClient();
}