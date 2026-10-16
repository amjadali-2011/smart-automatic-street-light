# ALVEMIO Smart Automatic Street Light

**Imagine. Build. Innovate.**

A beginner-friendly electronics project that demonstrates how an automatic street light can switch on in darkness and switch off in bright light. The project is designed for learning basic electronics, light sensing, transistor switching, and introductory Arduino control.

> **Project status:** Documentation and circuit designs are in progress. The circuits have not yet been confirmed by physical testing. Verify all connections and component pinouts before powering the circuit.

## Project overview

An LDR (light-dependent resistor) changes resistance depending on the amount of light falling on it. A simple control circuit uses this change to control an LED:

- **Bright environment:** LED should be OFF.
- **Dark environment:** LED should be ON.

This is a low-voltage educational prototype, not a mains-powered street-light controller.

## Build options

### 1. Transistor-only circuit

A discrete-component version for learning how an LDR voltage divider and NPN transistor can control an LED without a microcontroller.

**Planned components**
- 1 × LDR (photoresistor)
- 1 × NPN transistor (for example, BC547; check the exact part's pinout)
- 1 × 10 kΩ resistor
- 1 × 4.7 kΩ resistor
- 1 × 330 Ω resistor
- 1 × LED
- Regulated 5 V DC supply
- Breadboard and jumper wires (optional, for prototyping)

**Circuit notes**
1. Connect +5 V through the 10 kΩ resistor to the sensor junction.
2. Connect the LDR between the sensor junction and GND.
3. Connect the sensor junction through the 4.7 kΩ resistor to the transistor base.
4. Connect the emitter to GND.
5. Connect the transistor collector to the LED cathode.
6. Connect the LED anode through the 330 Ω resistor to +5 V.
7. Ensure all circuit grounds share the same reference.

This arrangement is intended to turn the LED on when the environment becomes dark. Actual switching behavior depends on component values, the transistor pinout, and ambient light; adjust and test the design before use.

See [the transistor circuit notes](circuit/transistor-circuit.txt).

### 2. Optional Arduino version

An Arduino-based version can read an LDR voltage divider through an analog input and control an LED output. It is a separate implementation from the transistor-only circuit.

- Sketch: [src/arduino/street_light_arduino.ino](src/arduino/street_light_arduino.ino)
- Wiring guide: [docs/WIRING.md](docs/WIRING.md)
- Testing guide: [docs/TESTING.md](docs/TESTING.md)

Check the sketch's pin assignments and light threshold for your particular board and setup.

## Repository structure

| Path | Purpose |
| --- | --- |
| `circuit/transistor-circuit.txt` | Transistor-only circuit notes |
| `src/arduino/street_light_arduino.ino` | Optional Arduino sketch |
| `docs/WIRING.md` | Wiring reference |
| `docs/TESTING.md` | Suggested testing steps |
| `docs/PROJECT_OVERVIEW.md` | Project background and status |
| `images/README.md` | Notes for project images |

## Getting started

1. Review the relevant circuit notes and wiring guide.
2. Confirm every component value and transistor pinout from its datasheet.
3. Assemble the circuit using a regulated **5 V DC** supply and check for shorts before powering it.
4. Test the circuit in bright light and in darkness.
5. Record the results and update the documentation after physical testing.

## Safety

- Use only a suitable, regulated low-voltage DC supply for this prototype.
- Never connect this breadboard circuit directly to household mains electricity.
- Disconnect power before changing wiring.
- Use the correct current-limiting resistor for the LED.
- Transistor pin arrangements vary by model and package; verify the datasheet before connecting it.

## Learning goals

- Understand how an LDR responds to light.
- Build and observe a voltage divider.
- Learn how an NPN transistor can act as a switch.
- Compare a discrete-component circuit with an Arduino-based implementation.
- Practise systematic circuit testing and documentation.

## Contributing

Suggestions, corrections, circuit improvements, and verified test results are welcome. Please clearly distinguish simulated or planned behavior from results confirmed on physical hardware.

## About

Created as a beginner-friendly electronics project by **ALVEMIO Technologies**.

**Tagline:** Imagine. Build. Innovate.
