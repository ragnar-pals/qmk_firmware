/* Copyright 2020 tominabox1
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
#include "keymap_icelandic.h"

enum layers {
  _QWERTY,
  _QWERTY_IS,
  _SYM,
  _FUNCTION,
  _NAV,
  _NUM,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_IS,
};

#define SYM MO(_SYM)
#define FUN LT(_FUNCTION, KC_ENT)
#define MYTAB LT(_NAV, KC_TAB)
#define MYNAV LT(_NAV, KC_DEL)
#define MYNUM LT(_NUM, KC_BSPC)

// This must be here if we have TAB_DANCING enabled
qk_tap_dance_action_t tap_dance_actions[] = {
};


void set_color(int r, int g, int b) {
	rgb_matrix_set_color(5,  r, g, b);
	rgb_matrix_set_color(6,  r, g, b);
	rgb_matrix_set_color(17, r, g, b);
	rgb_matrix_set_color(18, r, g, b);
	rgb_matrix_set_color(29, r, g, b);
	rgb_matrix_set_color(30, r, g, b);
	rgb_matrix_set_color(41, r, g, b);
}

void rgb_matrix_indicators_user(void) {

	switch (get_highest_layer(layer_state)) {
		case _QWERTY_IS:
			set_color(128, 64, 0);
			break;
        case _SYM:
			set_color(106, 128, 0);
			break;
		case _FUNCTION:
			set_color(50, 10, 20);
			break;
		case _NAV:
			set_color(39, 25, 77);
			break;
        case _NUM:
			set_color(0, 40, 50);
			break;
        case _ADJUST:
			set_color(193, 47, 32);
			break;
	}
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) == _QWERTY_IS) {
        set_color(128, 64, 0);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//qwerty base layer ok
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    MYTAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    _______, _______,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  _______, KC_RSPC,
    KC_LCTL, KC_LALT, KC_LGUI, SYM,     MYNAV,       KC_SPC,       MYNUM,   FUN,     KC_RGUI, KC_LALT, RCTL_T(KC_ENT)
),

//qwerty base layer ok
[_QWERTY_IS] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    IS_ETH,
    MYTAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    IS_AE, IS_ACUT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  IS_THRN, IS_LABK,
    KC_LCTL, KC_LALT, KC_LGUI, SYM,     MYNAV,       KC_SPC,       MYNUM,   FUN,     KC_RGUI, KC_LALT, RCTL_T(KC_ENT)
),

//navigation and utility layer ok
[_NAV] = LAYOUT_planck_mit(
    KC_TRNS, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_VOLU,
    _______, _______, _______, _______, IS_QUOT, _______, KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_VOLD,
    KC_TRNS, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, _______, _______, KC_BSPC, KC_DEL,  _______, _______, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,     _______,      MYNUM, _______, KC_MPRV, KC_MPLY, KC_MNXT
),

//symbols layer ok
[_SYM] = LAYOUT_planck_mit(
    IS_DQUO, IS_EXLM, IS_AT,   IS_HASH, IS_DLR,  IS_PERC, IS_DIAE, IS_AMPR, IS_ASTR, IS_LPRN, IS_RPRN, IS_COLN,
    IS_QUOT, IS_PIPE, _______, _______, _______, _______, _______, IS_PLUS, IS_UNDS, IS_LBRC, IS_RBRC, IS_SCLN,
    KC_TRNS, IS_BSLS, _______, _______, _______, _______, _______, IS_EQL,  IS_MINS, IS_LCBR, IS_RCBR, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,     _______,      _______, _______, KC_TRNS, KC_TRNS, KC_TRNS
),

//numbers layer ok
[_NUM] = LAYOUT_planck_mit(
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    IS_MINS,
    _______, IS_ASTR, IS_SLSH, IS_MINS, IS_PLUS, _______, _______, KC_4,    KC_5,    KC_6,    IS_COMM, IS_PLUS,
    KC_TRNS, IS_PERC, IS_EQL,  IS_DOT,  IS_COMM, _______, _______, KC_1,    KC_2,    KC_3,    IS_DOT,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, MYNAV,       _______,      _______, KC_0,    KC_0,    KC_COMM, KC_ENT
),

//FN layer 
[_FUNCTION] = LAYOUT_planck_mit(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_INS,
    KC_PSCR, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_PAUS,
    KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, _______,     _______,      _______, _______, KC_TRNS, KC_TRNS, KC_TRNS
),

// adjust layer ok
[_ADJUST] = LAYOUT_planck_mit(
    RESET,   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______,
    KC_CAPS, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, QWERTY,  QWERTY_IS,  _______, _______, _______,
    _______, MI_ON,   MI_OFF,  MI_TOG,  MU_ON,   MU_OFF,  MU_TOG,  MU_MOD,  AU_ON,   AU_OFF,  _______, _______,
    RGB_TOG, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case QWERTY_IS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_IS);
      }
      return false;
   }
   return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}

