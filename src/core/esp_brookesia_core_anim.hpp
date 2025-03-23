/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <memory>

#include "lvgl.h"
#include "esp_brookesia_core_app.hpp"

class ESP_Brookesia_CoreAnim {
public:
    ESP_Brookesia_CoreAnim();
    ~ESP_Brookesia_CoreAnim();

    void reset(void);
    bool processRun(ESP_Brookesia_CoreApp *app, ESP_Brookesia_LvAnimationActionType_t action, ESP_Brookesia_LvAnimationPathType_t path);

private:
    ESP_Brookesia_LvAnimationActionType_t anim_action = ESP_Brookesia_LvAnimationActionType_t::ESP_BROOKESIA_LV_ANIM_ACT_NONE;
    ESP_Brookesia_LvAnimationPathType_t anim_path = ESP_Brookesia_LvAnimationPathType_t::ESP_BROOKESIA_LV_ANIM_PATH_TYPE_LINEAR;

    static void opaScaleAnim(void * obj, int32_t v);
    static void setXposAnim(void * obj, int32_t v);
    static void setYposAnim(void * obj, int32_t v);

};
