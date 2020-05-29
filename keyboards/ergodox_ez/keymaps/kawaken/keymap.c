#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,

  // Send keys
  MY_BKAR, // <- : back arrow
  MY_ARRW, // -> : arrow
  MY_DARW, // => : double arrow
  MY_LTEQ, // <= : less than or equal
  MY_GTEQ, // >= : greater than or equal
  MY_DEQL, // == : double equal
  MY_NTEQ, // != : not equal
  MY_CLEQ, // := : cologne equal
  MY_3GRV, // ``` : the phrase "```""
  MY_CDBL, // ```~``` : code block
  MY_BKBL, // `~` : back quote block
  MY_DBSL, // // : double slash
};

#define MC_KANA KC_LANG1          // Mac KANA
#define MC_EISU KC_LANG2          // Mac EISU
#define MC_SCSH SGUI(KC_4)        // Mac Screen Shot selected area
#define MC_SCMV SGUI(KC_5)        // Mac Screen movie
#define MY_ESC  LT(SYMB, KC_ESC)  // Held L1, Tap ESC
#define MY_ENT  LT(MDIA, KC_ENT)  // Held L2, Tap Enter
#define MY_NXTB SGUI(KC_RBRC)     // Move next tab
#define MY_PRTB SGUI(KC_LBRC)     // Move prev tab
#define MY_FLSC G(C(KC_F))        // Full Screen



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | EISU   |   1  |   2  |   3  |   4  |   5  |  6   |           |  5   |   6  |   7  |   8  |   9  |   0  | KANA   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  (   |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   `  |           |  =   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |ScrenS|ScrenM|Alt   | LGui |L1/ESC|                                       |L2/Ent|BkSpc | FlScr| Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |   [  |PrevTb|       |NextTb|   ]    |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Up   |       | Up   |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |Space |   (  | Down |       | Down |   )    |  -   |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    MC_EISU,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_LPRN,
    KC_LCTL,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_GRV,
    MC_SCSH,    MC_SCMV,    KC_LALT,    KC_LGUI,    MY_ESC,
                                                                                    // guide
                                                                KC_LBRC,    MY_PRTB,
                                                                            KC_UP,
                                                    KC_SPC,     KC_LPRN,    KC_DOWN,
    // right hand
    KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       MC_KANA,
    KC_RPRN,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
                KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_EQL,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                            MY_ENT,     KC_BSPC,    MY_FLSC,    KC_LEFT,    KC_RGHT,
                                                                                    // guide
    MY_NXTB,    KC_RBRC,
    KC_UP,
    KC_DOWN,    KC_RPRN,    KC_MINS
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  {   |  [   |  (   | <-   | CODE |           | Back |  ->  |  )   |  ]   |  }   |      |        |
 * |--------+------+------+------+------+------| BLOCK|           | Quote|------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |------|           |------|  ^   |  &   |   *  |      |  :   |   "    |
 * |--------+------+------+------+------+------|   ~  |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | ```  |      |           |  ==  |  !=  |  :=  |  <=  |  >=  |  //  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Next |KANA  |
 *                                 |      |      |      |       |      | Tab  |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_LCBR,    KC_LBRC,    KC_LPRN,    MY_BKAR,    MY_CDBL,
    KC_TRNS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    MY_3GRV,    KC_TILD,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                    // guide
                                                                KC_TRNS,    KC_TRNS,
                                                                            KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,
    // right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    MY_BKBL,    MY_ARRW,    KC_RPRN,    KC_RBRC,    KC_RCBR,    KC_TRNS,    KC_PIPE,
                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_TRNS,    KC_COLN,    KC_DQUO,
    MY_DEQL,    MY_NTEQ,    MY_CLEQ,    MY_LTEQ,    MY_GTEQ,    MY_DBSL,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                    // guide
    KC_TRNS,    KC_TRNS,
    KC_TRNS,
    KC_TRNS,    MY_NXTB,    MC_KANA
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |   6  |  7   |  8   |   9  |   0  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Home | PgUp |PgDown| End  |------|           |------| Left | Down | Up   | Right|   :  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | EISU | Prev |------|       |------|      |      |
 *                                 |      | Tab  |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
    RESET,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_BTN1,    KC_BTN2,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                    // guide
                                                                KC_TRNS,    KC_TRNS,
                                                                            KC_TRNS,
                                                    MC_EISU,    MY_PRTB,    KC_TRNS,
// right hand
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_PIPE,
                KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_COLN,    KC_DQUO,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                                    // guide
    KC_TRNS,    KC_TRNS,
    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case MY_BKAR:
        SEND_STRING ("<-");
        return false;
      case MY_ARRW:
        SEND_STRING ("->");
        return false;
      case MY_DARW:
        SEND_STRING ("=>");
        return false;
      case MY_LTEQ:
        SEND_STRING ("<=");
        return false;
      case MY_GTEQ:
        SEND_STRING (">=");
        return false;
      case MY_DEQL:
        SEND_STRING ("==");
        return false;
      case MY_NTEQ:
        SEND_STRING ("!=");
        return false;
      case MY_CLEQ:
        SEND_STRING (":=");
        return false;
      case MY_3GRV:
        SEND_STRING ("```");
        return false;
      case MY_CDBL:
        SEND_STRING ("```");
        SEND_STRING (SS_LGUI("v"));
        SEND_STRING ("```");
        return false;
      case MY_BKBL:
        SEND_STRING ("`");
        SEND_STRING (SS_LGUI("v"));
        SEND_STRING ("`");
        return false;
      case MY_DBSL:
        SEND_STRING ("//");
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
