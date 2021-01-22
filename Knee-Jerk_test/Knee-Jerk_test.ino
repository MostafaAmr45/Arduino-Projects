//MPU
#include <Wire.h>
int gyro_x, gyro_y, gyro_z;
long gyro_x_cal, gyro_y_cal, gyro_z_cal;
boolean set_gyro_angles;

long acc_x, acc_y, acc_z, acc_total_vector;
float angle_roll_acc, angle_pitch_acc;

float angle_pitch, angle_roll;
int angle_pitch_buffer, angle_roll_buffer;
float angle_pitch_output, angle_roll_output;

long loop_timer;
int temp;

// knee 
int F=0;
long acc_x=0, X=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,7,6,5,4) ;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2) ;
}

void loop() {
  
float Force= analogRead(A1);  
float Angle= analogRead(A0);
  Serial.print("Force: "); 
  Serial.println(F);
  //Serial.println(" Angle");
  //Serial.print(Angle);   
  delay(10);
  if (Force>5)
  {
    F=Force;
  }
  
  X=abs(170-acc_x);

  if (F<10) 
  {
    lcd.clear();
    lcd.setCursor (0,0) ;
    lcd.print ("HIT HARDER!!") ;
  }
  else if ((F<100)  && (F>10))
  {
    if (X<5)
    {
      lcd.clear();
      lcd.setCursor (0,0) ;
      lcd.print ("Possible diagnosis: Hyporeflyxia") ;
    }
    else if ((X>5) && (X<40))
    {
      lcd.clear();
      lcd.setCursor (0,0) ;
      lcd.print (" You are fine ;)") ;
    }
    else if (X>40)
    {
      lcd.clear();
      lcd.setCursor (0,0) ;
      lcd.print ("Possible diagnosis: Hyperreflyxia") ;
    }
  }
  else if (F>100)
  {
    lcd.clear();
    lcd.setCursor (0,0) ;
    lcd.print ("hit gentler") ;
  }
  
}
