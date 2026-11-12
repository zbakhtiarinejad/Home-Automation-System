# Home-Automation-System
This smart home system uses an Arduino microcontroller and sensors to automatically monitor a room's temperature, light levels, and motion. Depending on the conditions, it automatically switches appliances like a lamp and cooling fan on or off while displaying live status updates on a small screen.

## Hardware Architecture
* **Microcontroller:** Arduino Uno (ATmega328P)[cite: 1]
* **Sensors (Inputs):**
  * **PIR Motion Sensor:** Detects human presence and room occupancy[cite: 1].
  * **Photoresistor (LDR) + Voltage Divider:** Measures ambient light levels[cite: 1].
  * **TMP36 Temperature Sensor:** Captures real-time ambient thermal data[cite: 1].
* **Actuators & Power Switching (Outputs):**
  * **2x SPDT Relays:** Opto-isolated/electromechanical switching for high-power loads[cite: 1].
  * **Incandescent Light Bulb:** Simulates automated room lighting[cite: 1].
  * **DC Motor:** Simulates an automated HVAC/cooling fan load[cite: 1].
  * **External Benchtop Power Supply:** Delivers dedicated power to the switched loads[cite: 1].
* **User Interface:**
  * **16x2 Character LCD:** Displays live sensor readings and appliance status[cite: 1].
  * **10kΩ Potentiometer:** Adjusts LCD screen contrast[cite: 1].

---

## System Logic & Operation
1. **Environmental Polling:** The Arduino reads analog voltage signals from the TMP36 temperature sensor and LDR, alongside digital high/low interrupts from the PIR motion sensor[cite: 1].
2. **Automated Load Switching:** 
   * **Lighting Control:** When motion is detected and ambient light drops below a set threshold, the microcontroller energizes the first SPDT relay to switch on the light bulb[cite: 1].
   * **Thermal Control:** When the room temperature exceeds a target threshold (or occupancy is active), the microcontroller triggers the second SPDT relay to power the DC cooling fan[cite: 1].
3. **Live Telemetry:** Sensor values and active relay states (`ON`/`OFF`) are formatted and printed to the 16x2 LCD in real time[cite: 1].

---

## Engineering Highlights
* **Power Isolation:** Separates low-voltage microcontroller logic (5V) from higher-power actuator circuits using dual SPDT relays and an external power supply[cite: 1].
* **Multi-Sensor Fusion:** Combines analog threshold sensing (temperature and light) with digital event detection (motion) to prevent unnecessary energy consumption[cite: 1].
