#ifndef web_h
#define web_h

#include "Arduino.h"
#include <WebServer.h>

class web
{
  public: 
    web();
    void atenderCliente();
    WebServer server;
    /*void handle_OnConnect();
    void handle_NotFound();
    void handle_saveWifi();
    void handlePostForm();*/
    String SendHTML(bool,bool);

  private:

    int wifi_status_pin;  
   
};

#endif 