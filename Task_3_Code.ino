//Task 3 Stamp machine

// Library additions 
#include <LiquidCrystal.h>
#include <Servo.h>
 
// Defined Pins 
const int SERVO_PIN  = 6;
const int POT_PIN    = A0;
const int BUTTON_PIN = 7;
const int LED_PIN    = 8;
 
// LCD + Servo setup 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo motor;
 
void setup() {
  lcd.begin(16, 2);
  motor.attach(SERVO_PIN);
 
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
 
  lcd.clear();
}
 
void loop() {
 
//If button is pressed- the sequence 
  if (digitalRead(BUTTON_PIN) == LOW) {
    lcd.clear();
    lcd.print("Stamping in prog");
 
    // Move servo motor to 180 degrees + flash LED
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
 
    motor.write(180);
    lcd.setCursor(0, 1);
    lcd.print("Angle: 180");
    delay(2000);
 
    // Move back to 0- default + flashing light again 
    for (int i = 0; i < 5; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
 
    motor.write(0);
    lcd.setCursor(0, 1);
    lcd.print("Angle: 0   ");
    delay(2000);
 
    lcd.clear();
    return;
  }
 
// Potentiometer is turned 
  int angle = map(analogRead(POT_PIN), 0, 1023, 0, 180);
  motor.write(angle);
 
  if (angle == 0) {
    lcd.clear();
    digitalWrite(LED_PIN, LOW);
    return;
  }
 
  // Flash the LED when moving
  digitalWrite(LED_PIN, HIGH);
  delay(30);
  digitalWrite(LED_PIN, LOW);
 
  // Update display when functions are active 
  lcd.setCursor(0, 0);
  lcd.print("Manual Control ");
 
  lcd.setCursor(0, 1);
  lcd.print("Angle: ");
  lcd.print(angle);
  lcd.print("   ");
 
  delay(20);
}