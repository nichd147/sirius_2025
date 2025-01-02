# getting started

https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide.html#getting-started

# extension for vsc
https://github.com/espressif/vscode-esp-idf-extension

# permision for usb

`sudo chmod 666 /dev/ttyACM0`

# RGB-LED not working

RGB-LED works on GPIO48.

But it might be disabled (on replica; for example YD-ESP32-23 2022-V1.3)

![alt text](image-1.png)

In case LED is not working check the `RGB` jumper on a board.

![alt text](image.png)

# have got some problem with connecting board to wifi

this is logs

```
--- idf_monitor on /dev/ttyACM0 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ESP-ROM:esp32s3-20210327
Build:Mar 27 2021
rst:0x1 (POWERON),boot:0x8 (SPI_FAST_FLASH_BOOT)
SPIWP:0xee
mode:DIO, clock div:1
load:0x3fce3808,len:0x16cc
load:0x403c9700,len:0xbd4
load:0x403cc700,len:0x2fb0
SHA-256 comparison failed:
Calculated: d26c14ee03530dee14e9dfef1a8a4c5232f8101699b750b99c31cbc10cef8557
Expected: f5b2b4b835e58aba135b96277ccc63f5eb1b3f6ec1997e9b65a99136c5ceafe3
Attempting to boot anyway...
entry 0x403c9954
I (43) boot: ESP-IDF v4.4.8-dirty 2nd stage bootloader
I (43) boot: compile time 16:27:53
I (43) boot: Multicore bootloader
I (45) boot: chip revision: v0.2
I (49) boot.esp32s3: Boot SPI Speed : 80MHz
I (54) boot.esp32s3: SPI Mode       : DIO
I (59) boot.esp32s3: SPI Flash Size : 8MB
I (64) boot: Enabling RNG early entropy source...
I (69) boot: Partition Table:
I (73) boot: ## Label            Usage          Type ST Offset   Length
I (80) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (87) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (95) boot:  2 factory          factory app      00 00 00010000 00100000
I (102) boot: End of partition table
I (107) esp_image: segment 0: paddr=00010020 vaddr=3c080020 size=18d50h (101712) map
I (133) esp_image: segment 1: paddr=00028d78 vaddr=3fc98030 size=03cech ( 15596) load
I (137) esp_image: segment 2: paddr=0002ca6c vaddr=40374000 size=035ach ( 13740) load
I (142) esp_image: segment 3: paddr=00030020 vaddr=42000020 size=74988h (477576) map
I (233) esp_image: segment 4: paddr=000a49b0 vaddr=403775ac size=10a80h ( 68224) load
I (256) boot: Loaded app from partition at offset 0x10000
I (256) boot: Disabling RNG early entropy source...
I (268) cpu_start: Multicore app
I (268) cpu_start: Pro cpu up.
I (268) cpu_start: Starting app cpu, entry point is 0x40375354
0x40375354: call_start_cpu1 at /home/nick/esp/v4.4.8/esp-idf/components/esp_system/port/cpu_start.c:151

2m27(0 ecpsu_stn rFUS _App2cpDA Au_. 0m 
sed 2 bits starting with 0 bit
D (278) efuse: In EFUSE_BLK2__DATA4_REG is used 8 bits starting with 13 bit
D (285) efuse: In EFUSE_BLK1__DATA3_REG is used 3 bits starting with 24 bit
D (292) efuse: In EFUSE_BLK2__DATA4_REG is used 2 bits starting with 0 bit
D (299) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (306) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (313) efuse: In EFUSE_BLK1__DATA5_REG is used 5 bits starting with 11 bit
D (320) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 13 bit
D (327) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (334) efuse: In EFUSE_BLK1__DATA4_REG is used 5 bits starting with 27 bit
D (341) efuse: In EFUSE_BLK1__DATA5_REG is used 3 bits starting with 0 bit
D (348) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (355) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 13 bit
D (362) efuse: In EFUSE_BLK1__DATA4_REG is used 7 bits starting with 20 bit
D (369) efuse: In EFUSE_BLK1__DATA4_REG is used 5 bits starting with 27 bit
D (376) efuse: In EFUSE_BLK1__DATA5_REG is used 3 bits starting with 0 bit
D (383) efuse: In EFUSE_BLK1__DATA5_REG is used 8 bits starting with 3 bit
D (398) clk: RTC_SLOW_CLK calibration value: 4055091
I (406) cpu_start: Pro cpu start user code
I (406) cpu_start: cpu freq: 160000000
I (407) cpu_start: Application information:
I (409) cpu_start: Project name:     udp_server
I (414) cpu_start: App version:      5f91665-dirty
I (420) cpu_start: Compile time:     Jan  2 2025 16:27:45
I (426) cpu_start: ELF file SHA256:  09f53a58f4df024c...
I (432) cpu_start: ESP-IDF:          v4.4.8-dirty
I (437) cpu_start: Min chip rev:     v0.0
I (442) cpu_start: Max chip rev:     v0.99 
I (447) cpu_start: Chip rev:         v0.2
D (452) memory_layout: Checking 5 reserved memory ranges:
D (457) memory_layout: Reserved memory range 0x3fc84000 - 0x3fc9802c
D (463) memory_layout: Reserved memory range 0x3fc98030 - 0x3fc9f818
D (470) memory_layout: Reserved memory range 0x3fceee34 - 0x3fcf0000
D (476) memory_layout: Reserved memory range 0x40374000 - 0x4038802c
0x40374000: _WindowOverflow4 at /home/nick/esp/v4.4.8/esp-idf/components/freertos/port/xtensa/xtensa_vectors.S:1743

D (483) memory_layout: Reserved memory range 0x600fe000 - 0x600fe000
D (489) memory_layout: Building list of available memory regions:
D (495) memory_layout: Available memory region 0x3fc9f818 - 0x3fca0000
D (502) memory_layout: Available memory region 0x3fca0000 - 0x3fcb0000
D (509) memory_layout: Available memory region 0x3fcb0000 - 0x3fcc0000
D (515) memory_layout: Available memory region 0x3fcc0000 - 0x3fcd0000
D (522) memory_layout: Available memory region 0x3fcd0000 - 0x3fce0000
D (528) memory_layout: Available memory region 0x3fce0000 - 0x3fce9710
D (535) memory_layout: Available memory region 0x3fce9710 - 0x3fceee34
D (542) memory_layout: Available memory region 0x3fcf0000 - 0x3fcf8000
D (548) memory_layout: Available memory region 0x600fe000 - 0x60100000
I (555) heap_init: Initializing. RAM available for dynamic allocation:
D (562) heap_init: New heap initialised at 0x3fc9f818
I (567) heap_init: At 3FC9F818 len 00049EF8 (295 KiB): D/IRAM
I (573) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DIRAM
D (580) heap_init: New heap initialised at 0x3fcf0000
I (585) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
D (592) heap_init: New heap initialised at 0x600fe000
I (597) heap_init: At 600FE000 len 00002000 (8 KiB): RTCRAM
D (603) FLASH_HAL: extra_dummy: 0
D (606) spi_flash: trying chip: issi
D (610) spi_flash: trying chip: gd
D (614) spi_flash: trying chip: mxic
D (617) spi_flash: trying chip: winbond
D (621) spi_flash: trying chip: boya
D (625) spi_flash: trying chip: th
D (628) spi_flash: trying chip: mxic (opi)
D (632) spi_flash: trying chip: generic
I (636) spi_flash: detected chip: generic
I (641) spi_flash: flash io: dio
D (645) cpu_start: calling init function: 0x42062374
0x42062374: _GLOBAL__sub_I___cxa_get_globals_fast at /builds/idf/crosstool-NG/.build/xtensa-esp32s3-elf/src/gcc/libstdc++-v3/libsupc++/eh_globals.cc:145

D (650) cpu_start: calling init function: 0x420136e8
0x420136e8: s_set_default_wifi_log_level at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_init.c:65

D (655) cpu_start: calling init function: 0x42008678
0x42008678: esp_ipc_init at /home/nick/esp/v4.4.8/esp-idf/components/esp_ipc/src/esp_ipc.c:105

D (660) cpu_start: calling init function: 0x420020d0
0x420020d0: esp_ota_init_app_elf_sha256 at /home/nick/esp/v4.4.8/esp-idf/components/app_update/esp_app_desc.c:68

D (665) intr_alloc: Connected src 59 to int 2 (cpu 0)
I (670) sleep: Configure to isolate all GPIO pins in sleep state
I (677) sleep: Enable automatic switching of GPIO sleep configuration
D (684) intr_alloc: Connected src 79 to int 3 (cpu 0)
I (689) cpu_start: Starting scheduler on PRO CPU.
D (695) intr_alloc: Connected src 57 to int 9 (cpu 0)
D (695) intr_alloc: Connected src 80 to int 2 (cpu 1)
I (705) cpu_start: Starting scheduler on APP CPU.
D (705) intr_alloc: Connected src 58 to int 3 (cpu 1)
D (715) heap_init: New heap initialised at 0x3fce9710
D (715) intr_alloc: Connected src 52 to int 12 (cpu 0)
D (725) partition: Loading the partition table
D (725) partition: Partition table MD5 verified
D (765) esp_netif_lwip: LwIP stack has been initialized
D (765) esp_netif_lwip: esp-netif has been successfully initialized
D (765) event: running task for loop 0x3fceb4bc
D (775) event: created task for loop 0x3fceb4bc
D (775) event: created event loop 0x3fceb4bc
I (775) pp: pp rom version: e7ae62f
I (785) net80211: net80211 rom version: e7ae62f
D (785) nvs: nvs_open_from_partition misc 1
I (805) wifi:wifi driver task: 3fceea64, prio:23, stack:6656, core=0
I (805) system_api: Base MAC address is not set
I (805) system_api: read default base MAC address from EFUSE
D (815) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 8 bit
D (815) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 0 bit
D (825) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 24 bit
D (835) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 16 bit
D (835) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 8 bit
D (845) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 0 bit
D (855) nvs: nvs_open_from_partition nvs.net80211 1
D (855) nvs: nvs_get opmode 1
D (865) nvs: nvs_get_str_or_blob sta.ssid
D (865) nvs: nvs_get sta.authmode 1
D (865) nvs: nvs_get_str_or_blob sta.pswd
D (875) nvs: nvs_get_str_or_blob sta.pmk
D (875) nvs: nvs_get sta.chan 1
D (875) nvs: nvs_get auto.conn 1
D (885) nvs: nvs_get bssid.set 1
D (885) nvs: nvs_get_str_or_blob sta.bssid
D (895) nvs: nvs_get sta.lis_intval 2
D (895) nvs: nvs_get sta.phym 1
D (895) nvs: nvs_get sta.phybw 1
D (905) nvs: nvs_get_str_or_blob sta.apsw
D (905) nvs: nvs_get_str_or_blob sta.apinfo
D (915) nvs: nvs_get sta.scan_method 1
D (915) nvs: nvs_get sta.sort_method 1
D (915) nvs: nvs_get sta.minrssi 1
D (925) nvs: nvs_get sta.minauth 1
D (925) nvs: nvs_get sta.pmf_e 1
D (925) nvs: nvs_get sta.pmf_r 1
D (935) nvs: nvs_get sta.btm_e 1
D (935) nvs: nvs_get sta.rrm_e 1
D (935) nvs: nvs_get sta.mbo_e 1
D (935) nvs: nvs_get_str_or_blob ap.ssid
D (945) nvs: nvs_get_str_or_blob ap.passwd
D (945) nvs: nvs_get_str_or_blob ap.pmk
D (955) nvs: nvs_get ap.chan 1
D (955) nvs: nvs_get ap.authmode 1
D (955) nvs: nvs_get ap.hidden 1
D (965) nvs: nvs_get ap.max.conn 1
D (965) nvs: nvs_get bcn.interval 2
D (965) nvs: nvs_get ap.phym 1
D (975) nvs: nvs_get ap.phybw 1
D (975) nvs: nvs_get ap.sndchan 1
D (975) nvs: nvs_get ap.pmf_e 1
D (985) nvs: nvs_get ap.pmf_r 1
D (985) nvs: nvs_get ap.p_cipher 1
D (985) nvs: nvs_get lorate 1
D (995) nvs: nvs_get_str_or_blob country
D (995) nvs: nvs_get ap.ftm_r 1
D (995) nvs: nvs_get sta.trans_d 1
D (1005) nvs: nvs_get sta.sae_h2e 1
D (1005) nvs: nvs_get sta.bss_retry 1
D (1005) nvs: nvs_get_str_or_blob ap.pmk_info
D (1015) nvs: nvs_set ap.sndchan 1 1
I (1015) wifi:wifi firmware version: ff661c3
I (1025) wifi:wifi certification version: v7.0
I (1025) wifi:config NVS flash: enabled
I (1025) wifi:config nano formating: disabled
I (1035) wifi:Init data frame dynamic rx buffer num: 32
I (1035) wifi:Init static rx mgmt buffer num: 5
I (1045) wifi:Init management short buffer num: 32
I (1045) wifi:Init dynamic tx buffer num: 32
I (1055) wifi:Init static tx FG buffer num: 2
I (1055) wifi:Init static rx buffer size: 1600
I (1055) wifi:Init static rx buffer num: 10
I (1065) wifi:Init dynamic rx buffer num: 32
I (1065) wifi_init: rx ba win: 6
I (1075) wifi_init: tcpip mbox: 32
I (1075) wifi_init: udp mbox: 6
I (1075) wifi_init: tcp mbox: 6
I (1085) wifi_init: tcp tx win: 5760
I (1085) wifi_init: tcp rx win: 5760
I (1095) wifi_init: tcp mss: 1440
I (1095) wifi_init: WiFi IRAM OP enabled
I (1095) wifi_init: WiFi RX IRAM OP enabled
D (1105) esp_netif_objects: esp_netif_add_to_list 0x3fcf7cf4
D (1115) esp_netif_objects: esp_netif_add_to_list netif added successfully (total netifs: 1)
I (1115) example_connect: Connecting to mi_383B...
D (1125) wifi:clear blacklist
I (1125) phy_init: phy_version 670,b7bc9b9,Apr 30 2024,10:54:13
D (1135) phy_init: loading PHY init data from application binary
D (1135) nvs: nvs_open_from_partition phy 0
D (1145) nvs: nvs_get cal_version 4
D (1145) nvs: nvs_get_str_or_blob cal_mac
D (1155) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 8 bit
D (1155) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 0 bit
D (1165) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 24 bit
D (1175) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 16 bit
D (1175) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 8 bit
D (1185) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 0 bit
D (1195) nvs: nvs_get_str_or_blob cal_data
D (1205) nvs: nvs_close 3
D (1205) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 8 bit
D (1205) efuse: In EFUSE_BLK1__DATA1_REG is used 8 bits starting with 0 bit
D (1215) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 24 bit
D (1225) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 16 bit
D (1225) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 8 bit
D (1235) efuse: In EFUSE_BLK1__DATA0_REG is used 8 bits starting with 0 bit
D (1265) temperature_sensor: range changed, change to index 2
D (1285) wifi:filter: set rx policy=0
I (1285) wifi:mode : sta (80:65:99:d3:2b:3c)
I (1285) wifi:enable tsf
D (1285) wifi:filter: set rx policy=1
D (1285) wifi:connect status 0 -> 0
D (1285) event: running post WIFI_EVENT:2 with handler 0x42013978 and context 0x3fcf7cc4 on loop 0x3fceb4bc
0x42013978: wifi_default_action_sta_start at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:67

D (1295) wifi_init_default: wifi_start esp-netif:0x3fcf7cf4 event-id2
D (1305) wifi_init_default: WIFI mac address: 80 65 99 d3 2b 3c
D (1315) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201056c
0x4201056c: esp_netif_set_mac_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:711


D (1315) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (1315) wifi:Start wifi connect
D (1325) wifi:connect status 0 -> 0
D (1325) wifi:connect chan=0
D (1335) wifi:first chan=1
D (1335) wifi:connect status 0 -> 1
D (1335) wifi:filter: set rx policy=3
D (1345) wifi:clear scan ap list
D (1345) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=1349331, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (1355) wifi:perform scan: ss_state=0x9, chan<1,0>, dur<0,120>
D (1365) esp_netif_handlers: esp_netif action has started with netif0x3fcf7cf4 from event_id=2
D (1365) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x42010db4
0x42010db4: esp_netif_start_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:785


D (1375) esp_netif_lwip: esp_netif_start_api 0x3fcf7cf4
I (1375) example_connect: Waiting for IP(s)
D (1385) esp_netif_lwip: esp_netif_get_hostname esp_netif:0x3fcf7cf4
D (1395) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (1395) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (1405) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (1485) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (1485) wifi:perform scan: ss_state=0x9, chan<2,0>, dur<0,120>
D (1605) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (1605) wifi:perform scan: ss_state=0x9, chan<3,0>, dur<0,120>
D (1725) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (1725) wifi:perform scan: ss_state=0x9, chan<4,0>, dur<0,120>
D (1845) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (1845) wifi:perform scan: ss_state=0x9, chan<5,0>, dur<0,120>
D (1965) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (1965) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (2035) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (2035) wifi:profile match: ss_state=0x7
D (2085) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2085) wifi:perform scan: ss_state=0xd, chan<7,0>, dur<0,120>
D (2205) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2215) wifi:perform scan: ss_state=0xd, chan<8,0>, dur<0,120>
D (2335) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2335) wifi:perform scan: ss_state=0xd, chan<9,0>, dur<0,120>
D (2455) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2455) wifi:perform scan: ss_state=0xd, chan<10,0>, dur<0,120>
D (2575) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2575) wifi:perform scan: ss_state=0xd, chan<11,0>, dur<0,120>
D (2695) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (2695) wifi:perform scan: ss_state=0xd, chan<12,0>, dur<360,360>
D (3055) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (3055) wifi:perform scan: ss_state=0xd, chan<13,0>, dur<360,360>
D (3415) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (3415) wifi:perform scan: ss_state=0xd, chan<14,0>, dur<360,360>
D (3785) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (3785) wifi:filter: set rx policy=4
D (3785) wifi:first chan=1
D (3785) wifi:handoff_cb: status=0
D (3785) wifi:ap found, mac=50:88:11:ae:24:e6
D (3785) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=1
D (3795) wifi:filter: set rx policy=5
I (3795) wifi:new:<6,0>, old:<1,0>, ap:<255,255>, sta:<6,0>, prof:6
D (3805) wifi:connect_op: status=0, auth=5, cipher=3 
D (3805) gdma: new group (0) at 0x3fca352c
D (3815) gdma: new pair (0,0) at 0x3fca3570
D (3815) gdma: new tx channel (0,0) at 0x3fca34d4
D (3825) gdma: new rx channel (0,0) at 0x3fca3590
D (3825) gdma: tx channel (0,0), (1:16) bytes aligned, burst enabled
D (3835) gdma: rx channel (0,0), (1:16) bytes aligned, burst disabled
D (4305) wifi:auth mode is not none
D (4305) wifi:connect_bss: auth=1, reconnect=0
I (4305) wifi:state: init -> auth (b0)
D (4305) wifi:start 1s AUTH timer
D (4315) wifi:clear scan ap list
D (5315) wifi:auth timeout
I (5315) wifi:state: auth -> init (200)
D (5315) wifi:connect status 1 -> 4
D (5315) wifi:stop beacon/connect timer
D (5315) wifi:reason: auth expire(2)
D (5315) wifi:add bssid 50:88:11:ae:24:e6 to blacklist, cnt=0
D (5325) wifi:stop CSA timer
D (5325) wifi:connect status 4 -> 0
D (5325) wifi:remove 50:88:11:ae:24:e6 from rc list
I (5335) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (5335) wifi:filter: set rx policy=8
D (5345) wifi:Send disconnect event, reason=2, AP number=0
D (5345) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (5355) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (5365) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (5375) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (5375) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (5385) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (5395) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (5405) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (5405) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (5415) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (5425) example_connect: Wi-Fi disconnected, trying to reconnect...
D (5435) wifi:Start wifi connect
D (5435) wifi:connect status 0 -> 0
D (5435) wifi:connect chan=0
D (5435) wifi:first chan=6
D (5445) wifi:connect status 0 -> 1
D (5445) wifi:filter: set rx policy=3
D (5445) wifi:clear scan ap list
D (5455) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=5456848, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (5465) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (5515) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (5515) wifi:find the 50:88:11:ae:24:e6 in blacklist.

D (5585) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (5585) wifi:perform scan: ss_state=0x9, chan<1,0>, dur<0,120>
D (5705) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (5705) wifi:perform scan: ss_state=0x9, chan<2,0>, dur<0,120>
D (5835) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (5835) wifi:perform scan: ss_state=0x9, chan<3,0>, dur<0,120>
D (5955) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (5955) wifi:perform scan: ss_state=0x9, chan<4,0>, dur<0,120>
D (6075) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6075) wifi:perform scan: ss_state=0x9, chan<5,0>, dur<0,120>
D (6195) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6195) wifi:perform scan: ss_state=0x9, chan<7,0>, dur<0,120>
D (6315) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6315) wifi:perform scan: ss_state=0x9, chan<8,0>, dur<0,120>
D (6435) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6435) wifi:perform scan: ss_state=0x9, chan<9,0>, dur<0,120>
D (6565) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6565) wifi:perform scan: ss_state=0x9, chan<10,0>, dur<0,120>
D (6685) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6685) wifi:perform scan: ss_state=0x9, chan<11,0>, dur<0,120>
D (6805) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (6805) wifi:perform scan: ss_state=0x9, chan<12,0>, dur<360,360>
D (7165) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (7165) wifi:perform scan: ss_state=0x9, chan<13,0>, dur<360,360>
D (7525) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (7525) wifi:perform scan: ss_state=0x9, chan<14,0>, dur<360,360>
D (7885) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (7885) wifi:filter: set rx policy=4
D (7885) wifi:first chan=1
D (7885) wifi:handoff_cb: status=0
D (7895) wifi:clear blacklist
D (7895) wifi:clear rc list
D (7895) wifi:clear blacklist
D (7895) wifi:Send disconnect event, reason=205
D (7905) wifi:connect status 1 -> 3
D (7905) wifi:disable connect timer
D (7905) wifi:clear scan ap list
D (7915) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (7925) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (7935) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (7935) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (7945) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (7955) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (7965) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (7965) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (7975) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (7975) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (7985) example_connect: Wi-Fi disconnected, trying to reconnect...
D (7995) wifi:Start wifi connect
D (7995) wifi:connect status 3 -> 0
D (8005) wifi:connect chan=0
D (8005) wifi:first chan=6
D (8005) wifi:connect status 0 -> 1
D (8015) wifi:filter: set rx policy=3
D (8015) wifi:clear scan ap list
D (8015) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=8022219, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (8025) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (8075) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (8075) wifi:profile match: ss_state=0x7
D (8155) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8155) wifi:perform scan: ss_state=0xd, chan<1,0>, dur<0,120>
D (8275) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8275) wifi:perform scan: ss_state=0xd, chan<2,0>, dur<0,120>
D (8395) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8395) wifi:perform scan: ss_state=0xd, chan<3,0>, dur<0,120>
D (8515) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8515) wifi:perform scan: ss_state=0xd, chan<4,0>, dur<0,120>
D (8635) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8635) wifi:perform scan: ss_state=0xd, chan<5,0>, dur<0,120>
D (8765) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8765) wifi:perform scan: ss_state=0xd, chan<7,0>, dur<0,120>
D (8885) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (8885) wifi:perform scan: ss_state=0xd, chan<8,0>, dur<0,120>
D (9005) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (9005) wifi:perform scan: ss_state=0xd, chan<9,0>, dur<0,120>
D (9125) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (9125) wifi:perform scan: ss_state=0xd, chan<10,0>, dur<0,120>
D (9245) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (9245) wifi:perform scan: ss_state=0xd, chan<11,0>, dur<0,120>
D (9365) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (9365) wifi:perform scan: ss_state=0xd, chan<12,0>, dur<360,360>
D (9735) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (9735) wifi:perform scan: ss_state=0xd, chan<13,0>, dur<360,360>
D (10095) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (10095) wifi:perform scan: ss_state=0xd, chan<14,0>, dur<360,360>
D (10455) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (10455) wifi:filter: set rx policy=4
D (10455) wifi:first chan=1
D (10455) wifi:handoff_cb: status=0
D (10455) wifi:ap found, mac=50:88:11:ae:24:e6
D (10465) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=6
D (10465) wifi:filter: set rx policy=5
I (10475) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (10475) wifi:connect_op: status=0, auth=5, cipher=3 
D (10485) wifi:auth mode is not none
D (10485) wifi:connect_bss: auth=1, reconnect=0
I (10485) wifi:state: init -> auth (b0)
D (10495) wifi:start 1s AUTH timer
D (10495) wifi:clear scan ap list
D (11495) wifi:auth timeout
I (11495) wifi:state: auth -> init (200)
D (11495) wifi:connect status 1 -> 4
D (11495) wifi:stop beacon/connect timer
D (11495) wifi:reason: auth expire(2)
D (11505) wifi:add bssid 50:88:11:ae:24:e6 to blacklist, cnt=0
D (11505) wifi:stop CSA timer
D (11515) wifi:connect status 4 -> 0
D (11515) wifi:remove 50:88:11:ae:24:e6 from rc list
I (11515) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (11525) wifi:filter: set rx policy=8
D (11525) wifi:Send disconnect event, reason=2, AP number=0
D (11535) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (11545) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (11555) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (11555) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (11565) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (11575) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (11585) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (11585) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (11595) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (11605) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (11615) example_connect: Wi-Fi disconnected, trying to reconnect...
D (11615) wifi:Start wifi connect
D (11625) wifi:connect status 0 -> 0
D (11625) wifi:connect chan=0
D (11625) wifi:first chan=6
D (11625) wifi:connect status 0 -> 1
D (11635) wifi:filter: set rx policy=3
D (11635) wifi:clear scan ap list
D (11635) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=11644479, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (11645) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (11655) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (11655) wifi:find the 50:88:11:ae:24:e6 in blacklist.

D (11755) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (11755) wifi:find the 50:88:11:ae:24:e6 in blacklist.

D (11775) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (11775) wifi:perform scan: ss_state=0x9, chan<1,0>, dur<0,120>
D (11895) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (11895) wifi:perform scan: ss_state=0x9, chan<2,0>, dur<0,120>
D (12015) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12015) wifi:perform scan: ss_state=0x9, chan<3,0>, dur<0,120>
D (12145) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12145) wifi:perform scan: ss_state=0x9, chan<4,0>, dur<0,120>
D (12265) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12265) wifi:perform scan: ss_state=0x9, chan<5,0>, dur<0,120>
D (12385) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12385) wifi:perform scan: ss_state=0x9, chan<7,0>, dur<0,120>
D (12505) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12505) wifi:perform scan: ss_state=0x9, chan<8,0>, dur<0,120>
D (12625) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12625) wifi:perform scan: ss_state=0x9, chan<9,0>, dur<0,120>
D (12745) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12745) wifi:perform scan: ss_state=0x9, chan<10,0>, dur<0,120>
D (12865) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12875) wifi:perform scan: ss_state=0x9, chan<11,0>, dur<0,120>
D (12995) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (12995) wifi:perform scan: ss_state=0x9, chan<12,0>, dur<360,360>
D (13355) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (13355) wifi:perform scan: ss_state=0x9, chan<13,0>, dur<360,360>
D (13715) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (13715) wifi:perform scan: ss_state=0x9, chan<14,0>, dur<360,360>
D (14075) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (14075) wifi:filter: set rx policy=4
D (14075) wifi:first chan=1
D (14075) wifi:handoff_cb: status=0
D (14075) wifi:clear blacklist
D (14085) wifi:clear rc list
D (14085) wifi:clear blacklist
D (14085) wifi:Send disconnect event, reason=205
D (14095) wifi:connect status 1 -> 3
D (14095) wifi:disable connect timer
D (14095) wifi:clear scan ap list
D (14105) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (14115) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (14115) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (14125) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (14135) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (14135) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (14155) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (14155) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (14165) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (14165) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (14175) example_connect: Wi-Fi disconnected, trying to reconnect...
D (14185) wifi:Start wifi connect
D (14185) wifi:connect status 3 -> 0
D (14195) wifi:connect chan=0
D (14195) wifi:first chan=6
D (14195) wifi:connect status 0 -> 1
D (14205) wifi:filter: set rx policy=3
D (14205) wifi:clear scan ap list
D (14205) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=14212479, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (14215) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (14225) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (14225) wifi:profile match: ss_state=0x7
D (14315) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (14315) wifi:set max rate: from <rate=130, phy=3, sig=0> to <rate=144, phy=3 sig=0>
D (14315) wifi:sig_b=0, sig_g=0, sig_n=0, max_b=22, max_g=108, max_n=144
D (14325) wifi:profile match: ss_state=0x7
D (14345) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14345) wifi:perform scan: ss_state=0xd, chan<1,0>, dur<0,120>
D (14465) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14465) wifi:perform scan: ss_state=0xd, chan<2,0>, dur<0,120>
D (14585) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14585) wifi:perform scan: ss_state=0xd, chan<3,0>, dur<0,120>
D (14705) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14705) wifi:perform scan: ss_state=0xd, chan<4,0>, dur<0,120>
D (14825) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14835) wifi:perform scan: ss_state=0xd, chan<5,0>, dur<0,120>
D (14955) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (14955) wifi:perform scan: ss_state=0xd, chan<7,0>, dur<0,120>
D (15075) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15075) wifi:perform scan: ss_state=0xd, chan<8,0>, dur<0,120>
D (15195) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15195) wifi:perform scan: ss_state=0xd, chan<9,0>, dur<0,120>
D (15315) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15315) wifi:perform scan: ss_state=0xd, chan<10,0>, dur<0,120>
D (15435) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15435) wifi:perform scan: ss_state=0xd, chan<11,0>, dur<0,120>
D (15555) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15565) wifi:perform scan: ss_state=0xd, chan<12,0>, dur<360,360>
D (15925) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (15925) wifi:perform scan: ss_state=0xd, chan<13,0>, dur<360,360>
D (16285) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (16285) wifi:perform scan: ss_state=0xd, chan<14,0>, dur<360,360>
D (16645) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (16645) wifi:filter: set rx policy=4
D (16645) wifi:first chan=1
D (16645) wifi:handoff_cb: status=0
D (16645) wifi:ap found, mac=50:88:11:ae:24:e6
D (16655) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=6
D (16655) wifi:filter: set rx policy=5
I (16665) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (16665) wifi:connect_op: status=0, auth=5, cipher=3 
D (16675) wifi:auth mode is not none
D (16675) wifi:connect_bss: auth=1, reconnect=0
I (16675) wifi:state: init -> auth (b0)
D (16685) wifi:start 1s AUTH timer
D (16685) wifi:clear scan ap list
D (17685) wifi:auth timeout
I (17685) wifi:state: auth -> init (200)
D (17685) wifi:connect status 1 -> 4
D (17685) wifi:stop beacon/connect timer
D (17685) wifi:reason: auth expire(2)
D (17695) wifi:add bssid 50:88:11:ae:24:e6 to blacklist, cnt=0
D (17695) wifi:stop CSA timer
D (17705) wifi:connect status 4 -> 0
D (17705) wifi:remove 50:88:11:ae:24:e6 from rc list
I (17705) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (17715) wifi:filter: set rx policy=8
D (17715) wifi:Send disconnect event, reason=2, AP number=0
D (17725) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (17735) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (17745) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (17745) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (17755) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (17765) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (17775) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (17775) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (17785) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (17795) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (17805) example_connect: Wi-Fi disconnected, trying to reconnect...
D (17805) wifi:Start wifi connect
D (17815) wifi:connect status 0 -> 0
D (17815) wifi:connect chan=0
D (17815) wifi:first chan=6
D (17825) wifi:connect status 0 -> 1
D (17825) wifi:filter: set rx policy=3
D (17825) wifi:clear scan ap list
D (17835) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=17835033, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (17835) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (17895) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (17895) wifi:find the 50:88:11:ae:24:e6 in blacklist.

D (17965) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (17965) wifi:perform scan: ss_state=0x9, chan<1,0>, dur<0,120>
D (18085) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18085) wifi:perform scan: ss_state=0x9, chan<2,0>, dur<0,120>
D (18205) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18205) wifi:perform scan: ss_state=0x9, chan<3,0>, dur<0,120>
D (18335) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18335) wifi:perform scan: ss_state=0x9, chan<4,0>, dur<0,120>
D (18455) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18455) wifi:perform scan: ss_state=0x9, chan<5,0>, dur<0,120>
D (18575) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18575) wifi:perform scan: ss_state=0x9, chan<7,0>, dur<0,120>
D (18695) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18695) wifi:perform scan: ss_state=0x9, chan<8,0>, dur<0,120>
D (18815) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18815) wifi:perform scan: ss_state=0x9, chan<9,0>, dur<0,120>
D (18935) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (18935) wifi:perform scan: ss_state=0x9, chan<10,0>, dur<0,120>
D (19065) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (19065) wifi:perform scan: ss_state=0x9, chan<11,0>, dur<0,120>
D (19185) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (19185) wifi:perform scan: ss_state=0x9, chan<12,0>, dur<360,360>
D (19545) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (19545) wifi:perform scan: ss_state=0x9, chan<13,0>, dur<360,360>
D (19905) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (19905) wifi:perform scan: ss_state=0x9, chan<14,0>, dur<360,360>
D (20265) wifi:scan end: arg=0x0, status=0, ss_state=0x3
D (20265) wifi:filter: set rx policy=4
D (20265) wifi:first chan=1
D (20265) wifi:handoff_cb: status=0
D (20265) wifi:clear blacklist
D (20275) wifi:clear rc list
D (20275) wifi:clear blacklist
D (20275) wifi:Send disconnect event, reason=205
D (20285) wifi:connect status 1 -> 3
D (20285) wifi:disable connect timer
D (20285) wifi:clear scan ap list
D (20295) event: running post WIFI_EVENT:5 with handler 0x42013990 and context 0x3fcf7f20 on loop 0x3fceb4bc
0x42013990: wifi_default_action_sta_disconnected at /home/nick/esp/v4.4.8/esp-idf/components/esp_wifi/src/wifi_default.c:100

D (20305) esp_netif_handlers: esp_netif action disconnected with netif0x3fcf7cf4 from event_id=5
D (20315) esp_netif_lwip: check: remote, if=0x3fcf7cf4 fn=0x4201103c
0x4201103c: esp_netif_down_api at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:1372


D (20315) esp_netif_lwip: esp_netif_down_api esp_netif:0x3fcf7cf4
D (20325) esp_netif_lwip: esp_netif_start_ip_lost_timer esp_netif:0x3fcf7cf4
D (20335) esp_netif_lwip: if0x3fcf7cf4 start ip lost tmr: no need start because netif=0x3fcf7d58 interval=120 ip=0
D (20345) esp_netif_lwip: check: local, if=0x3fcf7cf4 fn=0x4201188c
0x4201188c: esp_netif_update_default_netif_lwip at /home/nick/esp/v4.4.8/esp-idf/components/esp_netif/lwip/esp_netif_lwip.c:219


D (20345) esp_netif_lwip: esp_netif_update_default_netif_lwip 0x3fcf7cf4
D (20355) esp_netif_lwip: call api in lwip: ret=0x0, give sem
D (20355) event: running post WIFI_EVENT:5 with handler 0x42007770 and context 0x3fcf7fe4 on loop 0x3fceb4bc
0x42007770: on_wifi_disconnect at /home/nick/esp/v4.4.8/esp-idf/examples/common_components/protocol_examples_common/connect.c:253

I (20365) example_connect: Wi-Fi disconnected, trying to reconnect...
D (20375) wifi:Start wifi connect
D (20375) wifi:connect status 3 -> 0
D (20385) wifi:connect chan=0
D (20385) wifi:first chan=6
D (20385) wifi:connect status 0 -> 1
D (20395) wifi:filter: set rx policy=3
D (20395) wifi:clear scan ap list
D (20395) wifi:start scan: type=0x50f, priority=2, cb=0x42040cec, arg=0x0, ss_state=0x1, time=20402874, index=0
0x42040cec: cnx_start_handoff_cb at ??:?

D (20405) wifi:perform scan: ss_state=0x9, chan<6,0>, dur<0,120>
D (20455) wifi:rsn valid: gcipher=3 ucipher=3 akm=5

D (20455) wifi:profile match: ss_state=0x7
D (20535) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (20535) wifi:perform scan: ss_state=0xd, chan<1,0>, dur<0,120>
D (20655) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (20655) wifi:perform scan: ss_state=0xd, chan<2,0>, dur<0,120>
D (20775) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (20775) wifi:perform scan: ss_state=0xd, chan<3,0>, dur<0,120>
D (20895) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (20895) wifi:perform scan: ss_state=0xd, chan<4,0>, dur<0,120>
D (21025) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21025) wifi:perform scan: ss_state=0xd, chan<5,0>, dur<0,120>
D (21145) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21145) wifi:perform scan: ss_state=0xd, chan<7,0>, dur<0,120>
D (21265) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21265) wifi:perform scan: ss_state=0xd, chan<8,0>, dur<0,120>
D (21385) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21385) wifi:perform scan: ss_state=0xd, chan<9,0>, dur<0,120>
D (21505) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21505) wifi:perform scan: ss_state=0xd, chan<10,0>, dur<0,120>
D (21625) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21625) wifi:perform scan: ss_state=0xd, chan<11,0>, dur<0,120>
D (21745) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (21755) wifi:perform scan: ss_state=0xd, chan<12,0>, dur<360,360>
D (22115) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (22115) wifi:perform scan: ss_state=0xd, chan<13,0>, dur<360,360>
D (22475) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (22475) wifi:perform scan: ss_state=0xd, chan<14,0>, dur<360,360>
D (22835) wifi:scan end: arg=0x0, status=0, ss_state=0x7
D (22835) wifi:filter: set rx policy=4
D (22835) wifi:first chan=1
D (22835) wifi:handoff_cb: status=0
D (22835) wifi:ap found, mac=50:88:11:ae:24:e6
D (22845) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=6
D (22845) wifi:filter: set rx policy=5
I (22855) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (22855) wifi:connect_op: status=0, auth=5, cipher=3 
D (22865) wifi:auth mode is not none
D (22865) wifi:connect_bss: auth=1, reconnect=0
I (22875) wifi:state: init -> auth (b0)
D (22875) wifi:start 1s AUTH timer
D (22875) wifi:clear scan ap list
```



