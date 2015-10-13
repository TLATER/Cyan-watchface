#include <pebble.h>

#include "date_layer.h"

void tick_handler (struct tm *tick_time, TimeUnits units_changed)
{
    date_update();
}
