#include <stdio.h>
#include <stdlib.h>

#include "dred.h"

int main(void) {
	struct string s;
	initstr(&s);

	getstr(&s, "https://drednot.io/api/scoreboard");

	struct ship buf[1000];

	parsetext(s.str, buf);
	for(int i = 0; i < GRAB_AMOUNT; i++) {
		printf("%s\n", buf[i].name);
	}

	return 0;
}
