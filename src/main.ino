#include "core/dashboard.ino"
#include "core/ble.ino"

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

    // 初始化蓝牙
    setupBLE();
}

void loop()
{
    // put your main code here, to run repeatedly:
    // 读取蓝牙数据
    loopBLE();
    lv_flash_screen(5);
}
