## Overview
This application project showcases BLE connectivity use case. In this application, the RA MCU kit
will act as BLE peripheral and user's cellphone/tablet will act as BLE Central.
In this application project, RA MCU device will read sensor data through I2C interface and publish
the sensor data through DA14531 BLE module.

## Tools
To use this repo users must have:

Software
* Python 3.10

#### Instructions For Running the Application
1. Import this project on e2 studio.
2. Generate the code and build it.
3. Start a debug section and run the code.
5. At this stage, the MCU kit will start BLE Advertising packet and the green LED will blink.
6. User can configure Segger RTT Viewer to view the project log.
7. Open the Quick-Connect Mobile Sandbox application on cellphone/tablet, scan for BLE device and connect to RA MCU Kit.
8. After connection to the BLE peripheral, user can check the sensor data published on the mobile application.

#### Troubleshooting
- Green LED not blinking:
    - Ensure proper connection of the Sensor interposer. The sticker should be positioned on the bottom side.
- Nothing is displaying on the Quick-Connect Mobile Sandbox:
    - Verify if your US159-DA14531EVZ is equipped with the latest DA14531-GTL-FSP firmware. (Refer to "US159-DA14531EVZ Firmware Upgrade" for instructions).

#### Instructions adding a new sensor module

1. Rename and modify the sensor_dummy folder to use your sensor driver.
2. Rename and modify the sensor application interface (sensor_dummy_sensor.c and sensor_dummy_sensor.h).
3. Generate the Quick-Connect Mobile Sandbox binary
    * Rename and modify the gui_cfg_sensor_dummy.json to fit your sensor variables.
    * Run the json2array.py to generate the binary:
        .\json2array.py .\src\gui_cfg_{your sensor name}.json .\src\gui_cfg.h
4. Modify the following files replacing the sensor dummy code where you find the comment:
```c
/*Start adding @{PLACEHOLDER} code */
/*end adding @{PLACEHOLDER} code */ 
```
Files to be modified:
* src/user.h
    * Placeholders:
        * @INCLUDES
        * @MACROS
        * @EXTERN_GLOBAL_VARIABLES
        * @FN_DECLARATION
* src/gui_cfg.h
    * Placeholders:
        * @EXTERN_GLOBAL_VARIABLES
* src/qe_gen/ble/app_main.c
    * Placeholders:
        * @INCLUDES
        * @FN_DECLARATION
        * @GLOBAL_VARIABLES
        * @MAIN_INITIALIZATION
        * @MAIN_LOOP
        * @FN_IMPLEMENTATION

## References
1. Apple Store Quick-Connect Mobile Sandbox: https://apps.apple.com/us/app/quick-connect-mobile-sandbox/id6448645028
2. Google Play Quick-Connect Mobile Sandbox: https://play.google.com/store/apps/details?id=com.renesas.sst.qcsandbox&pli=1
3. J-Link / J-Trace Downloads: https://www.segger.com/downloads/jlink/
4. US159-DA14531EVZ Firmware Upgrade: https://lpccs-docs.renesas.com/US159-DA14531EVZ_Firmware_Upgrade/index.html
5. Interposer Board for Pmod™ Type 2A/3A to 6A: https://www.renesas.com/us/en/products/microcontrollers-microprocessors/us082-interpevz-interposer-board-pmod-type-2a3a-6a-renesas-quick-connect-iot
