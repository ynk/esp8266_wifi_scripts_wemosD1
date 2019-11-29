#include <TM1638.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
TM1638 module(4, 14, 12); // WEMOS D1 mini layout 

const char* ssid = "myWifi"; // SSID
const char* password = "myWifiPassword"; //Password
String api_url = "Enter your own api url here";

void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
delay(1500) 
}

void loop(){
 setDisplay(getFollwers("username_that_you_wanna_display"));
 delay(450000);
}

void setDisplay(String Number) {
  module.clearDisplay();
  module.setDisplayToString(Number);
}

String getFollwers(String Username)
{
  String follower_number = "";
  HTTPClient http; //Declare an object of class HTTPClient
  http.begin("http://"+ api_url + "/api/getFollwer?username=" + Username); //Specify request destination
  int httpCode = http.GET(); //send request
  if (httpCode > 0) { //return code check
    follower_number = http.getString(); //return what we are looking for
    
  }
  http.end(); //Close connection
  return follower_number;
}
