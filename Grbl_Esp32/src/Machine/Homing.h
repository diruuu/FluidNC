#pragma once

/*
    Part of Grbl_ESP32
    2021 -  Stefan de Bruijn, Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl_ESP32 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../Configuration/Configurable.h"

namespace Machine {
    class Homing : public Configuration::Configurable {
    public:
        Homing() = default;

        int   _cycle             = -1;
        bool  _square            = false;
        bool  _positiveDirection = true;
        float _mpos              = 0.0f;
        float _feedRate          = 500.0f;
        float _seekRate          = 100.0f;
        float _pulloff           = 1.0f;  // mm
        int   _debounce          = 10;
        float _search_scaler     = 1.1f;
        float _locate_scaler     = 5.0f;

        // Configuration system helpers:
        void validate() const override { Assert(_cycle >= 1, "Cycle has to be defined as >= 1 for homing sequence."); }

        void group(Configuration::HandlerBase& handler) override {
            handler.item("cycle", _cycle);
            handler.item("positive_direction", _positiveDirection);
            handler.item("mpos", _mpos);
            handler.item("feed_rate", _feedRate);
            handler.item("seek_rate", _seekRate);
            handler.item("debounce", _debounce);
            handler.item("pulloff", _pulloff);
            handler.item("square", _square);
            handler.item("search_scaler", _search_scaler);
            handler.item("locate_scaler", _locate_scaler);
        }
    };
}