/*
 *  Copyright (C) 2020 Kalizox
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __MORSE_H__
#define __MORSE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPH_SIZE 26		// alphabet
#define ALPH_LENGTH 4		// coded on 4
#define NUM_SIZE 10		// numbers
#define NUM_LENGTH 5		// coded on 5 
#define SPE_SIZE 18		// symbols
#define SPE_LENGTH 7		// coded on 7
#define STRING_LENTGH 150
#define MORSE_LENGTH_MAX 7

/*
 * \brief International morse code
 */
extern char *morse_alphabet[ALPH_SIZE];

/*
 * \brief International numerical morse code
 */
extern char *morse_numbers[NUM_SIZE];

/*
 * \brief International symbols morse code
 */
extern char *morse_symbols[SPE_SIZE];

/*
 * \brief Equivalent of international symbols morse code
 */
extern char *alph_symbols[SPE_SIZE];

/*
 * \param[in] int: alph size, allow us to determine which array has to be print
 * \brief Print the morse alphabet
 */
void print_alphabet(int p_alph);

/*
 * \param[in] char*: user string
 * \param[out] char*: morse string
 * \brief Translate user string in morse code
 */
char *alph_to_morse(char *p_pUser_string);

/*
 * \param[in] char*: morse string
 * \param[out] char*: translate morse code in understandable string
 * \brief Convert morse string to alphanumeric string
 */
char *morse_to_alph(char *p_pMorse_string);

/*
 * \param[in] char*: morse string
 * \param[out] char*: alphanumericable string of the morse string
 * \brief Translate a morse code in an understable character
 */
char *parse_morse_code(char *p_pMorse_string);

/*
 * \param[in] char*:
 * \param[out] char*:
 * \brief Seek morse character in alphanumerical alphabet
 */
char *seek_char(char *p_pMorse_character);

/*
 * \param[in] char*: string morse
 * \brief Count number of words in the morse string
 */
int count_Morse_word(char *p_pMorse_string);

/*
 * \param[in] char*: string morse
 * \param[in] int: number words
 * \param[in] int*: array of number words
 * \brief Count character in morse word
 */
void count_char(char *p_pMorse_string, int p_count_words, int *p_pCount_char);

/*
 * \brief Print marine code
 */
void print_marine_code();

#endif
