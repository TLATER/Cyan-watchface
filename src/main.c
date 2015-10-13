#include <pebble.h>

#include "main_window.h"

int main (void)
{
    init();
    app_event_loop();
    deinit();

    return 0;
}
