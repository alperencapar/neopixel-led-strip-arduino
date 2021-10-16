#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN        3  // led strip connection pin on arduino
#define NUMPIXELS 60 // Toplam Led Sayısı


uint8_t LEDCOUNT = 20;
// may vary on the strip type
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_BRG + NEO_KHZ400);


void setup() {

  //pixels.begin(); // Starting neopixel objecet  (must)
  strip.begin();
  strip.setBrightness(60);
  strip.clear();
  strip.show();
  

}

void loop() {

  uint32_t red = strip.Color(255, 0, 0);
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t light_blue = strip.Color(0, 110, 162);
  uint32_t indigo = strip.Color(116, 45, 230);
  uint32_t aqua = strip.Color(0,255,255);
  uint32_t purple = strip.Color(128,0,128);
  uint32_t magenta = strip.Color(255,0,255);
  uint32_t orange = strip.Color(255, 102, 0);
  uint32_t yellow = strip.Color(245, 184, 3);
  uint32_t silver = strip.Color(192,192,192);
  uint32_t white = strip.Color(255,255,255);


  
  //pixels.clear(); // makes all pixels offline(every single one of led on the neopixel strip)

//below this line, there are few animation. for use of animations, user must be uncomment animations and send colors
//oneColor(purple, 50);

rainbow(5);

//halfWayThere(purple , aqua, 50);
//halfWayThere(purple , red, 50);
//halfWayThere(purple , green, 50);
//quickTransition(purple , aqua, 50);
//flash(aqua, blue);
//twoColorMix(yellow,green);
//shootingStar(magenta);
//starLoop(magenta);


}

//just show one color only
void oneColor(uint32_t color, uint16_t wait){

  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    
  }
  brightness(20);
  
}


void rainbow(uint16_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }

}

//alternate between two colors(all the way up and down)
 void quickTransition (uint32_t color, uint32_t colorTwo, uint16_t wait){

  for (int i = 0; i <=strip.numPixels(); i++){
        strip.setPixelColor(i, color);
        //strip.setPixelColor(strip.numPixels() - i , colorTwo);
        strip.show();
        delay(wait);
}

for (int i=strip.numPixels(); i<=strip.numPixels(); i--){
        strip.setPixelColor(i, colorTwo);
        strip.show();
        delay(wait);
  }
   delay(wait*100);

}


//two colors meet middle of neopixel strip
void halfWayThere(uint32_t color, uint32_t colorTwo, uint8_t wait){
  for (int i = 0; i <=(LEDCOUNT/2-1); i++){
        strip.setPixelColor(i, color);
        strip.show();
        delay(wait);
}

delay(wait*2);

  for (int i = ceil(LEDCOUNT/2); i <=strip.numPixels(); i++){
        strip.setPixelColor(i, colorTwo);
        strip.show();
        delay(wait);
  }
  
  brightness(80);
  for (int i = LEDCOUNT; i <=strip.numPixels(); i--){
    
      strip.setPixelColor(i, color);
      strip.show();
      delay(wait);
  }
  
  delay(wait);

  for (int i = LEDCOUNT/2-1; i <=strip.numPixels(); i--){
        strip.setPixelColor(i, colorTwo);
        strip.show();
        delay(wait);
  }
  brightness(80);

  delay(wait*55);

}




uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


void brightness(uint16_t lumo){

  for(int i = lumo; i <=200; i+=10){
    strip.setBrightness(i);
    strip.show();
    delay(150);
  }
  delay(100);
  for(int i=200; i>=lumo; i-=10){
    strip.setBrightness(i);
    strip.show();
    delay(150);
  }
  
}

//flashing the strip(with brightness)
void flash(uint32_t color, uint32_t colorTwo){

  for (int i=0; i<=LEDCOUNT; i++){
    if(i%2 == 0){
      strip.setPixelColor(i, color);
      strip.show();
      delay(50);
    }
    if(i%2 == 1){
      strip.setPixelColor(i, colorTwo);
      strip.show();
      delay(50);
    }
  }

   for (int i=0; i<=LEDCOUNT; i++){
    if(i%2 == 0){
      strip.setBrightness(150);
      strip.show();
      delay(50);
      
    }
    if(i%2 == 1){
      strip.setBrightness(60);
      strip.show();
      delay(50);
    }
    delay(50);
  }

  
}

//mix two colors one by one
void twoColorMix(uint32_t color, uint32_t colorTwo){
  for (int i=0; i<=LEDCOUNT; i++){
    if(i%2 == 0){
      strip.setPixelColor(i, color);
      strip.show();

    }
    if(i%2 == 1){
      strip.setPixelColor(i, colorTwo);
      strip.show();
    }
    delay(50);
  }
}


void shootingStar(uint32_t color){
int i;
  for (i=0; i<=LEDCOUNT; i++){
  strip.clear();
    strip.setPixelColor(i, color);
    strip.setPixelColor(i+1, color);
    strip.setPixelColor(i+2, color);
    strip.show();
    delay(20);
    if(i == LEDCOUNT){
      i = LEDCOUNT;
      break;
    }
  }
delay(25);
if(i == LEDCOUNT){
    shootingStar(color);
  }
}


void starLoop(uint32_t color){
int i;
  for (i=0; i<=LEDCOUNT; i++){
  strip.clear();
    strip.setPixelColor(i, color);
    strip.setPixelColor(i+1, color);
    strip.show();
    delay(50);

  }
delay(25);

for (i=LEDCOUNT; i<=LEDCOUNT; i--){
  strip.clear();
    strip.setPixelColor(i, color);
    strip.setPixelColor(i+1, color);
    strip.setPixelColor(i+2, color);
    strip.show();
    delay(50);
    if(i == 1){
      i = 1;
      break;
    }
  }
  delay(25);
  if(i == 1){
    starLoop(color);
  }
    
}
