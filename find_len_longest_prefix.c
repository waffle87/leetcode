// 3043. Find the Length of the Longest Common Prefix
#include "leetcode.h"

/*
 * given two arrays with positive integers 'arr1' and 'arr2'. a prefix of a
 * positive integer is an integer formed by one or more of its digits, starting
 * from its leftmost digit. a common prefix of two integers 'a' and 'b' is an
 * integer 'c' such that is a prefix of both a and b. for example 6555359 and
 * 56554 have a common prefix 565 while q223 and 43456 do not have a common
 * prefix. return the length of the longest common prefix among all pairs. if no
 * common prefix exists among them, return 0.
 */

struct node {
  char val;
  int height;
  struct node *children[10];
};

struct trie {
  struct node *root;
};

int longestCommonPrefix(int *arr1, int arr1_size, int *arr2, int arr2_size) {}

int main() {
  int a11[] = {1, 10, 100}, a21[] = {1000};
  int a12[] = {1, 2, 3}, a22[] = {4, 4, 4};
  printf("%d\n", longestCommonPrefix(a11, ARRAY_SIZE(a11), a21,
                                     ARRAY_SIZE(a21))); // expect: 3
  printf("%d\n", longestCommonPrefix(a12, ARRAY_SIZE(a12), a22,
                                     ARRAY_SIZE(a22))); // expect: 3
}
