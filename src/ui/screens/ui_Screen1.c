// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.1
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    // 获取屏幕的高度
    lv_coord_t screen_height = lv_disp_get_ver_res(NULL);
    // 获取屏幕的宽度
    lv_coord_t screen_width = lv_disp_get_hor_res(NULL);

    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_Screen1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x05915D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0x055088), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Screen1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_speed = lv_arc_create(ui_Screen1);
    lv_coord_t ui_speed_w_h = screen_height * 0.8;
    lv_obj_set_width(ui_speed, ui_speed_w_h);
    lv_obj_set_height(ui_speed, ui_speed_w_h);
    // 设置圆弧的位置在左半边中央
    lv_coord_t ui_speed_arc_x = -(screen_width / 4);
    lv_obj_set_x(ui_speed, ui_speed_arc_x);
    lv_obj_set_y(ui_speed, 0);
    lv_obj_set_align(ui_speed, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_speed, 0, 299);
    lv_arc_set_value(ui_speed, 80);

    lv_obj_set_style_bg_color(ui_speed, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_speed, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_speed, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_speed, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_speedText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_speedText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_speedText, LV_SIZE_CONTENT); /// 1
    // 放在 ui_speed 圆弧中间
    lv_obj_set_x(ui_speedText, ui_speed_arc_x);
    lv_obj_set_y(ui_speedText, 0);
    lv_obj_set_align(ui_speedText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_speedText, "299");
    lv_obj_set_style_text_color(ui_speedText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_speedText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_speedText, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_kmhText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_kmhText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_kmhText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_kmhText, ui_speed_arc_x);
    lv_obj_set_y(ui_kmhText, ui_speed_w_h * 0.3);
    lv_obj_set_align(ui_kmhText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_kmhText, "km/h");
    lv_obj_set_style_text_color(ui_kmhText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_kmhText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_kmhText, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_localtionText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_localtionText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_localtionText, LV_SIZE_CONTENT); /// 1
    // 放在 ui_speedText 下面 y坐标要大于ui_speed_w_h/2且不能查过 screen_height/2
    lv_obj_set_x(ui_localtionText, ui_speed_arc_x);
    lv_obj_set_y(ui_localtionText, ui_speed_w_h / 2 + 10);
    lv_obj_set_align(ui_localtionText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_localtionText, "SuZhou");
    lv_obj_set_style_text_color(ui_localtionText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_localtionText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_localtionText, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_roll = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_roll, &ui_img_1869354606);
    lv_obj_set_width(ui_roll, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_roll, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_roll, screen_height * 0.2);  // 右边部分的 ui_speed_w_h 框架内 进行三行等分，
    lv_obj_set_y(ui_roll, 0);
    lv_obj_set_align(ui_roll, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_roll, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_roll, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_rollText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_rollText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_rollText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_rollText, 102);
    lv_obj_set_y(ui_rollText, 0);
    lv_obj_set_align(ui_rollText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_rollText, "0°");
    lv_obj_set_style_text_color(ui_rollText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_rollText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_rollText, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_coord_t altitude_y = -screen_height / 5;
    lv_coord_t altitude_x = screen_width * 0.1;
    ui_altitude = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_altitude, &ui_img_haiba_png);
    lv_obj_set_width(ui_altitude, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_altitude, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_altitude, altitude_x);           // 右边部分的 ui_speed_w_h 框架内 进行三行等分，
    lv_obj_set_y(ui_altitude, altitude_y);           // 三行等分的第二行
    lv_obj_set_align(ui_altitude, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_altitude, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_altitude, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_altitudeText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_altitudeText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_altitudeText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_altitudeText, 92);
    lv_obj_set_y(ui_altitudeText, altitude_y);
    lv_obj_set_align(ui_altitudeText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_altitudeText, "00m");
    lv_obj_set_style_text_color(ui_altitudeText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_altitudeText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_altitudeText, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_course = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_course, &ui_img_direction_png);
    lv_obj_set_width(ui_course, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_course, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_course, altitude_x);           // 右边部分的 ui_speed_w_h 框架内 进行三行等分，
    lv_obj_set_y(ui_course, -altitude_y);          // 三行等分的第三行
    lv_obj_set_align(ui_course, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_course, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_course, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_img_set_angle(ui_course, 0);

    ui_courseText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_courseText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_courseText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_courseText, 92);
    lv_obj_set_y(ui_courseText, -altitude_y);
    lv_obj_set_align(ui_courseText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_courseText, "000°");
    lv_obj_set_style_text_color(ui_courseText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_courseText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_courseText, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_gpsTime = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_gpsTime, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_gpsTime, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_gpsTime, screen_width * 0.15);
    lv_obj_set_y(ui_gpsTime, -(screen_height / 2 - screen_height * 0.05));
    lv_obj_set_align(ui_gpsTime, LV_ALIGN_CENTER);
    lv_label_set_text(ui_gpsTime, "1992-03-01 21:21:30");
    lv_obj_set_style_text_color(ui_gpsTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_gpsTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_gpsTime, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_bettery = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_bettery, &ui_img_dianliang_png);
    // lv_obj_set_width(ui_bettery, LV_SIZE_CONTENT);  /// 1
    // lv_obj_set_height(ui_bettery, LV_SIZE_CONTENT); /// 1
    // lv_obj_set_x(ui_bettery, 122);
    // lv_obj_set_y(ui_bettery, -82);
    // lv_obj_set_align(ui_bettery, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_bettery, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    // lv_obj_clear_flag(ui_bettery, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    // ui_wifi = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_wifi, &ui_img_953604683);
    // lv_obj_set_width(ui_wifi, LV_SIZE_CONTENT);  /// 1
    // lv_obj_set_height(ui_wifi, LV_SIZE_CONTENT); /// 1
    // lv_obj_set_x(ui_wifi, 112);
    // lv_obj_set_y(ui_wifi, -96);
    // lv_obj_set_align(ui_wifi, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_wifi, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    // lv_obj_clear_flag(ui_wifi, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_gps = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_gps, &ui_img_weixing_png);
    lv_obj_set_width(ui_gps, LV_SIZE_CONTENT);     /// 1
    lv_obj_set_height(ui_gps, LV_SIZE_CONTENT);    /// 1
    lv_coord_t ui_gps_x = -screen_width / 2 + 10;  // 右上角
    lv_coord_t ui_gps_y = -screen_height / 2 + 10; // 右上角
    lv_obj_set_x(ui_gps, ui_gps_x);                // 左上角
    lv_obj_set_y(ui_gps, ui_gps_y);
    lv_obj_set_align(ui_gps, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_gps, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_gps, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_satellitesText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_satellitesText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_satellitesText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_satellitesText, ui_gps_x + 20);
    lv_obj_set_y(ui_satellitesText, ui_gps_y);
    lv_obj_set_align(ui_satellitesText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_satellitesText, "99");
    lv_obj_set_style_text_color(ui_satellitesText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_satellitesText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_satellitesText, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_gpsText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_gpsText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_gpsText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_gpsText, screen_width / 4);     // 右边正下方
    lv_obj_set_y(ui_gpsText, screen_height / 2 - 20);
    lv_obj_set_align(ui_gpsText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_gpsText, "-999.999999, +999.999999");
    lv_obj_set_style_text_color(ui_gpsText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_gpsText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_gpsText, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_speed, ui_event_speed, LV_EVENT_ALL, NULL);
}
