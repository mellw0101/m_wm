#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

using namespace std;

#define U32_MAX 0xFFFFFFFF

extern xcb_connection_t *conn;
extern xcb_screen_t *screen;

class client;
extern vector<client *> clients;

static xcb_font_t default_font;

typedef xcb_void_cookie_t VoidC;

#endif/* GLOBALS_H */