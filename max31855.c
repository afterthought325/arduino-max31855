/*
 * =====================================================================================
 *
 *       Filename:  max31855.c
 *
 *    Description:  Simple library for handling the data from the max31855 chip.
 *
 *        Version:  1.0
 *        Created:  10/28/2018 03:09:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chaise Farrar (chaise.farrar@gmail.com), 
 *   Organization:  IntelliRoast 
 *
 * =====================================================================================
 */
#include "max31855.h"


int16_t max31855toCelcius(uint8_t *pu8Data) {
    uint16_t *pu16Data = (uint16_t *) pu8Data;
    uint16_t u16RawTemp = pu16Data[1]; //The Thermocouple temp is stored in the upper 14 bits, bit 16 & 17 are not needed.
    int16_t i16Celcius;
    
    if (u16RawTemp && 0x8000) { //temp is negative
        u16RawTemp = (u16RawTemp >> 2) & 0xFFFF; // drop lower two bits and keep 2's complemnt

    } else { // temp is positive
        u16RawTemp >>= 2; //drop lower two bits.
    }

    u16RawTemp >>= 2; // Divide by 4 (multiply by .25) //we don't care about the decimal place.
    i16Celcius = (int16_t) u16RawTemp;

    return i16Celcius;
}


int16_t max31855toCelcius_InternalRef(uint8_t *pu8Data) {
    uint16_t *pu16Data = (uint16_t *) pu8Data;
    uint16_t u16RawTemp = pu16Data[0]; //The Reference temp is stored in bits [15:4], bits [3:0] are not needed.
    int16_t i16Celcius;
    
    if (u16RawTemp && 0x8000) { //temp is negative
        u16RawTemp = (u16RawTemp >> 4) & 0xFFFF; // drop lower four bits and keep 2's complemnt

    } else { // temp is positive
        u16RawTemp >>= 2; //drop lower two bits.
    }

    u16RawTemp >>= 4; // Divide by 4 (multiply by .25) //we don't care about the decimal place.
    i16Celcius = (int16_t) u16RawTemp;

    return i16Celcius;
}


/**
 * @brief Returns true if the thermocouple is connected.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */

int max31855_ThermoCoupleConnected(uint8_t * pu8Data) {
    // If the thermocouple is disconnected, then the first bit is set. 
    // So if you & the first byte with 0x01, then if its disconnected,
    // it will return true, ! this to return true on connected and 
    // false on disconnected.
    return !(pu8Data[0] & 0x01);
}

/**
 * \brief Return true if the leads are shorted to ground.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */
int max31855_ShortGND(uint8_t * pu8Data) {
    return (pu8Data[0] & 0x02);
}

/**
 * \brief Return true if the leads are shorted to VCC.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */
int max31855_ShortVCC(uint8_t * pu8Data) {
    return (pu8Data[0] & 0x04);
}

