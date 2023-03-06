/*
   crc16.cpp

   Created: 16-01-2018 23:06:40
    Author: JMR_2
*/

#include "crc16.h"
#include "sys.h"
#include "JICE_io.h"

#define CRC16_POLY 0x1021

uint16_t CRC::next(uint8_t new_byte, uint16_t crc) {
    crc ^= new_byte;
    for (int i = 0; i < 8; ++i)
    {
        if (crc & 0x0001)
        {
            crc = (crc >> 1) ^ 0x8408;
        }
        else
        {
            crc >>= 1;
        }
    }
    return crc;
}
