#pragma once

#include <cstdint>
#include <functional>
#include <xcb/xcb.h>

#include "prof.hpp"
#include "Log.hpp"
#include "globals.h"
#include "defenitions.hpp"
#include "structs.hpp"

using namespace std;

// /****************************************
// **** @class @c __window_signals__
// ****************************************/
// class __window_signals__
// {
//     public:
//         umap<uint32_t, umap<int, function<void(uint32_t)>>> _data;

//         template<typename Callback>
//         void conect(uint32_t __w, uint8_t __sig, Callback &&__cb)
//         {
//             _data[__w][__sig] = std::forward<Callback>(__cb);
//         }

//         void emit(uint32_t __w, uint8_t __sig)
//         {
//             AutoTimer t("__window_signals__:" + string(__func__) + ":1");
        
//             auto it = _data[__w].find(__sig);
//             if (it != _data[__w].end())
//             {
//                 it->second(__w);
//             }
//         }

//         void emit(uint32_t __w, uint8_t __sig, uint32_t __w2)
//         {
//             AutoTimer t("__window_signals__:" + string(__func__) + ":2");

//             auto it = _data[__w].find(__sig);
//             if (it != _data[__w].end())
//             {
//                 it->second(__w2);
//             }
//         }

//         void remove(uint32_t __w)
//         {
//             auto it = _data.find(__w);
//             if (it == _data.end()) return;
//             _data.erase(it);
//         }
// };

// /* ***************************************
// **** @class @c __ev_sigs
// ****************************************/
// class __ev_sigs
// {
//     /* Defines   */
//         #define ConnEvSig(__w, __sig, __cb) \
//         do { \
//             ev_sigs->connect(__w, __sig, [this](const vector<uint32_t> &ev) -> void { __cb }); \
//         } while(false)

//     public:
//     /* Variabels */
//         umap<uint32_t, umap<int, function<void(vector<uint32_t>)>>> _data;

//     /* Methods   */
//         template<typename Callback>
//         void connect(uint32_t __w, uint8_t __sig, Callback &&__cb)
//         {
//             _data[__w][__sig] = std::forward<Callback>(__cb);
//         }

//         void emit(uint32_t __w, uint8_t __sig, const vector<uint32_t> &__event_vec)
//         {
//             AutoTimer t("__ev_sigs::emit");

//             auto it = _data[__w].find(__sig);
//             if (it == _data[__w].end()) return;
//             it->second(__event_vec);
//         }

//         void remove(uint32_t __w)
//         {
//             auto it = _data.find(__w);
//             if (it == _data.end()) return;
//             _data.erase(it);
//         }
// };
// static __ev_sigs *ev_sigs(nullptr);


// class client;
// class __window_client_map__
// {
//     public:
//         umap<uint32_t, client *> _data;

//         void connect(uint32_t __window, client *__c)
//         {
//             _data[__window] = __c;
//         }

//         /**

//             @returns @class client from uint32_t

//             */
//         client *retrive(uint32_t __window)
//         {
//             auto it = _data.find(__window);
//             if (it != _data.end())
//             {
//                 return it->second;
//             }
//             return nullptr;

//         }

//         void remove(uint32_t __window)
//         {
//             _data.erase(__window);
//         }

//         void remove_by_value(client* __c)
//         {
//             for (auto it = _data.begin(); it != _data.end();)
//             {
//                 if (it->second == __c)
//                 {
//                     it = _data.erase(it); // Erase and move to next valid iterator
//                 }
//                 else
//                 {
//                     ++it; // Move to next item if current doesn't match
//                 }
//             }

//             loutI << "Deleted window from map, current size:" << _data.size() << '\n';
//         }
// };

// class __c_func_arr__
// {
//     /* Defines   */
//         #define C_SIGNAL_WDATA(__cb, __sig) \
//             signal_manager->client_arr.add_func_to_sig_wdata([this](client *__c, void *__data){__cb}, __sig)

//         #define C_SIGNAL(__cb, __sig) \
//             signal_manager->client_arr.add_func_to_sig([this](client *__c){__cb}, __sig)

//         #define C_EMIT(__c, __sig) \
//             signal_manager->client_arr.send_c_sig(__c, __sig)

//         #define C_EMIT_DATA(__c, __sig, __data) \
//             signal_manager->client_arr.send_c_sig_w_data(__c, __sig, __data)

//     /* Variabels */
//         static constexpr uint8_t ERROR_STATE = make_T_MAX<uint8_t>();

//     /* Methods */
//         constexpr uint8_t sig_to_index__(uint8_t __sig)
//         {
//             switch (__sig)
//             {
//                 case BUTTON_MAXWIN_PRESS:               return 0;
//                 case KILL_SIGNAL:                       return 1;
//                 case FOCUS_CLIENT:                      return 2;
//                 case MOVE_CLIENT_MOUSE:                 return 3;
//                 case TILE_LEFT:                         return 4;
//                 case TILE_RIGHT:                        return 5;
//                 case TILE_DOWN:                         return 6;
//                 case TILE_UP:                           return 7;
//                 case EWMH_MAXWIN_SIGNAL:                return 8;
//                 case RESIZE_CLIENT_BORDER_LEFT:         return 9;
//                 case RESIZE_CLIENT_BORDER_RIGHT:        return 10;
//                 case RESIZE_CLIENT_BORDER_TOP:          return 11;
//                 case RESIZE_CLIENT_BORDER_BOTTOM:       return 12;
//                 case RESIZE_CLIENT_BORDER_TOP_LEFT:     return 13;
//                 case RESIZE_CLIENT_BORDER_TOP_RIGHT:    return 14;
//                 case RESIZE_CLIENT_BORDER_BOTTOM_RIGHT: return 15;
//                 case RESIZE_CLIENT_BORDER_BOTTOM_LEFT:  return 16;

