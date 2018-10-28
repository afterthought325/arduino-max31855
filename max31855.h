/*
 * =====================================================================================
 *
 *       Filename:  max31855.h
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


#ifndef max31855_H
#define max31855_H


/** @brief Returns thermocouple temperature for the MAX31855 chip in 
 *         degrees celcius.
 *
 *  @param pu8Data: array of bytes read from max31855 over SPI 
 *  @retval int16_t
 *  
 *  Expects a pointer to an array of bytes (uint8_t) from a max31855 chip.
 *  It converts the data representing the thermocouple temp from this 
 *  array into degrees celcius.
 *  It returns a 16 bit integer (int16_t).
 */

int16_t max31855toCelcius(uint8_t *pu8Data);

/** \brief Returns internal reference temperature for the MAX31855 chip in 
 *         degrees celcius.
 *
 *  @param pu8Data: array of bytes read from max31855 over SPI 
 *  @retval int16_t
 *  
 *  Expects a pointer to an array of bytes (uint8_t) from a max31855 chip.
 *  It converts the data representing the internal reference temp from this 
 *  array into degrees celcius.
 *  It returns a 16 bit integer (int16_t).
 */

int16_t max31855toCelcius_InternalRef(uint8_t *pu8Data);

/**
 * @brief Returns true if the thermocouple is connected.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */

int max31855_ThermoCoupleConnected(uint8_t * pu8Data);

/**
 * \brief Return true if the leads are shorted to ground.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */
int max31855_ShortGND(uint8_t * pu8Data);

/**
 * \brief Return true if the leads are shorted to VCC.
 * @param pu8Data: array of bytes read from max31855 over SPI 
 * @retval int
 */
int max31855_ShortVCC(uint8_t * pu8Data);

#endif
