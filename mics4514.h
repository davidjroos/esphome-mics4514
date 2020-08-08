#include "esphome.h"

#define DELAY_MS 30000 // Delay in miliseconds between readings

class MICS4514 : public PollingComponent {
 public:
  // constructor
  Sensor *no2_sensor = new Sensor();
  Sensor *co_sensor = new Sensor();
  
  MICS4514() : PollingComponent(DELAY_MS) {}

  void setup() override {
    // Setup preheater pin
    pinMode(D6, OUTPUT);

    // Wait for preheating
    digitalWrite(D6, 1);
    delay(10 * 1000);
    digitalWrite(D6, 0);
  }
  
  void update() override {
    // This will be called every "DELAY_MS" milliseconds.
    
    // Read analog values, print them out, and wait
    digitalWrite(D5, LOW);
    float vnox_value = ADCavg(A0);
    delay(10);
    digitalWrite(D5, HIGH);
    float vred_value = ADCavg(A0);
    
    no2_sensor->publish_state(vnox_value);
    co_sensor->publish_state(vred_value);
    
  }
  
  float ADCavg(int pin) {
    // get 10 measurements and average
    unsigned long acc = 0;
    for (int i = 0; i < 10; i++) {
      acc += analogRead(pin);
      delay(100);
    }
    return (int)(acc / 10);
  }
  
};
