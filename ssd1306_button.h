#ifndef ssd1306_h__
#define ssd1306_h__

#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class ssd1306_btn {
    public:
        bool sbtnState;
        bool sbtnEnable;
        int sbtnWidth;
        int sbtnHeight;
        int sbtnX;
        int sbtnY;
        String sbtnText;
        Adafruit_SSD1306 *sbtnDisplay;

        ssd1306_btn();
        ssd1306_btn(Adafruit_SSD1306 *nDsp, int nX, int nY, int nH, int nW, String nText, bool nState);

        void enable();
        void disable();

        void render();
        void render(bool nState);
        void render(String nText, bool nState);

    private:
        void constructorCore();
};

#endif