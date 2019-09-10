 #include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial myserial(10,11); // RX, TX

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buzzer = 12;


void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
   myserial.begin(38400);
}
void loop()
{
  while (Serial.available()) {
    lcd.home();
    lcd.clear();
    int ss = Serial.readStringUntil(59).toInt();
    lcd.print(ss);

lcd.print(" ppm");
    lcd.setCursor (1,0);
    
    

if (ss>400)
{
      digitalWrite(buzzer, HIGH);
     lcd.setCursor(0, 1);
     lcd.print("GAS LEAKED!!!");
     delay(250);
      }
else 
{
      digitalWrite(buzzer, LOW);
      delay(250);
}
myserial.println(ss); 
}
}
