#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

int main() {
	struct stat sb;

	DIR *d = opendir(".");
	struct dirent *dent;

	unsigned long size = 0;

	while(dent) {
		stat(dent->d_name, &sb);
		if (dent->d_type == 8) {
			size += sb.st_size;
			printf("Regular File: %s \n", dent->d_name);
		}
		if (dent->d_type == 4) {
			printf("Directory: %s \n", dent->d_name);
		}
		dent = readdir(d);
	}

	return 0;
}
