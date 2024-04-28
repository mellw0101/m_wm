#pragma once

#include <cstdint>

#include "xcb.hpp"

class window
{
private:
    uint32_t _window = 0;

public:
    operator uint32_t();

    operator const uint32_t&() const;

    void map();

    void unmap();

    void raise();

    void change_attribute(uint32_t __mask, const void *__data);

    void change_attribute_checked(uint32_t __mask, const void *__data);
};