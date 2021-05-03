/**
 * @file esp32s2-ulp-riscv-assembly-test.c
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp32s2/ulp_riscv.h"

#include "ulp_main.h"

static const char *TAG = "esp32s2-ulp-riscv-assembly-test";

extern const uint8_t bin_start[] asm("_binary_ulp_main_bin_start");
extern const uint8_t bin_end[] asm("_binary_ulp_main_bin_end");

static void init_ulp_program(void)
{
    ESP_ERROR_CHECK(ulp_riscv_load_binary(bin_start, bin_end - bin_start));

    /* The first argument is the period index, which is not used by
     * the ULP-RISC-V timer The second argument is the period in
     * microseconds, which gives a wakeup time period of: 20ms
     */
    ulp_set_wakeup_period(0, 20000);

    /* Start the program */
    ESP_ERROR_CHECK(ulp_riscv_run());
}

void app_main(void)
{
    init_ulp_program();

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(TAG, "results: %d, %d", ulp_result_s, ulp_result_c);
}
