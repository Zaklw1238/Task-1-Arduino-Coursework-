//Task 1 Traffic light 

//Defining variables
int red = 9;
int yellow = 8;
int green = 7;
int buttonPin = 2;
int rgbRed = 3;
int rgbBlue = 4;
int rgbGreen = 5;
int buzzer = 6;


void setup() {
  //Sets pins as outputs or inputs 
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(rgbBlue, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Initial setup before the button is pressed
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(rgbRed, HIGH);   
  digitalWrite(rgbGreen, LOW);  
  digitalWrite(rgbBlue, LOW);

  //Function once the button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    delay(2000); 
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(rgbRed, LOW);   
    digitalWrite(rgbGreen, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(5000);
    digitalWrite(buzzer, LOW);
    digitalWrite(rgbGreen, LOW);
    digitalWrite(rgbRed, HIGH);
    delay(500);
    digitalWrite(yellow, HIGH);
    delay(3000);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);

    while (digitalRead(buttonPin) == HIGH) {
      delay(10); //Delay from when the button is pressed
    }
  }
}
 