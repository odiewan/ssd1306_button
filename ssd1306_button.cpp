#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ssd1306_button.h"



uint16_t textWidths[] {
    6,
    12,
    18,
    24
};

uint16_t textHeights[] {
    8,
    16,
    24,
    32
};



//=================================================================================================
void ssd1306_btn::constructorCore() {
    sbtnDisplay = NULL;

    sbtnState = false;
    sbtnEnable = true;
    sbtnTxtSize = 1;
    sbtnX = 0;
    sbtnY = 0;
    sbtnTxtX = sbtnX + XPAD;
    sbtnTxtY = sbtnY + YPAD;
    sbtnText = "btnText";
    calcTextDims();
    sbtnBGColor = SSD1306_WHITE;
    sbtnTextColor = SSD1306_BLACK;

    // sbtnDisplay->setTextColor(sbtnTextColor);
}

//=================================================================================================
ssd1306_btn::ssd1306_btn()
{
    constructorCore();
}

//=================================================================================================
ssd1306_btn::ssd1306_btn(Adafruit_SSD1306 *nDsp, int16_t nX, int16_t nY, int16_t nH, int16_t nW, String nText, bool nState)
{
    constructorCore();
    sbtnDisplay = nDsp;
    sbtnState = nState;
    sbtnText = nText;
    sbtnWidth = nW;
    sbtnHeight = nH;
    sbtnX = nX;
    sbtnY = nY;
    sbtnTxtX = sbtnX + XPAD;
    sbtnTxtY = sbtnY + YPAD;
    calcTextDims();
}

//=================================================================================================
ssd1306_btn::ssd1306_btn(Adafruit_SSD1306 *nDsp, int16_t nX, int16_t nY, uint8_t nTxtSz, String nText, bool nState) {
    constructorCore();
    sbtnDisplay = nDsp;
    sbtnState = nState;
    sbtnText = nText;
    sbtnX = nX;
    sbtnY = nY;
    sbtnTxtX = sbtnX + XPAD;
    sbtnTxtY = sbtnY + YPAD;
    sbtnTxtSize = nTxtSz;
    calcTextDims();
}
//=================================================================================================
void ssd1306_btn::enable() {
    sbtnEnable = true;
}

//=================================================================================================
void ssd1306_btn::disable()  {
    sbtnEnable = false;
}

//=================================================================================================
void ssd1306_btn::render() {
    render(sbtnText, sbtnState);
}

//=================================================================================================
void ssd1306_btn::render(bool nState) {
    render(sbtnText, nState);
}

//=================================================================================================
void ssd1306_btn::renderText() {
    sbtnDisplay->print(sbtnText);
}

//=================================================================================================
void ssd1306_btn::calcTextDims() {
    sbtnTxtLen = sbtnText.length();
    sbtnTextWd = sbtnTxtLen * textWidths[sbtnTxtSize];
    sbtnTextHt = textHeights[sbtnTxtSize];
    sbtnWidth = XPAD + sbtnTextWd + XPAD;
    sbtnHeight = YPAD + sbtnTextHt + YPAD;
}

//=================================================================================================
void ssd1306_btn::render(String nText, bool nState)
{
    sbtnState = nState;
    sbtnText = nText;

    if (sbtnEnable)
    {
        sbtnDisplay->setTextSize(sbtnTxtSize);
        if (sbtnState)
        {
            sbtnDisplay->fillRect(sbtnX, sbtnY, sbtnWidth, sbtnHeight, sbtnTextColor);
            sbtnDisplay->setTextColor(sbtnBGColor); // Draw white text
        }
        else
        {
            sbtnDisplay->fillRect(sbtnX, sbtnY, sbtnWidth, sbtnHeight, sbtnBGColor);
            sbtnDisplay->setTextColor(sbtnTextColor);  // Draw white text
        }
        sbtnDisplay->drawRect(sbtnX, sbtnY, sbtnWidth, sbtnHeight, sbtnBGColor);
        sbtnDisplay->setCursor(sbtnTxtX, sbtnTxtY);  // Start at top-left corner
        renderText();
    }
}