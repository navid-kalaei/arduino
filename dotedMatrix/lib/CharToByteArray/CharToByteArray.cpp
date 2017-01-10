#include "CharToByteArray.h"

byte * char_to_byte_array(char c)
{
  byte * b = new byte[8];

  switch (c) {
    case 'A':
      b[0] = {0x3C};
      b[1] = {0x66};
      b[2] = {0xC3};
      b[3] = {0xFF};
      b[4] = {0xFF};
      b[5] = {0xC3};
      b[6] = {0xC3};
      b[7] = {0xC3};
      break;
    case 'N':
      b[0] = {0xC3};
      b[1] = {0xE3};
      b[2] = {0xF3};
      b[3] = {0xDB};
      b[4] = {0xCF};
      b[5] = {0xC7};
      b[6] = {0xC3};
      b[7] = {0xC3};
      break;
    case 'M':
      b[0] = {0xE7};
      b[1] = {0xFF};
      b[2] = {0xFF};
      b[3] = {0xDB};
      b[4] = {0xDB};
      b[5] = {0xDB};
      b[6] = {0xC3};
      b[7] = {0xC3};
      break;
    case ' ':
    default:
      b[0] = {0x00};
      b[1] = {0x00};
      b[2] = {0x00};
      b[3] = {0x00};
      b[4] = {0x00};
      b[5] = {0x00};
      b[6] = {0x00};
      b[7] = {0x00};
      break;
  }

  return b;
}
