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

#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"

void empty_buffer()
{
	int c = 0;

	while(c != '\n'  && c != EOF)
		c = getchar();
}

char *input(char *p_pMessage, int p_char_max)
{
	char *pUser_input = NULL, *pReplace = NULL, *pTmp = NULL;
	int tmp_length = 0;

	pTmp = (char*) malloc(sizeof(char)*p_char_max);

	if(p_pMessage)
		printf("%s:\n", p_pMessage);
	printf("> ");
	fgets(pTmp, p_char_max, stdin);
	pReplace = strchr(pTmp, '\n');

	if(pReplace != NULL)
		*pReplace = '\0';
	else
		empty_buffer();

	tmp_length = strlen(pTmp);
	pUser_input = (char*) malloc(sizeof(char)*tmp_length);
	strcpy(pUser_input, pTmp);

	return pUser_input;
}
