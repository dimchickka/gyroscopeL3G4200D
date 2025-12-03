# gyroscopeL3G4200D
This repository contains a small embedded project for reading data from a gyroscope on an STM32 platform.
Alongside the sensor part, the project also includes the initial implementation of a driver for the W25Q32JV SPI NOR flash.
# Gyroscope Reader + W25Q32JV SPI Flash (Frozen)

What’s inside
Gyroscope
This repository contains a small embedded project for reading data from a gyroscope on an STM32 platform. Alongside the sensor part, the project also includes the initial implementation of a driver for the W25Q32JV SPI NOR flash.

Gyroscope is fully configured.
## Contents

Data acquisition works reliably.
- **Gyroscope** – fully configured, with reliable data acquisition plus a working reading loop and basic processing.
- **W25Q32JV Flash (SPI)** – early driver work; JEDEC ID read (0x9F) implemented and correctly detects the Microchip ID over SPI.

Reading loop and basic processing are already implemented.
## Project Status

W25Q32JV Flash (SPI)
This version of the project is frozen. A larger memory capacity is required, so further work continues in a separate repository targeting a bigger storage device.

Work on the flash driver has started.

Implemented:

JEDEC ID read over SPI (0x9F)

Microchip ID is correctly detected by the MCU.

Project status

This version of the project is frozen.

During development it became clear that a larger memory capacity is required, so further work continues in a separate repository that targets a bigger storage device.

✅ Gyroscope part — finished and stable

🧊 W25Q32JV flash branch — archived / no longer developed here
- ✅ **Gyroscope** — finished and stable
- 🧊 **W25Q32JV flash branch** — archived / no longer developed here

If you are looking for the active continuation of this project (with a new memory solution), please check the other repository.

Notes
## Notes

This repo is kept for reference: wiring, basic SPI flash experiments, and a working gyroscope readout example.
This repo is kept for reference: wiring details, basic SPI flash experiments, and a working gyroscope readout example.
