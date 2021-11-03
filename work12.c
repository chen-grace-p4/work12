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
	stat("nums.data", &sb);
	printf("size: %lu\n", sb.st_size);
	printf("perms: %o\n", sb.st_mode);
	printf("access time: %s\n", ctime(&(sb.st_atime)));

	DIR *d;
	struct dirent *dent;
	d = opendir(".");

	dent = readdir(d);
	printf("name: %s\n", dent->d_name);
	dent = readdir(d);
	printf("name: %s\n", dent->d_name);

	return 0;
}
