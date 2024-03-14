#include <stdio.h>

int *func2_ptr;

void func2() {
  int func2_data = 120;
  func2_ptr = &func2_data;
}

void func1() {
  func2();
}

int main() {
  func1();
  printf("func2_data address: %d\n", *func2_ptr);
  return 0;
}