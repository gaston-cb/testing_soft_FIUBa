/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_GPIO_H
#define _MOCK_GPIO_H

#include "unity.h"
#include "gpio.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_gpio_Init(void);
void mock_gpio_Destroy(void);
void mock_gpio_Verify(void);




#define gpio_set_inover_Ignore() gpio_set_inover_CMockIgnore()
void gpio_set_inover_CMockIgnore(void);
#define gpio_set_inover_StopIgnore() gpio_set_inover_CMockStopIgnore()
void gpio_set_inover_CMockStopIgnore(void);
#define gpio_set_inover_ExpectAnyArgs() gpio_set_inover_CMockExpectAnyArgs(__LINE__)
void gpio_set_inover_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_inover_Expect(gpio, value) gpio_set_inover_CMockExpect(__LINE__, gpio, value)
void gpio_set_inover_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, uint value);
typedef void (* CMOCK_gpio_set_inover_CALLBACK)(uint gpio, uint value, int cmock_num_calls);
void gpio_set_inover_AddCallback(CMOCK_gpio_set_inover_CALLBACK Callback);
void gpio_set_inover_Stub(CMOCK_gpio_set_inover_CALLBACK Callback);
#define gpio_set_inover_StubWithCallback gpio_set_inover_Stub
#define gpio_set_inover_IgnoreArg_gpio() gpio_set_inover_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_inover_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_inover_IgnoreArg_value() gpio_set_inover_CMockIgnoreArg_value(__LINE__)
void gpio_set_inover_CMockIgnoreArg_value(UNITY_LINE_TYPE cmock_line);
#define gpio_set_oeover_Ignore() gpio_set_oeover_CMockIgnore()
void gpio_set_oeover_CMockIgnore(void);
#define gpio_set_oeover_StopIgnore() gpio_set_oeover_CMockStopIgnore()
void gpio_set_oeover_CMockStopIgnore(void);
#define gpio_set_oeover_ExpectAnyArgs() gpio_set_oeover_CMockExpectAnyArgs(__LINE__)
void gpio_set_oeover_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_oeover_Expect(gpio, value) gpio_set_oeover_CMockExpect(__LINE__, gpio, value)
void gpio_set_oeover_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, uint value);
typedef void (* CMOCK_gpio_set_oeover_CALLBACK)(uint gpio, uint value, int cmock_num_calls);
void gpio_set_oeover_AddCallback(CMOCK_gpio_set_oeover_CALLBACK Callback);
void gpio_set_oeover_Stub(CMOCK_gpio_set_oeover_CALLBACK Callback);
#define gpio_set_oeover_StubWithCallback gpio_set_oeover_Stub
#define gpio_set_oeover_IgnoreArg_gpio() gpio_set_oeover_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_oeover_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_oeover_IgnoreArg_value() gpio_set_oeover_CMockIgnoreArg_value(__LINE__)
void gpio_set_oeover_CMockIgnoreArg_value(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_enabled_Ignore() gpio_set_input_enabled_CMockIgnore()
void gpio_set_input_enabled_CMockIgnore(void);
#define gpio_set_input_enabled_StopIgnore() gpio_set_input_enabled_CMockStopIgnore()
void gpio_set_input_enabled_CMockStopIgnore(void);
#define gpio_set_input_enabled_ExpectAnyArgs() gpio_set_input_enabled_CMockExpectAnyArgs(__LINE__)
void gpio_set_input_enabled_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_enabled_Expect(gpio, enabled) gpio_set_input_enabled_CMockExpect(__LINE__, gpio, enabled)
void gpio_set_input_enabled_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, _Bool enabled);
typedef void (* CMOCK_gpio_set_input_enabled_CALLBACK)(uint gpio, _Bool enabled, int cmock_num_calls);
void gpio_set_input_enabled_AddCallback(CMOCK_gpio_set_input_enabled_CALLBACK Callback);
void gpio_set_input_enabled_Stub(CMOCK_gpio_set_input_enabled_CALLBACK Callback);
#define gpio_set_input_enabled_StubWithCallback gpio_set_input_enabled_Stub
#define gpio_set_input_enabled_IgnoreArg_gpio() gpio_set_input_enabled_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_input_enabled_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_enabled_IgnoreArg_enabled() gpio_set_input_enabled_CMockIgnoreArg_enabled(__LINE__)
void gpio_set_input_enabled_CMockIgnoreArg_enabled(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_hysteresis_enabled_Ignore() gpio_set_input_hysteresis_enabled_CMockIgnore()
void gpio_set_input_hysteresis_enabled_CMockIgnore(void);
#define gpio_set_input_hysteresis_enabled_StopIgnore() gpio_set_input_hysteresis_enabled_CMockStopIgnore()
void gpio_set_input_hysteresis_enabled_CMockStopIgnore(void);
#define gpio_set_input_hysteresis_enabled_ExpectAnyArgs() gpio_set_input_hysteresis_enabled_CMockExpectAnyArgs(__LINE__)
void gpio_set_input_hysteresis_enabled_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_hysteresis_enabled_Expect(gpio, enabled) gpio_set_input_hysteresis_enabled_CMockExpect(__LINE__, gpio, enabled)
void gpio_set_input_hysteresis_enabled_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, _Bool enabled);
typedef void (* CMOCK_gpio_set_input_hysteresis_enabled_CALLBACK)(uint gpio, _Bool enabled, int cmock_num_calls);
void gpio_set_input_hysteresis_enabled_AddCallback(CMOCK_gpio_set_input_hysteresis_enabled_CALLBACK Callback);
void gpio_set_input_hysteresis_enabled_Stub(CMOCK_gpio_set_input_hysteresis_enabled_CALLBACK Callback);
#define gpio_set_input_hysteresis_enabled_StubWithCallback gpio_set_input_hysteresis_enabled_Stub
#define gpio_set_input_hysteresis_enabled_IgnoreArg_gpio() gpio_set_input_hysteresis_enabled_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_input_hysteresis_enabled_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_input_hysteresis_enabled_IgnoreArg_enabled() gpio_set_input_hysteresis_enabled_CMockIgnoreArg_enabled(__LINE__)
void gpio_set_input_hysteresis_enabled_CMockIgnoreArg_enabled(UNITY_LINE_TYPE cmock_line);
#define gpio_is_input_hysteresis_enabled_IgnoreAndReturn(cmock_retval) gpio_is_input_hysteresis_enabled_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpio_is_input_hysteresis_enabled_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define gpio_is_input_hysteresis_enabled_StopIgnore() gpio_is_input_hysteresis_enabled_CMockStopIgnore()
void gpio_is_input_hysteresis_enabled_CMockStopIgnore(void);
#define gpio_is_input_hysteresis_enabled_ExpectAnyArgsAndReturn(cmock_retval) gpio_is_input_hysteresis_enabled_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void gpio_is_input_hysteresis_enabled_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, _Bool cmock_to_return);
#define gpio_is_input_hysteresis_enabled_ExpectAndReturn(gpio, cmock_retval) gpio_is_input_hysteresis_enabled_CMockExpectAndReturn(__LINE__, gpio, cmock_retval)
void gpio_is_input_hysteresis_enabled_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint gpio, _Bool cmock_to_return);
typedef _Bool (* CMOCK_gpio_is_input_hysteresis_enabled_CALLBACK)(uint gpio, int cmock_num_calls);
void gpio_is_input_hysteresis_enabled_AddCallback(CMOCK_gpio_is_input_hysteresis_enabled_CALLBACK Callback);
void gpio_is_input_hysteresis_enabled_Stub(CMOCK_gpio_is_input_hysteresis_enabled_CALLBACK Callback);
#define gpio_is_input_hysteresis_enabled_StubWithCallback gpio_is_input_hysteresis_enabled_Stub
#define gpio_is_input_hysteresis_enabled_IgnoreArg_gpio() gpio_is_input_hysteresis_enabled_CMockIgnoreArg_gpio(__LINE__)
void gpio_is_input_hysteresis_enabled_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_slew_rate_Ignore() gpio_set_slew_rate_CMockIgnore()
void gpio_set_slew_rate_CMockIgnore(void);
#define gpio_set_slew_rate_StopIgnore() gpio_set_slew_rate_CMockStopIgnore()
void gpio_set_slew_rate_CMockStopIgnore(void);
#define gpio_set_slew_rate_ExpectAnyArgs() gpio_set_slew_rate_CMockExpectAnyArgs(__LINE__)
void gpio_set_slew_rate_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_slew_rate_Expect(gpio, slew) gpio_set_slew_rate_CMockExpect(__LINE__, gpio, slew)
void gpio_set_slew_rate_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, enum gpio_slew_rate slew);
typedef void (* CMOCK_gpio_set_slew_rate_CALLBACK)(uint gpio, enum gpio_slew_rate slew, int cmock_num_calls);
void gpio_set_slew_rate_AddCallback(CMOCK_gpio_set_slew_rate_CALLBACK Callback);
void gpio_set_slew_rate_Stub(CMOCK_gpio_set_slew_rate_CALLBACK Callback);
#define gpio_set_slew_rate_StubWithCallback gpio_set_slew_rate_Stub
#define gpio_set_slew_rate_IgnoreArg_gpio() gpio_set_slew_rate_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_slew_rate_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_slew_rate_IgnoreArg_slew() gpio_set_slew_rate_CMockIgnoreArg_slew(__LINE__)
void gpio_set_slew_rate_CMockIgnoreArg_slew(UNITY_LINE_TYPE cmock_line);
#define gpio_get_slew_rate_IgnoreAndReturn(cmock_retval) gpio_get_slew_rate_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpio_get_slew_rate_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, enum gpio_slew_rate cmock_to_return);
#define gpio_get_slew_rate_StopIgnore() gpio_get_slew_rate_CMockStopIgnore()
void gpio_get_slew_rate_CMockStopIgnore(void);
#define gpio_get_slew_rate_ExpectAnyArgsAndReturn(cmock_retval) gpio_get_slew_rate_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void gpio_get_slew_rate_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum gpio_slew_rate cmock_to_return);
#define gpio_get_slew_rate_ExpectAndReturn(gpio, cmock_retval) gpio_get_slew_rate_CMockExpectAndReturn(__LINE__, gpio, cmock_retval)
void gpio_get_slew_rate_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint gpio, enum gpio_slew_rate cmock_to_return);
typedef enum gpio_slew_rate (* CMOCK_gpio_get_slew_rate_CALLBACK)(uint gpio, int cmock_num_calls);
void gpio_get_slew_rate_AddCallback(CMOCK_gpio_get_slew_rate_CALLBACK Callback);
void gpio_get_slew_rate_Stub(CMOCK_gpio_get_slew_rate_CALLBACK Callback);
#define gpio_get_slew_rate_StubWithCallback gpio_get_slew_rate_Stub
#define gpio_get_slew_rate_IgnoreArg_gpio() gpio_get_slew_rate_CMockIgnoreArg_gpio(__LINE__)
void gpio_get_slew_rate_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_drive_strength_Ignore() gpio_set_drive_strength_CMockIgnore()
void gpio_set_drive_strength_CMockIgnore(void);
#define gpio_set_drive_strength_StopIgnore() gpio_set_drive_strength_CMockStopIgnore()
void gpio_set_drive_strength_CMockStopIgnore(void);
#define gpio_set_drive_strength_ExpectAnyArgs() gpio_set_drive_strength_CMockExpectAnyArgs(__LINE__)
void gpio_set_drive_strength_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_set_drive_strength_Expect(gpio, drive) gpio_set_drive_strength_CMockExpect(__LINE__, gpio, drive)
void gpio_set_drive_strength_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, enum gpio_drive_strength drive);
typedef void (* CMOCK_gpio_set_drive_strength_CALLBACK)(uint gpio, enum gpio_drive_strength drive, int cmock_num_calls);
void gpio_set_drive_strength_AddCallback(CMOCK_gpio_set_drive_strength_CALLBACK Callback);
void gpio_set_drive_strength_Stub(CMOCK_gpio_set_drive_strength_CALLBACK Callback);
#define gpio_set_drive_strength_StubWithCallback gpio_set_drive_strength_Stub
#define gpio_set_drive_strength_IgnoreArg_gpio() gpio_set_drive_strength_CMockIgnoreArg_gpio(__LINE__)
void gpio_set_drive_strength_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_set_drive_strength_IgnoreArg_drive() gpio_set_drive_strength_CMockIgnoreArg_drive(__LINE__)
void gpio_set_drive_strength_CMockIgnoreArg_drive(UNITY_LINE_TYPE cmock_line);
#define gpio_get_drive_strength_IgnoreAndReturn(cmock_retval) gpio_get_drive_strength_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void gpio_get_drive_strength_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, enum gpio_drive_strength cmock_to_return);
#define gpio_get_drive_strength_StopIgnore() gpio_get_drive_strength_CMockStopIgnore()
void gpio_get_drive_strength_CMockStopIgnore(void);
#define gpio_get_drive_strength_ExpectAnyArgsAndReturn(cmock_retval) gpio_get_drive_strength_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void gpio_get_drive_strength_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum gpio_drive_strength cmock_to_return);
#define gpio_get_drive_strength_ExpectAndReturn(gpio, cmock_retval) gpio_get_drive_strength_CMockExpectAndReturn(__LINE__, gpio, cmock_retval)
void gpio_get_drive_strength_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint gpio, enum gpio_drive_strength cmock_to_return);
typedef enum gpio_drive_strength (* CMOCK_gpio_get_drive_strength_CALLBACK)(uint gpio, int cmock_num_calls);
void gpio_get_drive_strength_AddCallback(CMOCK_gpio_get_drive_strength_CALLBACK Callback);
void gpio_get_drive_strength_Stub(CMOCK_gpio_get_drive_strength_CALLBACK Callback);
#define gpio_get_drive_strength_StubWithCallback gpio_get_drive_strength_Stub
#define gpio_get_drive_strength_IgnoreArg_gpio() gpio_get_drive_strength_CMockIgnoreArg_gpio(__LINE__)
void gpio_get_drive_strength_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_acknowledge_irq_Ignore() gpio_acknowledge_irq_CMockIgnore()
void gpio_acknowledge_irq_CMockIgnore(void);
#define gpio_acknowledge_irq_StopIgnore() gpio_acknowledge_irq_CMockStopIgnore()
void gpio_acknowledge_irq_CMockStopIgnore(void);
#define gpio_acknowledge_irq_ExpectAnyArgs() gpio_acknowledge_irq_CMockExpectAnyArgs(__LINE__)
void gpio_acknowledge_irq_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_acknowledge_irq_Expect(gpio, event_mask) gpio_acknowledge_irq_CMockExpect(__LINE__, gpio, event_mask)
void gpio_acknowledge_irq_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio, uint32_t event_mask);
typedef void (* CMOCK_gpio_acknowledge_irq_CALLBACK)(uint gpio, uint32_t event_mask, int cmock_num_calls);
void gpio_acknowledge_irq_AddCallback(CMOCK_gpio_acknowledge_irq_CALLBACK Callback);
void gpio_acknowledge_irq_Stub(CMOCK_gpio_acknowledge_irq_CALLBACK Callback);
#define gpio_acknowledge_irq_StubWithCallback gpio_acknowledge_irq_Stub
#define gpio_acknowledge_irq_IgnoreArg_gpio() gpio_acknowledge_irq_CMockIgnoreArg_gpio(__LINE__)
void gpio_acknowledge_irq_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_acknowledge_irq_IgnoreArg_event_mask() gpio_acknowledge_irq_CMockIgnoreArg_event_mask(__LINE__)
void gpio_acknowledge_irq_CMockIgnoreArg_event_mask(UNITY_LINE_TYPE cmock_line);
#define gpio_init_Ignore() gpio_init_CMockIgnore()
void gpio_init_CMockIgnore(void);
#define gpio_init_StopIgnore() gpio_init_CMockStopIgnore()
void gpio_init_CMockStopIgnore(void);
#define gpio_init_ExpectAnyArgs() gpio_init_CMockExpectAnyArgs(__LINE__)
void gpio_init_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_init_Expect(gpio) gpio_init_CMockExpect(__LINE__, gpio)
void gpio_init_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio);
typedef void (* CMOCK_gpio_init_CALLBACK)(uint gpio, int cmock_num_calls);
void gpio_init_AddCallback(CMOCK_gpio_init_CALLBACK Callback);
void gpio_init_Stub(CMOCK_gpio_init_CALLBACK Callback);
#define gpio_init_StubWithCallback gpio_init_Stub
#define gpio_init_IgnoreArg_gpio() gpio_init_CMockIgnoreArg_gpio(__LINE__)
void gpio_init_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_deinit_Ignore() gpio_deinit_CMockIgnore()
void gpio_deinit_CMockIgnore(void);
#define gpio_deinit_StopIgnore() gpio_deinit_CMockStopIgnore()
void gpio_deinit_CMockStopIgnore(void);
#define gpio_deinit_ExpectAnyArgs() gpio_deinit_CMockExpectAnyArgs(__LINE__)
void gpio_deinit_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_deinit_Expect(gpio) gpio_deinit_CMockExpect(__LINE__, gpio)
void gpio_deinit_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio);
typedef void (* CMOCK_gpio_deinit_CALLBACK)(uint gpio, int cmock_num_calls);
void gpio_deinit_AddCallback(CMOCK_gpio_deinit_CALLBACK Callback);
void gpio_deinit_Stub(CMOCK_gpio_deinit_CALLBACK Callback);
#define gpio_deinit_StubWithCallback gpio_deinit_Stub
#define gpio_deinit_IgnoreArg_gpio() gpio_deinit_CMockIgnoreArg_gpio(__LINE__)
void gpio_deinit_CMockIgnoreArg_gpio(UNITY_LINE_TYPE cmock_line);
#define gpio_init_mask_Ignore() gpio_init_mask_CMockIgnore()
void gpio_init_mask_CMockIgnore(void);
#define gpio_init_mask_StopIgnore() gpio_init_mask_CMockStopIgnore()
void gpio_init_mask_CMockStopIgnore(void);
#define gpio_init_mask_ExpectAnyArgs() gpio_init_mask_CMockExpectAnyArgs(__LINE__)
void gpio_init_mask_CMockExpectAnyArgs(UNITY_LINE_TYPE cmock_line);
#define gpio_init_mask_Expect(gpio_mask) gpio_init_mask_CMockExpect(__LINE__, gpio_mask)
void gpio_init_mask_CMockExpect(UNITY_LINE_TYPE cmock_line, uint gpio_mask);
typedef void (* CMOCK_gpio_init_mask_CALLBACK)(uint gpio_mask, int cmock_num_calls);
void gpio_init_mask_AddCallback(CMOCK_gpio_init_mask_CALLBACK Callback);
void gpio_init_mask_Stub(CMOCK_gpio_init_mask_CALLBACK Callback);
#define gpio_init_mask_StubWithCallback gpio_init_mask_Stub
#define gpio_init_mask_IgnoreArg_gpio_mask() gpio_init_mask_CMockIgnoreArg_gpio_mask(__LINE__)
void gpio_init_mask_CMockIgnoreArg_gpio_mask(UNITY_LINE_TYPE cmock_line);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
