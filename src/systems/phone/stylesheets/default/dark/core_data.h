/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "core/esp_brookesia_core_type.h"
#include "assets/esp_brookesia_assets.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Home */
#define ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_HOME_BG_COLOR    (0x1A1A1A)
#define ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_HOME_DATA()                                      \
    {                                                                                   \
        .background = {                                                                 \
            .color = ESP_BROOKESIA_STYLE_COLOR(ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_HOME_BG_COLOR),  \
            .wallpaper_image_resource = NULL,                                           \
        },                                                                              \
        .text = {                                                                       \
            .default_fonts_num = 1,                                                    \
            .default_fonts = {                                                          \
                ESP_BROOKESIA_STYLE_FONT_CUSTOM_SIZE(14, &esp_brookesia_font_maison_neue_book_14),    \
            },                                                                          \
        },                                                                              \
        .container = {                                                                  \
            .styles = {                                                                 \
                { .outline_width = 1, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0xeb3b5a), }, \
                { .outline_width = 2, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0xfa8231), }, \
                { .outline_width = 1, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0xf7b731), }, \
                { .outline_width = 2, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0x20bf6b), }, \
                { .outline_width = 1, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0x0fb9b1), }, \
                { .outline_width = 2, .outline_color = ESP_BROOKESIA_STYLE_COLOR(0x2d98da), }, \
            },                                                                          \
        },                                                                              \
    }

/* manager */
#define ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_MANAGER_DATA() \
    {                                                 \
        .app = {                                      \
            .max_running_num = 3,                     \
        },                                            \
        .flags = {                                    \
            .enable_app_save_snapshot = 1,            \
        },                                            \
    }

/* Core */
#define ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_INFO_DATA_NAME    "Default Dark"
#define ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_DATA()                     \
    {                                                             \
        .name = ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_INFO_DATA_NAME,    \
        .screen_size = ESP_BROOKESIA_STYLE_SIZE_RECT_PERCENT(100, 100),  \
        .home = ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_HOME_DATA(),       \
        .manager = ESP_BROOKESIA_PHONE_DEFAULT_DARK_CORE_MANAGER_DATA(), \
    }

#ifdef __cplusplus
}
#endif
