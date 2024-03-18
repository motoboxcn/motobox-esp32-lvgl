#include "core/dashboard.ino"

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    // 初始化函数TFT仪表驱动和LVGL
    LVSetup();
    // 初始化UI图形
    ui_init();
    // 展示开机仪表动画
    ShowSpeed();
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(5);
    lv_timer_handler();
    lv_tick_inc(5);
}