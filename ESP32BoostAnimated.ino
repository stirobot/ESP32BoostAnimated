//128*64 (double height of brz gauge)
//i2c interface
//not sure what to use wifi for (webserve it with wifi direct webpage?)

//this uses the squix ssd1306 library...it is faster and has more functions
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"
#include "SSD1306Brzo.h"
// Include the UI lib
#include "OLEDDisplayUi.h"

// Include custom images
#include "images.h"
int atmo = 0;
SSD1306  display(0x3c, 4, 15); //for the heltec with the built in oled...SSD1306  display(0x3c, D3, D5); for normal
int rBoost = 0;
bool isInverted = false;
int peakboost = 0;

void setup() {
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW); // set GPIO16 low to reset OLED
  delay(50);
  digitalWrite(16, HIGH); // while OLED is running, must set GPIO16 to high
  //Wire.begin(4,15);

  display.init();

  //display.flipScreenVertically(); //usb to the left
  // The ESP is capable of rendering 60fps in 80Mhz mode
  // but that won't give you much time for anything else
  // run it in 160Mhz mode or just set it to 30 fps
  //ui.setTargetFPS(30);
  display.setFont(ArialMT_Plain_24);
  display.setTextAlignment(TEXT_ALIGN_RIGHT);

  //show logo
  //display.drawFastImage(59, 21, splash_Logo_width, splash_Logo_height, splash_Logo_bits);
  //display.drawXbm(0,0, splash_Logo_width, splash_Logo_height, splash_Logo_bits);
  //display.display();
  //delay(2000);
  //do the gauge sweep dance
  display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge0_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge1_width, gauge1_height, gauge1_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge2_width, gauge2_height, gauge2_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge3_width, gauge3_height, gauge3_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge4_width, gauge4_height, gauge4_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge5_width, gauge5_height, gauge5_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge6_width, gauge6_height, gauge6_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge7_width, gauge7_height, gauge7_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge8_width, gauge8_height, gauge8_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge9_width, gauge9_height, gauge9_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge10_width, gauge10_height, gauge10_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge11_width, gauge11_height, gauge11_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge12_width, gauge12_height, gauge12_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge13_width, gauge13_height, gauge13_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge14_width, gauge14_height, gauge14_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge15_width, gauge15_height, gauge15_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge16_width, gauge16_height, gauge16_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge17_width, gauge17_height, gauge17_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge18_width, gauge18_height, gauge18_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge19_width, gauge19_height, gauge19_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge20_width, gauge20_height, gauge20_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge19_width, gauge19_height, gauge19_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge18_width, gauge18_height, gauge18_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge17_width, gauge17_height, gauge17_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge16_width, gauge16_height, gauge16_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge15_width, gauge15_height, gauge15_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge14_width, gauge14_height, gauge14_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge13_width, gauge13_height, gauge13_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge12_width, gauge12_height, gauge12_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge11_width, gauge11_height, gauge11_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge10_width, gauge10_height, gauge10_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge9_width, gauge9_height, gauge9_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge8_width, gauge8_height, gauge8_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge7_width, gauge7_height, gauge7_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge6_width, gauge6_height, gauge6_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge5_width, gauge5_height, gauge5_bits);
  display.display();
  delay(20);
  display.clear();
  display.drawXbm(0, 0, gauge4_width, gauge4_height, gauge4_bits);
  display.display();
  delay(30);
  display.clear();
  display.drawXbm(0, 0, gauge3_width, gauge3_height, gauge3_bits);
  display.display();
  delay(40);
  display.clear();
  display.drawXbm(0, 0, gauge2_width, gauge2_height, gauge2_bits);
  display.display();
  delay(50);
  display.clear();
  display.drawXbm(0, 0, gauge1_width, gauge1_height, gauge1_bits);
  display.display();
  delay(50);
  display.clear();
  display.clear();
}

void loop() {
  //I guess this lib XOR's everything because it doesn't seem to flicker with this horribly straightforward code
  //turbo logo
  //get boost value
  int boost = getBoost() - 14;  //1 atmosphere is roughtly 14.6 psi
  if (boost > peakboost){
    peakboost = boost;
  }
  String Speakboost = String(peakboost);
  String Sboost = String(boost);
  //update boost value print at 90, 10  
  if (boost >=0 ){
    display.drawString(120, 4, Sboost); 
    display.drawString(125, 24, "psi");
  }
  else {
    Sboost = String(boost * 2);
    //psi to in/Hg
    display.drawString(126, 4, Sboost); 
    display.drawString(127, 24, "Hg");
  }
  //display peak
  display.setFont(ArialMT_Plain_10);
  display.drawString(128,53,"max " + Speakboost);
  display.setFont(ArialMT_Plain_24);
  
  
  //select the right xbm for the number
  if ((boost > 16) && (isInverted == false)) {
    display.invertDisplay();
    isInverted = true;
  }
  if ((boost <= 16) && (isInverted == true)) {
    display.normalDisplay();
    isInverted = false;
  }
  switch (boost) {
    case 0:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge0_bits);
      break;
    case 1:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge1_bits);
      break;
    case 2:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge2_bits);
      break;
    case 3:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge3_bits);
      break;
    case 4:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge4_bits);
      break;
    case 5:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge5_bits);
      break;
    case 6:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge6_bits);
      break;
    case 7:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge7_bits);
      break;
    case 8:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge8_bits);
      break;
    case 9:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge9_bits);
      break;
    case 10:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge10_bits);
      break;
    case 11:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge11_bits);
      break;
    case 12:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge12_bits);
      break;
    case 13:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge13_bits);
      break;
    case 14:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge14_bits);
      break;
    case 15:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge15_bits);
      break;
    case 16:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge16_bits);
      break;
    case 17:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge17_bits);
      break;
    case 18:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge18_bits);
      break;
    case 19:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge19_bits);
      break;
    case 20:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge20_bits);
      break;
    default:
      display.drawXbm(0, 0, gauge0_width, gauge0_height, gauge0_bits);
  }
  display.display();
  delay(20);
  display.clear();
}

int getBoost() {
  float rboost = analogRead(36);
  //float ResultPSI = (rboost*(.00488)/(.022)+20)/6.89 - atmo; //leave of the /6.89 for kpa
  float ResultPSI = (((rboost / 4095) + 0.04) / 0.004) * 0.145 - atmo; //by 0.145 to calc psi //4096 values on esp32
  /*rBoost = rBoost + 1 ;
    if (rBoost >= 20) {
    rBoost = 0;
    }*/
  return (ResultPSI);
}

float getOilPSI() {
  float psival = analogRead(A1);
  //Serial.print(psival);
  if (psival > 722) {
    return (0);
  }
  if (psival < 257) {
    return (110); //110 swings higher than the gauge goes which will alert the user to something being wrong
  }
  if ((psival <= 722) && (psival > 619)) { //722 = 1.42
    return 174.7 - (psival * 240) / 1000;
  }
  if ((psival <= 619) && (psival > 520)) {
    return 180.2 - (psival * 250) / 1000;
  }
  if ((psival <= 520) && (psival > 411)) {
    return 169.4 - (psival * 230) / 1000;
  }
  if ((psival <= 411) && (psival > 257)) { //257 = 100.68
    return 141.8 - (psival * 160) / 1000;
  }
}
