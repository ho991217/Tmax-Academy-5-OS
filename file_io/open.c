#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 5
char fname[]="alphabet.txt";


int main() {
	int fd, size;
	char buf[MAX_BUF];

	fd = open(fname,O_RDONLY);
	if(fd<0) {
		printf("Can't open %s file with errno %d\n", fname, errno);
		exit(-1);
	}
	size = read(fd,buf,MAX_BUF);
	if(size < 0) {
		printf("Can't read from file %s, size=%d\n", fname, size);
	} else {
		printf("size of read data is %d\n",size);
	}
	close(fd);
}
