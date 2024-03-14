#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]) {
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	// 두개가 아니면
	if(argc != 2) {
		printf("USAGE: %S file_name\n", argv[0]);
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("Can't open file with errno %d\n", errno);
		exit(-1);
	}
	while(1) {
		read_size = read(fd,buf,MAX_BUF);
		if(read_size == 0) break;
	
		write_size = write(STDOUT_FILENO,buf,read_size);
	}
	close(fd);
}
