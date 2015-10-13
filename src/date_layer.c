#include <pebble.h>

#include "date_layer.h"
#include "resources.h"

static TextLayer* DATE_LAYER;

void date_layer_create (Window* window)
{
    DATE_LAYER = text_layer_create(GRect(0, 120, 144, 30));
    text_layer_set_background_color(DATE_LAYER, GColorClear);
    text_layer_set_text_color(DATE_LAYER, GColorWhite);
    date_update();

    create_terminus_16b();

    text_layer_set_font(DATE_LAYER, TERMINUS_16B);
    text_layer_set_text_alignment(DATE_LAYER, GTextAlignmentCenter);

    layer_add_child(window_get_root_layer(window),
                    text_layer_get_layer(DATE_LAYER));
}

void date_update ()
{
    time_t temp = time(NULL);
    struct tm* tick_time = localtime(&temp);

    static char* date = "Thu Oct 13";
    strftime(date, sizeof(char) * 10, "%a %b %e", tick_time);

    text_layer_set_text(DATE_LAYER, date);
}

void date_layer_destroy ()
{
    text_layer_destroy(DATE_LAYER);
    destroy_terminus_16b();
}
