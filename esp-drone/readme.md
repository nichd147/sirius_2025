# ESP-Drone
https://github.com/espressif/esp-drone


# Troubleshooting

## in case a problem with connection check this

https://github.com/espressif/esp-drone/issues/66#issuecomment-2373625957

## problem with flashing `Permission deny`?

`sudo chmod 666 /dev/ttyACM0`

## problem with run `cfclient`
```
...
INFO:cflib.crazyflie:Resending for pattern (76, 1)
INFO:cflib.crazyflie:Resending for pattern (76, 1)
INFO:cflib.crazyflie:Resending for pattern (76, 1)
...
```
[How to connect my ESP32-Drone aircraft to cfclient?](https://github.com/espressif/esp-drone/issues/33) \
[How to connect my ESP32-S2-Drone v1.2 to cfclient?](https://github.com/espressif/esp-drone/issues/66)

Recomndation from source: Use latest version of cfclient and compile&flash latest firmware on board.


## problem with flashing like

```
esptool.py v3.3.4-dev
Serial port /dev/ttyACM0
Connecting...
Traceback (most recent call last):
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 5655, in <module>
    _main()
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 5648, in _main
    main()
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 4955, in main
    esp = esp or get_default_connected_device(ser_list, port=args.port, connect_attempts=args.connect_attempts,
                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 116, in get_default_connected_device
    _esp.connect(before, connect_attempts)
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 689, in connect
    last_error = self._connect_attempt(mode=mode, usb_jtag_serial=usb_jtag_serial, extra_delay=extra_delay)
                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 639, in _connect_attempt
    self.bootloader_reset(usb_jtag_serial, extra_delay)
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 600, in bootloader_reset
    self._setRTS(False)
  File "/home/nick/esp/v4.4.8/esp-idf/components/esptool_py/esptool/esptool.py", line 560, in _setRTS
    self._port.setRTS(state)
  File "/home/nick/.espressif/python_env/idf4.4_py3.12_env/lib/python3.12/site-packages/serial/serialutil.py", line 600, in setRTS
    self.rts = value
    ^^^^^^^^
  File "/home/nick/.espressif/python_env/idf4.4_py3.12_env/lib/python3.12/site-packages/serial/serialutil.py", line 463, in rts
    self._update_rts_state()
  File "/home/nick/.espressif/python_env/idf4.4_py3.12_env/lib/python3.12/site-packages/serial/serialposix.py", line 708, in _update_rts_state
    fcntl.ioctl(self.fd, TIOCMBIC, TIOCM_RTS_str)
OSError: [Errno 71] Protocol error
```

try following:
1. [board has two buttons](https://docs.espressif.com/projects/esptool/en/latest/esp32s3/advanced-topics/boot-mode-selection.html#manual-bootloader): `Boot` (left) and `EN` (right)
2. click `Boot` then `EN`
3. `cd build`
4. copy the flash command from previous attempt
5. replace `--before default_reset` by `--before no_reset`
6. run command

## this is origin output of drone on start

```
nick@:~/***/***/esp-drone/esp-drone-origin$ '/home/nick/.espressif/python_env/idf4.4_py3.12_env/bin/python' '/home/nick/esp/v4.4.8/esp-idf/tools/idf_monitor.py' -p /dev/ttyACM0 -b 115200 --toolchain-prefix xtensa-esp32s3-elf- --target esp32s3 '/home/nick/***/***/esp-drone/esp-drone-origin/build/ESPDrone.elf'
--- idf_monitor on /dev/ttyACM0 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x15 (USB_UART_CHIP_RESET),boot:0x8 (SPI_FAST_FLASH_BOOT)
Saved PC:0x4207f5be
0x4207f5be: _svfprintf_r at /builds/idf/crosstool-NG/.build/xtensa-esp32s3-elf/src/newlib/newlib/libc/stdio/vfprintf.c:1535

SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3808,len:0x17b0
load:0x403c9700,len:0xe64
load:0x403cc700,len:0x30e8
entry 0x403c9980
I (24) boot: ESP-IDF v4.4.2-dirty 2nd stage bootloader
I (25) boot: compile time 16:08:55
I (25) boot: chip revision: 0
I (27) qio_mode: Enabling default flash chip QIO
I (32) boot.esp32s3: Boot SPI Speed : 80MHz
I (37) boot.esp32s3: SPI Mode       : QIO
I (41) boot.esp32s3: SPI Flash Size : 8MB
I (46) boot: Enabling RNG early entropy source...
I (52) boot: Partition Table:
I (55) boot: ## Label            Usage          Type ST Offset   Length
I (62) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (70) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (77) boot:  2 factory          factory app      00 00 00010000 00100000
I (85) boot: End of partition table
I (89) esp_image: segment 0: paddr=00010020 vaddr=3c090020 size=1bed8h (114392) map
I (115) esp_image: segment 1: paddr=0002bf00 vaddr=3fc97920 size=04118h ( 16664) load
I (118) esp_image: segment 2: paddr=00030020 vaddr=42000020 size=82040h (532544) map
I (201) esp_image: segment 3: paddr=000b2068 vaddr=3fc9ba38 size=01128h (  4392) load
I (203) esp_image: segment 4: paddr=000b3198 vaddr=40374000 size=13918h ( 80152) load
I (222) esp_image: segment 5: paddr=000c6ab8 vaddr=50000000 size=00010h (    16) load
I (231) boot: Loaded app from partition at offset 0x10000
I (231) boot: Disabling RNG early entropy source...
I (243) cpu_start: Pro cpu up.
I (243) cpu_start: Starting app cpu, entry point is 0x4037540c
0x4037540c: esp_ota_get_app_elf_sha256 at /home/nick/esp/v4.4.8/esp-idf/components/app_update/esp_app_desc.c:88

I (0) cpu_start: App cpu up.
I (257) cpu_start: Pro cpu start user code
I (257) cpu_start: cpu freq: 240000000
I (257) cpu_start: Application information:
I (260) cpu_start: Project name:     ESPDrone
I (265) cpu_start: App version:      3e8ffe3-dirty
I (270) cpu_start: Compile time:     Sep 24 2024 16:08:25
I (276) cpu_start: ELF file SHA256:  869b87aca95d076d...
I (282) cpu_start: ESP-IDF:          v4.4.2-dirty
I (288) heap_init: Initializing. RAM available for dynamic allocation:
I (295) heap_init: At 3FCB1F38 len 0002E0C8 (184 KiB): D/IRAM
I (301) heap_init: At 3FCE0000 len 0000EE34 (59 KiB): STACK/DRAM
I (308) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
I (314) heap_init: At 600FE000 len 00002000 (8 KiB): RTCRAM
I (321) spi_flash: detected chip: generic
I (325) spi_flash: flash io: qio
W (329) spi_flash: Detected size(16384k) larger than the size in the binary image header(8192k). Using the size in the binary image header.
I (342) sleep: Configure to isolate all GPIO pins in sleep state
I (349) sleep: Enable automatic switching of GPIO sleep configuration
I (356) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (399) PLATFORM: set active config 
I (399) gpio: GPIO[7]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (401) gpio: GPIO[8]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (411) gpio: GPIO[9]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (421) pp: pp rom version: e7ae62f
I (424) net80211: net80211 rom version: e7ae62f
I (430) wifi:wifi driver task: 3fce59a8, prio:23, stack:6656, core=0
I (435) system_api: Base MAC address is not set
I (440) system_api: read default base MAC address from EFUSE
I (450) wifi:wifi firmware version: eeaa27d
I (451) wifi:wifi certification version: v7.0
I (455) wifi:config NVS flash: enabled
I (458) wifi:config nano formating: disabled
I (462) wifi:Init data frame dynamic rx buffer num: 32
I (467) wifi:Init management frame dynamic rx buffer num: 32
I (472) wifi:Init management short buffer num: 32
I (477) wifi:Init dynamic tx buffer num: 32
I (481) wifi:Init static tx FG buffer num: 2
I (485) wifi:Init static rx buffer size: 1600
I (489) wifi:Init static rx buffer num: 10
I (492) wifi:Init dynamic rx buffer num: 32
I (497) wifi_init: rx ba win: 6
I (500) wifi_init: tcpip mbox: 32
I (504) wifi_init: udp mbox: 6
I (508) wifi_init: tcp mbox: 6
I (512) wifi_init: tcp tx win: 5744
I (516) wifi_init: tcp rx win: 5744
I (520) wifi_init: tcp mss: 1440
I (524) wifi_init: WiFi IRAM OP enabled
I (528) wifi_init: WiFi RX IRAM OP enabled
I (536) phy_init: phy_version 503,13653eb,Jun  1 2022,17:47:08
I (572) wifi:mode : softAP (98:3d:ae:e2:0e:9d)
I (574) wifi:Total power save buffer number: 16
I (574) wifi:Init max length of beacon: 752/752
I (574) wifi:Init max length of beacon: 752/752
I (578) WIFI_UDP: wifi_init_softap complete.SSID:ESP-DRONE_983DAEE20E9D password:12345678
I (587) WIFI_UDP: Socket created
I (591) WIFI_UDP: Socket bound, port 2390
I (595) WIFI_UDP: UDP server create socket succeed!!!
I (1101) SYS: ----------------------------

I (1101) SYS: ESPlane 2.0  is up and running!

I (1101) I2CDRV:  i2c 1 driver install return = 0
I (1105) EEPROM: spi_flash_init ... !
I (1110) EEPROM: spi_flash_read ok !
Characterized using Default Vref
I (2422) I2CDRV:  i2c 0 driver install return = 0
I (2423) SENSORS: MPU6050 I2C connection [OK].

W (2781) ZR2: Z-down sensor [FAIL]

W (2781) SENSORS: VL53L1X I2C connection [FAIL].

I (2781) gpio: GPIO[34]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
W (2836) SENSORS: PMW3901 SPI connection [FAIL].

I (2837) SENSORS: sensors init done
I (2837) SENSORS: pitch_calib = 0.000000,roll_calib = 0.000000
I (2842) gpio: GPIO[12]| InputEn: 1| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:1 
I (2851) ESTIMATOR: Using Complementary (1) estimator

I (2857) POSITION_CONTROLLER: thrustBase = 24000,thrustMin  = 5000
I (2864) SYS: wifilinkTest = 1 
I (3367) SYS: pmTest = 1
I (3367) SYS: workerTest = 1
I (3367) SYS: systemTest = 1 
I (3367) SYS: configblockTest = 1 
I (3370) COMM: wifilinkTest = 1 
I (3374) COMM: crtpTest = 1 
I (3378) COMM: crtpserviceTest = 1 
I (3382) COMM: platformserviceTest = 1 
I (3386) COMM: consoleTest = 1 
I (3390) COMM: paramTest = 1 
I (3394) SYS: commTest = 1 
I (3397) SYS: commanderTest = 1 
I (5216) SYS: stabilizerTest = 1 
I (5216) SYS: estimatorKalmanTaskTest = 1 
I (5216) SYS: memTest = 1 
I (5217) STAB: Wait for sensor calibration...

I (5222) SYS: systemStart ! selftestPassed = 1
I (6102) SYSLOAD: Task dump
I (6103) SYSLOAD: Load  Stack left      Name    PRI
I (6103) SYSLOAD: nan   2328    Tmr Svc         1
I (6104) SYSLOAD: nan   1336    IDLE    0
I (6109) SYSLOAD: nan   1344    IDLE    0
I (6113) SYSLOAD: nan   1308    UDP_TX  3
I (6117) SYSLOAD: nan   5464    CRTP-RX         2
I (6122) SYSLOAD: nan   3200    PWRMGNT         0
I (6126) SYSLOAD: nan   2508    tiT     18
I (6130) SYSLOAD: nan   4084    SENSORS         4
I (6135) SYSLOAD: nan   3168    STABILIZER      5
I (6140) SYSLOAD: nan   1736    sys_evt         20
I (6144) SYSLOAD: nan   3156    UDP_RX  3
I (6149) SYSLOAD: nan   380     WIFILINK        3
I (6153) SYSLOAD: nan   2388    LOG     2
I (6157) SYSLOAD: nan   1400    CRTP-TX         2
I (6162) SYSLOAD: nan   1392    PARAM   2
I (6166) SYSLOAD: nan   1336    CMDHL   2
I (6171) SYSLOAD: nan   600     ipc0    2
I (6175) SYSLOAD: nan   1436    KALMAN  1
I (6179) SYSLOAD: nan   3600    SYSTEM  2
I (6184) SYSLOAD: nan   1424    LEDSEQCMD       1
I (6188) SYSLOAD: nan   3208    esp_timer       22
I (6193) SYSLOAD: nan   4332    wifi    23
I (6197) SYSLOAD: nan   544     ipc1    24
I (6202) SYSLOAD: Free heap: 196040 bytes
I (6210) PM: lowPower 

I (6444) SENSORS: isBiasValueFound!
I (6445) STAB: Ready to fly.
```

### or

```
nick@:~/***/***/esp-drone/esp-drone-origin$ '/home/nick/.espressif/python_env/idf4.4_py3.12_env/bin/python' '/home/nick/esp/v4.4.8/esp-idf/tools/idf_monitor.py' -p /dev/ttyACM0 -b 115200 --toolchain-prefix xtensa-esp32s3-elf- --target esp32s3 '/home/nick/***/***/esp-drone/esp-drone-origin/build/ESPDrone.elf'
--- idf_monitor on /dev/ttyACM0 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x15 (USB_UART_CHIP_RESET),boot:0x8 (SPI_FAST_FLASH_BOOT)
Saved PC:0x40056f72
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3808,len:0x17b0
load:0x403c9700,len:0xe64
load:0x403cc700,len:0x30e8
entry 0x403c9980
I (24) boot: ESP-IDF v4.4.2-dirty 2nd stage bootloader
I (25) boot: compile time 16:08:55
I (25) boot: chip revision: 0
I (27) qio_mode: Enabling default flash chip QIO
I (32) boot.esp32s3: Boot SPI Speed : 80MHz
I (37) boot.esp32s3: SPI Mode       : QIO
I (41) boot.esp32s3: SPI Flash Size : 8MB
I (46) boot: Enabling RNG early entropy source...
I (52) boot: Partition Table:
I (55) boot: ## Label            Usage          Type ST Offset   Length
I (62) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (70) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (77) boot:  2 factory          factory app      00 00 00010000 00100000
I (85) boot: End of partition table
I (89) esp_image: segment 0: paddr=00010020 vaddr=3c090020 size=1bed8h (114392) map
I (115) esp_image: segment 1: paddr=0002bf00 vaddr=3fc97920 size=04118h ( 16664) load
I (118) esp_image: segment 2: paddr=00030020 vaddr=42000020 size=82040h (532544) map
I (201) esp_image: segment 3: paddr=000b2068 vaddr=3fc9ba38 size=01128h (  4392) load
I (203) esp_image: segment 4: paddr=000b3198 vaddr=40374000 size=13918h ( 80152) load
I (222) esp_image: segment 5: paddr=000c6ab8 vaddr=50000000 size=00010h (    16) load
I (231) boot: Loaded app from partition at offset 0x10000
I (231) boot: Disabling RNG early entropy source...
I (243) cpu_start: Pro cpu up.
I (243) cpu_start: Starting app cpu, entry point is 0x4037540c
0x4037540c: esp_ota_get_app_elf_sha256 at /home/nick/esp/v4.4.8/esp-idf/components/app_update/esp_app_desc.c:89 (discriminator 3)

I (0) cpu_start: App cpu up.
I (257) cpu_start: Pro cpu start user code
I (257) cpu_start: cpu freq: 240000000
I (257) cpu_start: Application information:
I (260) cpu_start: Project name:     ESPDrone
I (265) cpu_start: App version:      3e8ffe3-dirty
I (270) cpu_start: Compile time:     Sep 24 2024 16:08:25
I (276) cpu_start: ELF file SHA256:  869b87aca95d076d...
I (282) cpu_start: ESP-IDF:          v4.4.2-dirty
I (288) heap_init: Initializing. RAM available for dynamic allocation:
I (295) heap_init: At 3FCB1F38 len 0002E0C8 (184 KiB): D/IRAM
I (301) heap_init: At 3FCE0000 len 0000EE34 (59 KiB): STACK/DRAM
I (308) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
I (314) heap_init: At 600FE000 len 00002000 (8 KiB): RTCRAM
I (321) spi_flash: detected chip: generic
I (325) spi_flash: flash io: qio
W (329) spi_flash: Detected size(16384k) larger than the size in the binary image header(8192k). Using the size in the binary image header.
I (342) sleep: Configure to isolate all GPIO pins in sleep state
I (349) sleep: Enable automatic switching of GPIO sleep configuration
I (356) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (399) PLATFORM: set active config 
I (399) gpio: GPIO[7]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (401) gpio: GPIO[8]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (411) gpio: GPIO[9]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
I (421) pp: pp rom version: e7ae62f
I (424) net80211: net80211 rom version: e7ae62f
I (430) wifi:wifi driver task: 3fce59a8, prio:23, stack:6656, core=0
I (435) system_api: Base MAC address is not set
I (440) system_api: read default base MAC address from EFUSE
I (450) wifi:wifi firmware version: eeaa27d
I (451) wifi:wifi certification version: v7.0
I (455) wifi:config NVS flash: enabled
I (458) wifi:config nano formating: disabled
I (462) wifi:Init data frame dynamic rx buffer num: 32
I (467) wifi:Init management frame dynamic rx buffer num: 32
I (472) wifi:Init management short buffer num: 32
I (477) wifi:Init dynamic tx buffer num: 32
I (481) wifi:Init static tx FG buffer num: 2
I (485) wifi:Init static rx buffer size: 1600
I (489) wifi:Init static rx buffer num: 10
I (492) wifi:Init dynamic rx buffer num: 32
I (497) wifi_init: rx ba win: 6
I (500) wifi_init: tcpip mbox: 32
I (504) wifi_init: udp mbox: 6
I (508) wifi_init: tcp mbox: 6
I (512) wifi_init: tcp tx win: 5744
I (516) wifi_init: tcp rx win: 5744
I (520) wifi_init: tcp mss: 1440
I (524) wifi_init: WiFi IRAM OP enabled
I (528) wifi_init: WiFi RX IRAM OP enabled
I (536) phy_init: phy_version 503,13653eb,Jun  1 2022,17:47:08
I (571) wifi:mode : softAP (98:3d:ae:e1:ba:a1)
I (574) wifi:Total power save buffer number: 16
I (574) wifi:Init max length of beacon: 752/752
I (574) wifi:Init max length of beacon: 752/752
I (578) WIFI_UDP: wifi_init_softap complete.SSID:ESP-DRONE_983DAEE1BAA1 password:12345678
I (587) WIFI_UDP: Socket created
I (590) WIFI_UDP: Socket bound, port 2390
I (595) WIFI_UDP: UDP server create socket succeed!!!
I (1101) SYS: ----------------------------

I (1101) SYS: ESPlane 2.0  is up and running!

I (1101) I2CDRV:  i2c 1 driver install return = 0
I (1105) EEPROM: spi_flash_init ... !
I (1110) EEPROM: spi_flash_read ok !
Characterized using Default Vref
I (2422) I2CDRV:  i2c 0 driver install return = 0
I (2422) SENSORS: MPU6050 I2C connection [OK].

W (2781) ZR2: Z-down sensor [FAIL]

W (2781) SENSORS: VL53L1X I2C connection [FAIL].

I (2781) gpio: GPIO[34]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
W (2836) SENSORS: PMW3901 SPI connection [FAIL].

I (2837) SENSORS: sensors init done
I (2837) SENSORS: pitch_calib = 0.000000,roll_calib = 0.000000
I (2842) gpio: GPIO[12]| InputEn: 1| OutputEn: 0| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:1 
I (2851) ESTIMATOR: Using Complementary (1) estimator

I (2857) POSITION_CONTROLLER: thrustBase = 24000,thrustMin  = 5000
I (2864) SYS: wifilinkTest = 1 
I (3367) SYS: pmTest = 1
I (3367) SYS: workerTest = 1
I (3367) SYS: systemTest = 1 
I (3367) SYS: configblockTest = 1 
I (3370) COMM: wifilinkTest = 1 
I (3374) COMM: crtpTest = 1 
I (3378) COMM: crtpserviceTest = 1 
I (3382) COMM: platformserviceTest = 1 
I (3386) COMM: consoleTest = 1 
I (3390) COMM: paramTest = 1 
I (3394) SYS: commTest = 1 
I (3397) SYS: commanderTest = 1 
I (5216) SYS: stabilizerTest = 1 
I (5216) SYS: estimatorKalmanTaskTest = 1 
I (5216) SYS: memTest = 1 
I (5217) STAB: Wait for sensor calibration...

I (5222) SYS: systemStart ! selftestPassed = 1
I (6102) SYSLOAD: Task dump
I (6103) SYSLOAD: Load  Stack left      Name    PRI
I (6103) SYSLOAD: nan   2328    Tmr Svc         1
I (6104) SYSLOAD: nan   1336    IDLE    0
I (6108) SYSLOAD: nan   1424    IDLE    0
I (6113) SYSLOAD: nan   1372    UDP_TX  3
I (6117) SYSLOAD: nan   5464    CRTP-RX         2
I (6122) SYSLOAD: nan   3200    PWRMGNT         0
I (6126) SYSLOAD: nan   2508    tiT     18
I (6130) SYSLOAD: nan   3168    STABILIZER      5
I (6135) SYSLOAD: nan   1736    sys_evt         20
I (6140) SYSLOAD: nan   3156    UDP_RX  3
I (6144) SYSLOAD: nan   380     WIFILINK        3
I (6149) SYSLOAD: nan   2388    LOG     2
I (6153) SYSLOAD: nan   1400    CRTP-TX         2
I (6157) SYSLOAD: nan   1392    PARAM   2
I (6162) SYSLOAD: nan   1336    CMDHL   2
I (6166) SYSLOAD: nan   600     ipc0    2
I (6170) SYSLOAD: nan   1436    KALMAN  1
I (6175) SYSLOAD: nan   3600    SYSTEM  2
I (6179) SYSLOAD: nan   1424    LEDSEQCMD       1
I (6184) SYSLOAD: nan   3240    esp_timer       22
I (6188) SYSLOAD: nan   4332    wifi    23
I (6193) SYSLOAD: nan   4084    SENSORS         4
I (6197) SYSLOAD: nan   608     ipc1    24
I (6202) SYSLOAD: Free heap: 196256 bytes
I (6209) PM: lowPower 

I (6447) SENSORS: isBiasValueFound!
I (6448) STAB: Ready to fly.
```

# some interesting from internet

## controlling by keyboard

https://forum.bitcraze.io/viewtopic.php?t=692 \
https://bitbucket.org/eldraco2000/crazyflie-programs/src/master/keyboard_control.py

## drone bridge

https://github.com/DroneBridge/ESP32