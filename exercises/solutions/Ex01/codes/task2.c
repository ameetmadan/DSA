#include <stdbool.h>
#include <stdio.h>

bool isPerfectSquare(int num) {
  int i = 0;
  while (i * i <= num) {
    if (i * i == num) {
      return true;
    }
    i++;
  }
  return false;
}

int main() {
  bool perfectSquareCheck;

  int num;

  printf("Please enter an integer to check if it is perfect square number: ");
  scanf("%d", &num);
  perfectSquareCheck = isPerfectSquare(num);

  if (perfectSquareCheck) {
    printf("Result string: %s\n", "TRUE");
  } else {
    printf("Result string: %s\n", "FALSE");
  }
  return 0;
}
// Linux, Mac: gcc task2.c -o task2; ./task2