#include <pebble.h>

#include "resources.h"

GFont TERMINUS_16B = NULL;

void create_terminus_16b ()
{
    if (TERMINUS_16B == NULL)
        TERMINUS_16B = fonts_load_custom_font
            (resource_get_handle(RESOURCE_ID_TERMINUS_BOLD_16));
}

void destroy_terminus_16b ()
{
    fonts_unload_custom_font(TERMINUS_16B);
    TERMINUS_16B = NULL;
}
