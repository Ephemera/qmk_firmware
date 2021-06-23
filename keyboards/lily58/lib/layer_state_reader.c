
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
// #define L_LOWER (1 << 1)
// #define L_RAISE (1 << 2)
// #define L_ADJUST (1 << 3)
// #define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)
#define L_QWERTY (1 << 1)
// #define L_NAV (1 << 2)
#define L_MEDIA (1 << 3)
#define L_NAV (1 << 4)
#define L_MOUSE (1 << 5)
#define L_SYM (1 << 6)
#define L_NUM (1 << 7)
#define L_FUN (1 << 8)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  /* case L_RAISE: */
  /*   snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise"); */
  /*   break; */
  /* case L_LOWER: */
  /*   snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower"); */
  /*   break; */
  /* case L_ADJUST: */
  /* case L_ADJUST_TRI: */
  /*   snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust"); */
  /*   break; */
  case L_QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;
  case L_NAV:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
    break;
  case L_MOUSE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
    break;
  case L_MEDIA:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Media");
    break;
  case L_NUM:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Num");
    break;
  case L_FUN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Fun");
    break;
  case L_SYM:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Sym");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
