#include <stdio.h>
#include <stdint.h>

int main(void) {
  int64_t apple = 3;
  int64_t orange = 7;
  int64_t name[4] = {1, 2, 3, 4};

  printf("apple address: %p\n", &apple);
  printf("orange address: %p\n", &orange);
  printf("name address: %p\n", name);

  return 0;
}