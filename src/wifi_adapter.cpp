#include "wifi_adapter.h"
#include <WiFi.h>
#include "Arduino.h"
const char* ssid;
const char* password;

wifi_adapter::wifi_adapter(int pin){
    pinMode(pin, OUTPUT);
    wifi_status_pin = pin;
    ssid = "WiFi-Arnet-nf4d";         //default credentials
    password =  "UFYMAUAWKF";     //default credentials
}


void wifi_adapter::conectarme(){
    WiFi.begin(ssid, password);
    Serial.println("connecting");
    bool estado_led = true;
    while(WiFi.status() != WL_CONNECTED) { 
        delay(500);
        Serial.print(".");
        if (estado_led){
            digitalWrite(wifi_status_pin, LOW);
            estado_led = false;
        } else{
            digitalWrite(wifi_status_pin, HIGH);
            estado_led = true;
        }              
    }
    digitalWrite(wifi_status_pin, HIGH);
    Serial.print("\nConectado a la red con la IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    return;
}

bool wifi_adapter::isConnected(){
    return WL_CONNECTED;
}

void wifi_adapter::setWifiCredentials(const char* new_SSID,const char* new_password){
    ssid = new_SSID;         
    password = new_password; 
}