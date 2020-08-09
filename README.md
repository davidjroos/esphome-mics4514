# esphome-mics4514
Custom component for the MiCS-4514 sensor to work in esphome

Add the include to your esphome device yaml file:
```
esphome:
  includes:
    - mics4514.h
 ```
 
 Add the sensor configuration in your device yaml file:
 ```
 sensor:
   - platform: custom
     lambda: |-
       auto my_sensor = new MICS4514();
       App.register_component(my_sensor);
       return {my_sensor->no2_sensor, my_sensor->co_sensor};
     sensors:
     - name: "MICS4514 Nitrogen Dioxide Sensor"
       unit_of_measurement: ppb
       accuracy_decimals: 1
     - name: "MICS4514 Carbon Monoxide Sensor"
       unit_of_measurement: ppm
       accuracy_decimals: 1
 ```
