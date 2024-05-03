## Overview
The objective of this repo is to provide some reference applications where partner can add its sensor modules to the current QC Studio enviroment.

## Tools
To use this repo users must have:

Hardware
* EK-RA6M4
* US082-INTERPEVZ
* US159-DA14531EVZ
* US159-DA16200MEVZ

Software
* FSP 5.3.0 platform installer bundle (e2_studio + FSP)

### Instructions For contribuiting
1. Import the projects on the e2 Studio (FSP 5.3.0 platform).

[Project Importing guide](https://en-support.renesas.com/knowledgeBase/21062045#:~:text=To%20start%20the%20Import%20Wizard,.%22%20in%20the%20context%20menu.)

2. Each project will guide you about which portion should be adapted to the new sensor

#### BLE Custom profile Documentation:
[BLE Custom profile - Quick-Connect Sandbox](ek_ra6m4_sensordummy_da14531_baremetal_custom_profile/README.md)

#### MQTT using Adafruit cloud Documentation:
[MQTT using Adafruit cloud](ek_ra6m4_sensordummy_da16200_freertos_adafruit_cloud/README.md)

<!-- CONTRIBUTING -->
## Contributing

1. Fork the Project
2. Import the projects on your e2studio using the `Rename and import Exisiting C/C++ Project into Workspace`.
    * module name: sensor1
        * ek_ra6m4_sensor1_da14531_baremetal_custom_profile
        * ek_ra6m4_sensor1_da16200_freertos_adafruit_cloud
2. Create your Feature Branch (`git checkout -b feature/new_module`)
3. Add your new module after testing it on the reference applications
3. Commit your Changes (`git commit -m 'Add a new_module'`)
4. Push to the Branch (`git push origin feature/new_module`)
5. After test them, send the link of your github to Renesas team

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## References
1. EK-RA6M4: https://www.renesas.com/us/en/products/microcontrollers-microprocessors/ra-cortex-m-mcus/ek-ra6m4-evaluation-kit-ra6m4-mcu-group
2. US159-DA14531EVZ: https://www.renesas.com/us/en/products/wireless-connectivity/bluetooth-low-energy/us159-da14531evz-low-power-bluetooth-pmod-board-renesas-quick-connect-iot
3. US159-DA16200MEVZ: https://www.renesas.com/us/en/products/wireless-connectivity/wi-fi/low-power-wi-fi/us159-da16200mevz-ultra-low-power-wi-fi-pmod-board-renesas-quick-connect-iot
4. FSP 5.3.0 platform installer (setup_fsp_v5_3_0_e2s_v2024-04): https://github.com/renesas/fsp/releases/tag/v5.3.0
5. Interposer Board for Pmod™ Type 2A/3A to 6A (US082-INTERPEVZ): https://www.renesas.com/us/en/products/microcontrollers-microprocessors/us082-interpevz-interposer-board-pmod-type-2a3a-6a-renesas-quick-connect-iot
