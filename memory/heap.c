#include <stdio.h>
#include <stdlib.h>

int *heap() {
  int *a = (int *)malloc(sizeof(int));
  *a = 3;
  return a;
}

int main(void) {
  int *a = heap();
  printf("A(%p): %d\n", a, *a);
}