#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
double i, v, L, R, X;
float Vo;
float R1 = 10000;
float logRth, Rth, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int buzz= 2;
void setup() {
  lcd.begin(16, 2);
Serial.begin(115200);
pinMode(2,OUTPUT);
}

void loop() {

  
while ((L>250)&&(L<1500))
{
  Vo = analogRead(A0);
  v= (analogRead(A1)*5.0)/1023;
  i=(5.0-v)/20000;
  R=(v/i);
  X=pow(R,-0.611);
  L=76607*X;
  Rth = R1 * (1023.0 / Vo - 1.0);
  logRth = log(Rth);
  Tc = (1.0 / (c1 + c2*logRth + c3*logRth*logRth*logRth));
  T = Tc - 273.15; 
  Serial.print("Temperature: "); 
  Serial.println(T); 
  Serial.print("Lux:");
  Serial.println(L);  
  delay(200);
  lcd.print("normal conditions");
   for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  if ((T>30)&&(T<35))
  {
    lcd.clear();
    lcd.print("photosynthesis rate = 130%");
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }
  else if((T>35)&&(T<40))
  {
    lcd.clear();
    lcd.print("photosynthesis rate = 160%");
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }
  else if((T>40)&&(T<45))
  {
    lcd.clear();
    lcd.print("photosynthesis rate = 190%");
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }
  else if(T>45)
  {
    tone(buzz, 300);
    lcd.clear();
    lcd.print("warning: very high temp");
    delay(2000);
    noTone(buzz);
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }
  
}
  Vo = analogRead(A0);
  v= (analogRead(A1)*5.0)/1023;
  i=(5.0-v)/20000;
  R=(v/i);
  X=pow(R,-0.611);
  L=76607*X;
  Rth = R1 * (1023.0 / Vo - 1.0);
  logRth = log(Rth);
  Tc = (1.0 / (c1 + c2*logRth + c3*logRth*logRth*logRth));
  T = Tc - 273.15; 
  Serial.print("Temperature: "); 
  Serial.println(T); 
  Serial.print("Lux:");
  Serial.println(L);  
  delay(200);
  
  if (L>1500)
  {
    tone(buzz, 300);
    lcd.clear();
    lcd.print("warning: high light intensity");
    delay(2000);
    noTone(buzz);
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }
  else if(L<250)
  {
    tone(buzz, 300);
    lcd.clear();
    lcd.print("warning: needs more light");
    delay(2000);
    noTone(buzz);
     for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }
  }

}
