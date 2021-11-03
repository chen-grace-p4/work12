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

	int size = 0;

	dent = readdir(d);

	printf("Statistics for current directory: . \n");
	while(dent) {
		stat(dent->d_name, &sb);
		if (dent->d_type == 8) {
			size += sb.st_size;
			printf("\tRegular File: %s \n", dent->d_name);
		}
		if (dent->d_type == 4) {
			printf("\tDirectory: %s \n", dent->d_name);
		}
		dent = readdir(d);
	}

	printf("Total Directory Size: %d Bytes\n", size);

	printf("Clearer print of files/directories:\n");


	printf("Directories:\n");
	rewinddir(d);
	dent = readdir(d);
	while (dent) {
		if (dent->d_type == 4) {
		printf("\t%s\n", dent->d_name);
		}
		dent = readdir(d);
	}

	printf("Regular files:\n");
	rewinddir(d);
	dent = readdir(d);
	while (dent) {
		if (dent->d_type == 8) {
		printf("\t%s\n", dent->d_name);
		}
		dent = readdir(d);
	}

	closedir(d);
	return 0;
}
