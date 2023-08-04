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
        XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX
    )
};


#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE},
    {1, 8, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN},
    {1, 9, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
    {1, 8, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE},
    {1, 8, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,    // Overrides base layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,     // Overrides other layers
    my_layer4_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_sethsv_noeeprom(HSV_ORANGE);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_layers = my_rgb_layers;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, NUM));
    rgblight_set_layer_state(2, layer_state_cmp(state, NAV));
    rgblight_set_layer_state(3, layer_state_cmp(state, EXTRA));
    return state;
}
#endif
