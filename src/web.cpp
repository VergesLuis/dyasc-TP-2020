#include <Web.h>
#include <WebServer.h>
#include <string.h>

WebServer server(80);
String notice,webPage ;

String SendHTML(uint8_t led1stat,uint8_t led2stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  /*ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +=".button-save {background-color: #34495e;}\n";
  ptr +=".button-save:active {background-color: #2c3e50;}\n";  
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
    ptr +="<h3>Using Station(STA) Mode</h3>\n";
  
   if(led1stat)
  {ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";}
  else
  {ptr +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";}

  //ptr += "SSID: <input type=\"text\">";

  ptr += "<form>";
  ptr += "<label for=\"SSID\">SSID:</label>";
  ptr += "<input type=\"text\" value=\"Please enter SSID\" id=\"SSID\" >";
  ptr += "<label for=\"pwd\">Password:</label>";
  ptr += "<input type=\"password\" id=\"pwd\" >";
  ptr += "</form>";
  ptr += "<a class=\"button button-save\" href=\"/saveWifi\">SAVE</a>";
  
  ptr += "<FORM METHOD=\"POST\"action=\"/postForm\">";
  ptr += "<input type=\"text\" name=\"myText\" value=\"Write your Notice...\">";
  ptr += "<label for=\"pwd\">Password:</label>";
  ptr += "<input type=\"password\" id=\"pwd\" name=\"pw\">";
  ptr += "<input type=\"submit\" value=\"Post Notice\">";
  ptr += "</form>";


  ptr +="</body>\n";
  ptr +="</html>\n";*/
  return ptr;
}

void handle_OnConnect() {
  Serial.println("GPIO4 Status: OFF | GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(true,true)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
void handle_saveWifi(){
  Serial.println("test");
  server.send(404, "text/plain", "Not found");
}

void handlePostForm()
{
  //webPage = SendHTML;
  notice = server.arg("myText");
  String passwordNueva = server.arg("pw");
  Serial.println("Text received. Contents: ");
  Serial.println(notice);
  Serial.println(passwordNueva);
}

web::web(){
  server.on("/",handle_OnConnect);
  server.on("/postForm", handlePostForm);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void web::atenderCliente() {
  server.handleClient();
  return;
}

