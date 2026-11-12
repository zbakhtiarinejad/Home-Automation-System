#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 4, 3, 2);

// Pin Definitions
const int MOTION_PIN = 8;
const int BULB_RELAY_PIN = 5;
const int FAN_RELAY_PIN = 6;
const int LIGHT_SENSOR_PIN = A5;
const int TEMP_SENSOR_PIN = A4;

void setup() {
  // Setup LCD display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Home Automation");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(3000);
  lcd.clear();

  // Configure pin modes
  pinMode(MOTION_PIN, INPUT);
  pinMode(BULB_RELAY_PIN, OUTPUT);
  pinMode(FAN_RELAY_PIN, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read sensors
  int motionDetected = digitalRead(MOTION_PIN);
  int lightLevel = analogRead(LIGHT_SENSOR_PIN);
  int rawTemp = analogRead(TEMP_SENSOR_PIN);

  // Print debug values to Serial Monitor
  Serial.print("Motion: "); Serial.println(motionDetected);
  Serial.print("Light: "); Serial.println(lightLevel);
  Serial.print("Raw Temp: "); Serial.println(rawTemp);

  // Convert TMP36 analog reading to Celsius
  float voltage = (float)rawTemp / 1024.0 * 5.0;
  float temperatureC = (voltage - 0.5) * 100.0;

  if (motionDetected == HIGH) {
    // Define environment conditions (Thresholds: Light < 550 is dark, Temp > 30°C is hot)
    bool isDark = (lightLevel < 550);
    bool isHot = (temperatureC > 30.0);

    if (isDark && isHot) {
      lcd.setCursor(0, 0);
      lcd.print("Movement Detected");
      delay(1000);
      lcd.clear();

      digitalWrite(BULB_RELAY_PIN, HIGH);
      digitalWrite(FAN_RELAY_PIN, HIGH);

      lcd.setCursor(0, 0);
      lcd.print("Bulb & Fan ON");
      delay(1000);
      lcd.clear();
    }
    else if (isDark && !isHot) {
      lcd.setCursor(0, 0);
      lcd.print("Movement Detected");
      delay(1000);
      lcd.clear();

      digitalWrite(BULB_RELAY_PIN, HIGH);
      digitalWrite(FAN_RELAY_PIN, LOW);

      lcd.setCursor(0, 0);
      lcd.print("Only Bulb is ON");
      delay(1000);
      lcd.clear();
    }
    else if (!isDark && isHot) {
      lcd.setCursor(0, 0);
      lcd.print("Movement Detected");
      delay(1000);
      lcd.clear();

      digitalWrite(BULB_RELAY_PIN, LOW);
      digitalWrite(FAN_RELAY_PIN, HIGH);

      lcd.setCursor(0, 0);
      lcd.print("Only Fan Started");
      delay(1000);
      lcd.clear();
    }
    else { // !isDark && !isHot (Sufficient light & comfortable temp)
      lcd.setCursor(0, 0);
      lcd.print("Movement Detected");
      lcd.setCursor(0, 1);
      lcd.print("Light & Temp OK");
      delay(1500);
      lcd.clear();

      digitalWrite(BULB_RELAY_PIN, LOW);
      digitalWrite(FAN_RELAY_PIN, LOW);

      lcd.setCursor(0, 0);
      lcd.print("Bulb & Fan Off");
      delay(3000);
      lcd.clear();
    }
  }
  else {
    // No motion detected -> turn off appliances
    digitalWrite(BULB_RELAY_PIN, LOW);
    digitalWrite(FAN_RELAY_PIN, LOW);

    lcd.setCursor(0, 0);
    lcd.print("No Movement");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
    delay(1500);
    lcd.clear();
  }
}
