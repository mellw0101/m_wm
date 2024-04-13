#include <cstdint>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

#include "globals.h"

/*
    #include "xcb.hpp"
    #include "structs.hpp"
*/

class client;

typedef enum : uint32_t
{
    FONT_STATE = (1 << 0)
}
window_bitstate_t;

class window_t
{
    private:
        uint32_t _state;
        uint32_t _w = 0;
        client *c = nullptr;

    public:
        operator uint32_t() { return _w; }
        operator const uint32_t&() const { return _w; }

        void map()
        {
            xcb_map_window(conn, _w);
            xcb_flush(conn);
        }

};