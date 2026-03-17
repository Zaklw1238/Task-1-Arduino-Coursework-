//Task 4 Car park 

//Including Libraries in this code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Setting up the lCD Display
LiquidCrystal_I2C lcd(0x27,16,2);

// Defining variables
const int buttonPin = 2;
const int trigPin = 7;
const int echoPin = 6;
const int potPin = A0;

Servo gateServo;
const int servoPin = 9;

// Defining servo angles
int gateClosed = 0; // Closed
int gateOpen = 90;  // Open

// Distance function
long getDistance()
{
  digitalWrite(trigPin, LOW); // Resetting
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); // Trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Time of ping
  long distance = duration * 0.034 / 2; // Converts time to distance 

  return distance;
}

// Define function that will allow writing to any LCD screen
void lcdMessage(String line1, String line2)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(0,1);
  lcd.print(line2);
}

// Setting up pins, servo and LCD
void setup()
{
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gateServo.attach(servoPin);
  gateServo.write(gateClosed);

  lcd.init();
  lcd.backlight();

  lcdMessage("Barrier Ready", "Waiting Car"); //Message on LCD
}

// LOOP
void loop()
{
  long distance = getDistance(); // Returns ultrasonic sensor distance

  int potValue = analogRead(potPin); // Poteniotmeter connected to Pin A0
  int threshold = map(potValue, 0, 1023, 5, 30); // Reads value from potentiometer and maps it to a threshold distance between 5 and 30cm. 

  // Prints distance and threshold in serial monitor for initial analysis 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Threshold: ");
  Serial.print(threshold);
  Serial.println(" cm");

  // Awaits a car to be detected
  if(distance < threshold)
  {
    lcdMessage("Car Detected","Press Button");

    // Waits for the button to be pressed
    while(digitalRead(buttonPin) == LOW)
    {
      delay(50);
    }

    lcdMessage("Opening Gate","");

    // Opens the gate
    gateServo.write(gateOpen);
    delay(1500);

    lcdMessage("Car Passing",""); //Signals to the car to pass

    // Wait 
    while(getDistance() < threshold)
    {
      delay(100);
    }

    // 
    delay(3000); //Delay for the car to fully pass the barrier
    lcdMessage("Closing Gate",""); //Signals that the gate is closing

    // Gate is closed
    gateServo.write(gateClosed);
    delay(2000);

    lcdMessage("Barrier Ready","Waiting Car"); //Back to signalling that the sensor is waiting for a car
  }

  delay(100);
}
