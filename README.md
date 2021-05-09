# esp32s2-ulp-riscv-assembly

This is an ESP-IDF example application that calls an assembly function
from C on the [ESP32-S2 ULP-RISC-V coprocessor][1].

This code relates to a [help request I posted on the esp32.com forum][2].

## Configuration

	$ idf.py set-target esp32s2
	$ idf.py menuconfig

In the `Component config` > `ESP32S2-specific` menu check:

- Enable Ultra Low Power (ULP) Coprocessor
- Enable RISC-V as ULP coprocessor

## Output

	$ idf.py build flash monitor
	...
	I (2262) esp32s2-ulp-riscv-assembly: results: 3, 3


[1]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/ulp-risc-v.html
[2]: https://esp32.com/viewtopic.php?f=2&t=20734&sid=d4a8b03e8f6a17d979eaeff65767b0af
