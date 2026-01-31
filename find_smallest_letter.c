// 744. Find Smallest Letter Greater Than Target
#include "leetcode.h"

/*
 * given an array of characters 'letters' that is sorted in non-decreasing
 * order, and a character 'target'. there are at least two different characters
 * in 'letters'. return the smallest character in 'letters' that is
 * lexicographically greater than 'target'. if such a character does not exist,
 * return the first character in 'letters'.
 */

char nextGreatestLetter(char *letters, int lettersSize, char target) {
  for (int i = 0; i < lettersSize; i++)
    if ((int)letters[i] > (int)target)
      return letters[i];
  return letters[0];
}

int main() {
  char l1[] = {'c', 'f', 'j'};
  char l2[] = {'c', 'f', 'j'};
  char l3[] = {'x', 'x', 'y', 'y'};
  printf("%c\n", nextGreatestLetter(l1, ARRAY_SIZE(l1), 'a')); // expect: c
  printf("%c\n", nextGreatestLetter(l2, ARRAY_SIZE(l2), 'c')); // expect: f
  printf("%c\n", nextGreatestLetter(l3, ARRAY_SIZE(l3), 'z')); // expect: x
}
