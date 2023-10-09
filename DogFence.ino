#include <LiquidCrystal_I2C.h>
#include <SR04.h>

int distanceCheck = 1191;

int triggerPin = 12;
int echoPin = 11;
SR04 sensor = SR04(echoPin, triggerPin);
long distance;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2); 

int buzzerPin = 3;

void setup() {
  // put your setup code here, to run once:
  lcd.init();          // Initiate the LCD module
  lcd.backlight(); 
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sensor.Distance();
  Serial.println(distance);
  lcd.setCursor(0, 0);          
  lcd.print("Distance");
  
  lcd.setCursor(1, 0);        
  lcd.print(distance);
  delay(1000);

  if (distance != distanceCheck)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(5000);
    digitalWrite(buzzerPin, LOW);
  }
}
