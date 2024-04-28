// #include "signal.h"

// /**
// *****************************************
// **** @class @c __window_signals__
// ****************************************/

//     template<typename Callback>
//     void __window_signals__::conect(uint32_t __w, uint8_t __sig, Callback &&__cb)
//     {
//         _data[__w][__sig] = std::forward<Callback>(__cb);
//     }

//     void __window_signals__::emit(uint32_t __w, uint8_t __sig)
//     {
//         AutoTimer t("__window_signals__:" + string(__func__) + ":1");
    
//         auto it = _data[__w].find(__sig);
//         if (it != _data[__w].end())
//         {
//             it->second(__w);
//         }
//     }

//     void __window_signals__::emit(uint32_t __w, uint8_t __sig, uint32_t __w2)
//     {
//         AutoTimer t("__window_signals__:" + string(__func__) + ":2");

//         auto it = _data[__w].find(__sig);
//         if (it != _data[__w].end())
//         {
//             it->second(__w2);
//         }
//     }

//     void __window_signals__::remove(uint32_t __w)
//     {
//         auto it = _data.find(__w);
//         if (it == _data.end()) return;
//         _data.erase(it);
//     }

// //

// /**
// *****************************************
// **** @class @c __ev_sigs
// ****************************************/

//     template<typename Callback>
//     void __ev_sigs::connect(uint32_t __w, uint8_t __sig, Callback &&__cb)
//     {
//         _data[__w][__sig] = std::forward<Callback>(__cb);
//     }

//     void __ev_sigs::emit(uint32_t __w, uint8_t __sig, const vector<uint32_t> &__event_vec)
//     {
//         AutoTimer t("__ev_sigs::emit");

//         auto it = _data[__w].find(__sig);
//         if (it == _data[__w].end()) return;
//         it->second(__event_vec);
//     }

//     void __ev_sigs::remove(uint32_t __w)
//     {
//         auto it = _data.find(__w);
//         if (it == _data.end()) return;
//         _data.erase(it);
//     }

// //

// /**
// *****************************************
// **** @class @c __window_client_map__ 
// ****************************************/

//     void __window_client_map__::connect(uint32_t window, client *c)
//     {
//         _data[window] = c;
//     }

//     client *__window_client_map__::retrive(uint32_t window)
//     {
//         auto it = _data.find(window);
//         if (it != _data.end())
//         {
//             return it->second;
//         }
//         return nullptr;

//     }

//     void __window_client_map__::remove(uint32_t window)
//     {
//         _data.erase(window);
//     }

//     void __window_client_map__::remove_by_value(client* c)
//     {
//         for (auto it = _data.begin(); it != _data.end();)
//         {
//             if (it->second == c)
//             {
//                 // Erase and move to next valid iterator
//                 it = _data.erase(it);
//             }
//             else
//             {
//                 // Move to next item if current doesn't match
//                 ++it;
//             }
//         }

//         loutI << "Deleted window from map, current size:" << _data.size() << '\n';
//     }

// //

// /**
// *****************************************
// **** @class @c __c_func_arr__ 
// ****************************************/

//     uint8_t __c_func_arr__::sig_to_index__(uint8_t __sig)
//     {
//         switch (__sig)
//         {
//             case BUTTON_MAXWIN_PRESS:               return 0;
//             case KILL_SIGNAL:                       return 1;
//             case FOCUS_CLIENT:                      return 2;
//             case MOVE_CLIENT_MOUSE:                 return 3;
//             case TILE_LEFT:                         return 4;
//             case TILE_RIGHT:                        return 5;
//             case TILE_DOWN:                         return 6;
//             case TILE_UP:                           return 7;
//             case EWMH_MAXWIN_SIGNAL:                return 8;
//             case RESIZE_CLIENT_BORDER_LEFT:         return 9;
//             case RESIZE_CLIENT_BORDER_RIGHT:        return 10;
//             case RESIZE_CLIENT_BORDER_TOP:          return 11;
//             case RESIZE_CLIENT_BORDER_BOTTOM:       return 12;
//             case RESIZE_CLIENT_BORDER_TOP_LEFT:     return 13;
//             case RESIZE_CLIENT_BORDER_TOP_RIGHT:    return 14;
//             case RESIZE_CLIENT_BORDER_BOTTOM_RIGHT: return 15;
//             case RESIZE_CLIENT_BORDER_BOTTOM_LEFT:  return 16;

//             default: return make_T_MAX<uint8_t>();
//         }
//     }

//     void __c_func_arr__::send_c_sig(client *__c, int __sig)
//     {
//         uint8_t index = sig_to_index__(__sig);
//         if (index == ERROR_STATE) return;
//         func[index](__c);
//     }

//     template<typename Callback>
//     void __c_func_arr__::add_func_to_sig(Callback &&__callback, uint8_t __sig)
//     {
//         uint8_t index = sig_to_index__(__sig);
//         if (index == ERROR_STATE) return;
//         func[index] = std::forward<function<void(client *)>>(__callback);
//     }

// //