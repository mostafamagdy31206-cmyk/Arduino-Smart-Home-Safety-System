# Smart Home & Safety System

**Author:** Mostafa Magdy  
**Platform:** Arduino

An integrated embedded project featuring smart ambient lighting, dynamic temperature/gas hazard alarm system, and an interactive digital counter via 7-segment display.

<img width="1580" height="798" alt="Screenshot 2026-08-12 184238" src="https://github.com/user-attachments/assets/690e2c1c-d128-472c-9a48-7deec5c07f0c" />


## 🚀 Features

- **Smart Lighting Control:** Automatically adjusts room LED brightness based on LDR light sensor and potentiometer input.
- **Safety Hazard Alarm:** Non-blocking hazard detection using `millis()` for gas, temperature, or manual switch triggers (buzzer set at 2500 Hz + blinking LED).
- **Digital Counter (0-9):** Push-button controlled up/down counter outputting to a Common Cathode 7-Segment display.

## 📌 Pin Configuration

| Component | Pin / Type |
| :--- | :--- |
| **Light Sensor (LDR)** | `A1` |
| **Potentiometer** | `A0` |
| **Gas Sensor** | `A2` |
| **Temp Sensor** | `A3` |
| **Slide Switch** | `Pin 4` |
| **Buzzer** | `Pin 11` |
| **Smart LEDs** | `Pin 10`, `Pin 5`, `Pin 6` |
| **Alarm LED** | `Pin 2` |
| **Buttons (Up / Down)** | `A5`, `A4` |
| **7-Segment (a-g)** | `1`, `0`, `13`, `12`, `9`, `7`, `8` |
