#pragma once
#include <ESP8266WiFi.h>
#include "DisplayPixels.h"

#include "C64FontUpper.h"
#include "C64FontLower.h"
#include "font5x7.h"

#define TOTALFONTS    3
#define FONTHEADERSIZE    6
static const unsigned char *fontsPointer[TOTALFONTS]  = {
  font5x7
  , C64FontUpper
  , C64FontLower
};



class DisplayPixelsText : public DisplayPixels {
  public:
    DisplayPixelsText() {
      setFontType(0);
      black.R = black.G = black.B = 0;
      setupStartMillis = millis();
      textStartX = 8;
    }
    void SetText(String text) {
      _text = text;
      textStartX = 8;
    }
    virtual void UpdateAnimation(void);

  private:
    int drawChar(uint8_t x, uint8_t y, uint8_t c, RgbColor color, uint8_t mode);
    int drawString(uint8_t x, uint8_t y, String text, RgbColor color);
    uint8_t setFontType(uint8_t type);
    void pixel(uint8_t x, uint8_t y,  RgbColor color, uint8_t mode);

    String _text;

    RgbColor black;
    long setupStartMillis;
    uint8_t foreColor, drawMode, fontWidth, fontHeight, fontType, fontStartChar, fontTotalChar, cursorX, cursorY;
    uint16_t fontMapWidth;
    int textStartX;
};


