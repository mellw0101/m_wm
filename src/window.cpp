#include "window.h"

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