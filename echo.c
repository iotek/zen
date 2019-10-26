#include <stdio.h>


int
main(int argc, char **argv) {
	(void)*argv++;
	(void)argc--;

	while (*argv)
		printf("%s%c", *argv++, --argc ? ' ' : '\n');


	return 0;
}
