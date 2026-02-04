# Манипулятор на esp32

## Стек
- ESP-IDF
- FreeRTOS
- PlatformIO

## Сборка
```sh
nix-shell
pio run -t upload
```

## Просчёт углов (Example)
```
python3 degree.py
Длина плеча 1:		20
Длина плеча 2:		20
Конечная точка X:	0
Конечная точка Y:	20
Конечная точка Z:	20
Угол меж плеч:		90.00000000000001
Угол плеча у башни:	90.0
Угол поворота башни:	0.0

python3 degree.py
Длина плеча 1:		20
Длина плеча 2:		20
Конечная точка X:	20
Конечная точка Y:	20
Конечная точка Z:	20
Угол меж плеч:		90.00000000000001
Угол плеча у башни:	80.26438968275465
Угол поворота башни:	45.0
```

## Тулзы и доки
- https://docs.platformio.org/en/latest/
- https://clang.llvm.org/extra/clang-tidy/
- https://sigmdel.ca/michel/ha/esp8266/super_mini_esp32c3_en.html
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/ledc.html
- https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_wifi.html
- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos.html
