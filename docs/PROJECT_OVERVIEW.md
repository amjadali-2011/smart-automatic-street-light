# Smart Automatic Street Light
### ALVEMIO Technologies — Imagine. Build. Innovate.

A beginner-friendly electronics project that automatically switches an LED on when the surrounding light becomes dim and switches it off when the surroundings are bright.

This repository contains **two implementations**:
1. **Transistor-only circuit** — no microcontroller or code required.
2. **Arduino version** — reads an LDR voltage on an analog input and controls an LED.

> **Project status:** These files provide a build design and test procedure. The circuit has **not been physically tested or verified by ALVEMIO Technologies yet**. After building it, add your own photos and update this status honestly.

## Features
- Automatic day/night response using an LDR (photoresistor)
- Beginner-friendly components
- No internet connection required
- Optional Arduino implementation for adjustable threshold and serial monitoring

## Project versions

| Version | Controller | Best for |
|---|---|---|
| Transistor-only | NPN transistor | Learning basic electronics |
| Arduino | Arduino Uno/Nano | Learning analog inputs and digital outputs |

## Components

### A. Transistor-only version
- 1 × LDR (photoresistor)
- 1 × NPN transistor such as BC547 or 2N2222
- 1 × 10 kΩ resistor (sensor divider)
- 1 × 4.7 kΩ resistor (base resistor)
- 1 × LED
- 1 × 330 Ω resistor for a 5 V supply, or 1 kΩ for a 9 V supply
- 5 V regulated supply or a 9 V battery
- Breadboard and jumper wires

**Important:** BC547 and 2N2222 pinouts can differ by manufacturer and package. Check the datasheet for your exact transistor before wiring. Do not assume the flat side always means the same pin order.

### B. Arduino version
- Arduino Uno or Nano
- LDR
- 10 kΩ resistor
- 1 × LED
- 1 × 220–330 Ω LED resistor
- Breadboard and jumper wires
- USB cable / suitable Arduino power source

## How it works
An LDR's resistance usually **decreases in bright light** and **increases in darkness**.

- In the transistor version, the 10 kΩ resistor and LDR form a voltage divider. In bright light, the divider node is pulled lower; in darkness, it rises and supplies base current to the NPN transistor, turning on the LED.
- In the Arduino version, the analog input measures the divider voltage. The sketch turns the LED on when the reading crosses a configurable threshold.

## Build instructions
See [docs/WIRING.md](WIRING.md) for the connection tables and [docs/TESTING.md](TESTING.md) for the test procedure.

## Arduino code
Open `src/arduino/street_light_arduino.ino` in the Arduino IDE. Select your board and port, then upload.

### Arduino pin map
- LDR divider node → A0
- LED anode → D9 through a 220–330 Ω resistor
- LED cathode → GND

The Arduino sketch assumes the LDR is connected between **A0 and +5 V**, and the 10 kΩ resistor is connected between **A0 and GND**. With this arrangement, the reading generally rises in bright light, so the code turns the LED on when the reading is below the configured dark threshold. If your LDR module or divider is wired differently, adjust the threshold or reverse the comparison.

## Safety
- Use a **low-voltage DC supply only** for this beginner project.
- Never connect the circuit directly to household mains electricity.
- Check transistor pinout and LED polarity before applying power.
- Disconnect power before changing wiring.
- A 9 V rectangular battery may have limited capacity; a regulated 5 V supply is often more practical for testing.

## Future improvements
- Add a potentiometer to adjust the switching threshold.
- Add hysteresis to reduce flicker near dusk/dawn.
- Use a weather-resistant enclosure for an outdoor demonstration.
- Add a relay or MOSFET only after learning suitable load-driving and electrical safety practices.

## Repository structure
```text
smart-automatic-street-light/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── arduino/
│       └── street_light_arduino.ino
├── docs/
│   ├── WIRING.md
│   ├── TESTING.md
│   └── PROJECT_OVERVIEW.md
├── circuit/
│   └── transistor-circuit.txt
└── images/
    └── README.md
```

## Credits
Created as an educational project for **ALVEMIO Technologies**.
