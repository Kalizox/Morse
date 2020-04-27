/*
 *  Copyright 2020 Kalizox
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

#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>

#define VERY_SMALL_LENGTH 10
#define SMALL_LENGTH 20
#define MEDIUM_LENGTH 50
#define LONG_LENGTH 100
#define VERYL_LONG_LENGTH 200

/*
 * \brief empty buffer
 */
void empty_buffer();

/*
 * \param[in] char*: optionnal message to print before the user input, put NULL, to print nothing
 * \param[in] int: max_length of the string allowed
 * \brief user input
 */
char *input(char *p_pMessage, int p_char_max);

#endif
