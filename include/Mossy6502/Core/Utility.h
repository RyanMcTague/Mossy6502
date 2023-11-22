#pragma once
#include "Mossy6502/Core/Base.h"

namespace Utility
{
    std::string Uint8ToHex(uint8_t byte);
    std::string Uint16ToHex(uint16_t word);

    char HexCode(uint8_t value);
}
