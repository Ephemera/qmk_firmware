// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#ifdef TAP_DANCE_ENABLE
enum {
  TD_ESC_SLEEP
};
#endif

#include "manna-harbour_miryoku.h"

enum layers { MIRYOKU_LAYER_NAMES };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]   = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_BASE),
  [NAV]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_NAV),
  [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_MOUSE),
  [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_MEDIA),
  [NUM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_NUM),
  [SYM]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_SYM),
  [FUN]    = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_FUN),
  [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_BUTTON),
  [QWERTY] = U_MACRO_VA_ARGS(LAYOUT_miryoku, MIRYOKU_LAYER_QWERTY)
};

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(SYM, KC_ENT), LT(NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN1, KC_BTN3, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN2),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif


// CUSTOM //


#ifdef TAP_DANCE_ENABLE
// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_SLEEP] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_SLEP)
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  } else {
    return OLED_ROTATION_270;
  }
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    switch (get_highest_layer(layer_state)) {
      case BASE:
        oled_write_ln_P(PSTR("BASE"), false);
        break;
      case NAV:
        oled_write_ln_P(PSTR("NAV"), false);
        break;
      case MOUSE:
        oled_write_ln_P(PSTR("MOUSE"), false);
        break;
      case MEDIA:
        oled_write_ln_P(PSTR("MEDIA"), false);
        break;
      case NUM:
        oled_write_ln_P(PSTR("NUM"), false);
        break;
      case SYM:
        oled_write_ln_P(PSTR("SYM"), false);
        break;
      case FUN:
        oled_write_ln_P(PSTR("FUN"), false);
        break;
      case BUTTON:
        oled_write_ln_P(PSTR("BTTN"), false);
        break;
      case QWERTY:
        oled_write_ln_P(PSTR("QWRT"), false);
        break;
      default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }
  } else {
    oled_write(read_logo(), false);
  }

  return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // oled keylogger??
    // set_keylog(keycode, record);
    // oled timelog
    // set_timelog();
  }
  switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
#ifdef OCEAN_DREAM_ENABLE
            is_calm = (record->event.pressed) ? true : false;
#endif
            break;
    }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
layer_state_t default_layer_state_set_user(layer_state_t state) {
  switch (biton32(state)) {
    case QWERTY:
        rgblight_enable();
        rgblight_setrgb(RGB_WHITE);
        break;

    default: //  for any other layers, or the default layer
        rgblight_disable();
        break;
    }
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case QWERTY:
        rgblight_enable();
        rgblight_setrgb(RGB_WHITE);
        break;

    default: //  for any other layers, or the default layer
        rgblight_disable();
        break;
    }
  return state;
}
#endif // RGBLIGHT_ENABLE

// FIXME:
#ifdef ENCODER_ENABLE
bool encoder_updatae_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }

  return true;
}
#endif // ENCODER_ENABLE

#ifdef COMBO_ENABLE
enum combo_events {
  QWERTY_ON,
  QWERTY_OFF,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qwerty_on[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM qwerty_off[] = {KC_Y, KC_U, COMBO_END};

combo_t key_combos[] = {
  [QWERTY_ON] = COMBO(qwerty_on, KC_NO),
  [QWERTY_OFF] = COMBO(qwerty_off, KC_NO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case QWERTY_ON:
      if (pressed) {
        layer_on(QWERTY);
      }
      break;
    case QWERTY_OFF:
      if (pressed) {
        layer_off(QWERTY);
      }
  }
}

#endif // COMBO_ENABLE
