#include "test/sio.h"
typedef unsigned int uint ;







enum gpio_function {

    GPIO_FUNC_XIP = 0,

    GPIO_FUNC_SPI = 1,

    GPIO_FUNC_UART = 2,

    GPIO_FUNC_I2C = 3,

    GPIO_FUNC_PWM = 4,

    GPIO_FUNC_SIO = 5,

    GPIO_FUNC_PIO0 = 6,

    GPIO_FUNC_PIO1 = 7,

    GPIO_FUNC_GPCK = 8,

    GPIO_FUNC_USB = 9,

    GPIO_FUNC_NULL = 0x1f,

};

enum gpio_irq_level {

    GPIO_IRQ_LEVEL_LOW = 0x1u,

    GPIO_IRQ_LEVEL_HIGH = 0x2u,

    GPIO_IRQ_EDGE_FALL = 0x4u,

    GPIO_IRQ_EDGE_RISE = 0x8u,

};

enum gpio_override {

    GPIO_OVERRIDE_NORMAL = 0,

    GPIO_OVERRIDE_INVERT = 1,

    GPIO_OVERRIDE_LOW = 2,

    GPIO_OVERRIDE_HIGH = 3,

};

enum gpio_slew_rate {

    GPIO_SLEW_RATE_SLOW = 0,

    GPIO_SLEW_RATE_FAST = 1

};















enum gpio_drive_strength {

    GPIO_DRIVE_STRENGTH_2MA = 0,

    GPIO_DRIVE_STRENGTH_4MA = 1,

    GPIO_DRIVE_STRENGTH_8MA = 2,

    GPIO_DRIVE_STRENGTH_12MA = 3

};

void gpio_set_inover(uint gpio, uint value);















void gpio_set_oeover(uint gpio, uint value);















void gpio_set_input_enabled(uint gpio, 

                                      _Bool 

                                           enabled);

void gpio_set_input_hysteresis_enabled(uint gpio, 

                                                 _Bool 

                                                      enabled);

















_Bool 

    gpio_is_input_hysteresis_enabled(uint gpio);

void gpio_set_slew_rate(uint gpio, enum gpio_slew_rate slew);

enum gpio_slew_rate gpio_get_slew_rate(uint gpio);

void gpio_set_drive_strength(uint gpio, enum gpio_drive_strength drive);

enum gpio_drive_strength gpio_get_drive_strength(uint gpio);

void gpio_acknowledge_irq(uint gpio, uint32_t event_mask);

void gpio_init(uint gpio);













void gpio_deinit(uint gpio);

void gpio_init_mask(uint gpio_mask);

static inline void gpio_set_mask(uint32_t mask) {

    ((sio_hw_t *)0xd0000000)->gpio_set = mask;

}















static inline void gpio_clr_mask(uint32_t mask) {

    ((sio_hw_t *)0xd0000000)->gpio_clr = mask;

}

static inline void gpio_put_masked(uint32_t mask, uint32_t value) {

    ((sio_hw_t *)0xd0000000)->gpio_togl = (((sio_hw_t *)0xd0000000)->gpio_out ^ value) & mask;

}













static inline void gpio_put_all(uint32_t value) {

    ((sio_hw_t *)0xd0000000)->gpio_out = value;

}















static inline void gpio_put(uint gpio, 

                                      _Bool 

                                           value) {

    uint32_t mask = 1ul << gpio;

    if (value)

        gpio_set_mask(mask);

    else

        gpio_clr_mask(mask);

}

static inline 

             _Bool 

                  gpio_get_out_level(uint gpio) {

    return !!(((sio_hw_t *)0xd0000000)->gpio_out & (1u << gpio));

}

static inline void gpio_set_dir_out_masked(uint32_t mask) {

    ((sio_hw_t *)0xd0000000)->gpio_oe_set = mask;

}













static inline void gpio_set_dir_in_masked(uint32_t mask) {

    ((sio_hw_t *)0xd0000000)->gpio_oe_clr = mask;

}

static inline void gpio_set_dir_masked(uint32_t mask, uint32_t value) {

    ((sio_hw_t *)0xd0000000)->gpio_oe_togl = (((sio_hw_t *)0xd0000000)->gpio_oe ^ value) & mask;

}













static inline void gpio_set_dir_all_bits(uint32_t values) {

    ((sio_hw_t *)0xd0000000)->gpio_oe = values;

}















static inline void gpio_set_dir(uint gpio, 

                                          _Bool 

                                               out) {

    uint32_t mask = 1ul << gpio;

    if (out)

        gpio_set_dir_out_masked(mask);

    else

        gpio_set_dir_in_masked(mask);

}

static inline uint gpio_get_dir(uint gpio) ;







extern void gpio_debug_pins_init(void);
