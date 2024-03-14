#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));
  printf("Hello A: %p\n", a);
  printf("Hello B: %p\n", b);
  free(a);
  free(b);

  int *c = (int*)malloc(sizeof(int));
  printf("Hello C: %p\n", c);
  free(c);

  return 0;
}