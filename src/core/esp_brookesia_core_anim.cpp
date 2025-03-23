/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <algorithm>
#include "esp_brookesia_core_utils.h"
#include "esp_brookesia_core_anim.hpp"

using namespace std;

ESP_Brookesia_CoreAnim::ESP_Brookesia_CoreAnim()
{
}

ESP_Brookesia_CoreAnim::~ESP_Brookesia_CoreAnim()
{
}

void ESP_Brookesia_CoreAnim::reset(void)
{

}

bool ESP_Brookesia_CoreAnim::processRun(ESP_Brookesia_CoreApp *app, ESP_Brookesia_LvAnimationActionType_t action, ESP_Brookesia_LvAnimationPathType_t path)
{
    ESP_BROOKESIA_LOGD("Register event for app(0x%p) action(0x%2x) path(0x%2x)", app, action, path);
    ESP_BROOKESIA_CHECK_NULL_RETURN(app, false, "Invalid app pointer");

    lv_display_t * d = lv_obj_get_display(lv_scr_act());

    anim_action = action;
    anim_path = path;

    lv_anim_t anim_obj;
    lv_anim_init(&anim_obj);
    lv_anim_set_var(&anim_obj, lv_scr_act());
    lv_anim_set_duration(&anim_obj, 250);
    lv_anim_set_path_cb(&anim_obj, esp_brookesia_core_utils_get_anim_path_cb(path));
    lv_anim_start(&anim_obj);

    switch(anim_action)
    {
        case ESP_BROOKESIA_LV_ANIM_ACT_NONE:
            /*Create a dummy animation to apply the delay*/
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, 0, 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OVER_LEFT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, lv_display_get_horizontal_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OVER_RIGHT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, -lv_display_get_horizontal_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OVER_TOP:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, lv_display_get_vertical_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OVER_BOTTOM:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, -lv_display_get_vertical_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_MOVE_LEFT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, lv_display_get_horizontal_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_MOVE_RIGHT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, -lv_display_get_horizontal_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_MOVE_TOP:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, lv_display_get_vertical_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_MOVE_BOTTOM:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, -lv_display_get_vertical_resolution(d), 0);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_FADE_IN:
            lv_anim_set_exec_cb(&anim_obj, opaScaleAnim);
            lv_anim_set_values(&anim_obj, LV_OPA_TRANSP, LV_OPA_COVER);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_FADE_OUT:
            lv_anim_set_exec_cb(&anim_obj, opaScaleAnim);
            lv_anim_set_values(&anim_obj, LV_OPA_COVER, LV_OPA_TRANSP);
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OUT_LEFT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, 0, -lv_display_get_horizontal_resolution(d));
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OUT_RIGHT:
            lv_anim_set_exec_cb(&anim_obj, setXposAnim);
            lv_anim_set_values(&anim_obj, 0, lv_display_get_horizontal_resolution(d));
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OUT_TOP:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, 0, -lv_display_get_vertical_resolution(d));
            break;
        case ESP_BROOKESIA_LV_ANIM_ACT_OUT_BOTTOM:
            lv_anim_set_exec_cb(&anim_obj, setYposAnim);
            lv_anim_set_values(&anim_obj, 0, lv_display_get_vertical_resolution(d));
            break;
    }

    lv_anim_start(&anim_obj);

    return true;
}

void ESP_Brookesia_CoreAnim::opaScaleAnim(void *obj, int32_t v)
{
    lv_obj_t *obj_ = (lv_obj_t *)obj;
    lv_obj_set_style_opa(obj_, v, 0);
}

void ESP_Brookesia_CoreAnim::setXposAnim(void *obj, int32_t v)
{
    lv_obj_t *obj_ = (lv_obj_t *)obj;
    lv_obj_set_x(obj_, v);
}

void ESP_Brookesia_CoreAnim::setYposAnim(void *obj, int32_t v)
{
    lv_obj_t *obj_ = (lv_obj_t *)obj;
    lv_obj_set_y(obj_, v);
}
