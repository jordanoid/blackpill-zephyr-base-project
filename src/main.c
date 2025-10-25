#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/drivers/gpio.h>

BUILD_ASSERT(DT_NODE_HAS_COMPAT(DT_CHOSEN(zephyr_console), zephyr_cdc_acm_uart),
	     "Console device is not ACM CDC UART device");

static const struct gpio_dt_spec internal_led_spec = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

int main(void)
{
	int ret;

	/*
	const struct device *const dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	uint32_t dtr = 0;

	// Poll if the DTR flag was set
	while (!dtr) {
		uart_line_ctrl_get(dev, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}
	*/

	ret = gpio_pin_configure_dt(&internal_led_spec, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error configuring pin: %d\n", ret);
        return 0;
    }

	while (1) {
		ret = gpio_pin_toggle_dt(&internal_led_spec);
		if (ret < 0) {
            printk("Error toggling pin: %d\n", ret);
        }
		k_sleep(K_SECONDS(1));
	}
}