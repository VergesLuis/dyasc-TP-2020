#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h> // nos permite hacer peticiones http
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// credenciales de la red a la cual nos conectaremos
    /*const char* ssid = "MaxiS7";
    const char* password =  "fswn6522";*/
const char* ssid = "WIFI-Arnet-nf4d";
const char* password =  "UFYMAUAWKF";

// Url's para hacer las peticiones
const char* URL = "https://api.travis-ci.org/MaxiBis/test_build_status.svg?branch=master";
//const char* URL = "https://api.travis-ci.org/MaxiBis/aydoo-2018.svg?branch=master";

String answer;  //to save http answer

// ledPin refers to ESP32 GPIO 23
const int GreenLed = 2;
const int YellowLed = 22;
const int RedLed = 01;

const int requestInterval = 7000;  // 7s

void setup(){
    Serial.begin(115200);
    // initialize digital pin ledPin as an output and set them as low
    pinMode(GreenLed, OUTPUT);
    pinMode(YellowLed, OUTPUT);
    pinMode(RedLed, OUTPUT);
    digitalWrite(GreenLed, LOW);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, LOW);


    // nos conectamos a la red
    WiFi.begin(ssid, password);
    Serial.println("connecting");
    while(WiFi.status() != WL_CONNECTED) { 
        delay(500);
        Serial.print(".");
    }
    Serial.print("\nConectado a la red con la IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
    
} // EOF setup

String getRequest(const char* serverName) {
  HTTPClient http;    
  http.begin(serverName);
  
  // Enviamos peticion HTTP
  int httpResponseCode = http.GET();
  
  String payload = "..."; 
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // liberamos
  http.end();

  return payload;
}

void loop(){
    if(WiFi.status()== WL_CONNECTED ){ 
      answer = getRequest(URL);
      //Serial.println(answer); //imprimo respuesta
      
      if (answer.indexOf("failing") > 0) {
        Serial.println("FAILING\n");
        digitalWrite(GreenLed, LOW);
        digitalWrite(YellowLed, LOW);
        digitalWrite(RedLed, HIGH);
      } 
      if (answer.indexOf("canceled") > 0) {
        Serial.println("CANCELED\n");
        digitalWrite(GreenLed, LOW);
        digitalWrite(YellowLed, HIGH);
        digitalWrite(RedLed, LOW);
      } 
      if (answer.indexOf("passing") > 0) {
        Serial.println("PASSING\n");
        digitalWrite(GreenLed, HIGH);
        digitalWrite(YellowLed, LOW);
        digitalWrite(RedLed, LOW);
      } 
      
      delay(requestInterval); //delay entre requests
    }

    /*while(true){
        // bucle infinito
    }*/
} // EOF Loop