the problem in 


```
D (16645) wifi:ap found, mac=50:88:11:ae:24:e6
D (16655) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=6
D (16655) wifi:filter: set rx policy=5
I (16665) wifi:new:<6,0>, old:<6,0>, ap:<255,255>, sta:<6,0>, prof:6
D (16665) wifi:connect_op: status=0, auth=5, cipher=3 
D (16675) wifi:auth mode is not none
D (16675) wifi:connect_bss: auth=1, reconnect=0
I (16675) wifi:state: init -> auth (b0)
D (16685) wifi:start 1s AUTH timer
D (16685) wifi:clear scan ap list
D (17685) wifi:auth timeout
I (17685) wifi:state: auth -> init (200)
D (17685) wifi:connect status 1 -> 4
D (17685) wifi:stop beacon/connect timer
D (17685) wifi:reason: auth expire(2)
```

this is successfull connection of another valid board

```
D (3751) wifi:ap found, mac=50:88:11:ae:24:e6
D (3761) wifi:new_bss=0x3fc9da88, cur_bss=0x0, new_chan=<6,0>, cur_chan=1
D (3761) wifi:filter: set rx policy=5
I (3771) wifi:new:<6,0>, old:<1,0>, ap:<255,255>, sta:<6,0>, prof:6
D (3771) wifi:connect_op: status=0, auth=5, cipher=3 
D (3781) gdma: new group (0) at 0x3fca35b0
D (3781) gdma: new pair (0,0) at 0x3fca35f4
D (3791) gdma: new tx channel (0,0) at 0x3fca3558
D (3791) gdma: new rx channel (0,0) at 0x3fca3614
D (3801) gdma: tx channel (0,0), (1:16) bytes aligned, burst enabled
D (3801) gdma: rx channel (0,0), (1:16) bytes aligned, burst disabled
D (4281) wifi:auth mode is not none
D (4281) wifi:connect_bss: auth=1, reconnect=0
I (4281) wifi:state: init -> auth (b0)
D (4281) wifi:start 1s AUTH timer
D (4281) wifi:clear scan ap list
D (4291) wifi:recv auth: seq=2, status=0
I (4291) wifi:state: auth -> assoc (0)
D (4291) wifi:restart connect 1s timer for assoc
D (4301) wifi:recv assoc: type=0x10
D (4301) wifi:filter: set rx policy=6
I (4301) wifi:state: assoc -> run (10)
D (4311) wifi:start 10s connect timer for 4 way handshake
D (4321) intr_alloc: Connected src 77 to int 13 (cpu 0)
I (4331) wifi:connected with mi_383B, aid = 2, channel 6, BW20, bssid = 50:88:11:ae:24:e6
I (4331) wifi:security: WPA2-PSK, phy: bgn, rssi: -58
D (4331) wifi:remove all except 50:88:11:ae:24:e6 from rc list
D (4341) wifi:clear blacklist
D (4341) wifi:filter: set rx policy=7
I (4341) wifi:pm start, type: 1
```



and there is a difference i found in loading the board 
```
D (606) spi_flash: trying chip: issi
D (610) spi_flash: trying chip: gd
D (614) spi_flash: trying chip: mxic
D (617) spi_flash: trying chip: winbond
D (621) spi_flash: trying chip: boya
D (625) spi_flash: trying chip: th
D (628) spi_flash: trying chip: mxic (opi)
D (632) spi_flash: trying chip: generic
I (636) spi_flash: detected chip: generic
I (641) spi_flash: flash io: dio
```

in comparing with valid one

```
D (606) spi_flash: trying chip: issi
D (610) spi_flash: trying chip: gd
I (614) spi_flash: detected chip: gd
I (618) spi_flash: flash io: dio

```

Found questions in www but no answer.
