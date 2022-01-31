#include <stdio.h>
#include <stdlib.h>

#include "dred.h"

int main(void) {
	struct string s;
	initstr(&s);

	getstr(&s, "https://drednot.io/api/scoreboard");

	printf("%s\n", s.str);
	free(s.str);

	return 0;
}
