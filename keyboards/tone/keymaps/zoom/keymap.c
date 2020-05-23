/* Copyright 2019 peraneko
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
#include QMK_KEYBOARD_H

// zoom shortcut
// https://support.zoom.us/hc/en-us/articles/205683899-Hot-Keys-and-Keyboard-Shortcuts-for-Zoom

#define ZM_AUDIO  G(S(KC_A)) // Mute/unmute audio
#define ZM_PTT    KC_SPACE   // Push to talk
#define ZM_VIDEO  G(S(KC_V)) // Start/stop video
#define ZM_SCREEN G(S(KC_S)) // Start/stop screen share
#define ZM_VIEW   G(S(KC_W)) // Switch to active speaker view or gallery view
#define ZM_LEAVE  G(KC_W)    // Prompt to End or Leave Meeting
#define ZM_CONTRL C(KC_BSLS) // Toggle the "Always Show meeting controls" options in Settings/Accessibility

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ENTER, ZM_CONTRL, ZM_VIDEO,  ZM_AUDIO,
        ZM_LEAVE, ZM_VIEW,   ZM_SCREEN, ZM_PTT
    )
};

/* Rotary encoder settings */
void encoder_update_user(uint16_t index, bool clockwise) {
   if (clockwise) {
        tap_code(KC__VOLDOWN);    //Rotary encoder clockwise
    } else {
        tap_code(KC__VOLUP);  //Rotary encoder Reverse clockwise
    }
}
