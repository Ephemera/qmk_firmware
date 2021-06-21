#pragma once

#define XXX KC_NO
#define SSD1306OLED

#define LAYOUT_miryoku(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,\
KC_TAB, K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, KC_BSPC,\
KC_LCTL, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, KC_QUOT,\
KC_LSFT, K20, K21, K22, K23, K24, TG(QWERTY),      XXX, K25, K26, K27, K28, K29, KC_RSFT,\
               XXX, K32, K33, K34,      K35, K36, K37, XXX\
)