//                 default: return make_T_MAX<uint8_t>();
//             }
//         }

//     public:
//     /* Variabels */
//         FixedArray<function<void(client *c)>, 17> func;

//     /* Methods   */
//         constexpr void send_c_sig(client *__c, int __sig)
//         {
//             uint8_t index = sig_to_index__(__sig);
//             if (index == ERROR_STATE) return;
//             func[index](__c);
//         }

//         template<typename Callback>
//         constexpr void add_func_to_sig(Callback &&__callback, uint8_t __sig)
//         {
//             uint8_t index = sig_to_index__(__sig);
//             if (index == ERROR_STATE) return;
//             func[index] = std::forward<function<void(client *)>>(__callback);
//         }

// };

// /****************************************
// **** @class @c __signal_manager__
// ****************************************/
// class __signal_manager__
// {
//     /* Defines   */
//         #define WS_conn signal_manager->_window_signals.conect
//         #define WS_emit(_window, _event) signal_manager->_window_signals.emit(_window, _event)
//         #define WS_emit_Win(_window, _event, _w2) signal_manager->_window_signals.emit(_window, _event, _w2)
//         #define WS_emit_root(_event, _w2) signal_manager->_window_signals.emit(screen->root, _event, _w2)
//         #define W_callback \
//             [this](uint32_t __window)

//         #define CONN_Win(__window, __event, __callback) \
//             signal_manager->_window_signals.conect(this->__window, __event, W_callback {__callback})

//         #define CONN(__e, __cb, __w) \
//             signal_manager->_window_signals.conect(__w, __e, W_callback {__cb})

//         #define ConnSig(__w, __e, __cb) \
//             signal_manager->_window_signals.conect(__w, __e, [this](uint32_t w) {__cb})

//         #define SIG(__window, __callback, __event) \
//             signal_manager->_window_signals.conect(__window, __event, __callback)

//         #define CONN_root(__event, __callback) \
//             signal_manager->_window_signals.conect(screen->root, __event, __callback)

//         #define CONN_Win2(window, __event, __ref, __callback) \
//             signal_manager->_window_signals.conect(this->window, __event, [ref](uint32_t __window)  __callback)

//         #define CONNECT_window_client(__window, __c) signal_manager->_window_client_map.connect(__window, __c)
//         #define CWC(__window) CONNECT_window_client(this->__window, this)

//         #define C_SIG(__c, __callback, __sig) \
//             signal_manager->client_signals.connect(__c, __sig, [this](client *c) {__callback});

//         #define C_RETRIVE(__window) \
//             signal_manager->_window_client_map.retrive(__window)

//     private:
//     /* Variabels */
//         unordered_map<string, vector<function<void()>>> signals;
//         unordered_map<uint32_t, vector<pair<int, function<void()>>>> client_signal_map;

//     public:
//     /* Variabels */
//         __window_signals__ _window_signals;
//         __window_client_map__ _window_client_map;
//         __c_func_arr__ client_arr;

//     /* Methods   */
//         /* Connect a slot to a signal  */
//         template<typename Callback>
//         void connect(const string &__signal_name, Callback &&callback)
//         {
//             signals[__signal_name].emplace_back(std::forward<Callback>(callback));
//         }

//         /* Connect a slot to a signal */
//         template<typename Callback>
//         void connect_window(uint32_t __window, const string &__function, Callback &&callback)
//         {
//             signals[to_string(__window) + "__" + __function].emplace_back(std::forward<Callback>(callback));
//         }

//         /* Connect a slot to a signal */
//         template<typename Callback>
//         void connect_client(uint32_t __frame_window_id, int __client_signal, Callback &&callback)
//         {
//             client_signal_map[__frame_window_id].emplace_back(__client_signal, std::forward<Callback>(callback));
//         }

//         /* Emit a signal, calling all connected slots */
//         void emit(const string &__signal_name)
//         {
//             auto it = signals.find(__signal_name);
//             if (it != signals.end())
//             {
//                 for (auto& slot : it->second)
//                 {
//                     slot();
//                 }
//             }
//         }

//         /* Emit a signal, calling all connected slots */
//         void emit_window(uint32_t __window, const string &__function)
//         {
//             auto it = signals.find(to_string(__window) + "__" + __function);
//             if (it != signals.end())
//             {
//                 for (auto& slot : it->second)
//                 {
//                     slot();
//                 }
//             }
//         }

//         void emit_client(uint32_t __frame_window_id, int __client_signal)
//         {
//             auto it = client_signal_map.find(__frame_window_id);
//             if (it == client_signal_map.end())
//             {
//                 loutE << "client could not be found frame_window_id:" << __frame_window_id << loutEND;
//                 return;
//             }            

//             for (const auto &pair : it->second)
//             {
//                 if (pair.first == __client_signal)
//                 {
//                     pair.second();
//                 }
//             }
//         }

//         void remove_client(uint32_t __frame_window_id)
//         {
//             client_signal_map.erase(__frame_window_id);
//         }

//         void init()
//         {
//             signals.reserve(40);
//         }
// };
// static __signal_manager__ *signal_manager(nullptr);
