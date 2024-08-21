## Overview
The gas sensor FECS43(Figaro Engineering) allows to detect sulfur dioxide(SO2). By connecting the Pmod of this sensor and Renesas Quick-Connect Platform, you can see the sensor operation.
Refer to [QCIOT-FIGARO](https://www.renesas.com/us/en/products/sensor-products/environmental-sensors/humidity-temperature-sensors/qciot-figaro-figaro-sensor-pmod-boards-quickconnect-iot-platform#tools_support) for the detail of each sensor.

## Prerequisites
To use this repo users must have:

### Hardware
* EK-RA6M4
* US082-INTERPEVZ
* QCIoT-Figaro-FECS43-20
* US159-DA14531EVZ(In case of BLE)
* US159-DA16200MEVZ(In case of WiFi)

### Software
* FSP 5.3.0 platform installer bundle (e2_studio + FSP)

## Instructions
1. Import the reference projects on your e2studio.
2. Depending on whether your project uses BLE or WiFi, refer to the steps below.

    #### BLE Custom profile Documentation:
    [BLE Custom profile - Quick-Connect Sandbox](applications/sensordummy/ek_ra6m4_sensordummy_da14531_baremetal_custom_profile/README.md)

    #### MQTT using Adafruit cloud Documentation:
    [MQTT using Adafruit cloud](applications/sensordummy/ek_ra6m4_sensordummy_da16200_freertos_adafruit_cloud/README.md)

## Validation
* Specify the hardware components necessary for testing and validation. 
* Include step-by-step instructions for executing tests.
* Clearly state the performance metrics that will be used to evaluate the module.
* Specify acceptable thresholds for each metric.
* Define criteria that indicate successful validation of the module.
