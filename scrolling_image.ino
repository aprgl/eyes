/*
 * ------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 42.5):
 * Shaun Kinetic (@aprgl) made this mess. As long as you retain
 * this notice, you can do whatever you want with it. If we
 * meet someday, and you think this stuff is worth it, you can
 * buy me a coffee in return.
 * ------------------------------------------------------------
 */

#include "TFT_eSPI.h"
#include "bright_eye.h"
//#include "crows_have_eyes.h" //too scary for a party
#include "colorful_crow.h"
#include "background_eye.h"
#include "universe.h"
#include "laser.h"
#include "black_hole.h"
#include "button_eye.h"
#include "moon.h"

TFT_eSPI tft= TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);

int imageW=300;
int imageH=300;

//ESP32 requires 220x220
int screenW=240;
int screenH=240;
int m=imageW;

int start=1;
uint16_t imageS[48400]={0}; // edit this screenW * screen H

void bkg_eye(){
  tft.pushImage(0,0,240,240,background_eye);
}

void setup() {
  tft.init();
  tft.setRotation(2);
  tft.setSwapBytes(true);
  bkg_eye();
}

//Debugging Call
void test(){
  move_eye(0,0);
  delay(500);
  move_eye(0,60);
  delay(500);
  move_eye(60,0);
  delay(500);
  move_eye(60,60);
  delay(500);
  tft.pushImage(0,0,240,240,colorful_crow); 
  delay(3000);
  tft.pushImage(0,0,240,240,black_hole);
  delay(3000);
  tft.pushImage(0,0,240,240,button_eye);
  delay(3000);
  tft.pushImage(0,0,240,240,moon);
  delay(3000);
  tft.pushImage(0,0,240,240,laser);
  delay(3000);
  tft.pushImage(0,0,240,240,universe);
  delay(3000);
  bkg_eye();
  for(int i=0; i< 40; i++){
    tft.fillCircle(120,120,40+i, TFT_BLACK);
    delay(25);
  }
  delay(3000);
}

void special(){
  int special_id = random(6);
  switch(special_id){
    case 0:
      tft.pushImage(0,0,240,240,colorful_crow);
      break;
    case 1:
      tft.pushImage(0,0,240,240,black_hole);
      break;
    case 2:
      tft.pushImage(0,0,240,240,button_eye);
      break;
    case 3:
      tft.pushImage(0,0,240,240,moon);
      break;
    case 4:
      tft.pushImage(0,0,240,240,laser);
      break;
    case 5:
      tft.pushImage(0,0,240,240,universe);
      break;
    default:
      tft.pushImage(0,0,240,240,universe);
      break;
  }  
  delay(10000);
}

void eye_blink(){
  tft.fillTriangle(0, 0, 0, 240, 100, 0, TFT_DARKGREY);
  delay(20);
  tft.fillTriangle(0, 0, 0, 240, 200, 0, TFT_DARKGREY);
  delay(20);
  tft.fillScreen(TFT_DARKGREY);
  delay(200);
}

void loop() {
  //test();
  eye_blink();
  nominal();
}

int pos=0;
void move_eye(int x, int y){
    pos=x+imageW*y; // position = x + width*y (this gives our place in the array)
    start=pos;      // start there
    m=screenW+pos;
    for(int i=0;i<screenW*screenH;i++){
      if(start%m==0){
        start=start+(imageW-screenW);
        m=m+imageW;
      }
      imageS[i]=bright_eye[start];
      start++;
    }
    tft.pushImage(10,10,screenW,screenH,imageS);
}

void nominal() {
  while(1){
    for(int special_loop=0; special_loop<random(20,40); special_loop++){    // (avg 4min to 8min )
      eye_blink();
      bkg_eye();
      for(int i=0; i<random(3,15); i++){                                   // (.6-45, avg 12 sec)
        move_eye(random(60),random(60));
        delay(random(200,3000));
      }
    }
    eye_blink();
    special();
  }
}
