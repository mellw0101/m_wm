#include "signal.h"

/**
*****************************************
**** @class @c __window_signals__
****************************************/

    void __window_signals__::emit(uint32_t __w, uint8_t __sig)
    {
        AutoTimer t("__window_signals__:" + string(__func__) + ":1");
    
        auto it = _data[__w].find(__sig);
        if (it != _data[__w].end())
        {
            it->second(__w);
        }
    }

    void __window_signals__::emit(uint32_t __w, uint8_t __sig, uint32_t __w2)
    {
        AutoTimer t("__window_signals__:" + string(__func__) + ":2");

        auto it = _data[__w].find(__sig);
        if (it != _data[__w].end())
        {
            it->second(__w2);
        }
    }

    void __window_signals__::remove(uint32_t __w)
    {
        auto it = _data.find(__w);
        if (it == _data.end()) return;
        _data.erase(it);
    }

//
