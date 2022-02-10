#include <Arduino.h>
#include "LittleFS.h" // LittleFS is declared
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
  File file = LittleFS.open("/nihao.txt", "r");
  if(!file){
    Serial.println("Failed to open file for reading");
    return;
  }
  Serial.println("File Content:");
  while(file.available()){
    Serial.write(file.read());
  }
  Serial.println();
  file.close();


}
// #include <ESP8266WiFi.h>

// static WiFiClient espClient;
// #include <ArduinoJson.h>

// #include <AliyunIoTSDK.h>
// AliyunIoTSDK iot;

// #define PRODUCT_KEY "xxxxx"
// #define DEVICE_NAME "Device_D"
// #define DEVICE_SECRET "xxxxxxxxxxx"
// #define REGION_ID "cn-shanghai"

// #define WIFI_SSID "xxxxxx"
// #define WIFI_PASSWD "xxxxxxxx"


// void wifiInit(const char *ssid, const char *passphrase)
// {
//     WiFi.mode(WIFI_STA);
//     WiFi.begin(ssid, passphrase);
//     WiFi.setAutoConnect (true);
//     WiFi.setAutoReconnect (true);
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(1000);
//         Serial.println("WiFi not Connect");
//     }
//     Serial.println("Connected to AP");
// }
// void powerCallback(JsonVariant p);
// void setup()
// {
//     Serial.begin(115200);

//     wifiInit(WIFI_SSID, WIFI_PASSWD);

//     AliyunIoTSDK::begin(espClient, PRODUCT_KEY, DEVICE_NAME, DEVICE_SECRET, REGION_ID);

//     // 绑定属性回调
//     AliyunIoTSDK::bindData("PowerSwitch", powerCallback);
// }

// unsigned long lastMsMain = 0;
// void loop()
// {
//     AliyunIoTSDK::loop();
//     if (millis() - lastMsMain >= 5000)
//     {
//         lastMsMain = millis();
//         // 发送事件到阿里云平台
//         AliyunIoTSDK::sendEvent("xxx"); 
//         // 发送模型属性到阿里云平台
//         AliyunIoTSDK::send("CurrentTemperature", 30);
//     }
// }


// void powerCallback(JsonVariant p)
// {
//     int PowerSwitch = p["PowerSwitch"];
//     if (PowerSwitch == 1)
//     {
//         //
//     }
//     else
//     {
//         //
//     }
// }