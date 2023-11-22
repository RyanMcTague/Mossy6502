#include "Mossy6502/Core/Utility.h"

std::string Utility::Uint8ToHex(uint8_t byte)
{
    std::string hex;
    hex += HexCode((byte & 0xF0) >> 4);
    hex += HexCode((byte & 0xF));
    return hex;
}

std::string Utility::Uint16ToHex(uint16_t word)
{
    return Uint8ToHex((word & 0xFF00) >> 8) + Uint8ToHex(word & 0xFF);
}

char Utility::HexCode(uint8_t value)
{
    char code;
    switch (value)
    {
    case 10:
        code = 'A';
        break;
    case 11:
        code = 'B';
        break;
    case 12:
        code = 'C';
        break;
    case 13:
        code = 'D';
        break;
    case 14:
        code = 'E';
        break;
    case 15:
        code = 'F';
        break;
    default:
        code = '0' + value;
    }
    return code;
}