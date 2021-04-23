#include <stdio.h>

int func2(int a) {
  return a + 3;
}

int func1(int a) {
  int b = 0;
  for(int i = a; a != 0; a >> 1) {
    if (i & 1 != 0) {
      b = func2(b);
    }
  }
}

int main(int argc, char *argv[]) {
  int temp = atoi(argv[1]);
  printf("Result: %ld\n", func1(temp));
}