# esphome-mics4514

Fermion MEMS Gas Sensor (MiCS-5524) by DFRobot ([SKU_SEN0440](https://wiki.dfrobot.com/Fermion__MEMS_Gas_Sensor___MiCS-5524_SKU_SEN0440))

Based on Sample code from DFRobot

MICS-5524 can get the concentration of:
 - Methane (CH4) at 1000 to 25000 PPM
 - Ethanol (C2H5OH) at 10 to 500 PPM
 - Hydrogen (H2) at 1 to 1000 PPM
 - Ammonia (NH3) at 1 to 500
 - Carbon Monoxide (CO) at 1 to 1000 PPM

Calcaultions based on:
Rs/RO aka (powerData[0] - redData) / __r0_red;





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
