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
#include "main.h"

int main(int argc, char *argv[])
{
	char *string = NULL;
	int loop = 1, user_input = 0;

	header();

	while(loop)
	{
		menu();
		string = input("Type a number [0-6]", MEDIUM_LENGTH);
		user_input = atoi(string);
		printf("\n");

		switch(user_input)
		{
			case 0:
				loop = 0;
				break;
			case 1:
				string = input("[+] characters \\#*% are not handled", STRING_LENTGH);
				string = alph_to_morse(string);
				printf("\n[+] %s\n\n", string);
				break;
			case 2:
				string = input("[+] Put space between characters and double space between words", STRING_LENTGH);
				string = morse_to_alph(string);
				printf("\n[+] %s\n\n", string);
				break;
			case 3:
				print_alphabet(ALPH_SIZE);
				break;
			case 4:
				print_alphabet(NUM_SIZE);
				break;
			case 5:
				print_alphabet(SPE_SIZE);
				break;
			case 6:
				print_marine_code();
				break;
			default:
				printf("[!] Bad input\n");
				break;
		}
		printf("\n");
	}

	return 0;
}

void header()
{
	printf("\t\t\t\tMorse application\n\n"
		"[-] Developped by Kalizox\n"
		"[+] kalizox@pm.me\n"
		"[-] Version 1.0\n"
		"[-] International morse code\n"
		"[+] Learn more at: https://en.wikipedia.org/wiki/Morse_code\n\n"
		"\t\tMenu\n\n");
}

void menu()
{
	printf("[-] 1. Convert to morse\n"
		"[-] 2. Convert to alphanumeric\n"
		"[-] 3. Print morse alphabet\n"
		"[-] 4. Print numeric morse alphabet\n"
		"[-] 5. Print symbol morse alphabet\n"
		"[-] 6. Print marine code\n"
		"[-] 0. Quit\n\n");
}
