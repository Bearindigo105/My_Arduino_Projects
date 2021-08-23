/*
 * 8/23/2021 By Muthu Subhash Muthu
 * This is the software for an Attiny85
 * project, a pocket watch!
 *                   
 * Reset  (N/C)  1 -+-U-+-  VCC    (3-5v)
 * I/O 4  (N/C)  2 -|   |-  I/O 2  (SCL)
 * I/O 3  (N/C)  3 -|   |-  I/O 1  (Button)
 * Ground (GND)  4 -+---+-  I/O 0  (SDA)
 * 
 * This work is licensed under the 
 * Creative Commons Attribution 4.0 International License.
 * To view a copy of this license, visit 
 * http://creativecommons.org/licenses/by/4.0/ 
 * or send a letter to Creative Commons, 
 * PO Box 1866, Mountain View, CA 94042, USA.
 */


/*Libraries*/
#include <U8x8lib.h>

/*Pin Declarations*/
int FNPin = 1;

/*Time Declarations*/
int hh = 0; //Set the hour
int mm = 0; //Set the minute
int ss = 0; //Set the second

/*u8x8 Declarations*/
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 2, /* data=*/ 0, /* reset=*/ U8X8_PIN_NONE);

/*The Setup*/
void setup() {

  /*Pin Modes*/
  pinMode(FNPin, INPUT_PULLUP);

  /*Sleep Mode*/
  ADCSRA &= ~(1 << ADEN); //Turn off ADC

  /*u8x8 Shtuf*/
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_inr21_2x4_n);
  u8x8.clearDisplay();
}

/*The Loop*/
void loop() {
  ss++;
  delay(230);
  if (digitalRead(FNPin) == LOW) {
    u8x8.setPowerSave(0);
    u8x8.setCursor(0, 2);
    u8x8.print(hh);
    u8x8.print(":");
    if (mm < 10) {
      u8x8.print("0");
    }
    u8x8.print(mm);
    u8x8.print(":");
    if (ss < 10) {
      u8x8.print("0");
    }
    u8x8.print(ss);
  }
  else {
    u8x8.clearDisplay();
    u8x8.setPowerSave(1);
  }
  if (ss >= 60) {
    ss = 0;
    mm += 1;
    if (mm >= 60) {
      mm = 0;
      hh++;
    }
    if (hh > 12) {
      hh = 1;
    }
  }
}
