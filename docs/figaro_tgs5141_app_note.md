## Overview
The gas sensor TGS5141(Figaro Engineering) allows to detect Carbon monoxide(CO). By connecting the Pmod of this sensor and Renesas Quick-Connect Platform, you can see the sensor operation.
Refer to [QCIOT-FIGARO](https://www.renesas.com/us/en/products/sensor-products/environmental-sensors/humidity-temperature-sensors/qciot-figaro-figaro-sensor-pmod-boards-quickconnect-iot-platform#tools_support) for the detail of each sensor.

## Prerequisites
Users must have:

### Hardware
* EK-RA6M4
* US082-INTERPEVZ
* QCIoT-Figaro-TGS5141
* US159-DA14531EVZ(Option for BLE)
* US159-DA16200MEVZ(Option for WiFi/MQTT)

### Software
* FSP 5.3.0 platform installer bundle (e2_studio + FSP)

## Instructions
1. Import the reference projects on your e2studio.
2. Depending on whether your project uses BLE or WiFi, refer to the steps below.

    #### BLE Custom profile Documentation:
    [BLE Custom profile - Quick-Connect Sandbox](https://github.com/Renesas-Software-and-Digitalization/QCS_Silicon_Partners/blob/main/applications/sensordummy/ek_ra6m4_sensordummy_da14531_baremetal_custom_profile/README.md)

    #### MQTT using Adafruit cloud Documentation:
    [MQTT using Adafruit cloud](https://github.com/Renesas-Software-and-Digitalization/QCS_Silicon_Partners/blob/main/applications/sensordummy/ek_ra6m4_sensordummy_da16200_freertos_adafruit_cloud/README.md)
