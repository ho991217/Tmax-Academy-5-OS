#include <stdio.h>
#include "test1.h"
#include "test2.h"

int main() {
	printf("Hello, gcc\n");

	print_function1();
	print_function2();

	printf("Bye!\n");

	return 0;
}
