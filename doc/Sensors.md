# Supported and Tested Sensors #

The following sensors are well-tested and should be completely compatible, with all feature supported (unless otherwise noted):

 Manufacturer | Part | &nbsp;&nbsp;Packages&nbsp;&nbsp; | V<sub>min</sub> | V<sub>max</sub> | Resolution | Acc. |OS | Class(es) | &nbsp;
:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:| ---
Texas&nbsp;Instruments | [TMP102](http://www.ti.com/lit/ds/symlink/tmp102.pdf) | SOT563 | 1.4V | 3.6V | 9-13b <sup>1</sup> | ±1°C | ✓ | `TI_TMP102` | <sup>2</sup>&nbsp;<sup>3</sup>

# Generically-Supported Sensors #

While many of the below sensors have additional features (or higher accuracy) which may be supported by using a class name specific to the sensor, any generic LM75-compatible sensor should work using one of the following classes depending on which features the sensor has:

* `Generic_LM75` – Basic functionality of the LM75 (shutdown mode, selectableinterrupt/comparator thermostat mode, selectable alert pin polarity, selectable alert queue length) with fixed 9-bit resolution.
* `Generic_LM75_10Bit` – Same as `Generic_LM75` with fixed 10-bit resolution.
* `Generic_LM75_11Bit` – Same as `Generic_LM75` with fixed 11-bit resolution.
* `Generic_LM75_12Bit` – Same as `Generic_LM75` with fixed 12-bit resolution.
* `Generic_LM75_9_to_12Bit` – User-selectable 9- to 12-bit resolution using configuration register bits 5-6.
* `Generic_LM75_9_to_12Bit_OneShot` – Same as `Generic_LM75_9_to_12Bit` plus one-shot temperature measurement during shutdown mode using configuration register bit 7.

# Untested Sensors (likely compatible) #

The following sensors are untested and are likely to work, but have not yet been tested:

 Manufacturer | Part | &nbsp;&nbsp;Packages&nbsp;&nbsp; | V<sub>min</sub> | V<sub>max</sub> | Resolution | Acc. | <abbr title="Supports one-shot mode">OS</abbr> | Class(es) | &nbsp;
:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:| ---
Texas&nbsp;Instruments | [TMP112](http://www.ti.com/lit/ds/symlink/tmp112.pdf) | SOT563 | 1.4V | 3.6V | 9-13b <sup>1</sup> | ±0.5°C | ✓ | `TI_TMP112` | <sup>2</sup>&nbsp;<sup>3</sup>&nbsp;<sup>4</sup>
Texas&nbsp;Instruments | [LM75A](http://www.ti.com/lit/ds/symlink/lm75a.pdf) | SOIC8<br>VSSOP8 | 2.7V | 5.5V | 9b | ±2°C | | `TI_LM75A` |
Texas&nbsp;Instruments | [LM75B<br>LM75C](http://www.ti.com/lit/ds/symlink/lm75b.pdf) | SOIC8<br>VSSOP8 | 3.0V | 5.5V | 9b | ±2°C | | `TI_LM75B`<br>`TI_LM75C` |
Texas&nbsp;Instruments | [TMP75<br>TMP175](http://www.ti.com/lit/ds/symlink/tmp175.pdf) | SOIC8<br>VSSOP8 | 2.7V | 5.5V | 9-12b | ±1°C | ✓ | `TI_TMP75`<br>`TI_TMP175` |
Texas&nbsp;Instruments | [TMP275](http://www.ti.com/lit/ds/symlink/tmp275.pdf) | SOIC8<br>VSSOP8 | 2.7V | 5.5V | 9-12b | ±0.5°C | ✓ | `TI_TMP275` | <sup>5</sup>
Texas&nbsp;Instruments | [TMP100<br>TMP101](http://www.ti.com/lit/ds/symlink/tmp100.pdf) | SOT23-6<sup>a</sup> | 2.7V | 5.5V | 9-12b | ±1°C | ✓ | `TI_TMP100`<br>`TI_TMP101` |
Maxim&nbsp;Integrated | [DS1775](https://datasheets.maximintegrated.com/en/ds/DS1775-DS1775R.pdf) | SOT23-5<sup>a</sup> | 2.7V | 5.5V | 9-12b | ±2°C | | `Maxim_DS1775`
NXP | [LM75A](https://www.nxp.com/docs/en/data-sheet/LM75A.pdf) | SOIC8<br>TSSOP8 | 2.8V | 5.5V | 11b | ±2°C | | `NXP_LM75A` |
NXP | [LM75B](https://www.nxp.com/docs/en/data-sheet/LM75B.pdf) | SOIC8<br>TSSOP8<br>XSON8U<br>HWSON8 | 2.8V | 5.5V | 11b | ±2°C | | `NXP_LM75B` |
ON Semi. | [NCT75](https://www.onsemi.com/pub/Collateral/NCT75-D.PDF) | SOIC8<br>DFN8<br>Micro8™ | 3.0V | 5.5V | 12b | ±1°C | <sup>6</sup> | `ON_NCT75` |
Microchip | [MCP9800/1/2/3](http://ww1.microchip.com/downloads/en/DeviceDoc/21909d.pdf) | SOIC8<br>SOT23-5<sup>b</sup> | 2.7V | 5.5V | 9-12b | ±1°C | ✓ | `Microchip_MCP9800`<br>`Microchip_MCP9801`<br>`Microchip_MCP9802`<br>`Microchip_MCP9803` |
Microchip | [AT30TS750A](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8855-DTS-AT30TS750A-Datasheet.pdf) | SOIC8<br>MSOP8<br>UDFN8 | 1.7V | 5.5V | 9-12b | ±0.5°C | ✓ | `Microchip_AT30TS750A` | <sup>7</sup>
STMicroelectronics | [STLM75](http://www.st.com/content/ccc/resource/technical/document/datasheet/22/c6/56/13/dd/59/4b/43/CD00153511.pdf/files/CD00153511.pdf/jcr:content/translations/en.CD00153511.pdf) | SOIC8<br>TSSOP8 | 2.7V | 5.5V | 9b | ±2°C | | `ST_STLM75` |

# Unsupported Sensors #

There are many sensors based on or similar to the LM75 register layout and protocol, but which support only 8-bit registers. They are currently unsupported.

---

<sup>1</sup> Sensor supports an extended temperature range of -40°C to **150°C** using "extended mode", see `enableExtendedMode()` and `disableExtendedMode()`. Resolution within operating range is not improved, as the 13th bit is the MSB.

<sup>2</sup> Sensor supports variable conversion rate (0.25 Hz, 1 Hz, 4 Hz [default], or 8 Hz) in continuous conversion mode.

<sup>3</sup> Sensor supports checking the alert pin state via I²C.

<sup>4</sup> Based on the Texas Instruments TMP102, with improved ±0.5°C accuracy.

<sup>5</sup> Based on the Texas Instruments TMP175, with improved ±0.5°C accuracy.

<sup>6</sup> Sensor supports one-shot conversion, but incompatibly with the TMP75 implementation. This feature is not currently supported by the `ON_NCT75` class.

<sup>7</sup> Sensor supports non-volatile storage for the configuration, T<sub>high</sub>, T<sub>low</sub> registers by using pointer addresses `0x11`, `0x12`, and `0x13` respectively. This feature is not currently supported by the `Microchip_AT30TS750A` class.

---

<sup>a</sup> SOT23 pinout is SCL, GND, ALERT (or ADD<sub>1</sub>), V<sub>DD</sub>, ADD<sub>0</sub> (or unpopulated for -5 variant), SDA.

<sup>b</sup> SOT23 pinout is V<sub>DD</sub>, GND, ALERT, SCL, (unpopulated), SDA.