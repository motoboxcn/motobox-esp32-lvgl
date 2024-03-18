#include <TFT_eSPI.h>
#include "../ui/ui.h"

#define SPEED_LOG 0
/*Change to your screen resolution*/
static const uint16_t screenWidth = TFT_HEIGHT;
static const uint16_t screenHeight = TFT_WIDTH;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

/* Display flushing */
static void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp_drv);
}

// 刷新仪表盘
void lv_flash_screen(uint32_t time)
{
    lv_timer_handler();
    delay(time);
    lv_tick_inc(time);
}

void speed_dashboard_without_time(double speed)
{
    lv_arc_set_value(ui_speed, speed);
    lv_label_set_text_fmt(ui_speedText, "%d", int(speed));
    if (speed < 40)
    {
        lv_obj_set_style_arc_color(ui_speed, lv_color_hex(0x2274C2), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    else if (speed < 80)
    {
        lv_obj_set_style_arc_color(ui_speed, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    else if (speed < 120)
    {
        lv_obj_set_style_arc_color(ui_speed, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    else
    {
        lv_obj_set_style_arc_color(ui_speed, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    };
}

// 时速超过 一定值时，仪表盘变化：
// 低于 80 ，arc 变绿色，label 变绿色
// 超过 80，arc 变黄色，label 变黄色
// 超过 120，arc 变红色，label 变红色
void speed_dashboard(double speed, double time)
{
#if SPEED_LOG
    Serial.println(speed);
#endif
    speed_dashboard_without_time(speed);
    lv_flash_screen(time);
}

void ShowSpeed()
{
    // 初始化仪表盘
    for (int i = 0; i <= 299; i += 1)
    {
        speed_dashboard(i, 2);
    }

    for (int j = 299; j >= 0; j -= 1)
    {
        speed_dashboard(j, 2);
    }
    delay(10);
    // 重置仪表盘
    speed_dashboard(0, 2);
}

static void lv_demo_text()
{
    /*Create a simple text, background is back,text is white*/
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello Ardino and LVGL!"); // 设置文本
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);         // 居中显示
    lv_timer_handler();
    delay(2000);
    lv_obj_clean(label);
}

void LVSetup()
{
    String LVGL_Arduino = "Hello Arduino LVGL!";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println(LVGL_Arduino);

    lv_init();

    tft.begin();        // 初始化 TFT
    tft.setRotation(3); // 设置为横屏模式

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Create simple label */
    lv_demo_text();

    Serial.println("Setup LVGL done");
}

void ui_wifi_connect_off()
{
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0xEF1616), LV_PART_INDICATOR | LV_STATE_FOCUSED);
}

void ui_wifi_connect_on(char *ip)
{
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_arc_color(ui_wifi, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_FOCUSED);
}

void speed_demon()
{
    // 模拟速度变化
    // 定义一组速度数组，循环遍历数组，模拟速度变化
    // 模拟启动速度变化，0开始到199，前面加速快，到120后速度变化慢
    // 初始化速度数组
    for (int i = 0; i < 30; i++)
    {
        speed_dashboard(i * 6.6, 100);
    }

    // 模拟最高速度后波动
    for (int i = 0; i < 60; i++)
    {
        speed_dashboard(199 - random(-2, 2), 100);
    }

    // 开始刹车减速
    for (int i = 0; i < 50; i++)
    {
        speed_dashboard(199 - (i * 4), 100);
    }

    // 重置仪表盘
    speed_dashboard(0, 2);
    delay(5000);
}

void speed_demon_task()
{
    speed_dashboard_without_time(random(0, 299));
}