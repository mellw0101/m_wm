#pragma once

#include "globals.h"

#include <cstdint>
#include "defenitions.hpp"
#include <cstdlib>
#include <map>
#include <xcb/xcb.h>
#include <xcb/xcb_keysyms.h>

using namespace std;

class __key_codes__
{
    public:
    // constructor and destructor.
        __key_codes__()
        : keysyms(nullptr) {}

        ~__key_codes__();

    /* Methods */
        void init();

        constexpr uint8_t char_to_keycode__(int8_t c);

    // variabels.
        xcb_keycode_t
            a{}, b{}, c{}, d{}, e{}, f{}, g{}, h{}, i{}, j{}, k{}, l{}, m{},
            n{}, o{}, p{}, q{}, r{}, s{}, t{}, u{}, v{}, w{}, x{}, y{}, z{},
            
            space_bar{}, enter{},

            f11{}, n_1{}, n_2{}, n_3{}, n_4{}, n_5{}, r_arrow{},
            l_arrow{}, u_arrow{}, d_arrow{}, tab{}, _delete{},
            super_l{}, minus{}, underscore{};

    private:
    // variabels.
        xcb_key_symbols_t * keysyms;
};