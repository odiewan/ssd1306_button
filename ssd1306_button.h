#ifndef ssd1306_h__
#define ssd1306_h__

#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define XPAD 2
#define YPAD 1


enum textSizes {
    SZ_0,
    SZ_1,
    SZ_2,
    SZ_3,
    SZ_4,
    NUM_TEXT_SIZES
};

class ssd1306_btn {

    public:
        bool sbtnState;
        bool sbtnEnable;
        int16_t sbtnWidth;
        int16_t sbtnHeight;
        int16_t sbtnX;
        int16_t sbtnY;
        int16_t sbtnTxtX;
        int16_t sbtnTxtY;
        uint16_t sbtnTxtLen;
        int16_t sbtnTextWd;
        int16_t sbtnTextHt;
        uint8_t sbtnTxtSize;
        String sbtnText;
        uint16_t sbtnTextColor;
        uint16_t sbtnBGColor;
        Adafruit_SSD1306 *sbtnDisplay;

        ssd1306_btn();
        ssd1306_btn(Adafruit_SSD1306 *nDsp, int16_t nX, int16_t nY, int16_t nH, int16_t nW, String nText, bool nState);
        ssd1306_btn(Adafruit_SSD1306 *nDsp, int16_t nX, int16_t nY, uint8_t nTxtSz, String nText, bool nState);

        void enable();
        void disable();

        void renderText();

        void render();
        void render(bool nState);
        void render(String nText, bool nState);

    private:
        void constructorCore();
        void calcTextDims();
};

#endif