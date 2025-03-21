/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "widgets/navigation_bar/esp_brookesia_navigation_bar_type.h"
#include "assets/esp_brookesia_assets.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ESP_BROOKESIA_PHONE_240_135_DARK_NAVIGATION_BAR_DATA()                                              \
    {                                                                                                \
        .main = {                                                                                    \
            .size = ESP_BROOKESIA_STYLE_SIZE_RECT_W_PERCENT(100, 40),                                       \
            .size_min = {},                                                                          \
            .size_max = {},                                                                          \
            .background_color = ESP_BROOKESIA_STYLE_COLOR(0x38393A),                                        \
        },                                                                                           \
        .button = {                                                                                  \
            .icon_size = ESP_BROOKESIA_STYLE_SIZE_SQUARE_PERCENT(60),                                       \
            .icon_images = {                                                                         \
                ESP_BROOKESIA_STYLE_IMAGE_RECOLOR_WHITE(&esp_brookesia_image_middle_navigation_bar_back_32_32),           \
                ESP_BROOKESIA_STYLE_IMAGE_RECOLOR_WHITE(&esp_brookesia_image_middle_navigation_bar_home_32_32),           \
                ESP_BROOKESIA_STYLE_IMAGE_RECOLOR_WHITE(&esp_brookesia_image_middle_navigation_bar_recents_screen_32_32), \
            },                                                                                       \
            .navigate_types = {                                                                      \
                ESP_BROOKESIA_CORE_NAVIGATE_TYPE_BACK,                                                      \
                ESP_BROOKESIA_CORE_NAVIGATE_TYPE_HOME,                                                      \
                ESP_BROOKESIA_CORE_NAVIGATE_TYPE_RECENTS_SCREEN,                                            \
            },                                                                                       \
            .active_background_color = ESP_BROOKESIA_STYLE_COLOR_WITH_OPACIRY(0xFFFFFF, LV_OPA_50),         \
        },                                                                                           \
        .visual_flex = {                                                                             \
            .show_animation_time_ms = 200,                                                           \
            .show_animation_delay_ms = 0,                                                            \
            .show_animation_path_type = ESP_BROOKESIA_LV_ANIM_PATH_TYPE_EASE_OUT,                           \
            .show_duration_ms = 2000,                                                                \
            .hide_animation_time_ms = 200,                                                           \
            .hide_animation_delay_ms = 0,                                                            \
            .hide_animation_path_type = ESP_BROOKESIA_LV_ANIM_PATH_TYPE_EASE_IN,                            \
        },                                                                                           \
        .flags = {                                                                                   \
            .enable_main_size_min = 0,                                                               \
            .enable_main_size_max = 0,                                                               \
        },                                                                                           \
    }

#ifdef __cplusplus
}
#endif
