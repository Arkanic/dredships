#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dred.h"

int main(void) {
	struct string s;
	initstr(&s);

	int offset = 0;
	while(1) {
		char url[256];
		char offseturl[64];
		if(offset != 0) snprintf(offseturl, 64, "&offset_score=%d", offset);
		snprintf(url, 256, "https://drednot.io/api/scoreboard?count=%d%s", GRAB_AMOUNT, offseturl);
		getstr(&s, url);

		struct ship buf[GRAB_AMOUNT];
		parsetext(s.str, buf);

		int newscore = buf[GRAB_AMOUNT - 1].score;
		char *newname = strdup(buf[GRAB_AMOUNT - 1].name);

		printf("%s - %d\n", newname, newscore);
		if(offset == newscore) break;
		offset = newscore;
	}

	printf("Done.\n");

	return 0;
}
