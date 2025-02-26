# Firmware

请注意， `pmsn_v1.json` 的实现很不规范，请不要直接推到主线。

## How to use

1. Download [bootloader](https://github.com/adafruit/Adafruit_nRF52_Bootloader)
   ```shell
   wget https://github.com/adafruit/Adafruit_nRF52_Bootloader/releases/download/0.9.2/pca10056_bootloader-0.9.2_s140_6.1.1.hex
   ```
2. Flash it through J-Link/SWD-Link/DAPLink
   ```shell
   pyocd erase -t nrf52840 --chip nrf52840
   pyocd flash -t nrf52840 pca10056_bootloader-0.9.2_s140_6.1.1.hex
   ```
3. Clone the [Meshtastic Firmware](https://github.com/meshtastic/firmware) repository, update the repository's [submodules](https://github.com/meshtastic/firmware/blob/master/.gitmodules)
   ```shell
   git clone https://github.com/meshtastic/firmware.git
   cd firmware && git submodule update --init
   ```
4. Add source code
   ```shell
   mkdir -p /path/to/firmware/variants/pmsn_v1
   cp /path/to/pmsn/platformio.ini /path/to/firmware/platformio.ini
   cp /path/to/pmsn/variant.h /path/to/firmware/variant.h
   cp /path/to/pmsn/variant.cpp /path/to/firmware/variant.cpp
   cp /path/to/pmsn/pmsn_v1.json /path/to/firmware/boards/pmsn_v1.json
   ```
5. Build && Upload via USB