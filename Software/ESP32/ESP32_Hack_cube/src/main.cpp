#include <Arduino.h>

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(13,OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(13,HIGH);
//   delay(1000);
//   digitalWrite(13,LOW);
//   delay(1000);
// }

void appCpuLoop(void *pvParameters)
{
  for (;;)
  {
    Serial.println("appCpu");
    delay(1000);
  }
}
void setup()
{
  Serial.begin(9500);
  xTaskCreatePinnedToCore(appCpuLoop,     //具体实现的函数
                          "APP_CPU_LOOP", //任务名称
                          8192,           //堆栈大小
                          NULL,           //输入参数
                          1,              //任务优先级
                          NULL,           //
                          1               //核心  0\1
  );
}

void loop()
{
  Serial.println("main core");
  delay(1000);
}
