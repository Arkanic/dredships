#include <stdio.h>
#include <stdlib.h>

#include "dred.h"

int main(void) {
	struct string s;
	initstr(&s);

	char url[256];
	snprintf(url, 256, "https://drednot.io/api/scoreboard?count=%d", GRAB_AMOUNT);

	getstr(&s, url);

	struct ship buf[1000];

	parsetext(s.str, buf);
	for(int i = 0; i < GRAB_AMOUNT; i++) {
		printf("%s\n", buf[i].name);
	}

	return 0;
}
