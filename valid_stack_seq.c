// 946. Validate Stack Sequences
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given two integer arrays 'pushed' & 'popped' each with distinct
 * values, return true if this could have been the result of a sequence
 * of push and pop operations on an initially empty stack, or false otherwise
 */

bool validateStackSequences(int *pushed, int pushed_size, int *popped,
                            int popped_size) {
  int i = 0, j = 0, k = 0;
  int *s = (int *)malloc(pushed_size * sizeof(int));
  while (k >= 0 && k < pushed_size && j < popped_size) {
    if (k > 0 && s[k - 1] == popped[j]) {
      k--;
      j++;
    } else {
      if (i < pushed_size) {
        if (pushed[i] == popped[j]) {
          i++;
          j++;
        } else
          s[k++] = pushed[i++];
      } else {
        free(s);
        return false;
      }
    }
  }
  free(s);
  return true;
}

int main() {
  int pushed[] = {1, 2, 3, 4, 5};
  int p1[] = {4, 5, 3, 2, 1}, p2[] = {4, 3, 5, 1, 2};
  printf("%d\n", validateStackSequences(pushed, 5, p1, 5)); // expect: 1
  printf("%d\n", validateStackSequences(pushed, 5, p2, 5)); // expect: 0
}
