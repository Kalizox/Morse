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

#include <stdio.h>
#include <stdlib.h>
#include "morse.h"

char *morse_alphabet[ALPH_SIZE] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",  "...-", ".--", "-..-", "-.--", "--.."};

char *morse_numbers[NUM_SIZE] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

char *morse_symbols[SPE_SIZE] = {".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-."};

char *alph_symbols[SPE_SIZE] = {".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@"};

void count_char(char *p_pMorse_string, int p_count_words, int *p_pCount_char)
{
	int i = 0, j = 0;

	if(!p_pCount_char)
	{
		fprintf(stderr, "p_pCount_char not allocated\n");
		exit(0);
	}

	for(i=0; i<strlen(p_pMorse_string); i++)
	{
		if(p_pMorse_string[i] == '\0')
			break;

		if(p_pMorse_string[i] == ' ' && p_pMorse_string[i+1] == ' ')
			j++;

		if(p_pMorse_string[i] == ' ')
			continue;

		p_pCount_char[j]++;
	}
}

int count_Morse_word(char *p_pMorse_string)
{
	int i = 0, count_word = 0;

	for(i=0; i<strlen(p_pMorse_string); i++)
	{
		if(p_pMorse_string[i+1] == '\0')
		{
			count_word++;
			break;
		}

		if(p_pMorse_string[i] == ' ' && p_pMorse_string[i+1] == ' ')
			count_word++;
	}

	return count_word;	
}

char *seek_char(char *p_pMorse_string)
{
	char *pTmp = NULL;
	int i = 0, found = -1;

	pTmp = (char*) malloc(sizeof(char));

	for(i=0; i<ALPH_SIZE; i++)
	{
		found = strcmp(p_pMorse_string, morse_alphabet[i]);

		if(found == 0)
		{
			*pTmp = i+97;
			break;
		}
	}

	for(i=0; i<NUM_SIZE; i++)
	{
		found = strcmp(p_pMorse_string, morse_numbers[i]);

		if(found == 0)
		{
			*pTmp = i+48;
			break;
		}
	}

	for(i=0; i<SPE_SIZE; i++)
	{
		found = strcmp(p_pMorse_string, morse_symbols[i]);

		if(found == 0)
		{
			strcpy(pTmp, alph_symbols[i]);
			break;
		}
	}

	return pTmp;
}

char *parse_morse_code(char *p_pMorse_string)
{
	char *pTmp = NULL, *pChar = NULL;
	int i = 0;

	pTmp = (char*) malloc(sizeof(char)*MORSE_LENGTH_MAX+1); pChar = (char*) malloc(sizeof(char));

	for(i=0; i<MORSE_LENGTH_MAX; i++)
	{
		if(p_pMorse_string[i] == ' ' || p_pMorse_string[i] == '\0')
			break;

		pTmp[i] = p_pMorse_string[i];
	}

	pTmp[i+1] = '\0';
	pChar = seek_char(pTmp); 

	free(pTmp);

	return pChar;
}

char *morse_to_alph(char *p_pMorse_string)
{
	char *pString = NULL, *pChar = NULL, *pTmp = NULL, *pCount_words = NULL;
	int *pCount_char = NULL;
	int i = 0, j = 0, alph_pos = 0, count_word = 0, pos = 0, tmp_length = 0;

	pString = (char*) malloc(sizeof(char)*(strlen(p_pMorse_string)/2));
	pChar = (char*) malloc(sizeof(char));

	count_word = count_Morse_word(p_pMorse_string);

	pCount_char = (int*) calloc(sizeof(int), count_word);

	if(count_word > 1)	
		count_char(p_pMorse_string, count_word, pCount_char);

	pTmp = strtok(p_pMorse_string, " ");

	while(pTmp != NULL)
	{
		tmp_length += strlen(pTmp);

		pChar = seek_char(pTmp);
		if(i == 0)

			strcpy(pString, pChar);
		else
			strcat(pString, pChar);
		if(tmp_length  == pCount_char[j])
		{
			strcat(pString, " ");
			j++;
			tmp_length = 0;
		}

		pTmp = strtok(NULL, " ");
		i++;
	}

	free(pChar);
	free(pTmp);
	free(pCount_char);
	free(pCount_words);
	
	return pString;
}

