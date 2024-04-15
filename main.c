#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char*, int);

int main(int argc, char **argv) {
	if (argc != 4) {
		printf("Usage: rtpc r g b\n");
		return -1;
	}

	float res[3];

	for (int i = 1; i < 4; i++) {
		if (!isNumber(argv[i], strlen(argv[i]))) {
			printf("Invalid values!\n");
			return -1;
		}
		res[i-1] = atof(argv[i]) / 255.0f;
	}

	printf("rgb(");
	for (int i = 0; i < 3; i++) {
		printf("%.2f", res[i]);
		if (i != 2) printf(" ");
	}
	printf(")\n");

	return 0;
}

int isNumber(char *n, int len) {
	for (int i = 0; i < len; i++)
		if (!isdigit(n[i]))
			return 0;
	return 1;
}
