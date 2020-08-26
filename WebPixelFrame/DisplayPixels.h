#pragma once
//#include <NeoPixelBus.h>
#include <NeoPixelBrightnessBus.h>


// make sure to set these panel values to the sizes of yours
const uint8_t PanelWidth = 32;  // 8 pixel x 8 pixel matrix of leds
const uint8_t PanelHeight = 8;
const uint8_t TileWidth = 1;  // laid out in 4 panels x 2 panels mosaic
const uint8_t TileHeight = 1;

const uint16_t PixelCount = PanelWidth * PanelHeight * TileWidth * TileHeight;

// This is for my TopHat:
typedef ColumnMajorAlternating90Layout MyPanelLayout;
// This is for the instructable:
//typedef RowMajorAlternatingLayout MyPanelLayout;
typedef NeoGrbFeature MyPixelColorFeature;

extern NeoPixelBrightnessBus<MyPixelColorFeature, Neo800KbpsMethod> *strip;


static NeoMosaic <MyPanelLayout> mosaic(
    PanelWidth,
    PanelHeight,
    TileWidth,
    TileHeight);

    
class DisplayPixels
{
  public:
    
    DisplayPixels() { 
      strip->SetBrightness( 30 ); /* 0...255*/
    }
    virtual void UpdateAnimation(void) = 0;
    virtual void stop() {}
  protected:
   
};
