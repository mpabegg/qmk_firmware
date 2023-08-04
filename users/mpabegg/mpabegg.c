// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

// Layers
enum Layers {
  BASE,
  NUM,
  NAV,
  EXTRA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
         KC_TAB,   KC_Q, KC_W,    KC_E,    KC_R,             KC_T,    KC_Y,   KC_U,            KC_I,    KC_O,   KC_P,    KC_BSLS,
         LCTL_ESC, KC_A, KC_S,    KC_D,    KC_F,             KC_G,    KC_H,   KC_J,            KC_K,    KC_L,   KC_SCLN, KC_QUOT,
         KC_LSFT,  KC_Z, KC_X,    KC_C,    KC_V,             KC_B,    KC_N,   KC_M,            KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                  KC_LGUI, LT(NAV, KC_BSPC), KC_LSFT, KC_ENT, LT(NUM, KC_SPC), KC_RALT
    ),
    [NUM] = LAYOUT_split_3x6_3(
         KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
         XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
         KC_LSFT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
                                     XXXXXXX, MO(EXTRA), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [NAV] = LAYOUT_split_3x6_3(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_U,   KC_WH_D, KC_WH_L, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN,   KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(EXTRA), XXXXXXX
    ),
    [EXTRA] = LAYOUT_split_3x6_3(
        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
    )
};
