#include <stdio.h>

int *func2_ptr;

void func2() {
  int func2_data = 120;
  func2_ptr = &func2_data;
}

void func1() {
  func2();
}

void func3() {
  char buffer[200000] = {0};
  int i = 0;
  for (i = 0; i < 200000; i++) {
    buffer[i] = i;
  }
}

int main() {
  func1();
  printf("func2_data address: %d\n", *func2_ptr);
  func3();
  printf("func2_data address: %d\n", *func2_ptr);
  return 0;
}