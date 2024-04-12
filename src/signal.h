#ifndef SIGNAL_H
#define SIGNAL_H

#include <cstdint>
#include <functional>
#include <unordered_map>
#include <xcb/xcb.h>
#include "prof.hpp"
#include "globals.h"

using namespace std;

template<typename T0, typename T1>
using umap = unordered_map<T0, T1>;

/**
    *****************************************
    *****************************************
    **** @class @c __window_signals__
    *****************************************
    ****************************************/
    class __window_signals__
    {
        public:
            umap<uint32_t, umap<int, function<void(uint32_t)>>> _data;

            template<typename Callback>
            void connect(uint32_t __w, uint8_t __sig, Callback &&__cb)
            {
                _data[__w][__sig] = std::forward<Callback>(__cb);
            }

            void emit(uint32_t __w, uint8_t __sig)
            {
                AutoTimer t("__window_signals__:" + string(__func__) + ":1");
            
                auto it = _data[__w].find(__sig);
                if (it != _data[__w].end())
                {
                    it->second(__w);
                    xcb_flush(conn);
                }
            }

            void emit(uint32_t __w, uint8_t __sig, uint32_t __w2)
            {
                AutoTimer t("__window_signals__:" + string(__func__) + ":2");

                auto it = _data[__w].find(__sig);
                if (it != _data[__w].end())
                {
                    it->second(__w2);
                    xcb_flush(conn);
                }
            }

            void remove(uint32_t __w)
            {
                auto it = _data.find(__w);
                if (it == _data.end()) return;
                _data.erase(it);
            }
    };

#endif/* SIGNAL_H */