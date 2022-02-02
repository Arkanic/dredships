#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "dred.h"

int main(void) {
	FILE *fptr = opendat();
	appendcsvheader(fptr);

	struct string s;
	initstr(&s);

	int offset = 0;
	while(1) {
		char url[256] = {0};
		char offseturl[64] = {0};
		if(offset != 0) snprintf(offseturl, 64, "&offset_score=%d", offset);

		snprintf(url, 256, "https://drednot.io/api/scoreboard?count=%d%s", GRAB_AMOUNT, offseturl);
		getstr(&s, url);

		struct ship *buf = malloc(sizeof(struct ship) * GRAB_AMOUNT);
		parsetext(s.str, buf);

		struct ship newship = buf[GRAB_AMOUNT - 1];
		int newscore = newship.score;

		if(offset == newscore) break;

		appendcsvships(fptr, buf, GRAB_AMOUNT);
		printf("%s - %d\n", newship.name, newscore);
		
		offset = newscore;

		free(buf);

		sleep(1);
	}

	closedat(fptr);

	printf("Done.\n");

	return 0;
}
