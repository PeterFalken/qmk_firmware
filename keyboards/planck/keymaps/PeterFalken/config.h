/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

// Fix warning - "Attached USB accessory uses too much power."
#ifndef USB_MAX_POWER_CONSUMPTION
    #define USB_MAX_POWER_CONSUMPTION 100
#endif

// Fix unresponsive on wake from sleep
#ifndef USB_SUSPEND_WAKEUP_DELAY
    #define USB_SUSPEND_WAKEUP_DELAY 200
#endif

// Space optimizations - 01
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Remove predefined values
#undef RGB_DISABLE_TIMEOUT
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#undef RGB_MATRIX_STARTUP_MODE
#undef RGB_MATRIX_STARTUP_HUE
#undef RGB_MATRIX_STARTUP_SAT
#undef RGB_MATRIX_STARTUP_VAL

// Redefine values
// Number of milliseconds to wait until RGB automatically turns off
#define RGB_DISABLE_TIMEOUT 5000
// Limits maximum brightness of LEDs to 120 out of 255
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
// Sets the default startup mode
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_active_keys
// Sets the default hue, saturation & brightness values
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 0
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS/2


#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
