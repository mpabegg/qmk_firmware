// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "mpabegg.h"

// Layers
enum Layers {
  BASE,
  NUM,
  NAV,
  EXTRA
};

void set_color_for_layer(uint8_t index) {
#ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(layer_state)) {
        case NUM:
            rgb_matrix_set_color(index, RGB_RED);
            break;
        case NAV:
            rgb_matrix_set_color(index, RGB_BLUE);
            break;
        case EXTRA:
            rgb_matrix_set_color(index, RGB_GREEN);
            break;
        default:
            rgb_matrix_set_color(index, RGB_OFF);
    }
#endif
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
        XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
    )
};

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    if (get_highest_layer(layer_state) > 0) {
        /* for (uint8_t i = led_min; i < led_max; i++) { */
        /*     if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) { */
        /*         set_color_for_layer(i); */
        /*     } */
        /* } */
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];
                if (index >= led_min && index < led_max && index != NO_LED ) {
                    if (keymap_key_to_keycode(layer, (keypos_t){col,row}) != KC_TRNS &&
                            keymap_key_to_keycode(layer, (keypos_t){col,row}) != KC_NO) {
                        set_color_for_layer(index);
                    } else {
                        rgb_matrix_set_color(index, RGB_OFF);
                    }
                }
            }
        }
    }
    return false;
}
#endif
