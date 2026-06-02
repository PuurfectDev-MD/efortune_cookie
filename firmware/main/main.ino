#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "fortunes.h"



char currentFortune[100];

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET)

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  randomSeed(analogRead(A0))
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
motion_detected = detectMotion()

if (motion_detected){
  int randomIndex = random(0, totalFortunes);

  strcpy_P(currentFortune, (char*)pgm_read_word(&(fortuneTable[randomIndex])));
  displayText(currentFortune);
  Serial.println("Your fortune is printer on the display.")
  delay(7000)
}

delay(500)
}



void detectMotion(){
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
  delay(200);


  // Serial.print("Axis X = ");
  // Serial.print(data.X);
  // Serial.print("  ");
  // Serial.print("Axis Y = ");
  // Serial.print(data.Y);
  // Serial.print("  ");
  // Serial.print("Axis Z  = ");
  // Serial.println(data.Z);


  if (data.X <200 || data.Y<200 || data.Z<200){
    return true
  }
}


void displayText(text){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(text);
  display.display();
}