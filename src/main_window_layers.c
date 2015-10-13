#include <pebble.h>

#include "date_layer.h"
#include "main_window_layers.h"

void main_window_load (Window* window)
{
    date_layer_create(window);
}

void main_window_unload (Window* window)
{
    date_layer_destroy();
}
