//
// Created by Ryan on 11/22/23.
//

#ifndef MOSSY6502_CONSTANTS_H
#define MOSSY6502_CONSTANTS_H
#include <cmath>

namespace Constants
{
    float ASPECT_RATIO = 4.0f / 3.0f;
    int WINDOW_WIDTH = 900;
    int WINDOW_HEIGHT = floor((float )WINDOW_WIDTH / ASPECT_RATIO);
    const char* WINDOW_TITLE = "Mossy6502"
}

#endif //MOSSY6502_CONSTANTS_H
