#include <Arduino.h>

#define A_PIN 4
#define D_PIN 0

float iAnalogSig;
int iDigitalSig;

extern "C" void app_main() {
  initArduino();
  Serial.begin(115200);

  Serial.println("-----Hall Sensor 3144E-----");

  iAnalogSig = 0;
  iDigitalSig = 0;
  pinMode(D_PIN, INPUT);

  while(1) {
    iAnalogSig = (float)analogRead(A_PIN);
    iDigitalSig = digitalRead(D_PIN);

    Serial.println("Analog Voltage: " + (String)(3.3f * iAnalogSig/4096.0f) +
      " | Digital val: " + (String)iDigitalSig);
  
    delay(100);
  }
}
