//Task 2 Light control system 

//Including this library in this code
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0); //Enables tinkercad to simulate LCD

//Defining variables
int Photoresistor = A1;
int POTENTIOMETER = A0;
int Rled = 9;
int Wled = 10;

void setup() {
   //Defining the pins
  pinMode(Rled, OUTPUT);
  pinMode(Wled, OUTPUT);
  Serial.begin(9600);
{ 
  lcd.begin(16, 2);
  
}
}
void loop() {
  //Measures voltage on analog pins
  int Currentlight = analogRead(Photoresistor);   //reads photoresistor value
  int lightthreshold = analogRead(POTENTIOMETER); //reads potentiometer value
  
  //Printing values within serial monitor 
  Serial.print("Light = ");
  Serial.print(Currentlight);
  Serial.print(" | Threshold = ");
  Serial.println(lightthreshold);

 //If scenarios to decipher when the LED turns on
  if (Currentlight < lightthreshold) {
    digitalWrite(Rled, HIGH); // when it's dark
    digitalWrite(Wled, HIGH); // when it's dark
  } else {
    digitalWrite(Rled, LOW);  // when it's bright
    digitalWrite(Wled, LOW);  // when it's bright
  }
  //LCD screen set up 
  lcd.setCursor(0,0);          //Moves cursor to collumn 0, row 0         
  lcd.print("  Threshold = "); //Prints word
  lcd.setCursor(2,1);          //Moves cursor to collumn 2, row 1   
  lcd.print(lightthreshold);   //Prints value of potentiometer
}
