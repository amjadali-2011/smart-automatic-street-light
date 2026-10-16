# Testing Instructions

## Before power-on
- [ ] Confirm all wiring against `WIRING.md`.
- [ ] Verify LED polarity.
- [ ] Verify the NPN transistor pinout from its datasheet (transistor version).
- [ ] Check that there are no short circuits between supply positive and GND.
- [ ] Use only a low-voltage DC supply.

## Test A — Transistor-only circuit
1. Build the circuit with the supply disconnected.
2. Ask a helper to double-check the transistor pinout and wiring.
3. Apply 5 V DC.
4. Shine a phone flashlight on the LDR. The LED should turn off or become dimmer.
5. Cover the LDR with your hand or an opaque object. The LED should turn on.
6. If behavior is reversed or unreliable, disconnect power and check wiring, transistor pinout, LDR connections, and resistor values. The switching point depends on ambient light and component tolerances.

## Test B — Arduino version
1. Install Arduino IDE.
2. Open `src/arduino/street_light_arduino.ino`.
3. Select **Arduino Uno** (or the matching board) under Tools → Board.
4. Select the correct serial port under Tools → Port.
5. Upload the sketch.
6. Open Serial Monitor at **9600 baud**.
7. Shine a light on the LDR, then cover it.
8. Observe the readings and LED response.
9. If the LED response is inverted, confirm the divider matches the wiring guide. Change `DARK_THRESHOLD` based on observed readings.

## Record results
Add a table to your project log after testing:

| Test | Expected result | Actual result | Pass/Fail |
|---|---|---|---|
| Bright light on LDR | LED off | Fill after testing | Fill |
| LDR covered | LED on | Fill after testing | Fill |
| Power cycle | Starts in correct state | Fill after testing | Fill |

Do not mark the project “tested successfully” until you have completed the tests on real hardware.
