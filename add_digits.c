// 258. Add Digits
#include <stdio.h>

// given an integer 'num', repeatedly add all its digits until
// the result has onlye one digit and return it

int addDigits(int num) {
  int sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }
  if (sum < 10)
    return sum;
  else
    return addDigits(sum);
}

int main() {
  printf("%d\n", addDigits(38)); // expect: 2
  printf("%d\n", addDigits(0));  // expect: 0
}