char *alph_to_morse(char *p_pUser_string)
{
	char *pMorse_string = NULL;
	int i = 0, alph_pos = 0, numeric_flag = 0, symbol_flag = 0;

	pMorse_string = (char*) malloc(sizeof(char)*(strlen(p_pUser_string)*7));

	for(i=0; i<strlen(p_pUser_string); i++)
		p_pUser_string[i] = (char) tolower(p_pUser_string[i]);

	for(i=0; i<strlen(p_pUser_string); i++)
	{
		numeric_flag = 0;
		symbol_flag = 0;

		if(p_pUser_string[i] == '\n' || p_pUser_string[i] == '\0')
		{
			strcat(pMorse_string, "\0");
			break;
		}

		if(p_pUser_string[i] == ' ')
		{
			strcat(pMorse_string, " ");
			continue;
		}

		if(p_pUser_string[i] > 47 && p_pUser_string[i] < 58)
		{
			numeric_flag = 1;
			alph_pos = p_pUser_string[i] - 48;
		}
		else if(p_pUser_string[i] > 96 && p_pUser_string[i] < 123) // it was simple else before
			alph_pos = p_pUser_string[i] - 97;
		else
		{
			symbol_flag = 1;
			
			if(p_pUser_string[i] == '.')
				alph_pos = 0;
			if(p_pUser_string[i] == ',')
				alph_pos = 1;
			if(p_pUser_string[i] == '?')
				alph_pos = 2;
			if(p_pUser_string[i] == '\'')
				alph_pos = 3;
			if(p_pUser_string[i] == '!')
				alph_pos = 4;
			if(p_pUser_string[i] == '/')
				alph_pos = 5;
			if(p_pUser_string[i] == '(')
				alph_pos = 6;
			if(p_pUser_string[i] == ')')
				alph_pos = 7;
			if(p_pUser_string[i] == '&')
				alph_pos = 8;
			if(p_pUser_string[i] == ':')
				alph_pos = 9;
			if(p_pUser_string[i] == ';')
				alph_pos = 10;
			if(p_pUser_string[i] == '=')
				alph_pos = 11;
			if(p_pUser_string[i] == '+')
				alph_pos = 12;
			if(p_pUser_string[i] == '-')
				alph_pos = 13;
			if(p_pUser_string[i] == '_')
				alph_pos = 14;
			if(p_pUser_string[i] == '\"')
				alph_pos = 15;
			if(p_pUser_string[i] == '$')
				alph_pos = 16;
			if(p_pUser_string[i] == '@')
				alph_pos = 17;
		}

		if(i == 0)
		{
			if(numeric_flag == 1)
				strcpy(pMorse_string, morse_numbers[alph_pos]);
			else if(symbol_flag == 1)
				strcpy(pMorse_string, morse_symbols[alph_pos]);
			else
				strcpy(pMorse_string, morse_alphabet[alph_pos]);

			strcat(pMorse_string, " ");
		}
		else
		{
			if(numeric_flag == 1)
				strcat(pMorse_string, morse_numbers[alph_pos]);
			else if(symbol_flag == 1)
				strcat(pMorse_string, morse_symbols[alph_pos]);
			else
				strcat(pMorse_string, morse_alphabet[alph_pos]);

			strcat(pMorse_string, " ");
		}
	}

	return pMorse_string;
}

void print_alphabet(int p_alph)
{
	int i = 0;

	printf("\n");

	for(i=0; i<p_alph; i++)
	{
		if(p_alph == ALPH_SIZE)
			printf("[-] %c = %s\n",97+i, morse_alphabet[i]);
		if(p_alph == NUM_SIZE)
			printf("[-] %c = %s\n", 48+i, morse_numbers[i]);
		if(p_alph == SPE_SIZE)
		{
			if(i == 0)
				printf("[-] . = .-.-.-\n");
			else
				printf("[-] %s = %s\n", alph_symbols[i], morse_symbols[i]);
		}
	}

	printf("\n");

	return;
}

void print_marine_code()
{
	printf("[+] Miscellaneous abbreviations and Signals in radiocommunications of the maritime mobile service\n\n");

	printf("[-] ...---...\t:\t\tSOS\t\t\t:\tInternational distress call\n"
		"[-] -.-\t\t\t\t\t:\t\t(K)\t\t\t:\tContact, invitation to transmit\n"
		"[-] .-.-\t\t\t\t:\t\tAA\t\t\t\t:\tStart of message\n"
		"[-] ........\t:\t\tHH\t\t\t\t:\tError from the issuer\n"
		"[-] .-...-.\t\t:\t\tRF\t\t\t\t:\tBad signal, adjust your lights! (if light transmission)\n"
		"[-] .-...-..\t:\t\tLL\t\t\t\t:\tStronger light! (light transmission)\n"
		"[-] .--..--.\t:\t\tPP\t\t\t\t:\tLess light! (light transmission)\n"
		"[-] ....-..\t\t:\t\tSL\t\t\t\t:\tSlow down\n"
		"[-] -...-\t\t\t\t:\t\tBT (=)\t\t:\tStop. New paragraph\n"
		"[-] .-.-.\t\t\t\t:\t\tAR (+)\t\t:\tEnd of message/transmission\n"
		"[-] ..--..\t\t\t:\t\tIMI (?)\t:\tRepeat\n"
		"[-] ...-.\t\t\t\t:\t\tVE\t\t\t\t:\tUnderstood\n"
		"[-] .-...\t\t\t\t:\t\tAS\t\t\t\t:\tWait\n"
		"[-] ...-.-\t\t\t:\t\tVA, SK\t\t:\tOver\n\n");
}
