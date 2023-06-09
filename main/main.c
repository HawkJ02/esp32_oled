
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "u8g2.h"
#include "u8g2_hal.h"

void app_main(void)
{
    // 根据自身情况修改 I2C 引脚
    u8g2_hal_i2c_cfg_t i2c_cfg = {
        .scl = 21,
        .sda = 20,
    };

    /**
     * 有两种方式获得 u8g2_t*
     * 调用 u8g2_hal_i2c_init(i2c_cfg) 函数，会返回 u8g2_t*
     * u8g2_hal.h 里也定义了 extern u8g2_t u8g2;
     * 两者指向的位置是相同的
     */
    u8g2_t *u8g2 = u8g2_hal_i2c_init(i2c_cfg);

    // ==== 下面开始编写你的代码 ====
    u8g2_ClearBuffer(u8g2);
    u8g2_SetFont(u8g2, u8g2_font_ncenB14_tr);
    u8g2_DrawStr(u8g2, 0, 20, "Hello World!");
    u8g2_SendBuffer(u8g2);

    printf("All done!\n");
}
