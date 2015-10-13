#include <pebble.h>

#include "main_window.h"
#include "main_window_layers.h"
#include "tick_handler.h"

static Window* MAIN_WINDOW;

void init ()
{
    tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

    MAIN_WINDOW = window_create();
    window_set_window_handlers(MAIN_WINDOW, (WindowHandlers) {
        .load = main_window_load,
        .unload = main_window_unload,
    });

    window_set_background_color(MAIN_WINDOW, GColorBlack);

    window_stack_push(MAIN_WINDOW, true);
}

void deinit ()
{
    window_destroy(MAIN_WINDOW);
}
