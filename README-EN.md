# uselessbox
A 'useless' box is a fascinating and often humorous project that is perfect for beginners. It is a simple device that essentially has one function: flipping a switch and then turning itself off again.

Here's a summary and explanation of the code, along with the differences between each action, and a simple circuit diagram:

### Code Summary:
- The system uses an Arduino Nano with:
  - A servo motor (`handServo`) controlling a "hand" movement.
  - An LED WS2812 (`FastLED`) indicating status.
  - A switch connected to pin 3, used to cycle through actions.
- When the switch is pressed, an interrupt (`handleSwitchInterrupt`) increments the `action` variable, looping from 1 to 7.
- The `loop()` function checks the `action` value and executes different preset sequences involving servo movements, delays, and serial prints.
- Each action simulates a different "trick" like opening a box, moving the hand, wiggling, etc.
- During an action, the LED turns red; after completion, it switches back to blue.

---

### Differences Between Actions:

| **Action** | **Description** | **Key Movements & Effects** |
|--------------|-------------------|------------------------------|
| **1** | Opening box, moving hand down, wiggle, then closing | Servo moves from 180° to 35°, then moves to 26°, then back up |
| **2** | Partially opens box, waits, opens fully, moves hand down, wiggles, then closes | Servo moves to 170°, then down to 35°, then to 26°, then back up |
| **3** | Jittery opening, then moves hand down, wiggles, then closes | Servo quickly bounces between 180° and 165°, then down to 35°, then up to 180° |
| **4** | Opens box, moves hand down, wiggles, then closes | Servo from 180° to 35°, then back to 180° |
| **5** | Slow open, wiggles hand multiple times, then closes | Servo slowly from 180° to 26°, then wiggles between 75° and 40°, then back up |
| **6** | Slow open, wiggles hand, then closes | Servo from 180° to 26° at a slower rate, then back up |
| **7** | Opens to a certain point, wiggles, then fully opens, then closes | Servo from 180° to 60°, wiggles between 60° and 40°, then back to 180° |

---

### Circuit Diagram:
**Components Needed:**
- Arduino Nano
- switch MTS102 ON-ON
- Servo motor SG90
- WS2812B LED strip (single LED)

**Connections:**
```
[Arduino]
 Pin D2 ----> Data pin for LED (WS2812B)
 Pin D3 ----> Switch ----> GND (with internal pull-up enabled)
 Pin D4 ----> Servo Signal Pin
 +5V ----> Servo V+ / LED V+
 GND ----> Servo V- / Switch (mid) / LED V-
```
---
