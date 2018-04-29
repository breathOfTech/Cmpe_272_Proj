/************************
Author: Vera Wang
************************/
#include <ArduinoJson.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <SocketIoClient.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(D2, D3); //Rx, Tx

//Home IP: 192.168.1.130

ESP8266WiFiMulti WiFiMulti;
SocketIoClient webSocket;

int httpPort = 3000;
float temperature, humidity, voltage, current, power;
byte mac[6];
String mac_address;

void confirm(const char * payload, size_t length) {
    Serial.printf("got message: %s\n", payload);
}

void control(const char * payload, size_t length) {
    mySerial.println(payload); //send data to arduino   
}

void sendMessage() {
    
    StaticJsonBuffer<100> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["node_id"] = mac_address;
    root["temperature"] = temperature;
    root["humidity"] = humidity;
    root["voltage"] = voltage;
    root["current"] = current;
    root["var"] = power;
    char data[100];
    root.printTo(data);
    webSocket.emit("sensor_data", data); //send data to server
}


void readSerialMessage(){
  
    while(mySerial.read() != '+') {
      delay(500);
    }
    //read data into variables
    temperature = mySerial.parseFloat();
    humidity = mySerial.parseFloat();
    voltage = mySerial.parseFloat();
    current = mySerial.parseFloat();
    power = mySerial.parseFloat();
    Serial.println(temperature);
    Serial.println(humidity);
    Serial.println(voltage);
    Serial.println(current);
    Serial.println(power);
    delay(2000);
}

String mac2String(byte ar[])
{
  String s;
  for (byte i = 0; i < 6; ++i)
  {
    char buf[3];
    sprintf(buf, "%2X", ar[i]);
    s += buf;
    if (i < 5) s += ':';
  }
  return s;
}

void setup() {
    Serial.begin(115200);
    mySerial.begin(115200);
    Serial.setDebugOutput(true);

    //ssid, password
    if(WiFiMulti.addAP("AndroidAP", "luwo7299")){
      Serial.println("Wifi connected");
    }

    WiFi.macAddress(mac);
    Serial.println(WiFi.macAddress());
    mac_address = mac2String(mac);
    Serial.println(mac_address);

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.println("not connected");
        delay(1000);
    }
    
    webSocket.on("server_ack", confirm);
    webSocket.on("event_control", control);
    webSocket.begin("192.168.43.198", httpPort);
}

void loop() {

    if(mySerial.available() >= 6) {
        readSerialMessage(); //read data
        sendMessage(); //send data to server
    }
    delay(1000);
    
    webSocket.loop();
    
}
