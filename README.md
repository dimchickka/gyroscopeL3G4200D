# gyroscopeL3G4200D
This repository contains a small embedded project for reading data from a gyroscope on an STM32 platform.
Alongside the sensor part, the project also includes the initial implementation of a driver for the W25Q32JV SPI NOR flash.

What’s inside
Gyroscope

Gyroscope is fully configured.

Data acquisition works reliably.

Reading loop and basic processing are already implemented.

W25Q32JV Flash (SPI)

Work on the flash driver has started.

Implemented:

JEDEC ID read over SPI (0x9F)

Microchip ID is correctly detected by the MCU.

Project status

This version of the project is frozen.

During development it became clear that a larger memory capacity is required, so further work continues in a separate repository that targets a bigger storage device.

✅ Gyroscope part — finished and stable

🧊 W25Q32JV flash branch — archived / no longer developed here

If you are looking for the active continuation of this project (with a new memory solution), please check the other repository.

Notes

This repo is kept for reference: wiring, basic SPI flash experiments, and a working gyroscope readout example.
