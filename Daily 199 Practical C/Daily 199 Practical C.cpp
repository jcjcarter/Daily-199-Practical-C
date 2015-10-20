// Daily 199 Practical C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define BNRDIGITS 9

char *pat[] = {
	" _     _  _     _  _  _  _  _ ",
	"| |  | _| _||_||_ |_   ||_||_|",
	"|_|  ||_  _|  | _||_|  ||_| _|"
};

long debanner(char in[][BUFSIZE])
{
	int pos, dig, i, match;
	long n = 0;
	for (i = 0; i < 3; i++)
		for (pos = strlen(in[i]); pos < BNRDIGITS * 3; pos++)
			in[i][pos] = ' ';
	for (pos = 0; pos < BNRDIGITS && n >= 0; pos++) {
		for (dig = 0, match = 0; dig < 10 && !match; dig++)
			for (i = 0, match = 1; i < 9 && match; i++)
				if (in[i / 3][i % 3 + pos * 3] != pat[i / 3][i % 3 + dig * 3])
					match = 0;
		if (match)
			n = n * 10 + dig - 1;
		else
			n = -1;
	}
	return n;
}

int main()
{
	int i = 0;
	char buf[4][BUFSIZE];
	while (fgets(buf[i], BUFSIZE, stdin) != NULL) {
		buf[i][strlen(buf[i]) - 1] = '\0';
		if (++i >= 4) {
			printf("%ld\n\n", debanner(buf));
			i = 0;
		}
	}
	if (i == 3)
		printf("%ld\n\n", debanner(buf));
	return 0;
}