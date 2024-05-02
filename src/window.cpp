#include "window.h"
#include "xcb.hpp"

window::operator uint32_t()
{
    return _window;
}

window::operator const uint32_t&() const
{
    return _window;
}

void window::map()
{
    XCB::map_window(_window);
}

void window::unmap()
{
    XCB::unmap_window(_window);
}

void window::raise()
{
    XCB::raise_window(_window);
}

void window::change_attribute(uint32_t __mask, const void *__data)
{
    XCB::change_window_attributes(_window, __mask, __data);
}

void window::change_attribute_checked(uint32_t __mask, const void *__data)
{
    XCB::change_window_attributes_checked(_window, __mask, __data);
}

void window::get_font(const char* font_name)
{
    uint32_t font_id = XCB::open_and_get_font_id(font_name);
    _data.push_back({font_id, FONT_INTERNDATA});
}

void window::draw_acc_16(const char* str, int text_color, int back_color, const char* font_name)
{

}