#include <stdio.h>
#include <stdlib.h>

#include "dred.h"

int main(void) {
	struct string s;
	initstr(&s);

	getstr(&s, "https://drednot.io/api/scoreboard");

	struct ship *buf = malloc(sizeof(struct ship) * GRAB_AMOUNT);

	parsetext(s.str, buf);
	printf("%s\n", buf->name);

	return 0;
}
