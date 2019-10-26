#include <dirent.h>
#include <stdio.h>
#include <err.h>
#include "arg.h"

int aflag = 0;

void
ls(const char *path) {
	DIR *dir;
	struct dirent *dp;

	dir = opendir(path);
	if (dir == NULL) {
		warn("opendir");
		return;
	}

	while ((dp = readdir(dir)) != NULL) {
		if (dp->d_name[0] == '.' && !aflag)
			continue;

		printf("%s\n", dp->d_name);
	}

	closedir(dir);
}

int
main(int argc, char **argv) {
	char *argv0;

	ARGBEGIN {
	case 'a':
		aflag = 1;
		break;
	} ARGEND

	if (argc)
		while (*argv)
			ls(*argv++);
	else
		ls(".");

	return 0;
}
