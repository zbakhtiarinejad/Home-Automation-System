# Automated Smart Home & Environmental Control System

# Automated Smart Home & Environmental Control System

An Arduino-based home automation prototype designed and simulated in Tinkercad Circuits. The system monitors room occupancy, ambient light, and temperature to automatically control household lighting and cooling while displaying live telemetry on an LCD screen.

---

## System Architecture

| Component Category | Hardware Used | Role in System |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno (ATmega328P) | Central controller processing sensor inputs and driving outputs |
| **Sensors** | PIR Motion Sensor, Photoresistor (LDR), TMP36 | Detects occupancy, ambient light intensity, and room temperature |
| **Switching & Power** | 2x SPDT Relays, Benchtop Power Supply | Isolates 5V logic from higher-power actuator loads |
| **Actuators** | Light Bulb, DC Motor | Simulates automated room lighting and an HVAC cooling fan |
| **Display** | 16x2 Character LCD, Potentiometer | Outputs real-time sensor readings and appliance states (`ON`/`OFF`) |

---

## How It Works

1. **Sensing:** The Arduino continuously reads analog signals from the TMP36 and LDR alongside digital triggers from the PIR motion sensor.
2. **Automation Logic:** 
   * **Lighting:** Activates the light bulb relay when motion is detected in low-light conditions.
   * **Cooling:** Activates the DC motor relay when ambient temperature exceeds a set threshold.
3. **Monitoring:** Updates the 16x2 LCD in real time with current environmental values and active load statuses.

---

## Key Engineering Takeaways
* **Circuit Isolation:** Safely decouples low-voltage microcontroller logic from external load power using electromechanical relays.
* **Energy Efficiency:** Automates power delivery based on multi-sensor thresholds rather than manual switching.
* **Pre-Deployment Validation:** Verified circuit topology, power distribution, and signal routing in simulation prior to hardware assembly.
