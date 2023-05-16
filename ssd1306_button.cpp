#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ssd1306_button.h"

//=================================================================================================
void ssd1306_btn::constructorCore() {
    sbtnDisplay = NULL;


    sbtnState = false;
    sbtnEnable = true;
    sbtnWidth = 24;
    sbtnHeight = 8;
    sbtnX = 0;
    sbtnY = 0;
    sbtnText = "btnText";
}

//=================================================================================================
ssd1306_btn::ssd1306_btn()
{
    constructorCore();
}

//=================================================================================================
ssd1306_btn::ssd1306_btn(Adafruit_SSD1306 *nDsp, int nX, int nY, int nH, int nW, String nText, bool nState)
{
    constructorCore();
    sbtnDisplay = nDsp;
    sbtnState = nState;
    sbtnWidth = nW;
    sbtnHeight = nH;
    sbtnX = nX;
    sbtnY = nY;
    sbtnText = nText;
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
void ssd1306_btn::render(String nText, bool nState) {
    sbtnState = nState;
    sbtnText = nText;

    if(sbtnEnable) {
        if (sbtnState)
        {
            sbtnDisplay->fillRect(sbtnX, sbtnY, sbtnDisplay->width() - 1, sbtnHeight, SSD1306_WHITE);
            sbtnDisplay->setTextColor(SSD1306_INVERSE); // Draw white text
            sbtnDisplay->setCursor(sbtnX, sbtnY);       // Start at top-left corner
            sbtnDisplay->print(nText);
        }
        else
        {
            sbtnDisplay->drawRect(sbtnX, sbtnY, sbtnDisplay->width() - 1, sbtnHeight, SSD1306_WHITE);
            sbtnDisplay->setTextColor(SSD1306_WHITE); // Draw white text
            sbtnDisplay->setCursor(sbtnX, sbtnY);         // Start at top-left corner
            sbtnDisplay->print(nText);
        }
    }
}