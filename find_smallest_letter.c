// 744. Find Smallest Letter Greater Than Target
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* given an array of characters 'letters' that is sorted in non-decreasing
 * order, and a character 'target'. there are at least two different characters
 * in 'letters'. return the smallest character in 'letters' that is
 * lexicographically greater than 'target'. if such a character does not exist,
 * return the first character in 'letters'.
 */

char nextGreatestLetter(char *letters, int letters_size, char target) {
  int start = 0, end = letters_size - 1, mid;
  while (start < end) {
    mid = start + (end - start) / 2;
    if (letters[mid] - target < 0)
      start = mid + 1;
    else if (letters[mid] - target > 0)
      end = mid;
    else
      break;
  }
  while (mid < letters_size - 1 && letters[mid] <= target)
    mid++;
  char ans = letters[mid];
  return letters[mid] <= target && mid == letters_size - 1 ? letters[0] : ans;
}

int main() {
  char l1_2[] = {'c', 'f', 'j'};
  char l3[] = {'x', 'x', 'y', 'y'};
  printf("%c\n", nextGreatestLetter(l1_2, 3, 'a')); // expect: c
  printf("%c\n", nextGreatestLetter(l1_2, 3, 'c')); // expect: f
  printf("%c\n", nextGreatestLetter(l1_2, 4, 'z')); // expect: x
}
