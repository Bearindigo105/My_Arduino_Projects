#include <ss_oled.h>

int rc;
char hh[32];
char mm[32];
int hr = 3;
int minu = 58;
int sec = 55;

SSOLED ssoled;

void setup() {
  rc = oledInit(&ssoled, OLED_128x64, 0x3c, 0, 0, 0, 2, 0, -1, 400000L);
  
}

void loop() {
  sprintf(hh, "%d", (int)hr);
  sprintf(mm, "%d", (int)minu);

  if (true) {
    oledWriteString(&ssoled, 0, 12, 0, (char*)"00:00", FONT_12x16, 0, 1);
    if (hr > 9) {
      oledWriteString(&ssoled, 0, 12, 0, hh, FONT_12x16, 0, 1);
    } else {
      oledWriteString(&ssoled, 0, 24, 0, hh, FONT_12x16, 0, 1);
    }
    if (minu > 9) {
      oledWriteString(&ssoled, 0, 48, 0, mm, FONT_12x16, 0, 1);
    } else {
      oledWriteString(&ssoled, 0, 36, 0, mm, FONT_12x16, 0, 1);
    }
  }
  delay(1000);
  sec++;
  if (sec >= 60) {
    sec = 0;
    minu++;
  }
  if (minu >= 60) {
    minu = 0;
    hr++;
  }
  if (hr > 12) {
    hr = 0;
  }
}
