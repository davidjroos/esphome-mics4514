#include "esphome.h"

#define DELAY_MS 15000 // Delay in miliseconds between readings
#define VNOX_PIN A0
#define VRED_PIN A0
#define PRE_PIN D6
#define MUX_PIN D5


class MICS4514 : public PollingComponent {
 public:
  // constructor
  Sensor *no2_sensor = new Sensor();
  Sensor *co_sensor = new Sensor();
  
  MICS4514() : PollingComponent(DELAY_MS) {}

  void setup() override {
    // Initilize multiplexer in
    pinMode(MUX_PIN, OUTPUT);
    
    // Setup preheater pin
    pinMode(PRE_PIN, OUTPUT);

    // Wait for preheating
    digitalWrite(PRE_PIN, 1);
    
    // Preheat for 1 second
    delay(10 * 1000);
    
    // Stop preheating
    digitalWrite(PRE_PIN, 0);
  }
  
  void update() override {
    // This will be called every "DELAY_MS" milliseconds.
    
    // Prepare multiplexer for NO2 reading
    digitalWrite(MUX_PIN, LOW);
    
    // Read analog value for NO2
    float vnox_value = ADCavg(VNOX_PIN);
    //float vnox_value = analogRead(VNOX_PIN);
    
    delay(10);
    
    // Prepare multiplexer for CO reading
    digitalWrite(MUX_PIN, HIGH);
    
    // Read analog value for CO
    float vred_value = ADCavg(VRED_PIN);
    //float vred_value = analogRead(VRED_PIN);
    
    // Publish readings
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
