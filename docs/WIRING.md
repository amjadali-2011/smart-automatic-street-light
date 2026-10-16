# Wiring Guide

## Version A — Transistor-only automatic light

### Connection table (low-voltage DC)

| From | Connect to |
|---|---|
| Supply positive (+5 V) | One side of the 10 kΩ resistor |
| Other side of 10 kΩ resistor | Sensor node |
| Sensor node | One leg of the LDR |
| Other leg of the LDR | GND |
| Sensor node | One side of the 4.7 kΩ base resistor |
| Other side of 4.7 kΩ resistor | NPN transistor base |
| NPN emitter | GND |
| NPN collector | LED cathode (short leg / flat side, usually) |
| Supply positive | LED series resistor (330 Ω for 5 V) |
| Other side of LED resistor | LED anode (long leg, usually) |
| Supply negative (GND) | Common ground |

For a 9 V supply, use approximately **1 kΩ** as the LED series resistor instead of 330 Ω. The 10 kΩ sensor resistor and 4.7 kΩ base resistor may be retained for an initial prototype, but switching sensitivity varies with LDR and transistor characteristics.

### Text schematic
```text
          +5 V
            |
           10 kΩ
            |
     SENSOR NODE -------- 4.7 kΩ -------- Base (NPN)
            |                              Emitter ---- GND
           LDR                             Collector
            |                                  |
           GND                              LED cathode
                                               LED
          +5 V ---- 330 Ω ---------------- LED anode

Supply GND is the common GND.
```

The schematic shows the LED's anode supplied from +5 V through its current-limiting resistor and its cathode connected to the NPN collector. Do not connect the LED directly to the supply without a series resistor.

**Transistor pinout warning:** Identify base, collector, and emitter from the exact part's datasheet. Pin order is not universal.

## Version B — Arduino Uno/Nano

### LDR divider
1. Connect one LDR leg to **+5 V**.
2. Connect the other LDR leg to **A0**.
3. Connect a **10 kΩ resistor between A0 and GND**.

This creates a voltage that generally rises in brighter light.

### LED
1. Connect Arduino **D9 → 220–330 Ω resistor → LED anode** (long leg, usually).
2. Connect LED cathode (short leg, usually) to **GND**.

### Arduino connection table

| Part | Connection |
|---|---|
| LDR leg 1 | +5 V |
| LDR leg 2 | A0 |
| 10 kΩ resistor leg 1 | A0 |
| 10 kΩ resistor leg 2 | GND |
| D9 | 220–330 Ω resistor, then LED anode |
| LED cathode | GND |

Use the Arduino's regulated 5 V and GND for this low-current demonstration. Do not power a bare LED without its resistor.
