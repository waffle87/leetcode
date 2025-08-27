// 2381. Shifting Letters II
#include "leetcode.h"

/*
 * you are given a string 's' of lowercase english letters and a 2d integer
 * array 'shifts' where 'shifts[i] = [start_i, end_i, direction_i]'. for every
 * 'i', shift the characters in 's' from the index 'start_i' to he index 'end_i'
 * (inclusive) forward if the 'direction_i = 1' or shift the characters backward
 * if 'direction_i = 0'. shifting a character forward means replacing it with
 * the next letter in the alphabet. similarily, shifting a character backward
 * means replacing it with the previous alphabetic character. return the final
 * string ater all such shifts to 's' are applied
 */

char *shiftingLetters(char *s, int **shifts, int shiftsSize,
                      int *shiftsColSize) {
  int n = strlen(s), *shift = (int *)calloc(n + 1, sizeof(int));
  for (int i = 0; i < shiftsSize; ++i) {
    int start = shifts[i][0], end = shifts[i][1], direction = shifts[i][2];
    shift[start] += (direction == 1 ? 1 : -1);
    if (end + 1 < n)
      shift[end + 1] -= (direction == 1 ? 1 : -1);
  }
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    curr += shift[i];
    shift[i] = curr;
  }
  for (int i = 0; i < n; ++i) {
    int net = (shift[i] % 26 + 26) % 26;
    s[i] = 'a' + (s[i] - 'a' + net) % 26;
  }
  free(shift);
  return s;
}

int main() {
  char *s1 = "abc", *s2 = "dztz";
  int s1i[3][3] = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}},
      s2i[2][3] = {{0, 0, 0}, {1, 1, 1}};
  struct two_d_arr *sh1 = two_d_arr_init(3, 3, s1i);
  struct two_d_arr *sh2 = two_d_arr_init(2, 3, s2i);
  printf("%s\n", shiftingLetters(s1, sh1->arr, sh1->row_size,
                                 sh1->col_size)); // expect: ace
  printf("%s\n", shiftingLetters(s2, sh2->arr, sh2->row_size,
                                 sh2->col_size)); // expect: catz
  two_d_arr_free(sh1);
  two_d_arr_free(sh2);
}
