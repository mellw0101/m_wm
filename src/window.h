#pragma once

#include <cstdint>
#include <vector>

#include "xcb.hpp"

using namespace std;

typedef struct interndata
{

    uint32_t window = 0;
    string name = "";

} interndata;

#define FONT_INTERNDATA "font_interndata"
#define FONT_GC_INTERNDATA "font_gc_interndata"

class window
{
    private:
        uint32_t _window = 0;
        vector<interndata> _data;

        void get_font(const char* font_name);

    public:
        operator uint32_t();
        operator const uint32_t&() const;

        void map();
        void unmap();
        void raise();
        void change_attribute(uint32_t __mask, const void *__data);
        void change_attribute_checked(uint32_t __mask, const void *__data);
        void draw_acc_16(const char* str, int text_color, int back_color, const char* font_name);
};