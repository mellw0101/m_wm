// #pragma once

// #include <xcb/xcb.h>
// #include <functional>

// #include "prof.hpp"
// #include "window.h"

// class Entry
// {
//     public:
//     /* Constructor */
//         Entry() {}

//     /* Variabels */
//         window window;
//         bool menu = false;
//         string name;
//         function<void()> action;

//     /* Methods */
//         void make_window(uint32_t __parent, int16_t __x, int16_t __y, uint16_t __width, uint16_t __height)
//         {
//             AutoTimer t("Entry:make_window");

//             window.create_window
//             (
//                 __parent,
//                 __x,
//                 __y,
//                 __width,
//                 __height,
//                 BLACK,
//                 BUTTON_EVENT_MASK,
//                 MAP
//             );

//             ConnSig(window, XCB_EXPOSE,
//                 window.draw_acc(name.c_str());
//             );

//             ConnSig(window, L_MOUSE_BUTTON_EVENT,
//                 Emit(window.parent(), HIDE_CONTEXT_MENU);
//                 if (action != nullptr) action();
//             );

//             ConnSig(window, R_MOUSE_BUTTON_EVENT,
//                 Emit(window.parent(), HIDE_CONTEXT_MENU);
//             );
            
//             ConnSig(window, XCB_ENTER_NOTIFY,
//                 window.change_backround_color(WHITE);
//             );

//             ConnSig(window, XCB_LEAVE_NOTIFY,
//                 window.change_backround_color(BLACK);
//             );

//             window.grab_button
//             ({
//                 {L_MOUSE_BUTTON, XCB_BUTTON_MASK_ANY}
//             });
//         }
// };

/**
*****************************************
*****************************************
**** @class @c context_menu
*****************************************
****************************************/
// class context_menu
// {
//     private:
//     /* Variabels */
//         int16_t  _x = 0, _y = 0;
//         uint32_t _width = 120, _height = 20;

//         int border_size = 1;
//         vector<Entry> entries;

//     /* Methods   */
//         void create_dialog_win__()
//         {
//             context_window.create_window
//             (
//                 screen->root,
//                 0,
//                 0,
//                 _width,
//                 _height,
//                 DARK_GREY,
//                 XCB_EVENT_MASK_FOCUS_CHANGE | XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY | XCB_EVENT_MASK_POINTER_MOTION,
//                 RAISE
//             );

//             ConnSig(context_window, L_MOUSE_BUTTON_EVENT,
//                 hide__();
//             );
//         }

//         void hide__()
//         {
//             context_window.unmap();
//             context_window.kill();

//             for (int i = 0; i < entries.size(); ++i)
//             {
//                 entries[i].window.kill();
//             }
//         }
        
//         void make_entries__()
//         {
//             for (int i(0); i < entries.size(); ++i)
//             {
//                 entries[i].make_window
//                 (
//                     context_window,
//                     0,
//                     (_height * i),
//                     _width,
//                     _height
//                 );
//                 Emit(entries[i].window, XCB_EXPOSE);
//             }
//         }
    
//     public:
//     /* Variabels */
//         window context_window;
    
//     /* Methods   */
//         void show()
//         {
//             _x = m_pointer->x();
//             _y = m_pointer->y();
            
//             for (int i(0), max_len(0); i < entries.size(); ++i)
//             {
//                 if (entries[i].name.length() > max_len)
//                 {
//                     max_len = entries[i].name.length();
//                     _width = ((max_len + 2) * DEFAULT_FONT_WIDTH);
//                 }
//             }
//             uint16_t new_height = (entries.size() * _height);

//             if (_y + new_height > screen->height_in_pixels)
//             {
//                 _y = ( screen->height_in_pixels - new_height );
//             }
//             if (_x + _width > screen->width_in_pixels)
//             {
//                 _x = ( screen->width_in_pixels - _width );
//             }

//             context_window.x_y_width_height((_x - BORDER_SIZE), (_y - BORDER_SIZE), _width, new_height);
//             context_window.map();
//             context_window.focus();
//             ConnSig(context_window, HIDE_CONTEXT_MENU,
//                 hide__();
//             );
//             make_entries__();
//         }
        
//         void add_entry(string name, function<void()> action)
//         {
//             Entry entry;
//             entry.name = name;
//             entry.action = action;
//             entries.push_back(entry);
//         }

//     context_menu()
//     {
//         create_dialog_win__();
//     }
// };