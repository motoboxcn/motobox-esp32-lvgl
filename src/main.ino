#include "core/dashboard.ino"
#include "core/ble.ino"

#define LV_TICK_PERIOD_MS 1
#define BOOT_BTN_PIN 0 // boot按键的引脚

static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}

void setup()
{
    pinMode(BOOT_BTN_PIN, INPUT_PULLUP);

    // put your setup code here, to run once:
    Serial.begin(115200);

    // 初始化蓝牙
    setupBLE();
    // 初始化函数TFT仪表驱动和LVGL
    LVSetup();
    ShowSpeed();

    Serial.println("Ready!");

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    // const esp_timer_create_args_t periodic_timer_args = {
    //     .callback = &lv_tick_task,
    //     .name = "periodic_gui"};
    // esp_timer_handle_t periodic_timer;
    // ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));            // 创建定时器
    // ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000)); // 启动定时器
}

void loop()
{
    // 处理按键抖动，防止误触
    if (!digitalRead(BOOT_BTN_PIN))
    {
        delay(100);
        if (!digitalRead(BOOT_BTN_PIN))
        {
            Serial.println("Boot button pressed");
            reloadTFT();
        }
    }

    // 读取蓝牙数据
    loopBLE();
    delay(5);
    lv_tick_inc(1);
}
