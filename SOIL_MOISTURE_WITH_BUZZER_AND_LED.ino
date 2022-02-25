
#include <LiquidCrystal_I2C.h>

int alarm = 8;
int led = 9; 
int sensorValue = 0;
int percentValue = 0;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(alarm, OUTPUT);
  pinMode(led, OUTPUT);
  lcd.init();
}

void loop() {

  int sensorValue = analogRead(A0);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  
 if(sensorValue>750) digitalWrite(alarm,HIGH);
 if(sensorValue>750) digitalWrite(led,HIGH);
  else if(sensorValue<500) digitalWrite(alarm,LOW);
  if(sensorValue<500) digitalWrite(led,LOW);
  delay(100);
  
  percentValue = map(sensorValue, 897, 410, 0, 100);
    lcd.backlight();
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  lcd.setCursor(0, 0);
    lcd.backlight();
  lcd.print("Soil Moisture");
  
  lcd.setCursor(0, 1);
  lcd.backlight();  
  lcd.print("Percent: ");
  lcd.print(percentValue);
    lcd.backlight();
  lcd.print("%");
  delay(1000);

 }
