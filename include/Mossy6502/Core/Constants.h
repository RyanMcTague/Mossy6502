#pragma once
#include <cmath>

namespace Constants
{
    float ASPECT_RATIO = 4.0f / 3.0f;
    int WINDOW_WIDTH = 900;
    int WINDOW_HEIGHT = floor((float)WINDOW_WIDTH / ASPECT_RATIO);
    const char *WINDOW_TITLE = "Mossy6502";
}
