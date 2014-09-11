#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	char dir[4096];
	char* home = getenv("HOME");
	if(home == NULL) {
		fprintf(stderr, "Couldn't get user home directory!\n");
		return EXIT_FAILURE;
	}
	sprintf(dir, "%s/%s", home, "xinu-14Fall-lab0-linksys/compile");
	int status = chdir(dir);
	if(status != 0) {
		fprintf(stderr, "Couldn't change directory to compile!\n");
		return EXIT_FAILURE;
	}
	FILE* fp;
	char line[1024];
	fp = popen("make", "r");
	if(fp == NULL) {
		fprintf(stderr, "Couldn't run make!\n");
		return EXIT_FAILURE;
	}
	while(fgets(line, sizeof(line)-1, fp) != NULL) {
		printf("%s", line);
	}
	status = pclose(fp);
	if(status != 0) {
		fprintf(stderr, "Make failed!\n");
		return EXIT_FAILURE;
	}
	execl("/p/xinu/bin/mips-console", "mips-console", NULL);
}
