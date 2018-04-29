
/************************
Author: Vera Wang
************************/
#include <dht.h>
#include "EmonLib.h"          
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

EnergyMonitor emon1;  
dht DHT;

#define DHT11_PIN 7
#define ENABLE 5 //motor enable
#define DIRA 6
#define DIRB 4

void sendToWifi(){

    if(DHT.temperature != -999.00){
        mySerial.println('+'); //send initial char
        mySerial.println(DHT.temperature); //send data
        mySerial.println(DHT.humidity);
        mySerial.println(emon1.Vrms); //send voltage
        mySerial.println(emon1.Irms); //send current
        mySerial.println(emon1.apparentPower); //send apparent power
    }
    delay(1000);
}

void readSerialMessage(){
    while(mySerial.available() == 0){
        delay(500);
    }
    bool control = mySerial.read();
    if(control == 1)
      turnOnFan();
    else
      turnOffFan();
}

void turnOnFan(){
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA,LOW); //one way
    digitalWrite(DIRB,HIGH);
}

void turnOffFan(){
    digitalWrite(ENABLE, LOW);
}
 
void setup() {
  //---set pin direction
    pinMode(ENABLE,OUTPUT);
    pinMode(DIRA,OUTPUT);
    pinMode(DIRB,OUTPUT);
    
    Serial.begin(9600);
    mySerial.begin(115200);
    
    emon1.voltage(9, 234.26, 1.7);  // Voltage: input pin 9, calibration, phase_shift
    emon1.current(8, 111.1);       // Current: input pin 8, calibration.
}

void loop() {

    int chk = DHT.read11(DHT11_PIN);
    emon1.calcVI(20,2000);         // Calculate power
    
    float apparentPower   = emon1.apparentPower;  
    float supplyVoltage   = emon1.Vrms;             //extract Vrms into Variable
    float Irms            = emon1.Irms;             //extract Irms into Variable

    delay(2000);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity); 

    
    while(DHT.humidity >= 60 || DHT.temperature >= 28){
      
        turnOnFan();
        delay(10000);
        
        chk = DHT.read11(DHT11_PIN); 
        sendToWifi();    
    }
    turnOffFan(); // disable fan

    sendToWifi(); // send data every 30 seconds

    if(mySerial.available() > 0){
        readSerialMessage();
    }

    delay(30000);

}
   
