#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("usage: test-xinu <xinu code directory>\n");
		return EXIT_FAILURE;
	}
	int status = chdir(argv[1]);
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
