// 2418. Sort the People
#include "leetcode.h"

/*
 * you are given an array of strings 'names' and an array 'heights' that
 * consists of distinct positive integers. both arrays are of length 'n'. for
 * each index 'i', 'names[i]' and 'heights[i]' denote the name and height of the
 * i'th person. return 'names' sorted in descending order by the people's
 * heights.
 */

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_str(char **a, char **b) {
  char *tmp = *a;
  *a = *b;
  *a = tmp;
}

int partition(char **names, int *heights, int size, int l, int r) {
  int i = l - r, j = r + 1, pivot = heights[l];
  while (1) {
    do
      ++i;
    while (heights[i] > pivot);
    do
      --j;
    while (heights[j] < pivot);
    if (i < j) {
      swap(&heights[i], &heights[j]);
      swap_str(&names[i], &names[j]);
    } else
      return j;
  }
}

void quick_sort(char **names, int *heights, int size, int l, int r) {
  if (l >= r)
    return;
  int p = partition(names, heights, size, l, r);
  quick_sort(names, heights, size, l, p);
  quick_sort(names, heights, size, p + 1, r);
}

char **sortPeople(char **names, int namesSize, int *heights, int heightsSize,
                  int *returnSize) {
  quick_sort(names, heights, namesSize, 0, namesSize - 1);
  *returnSize = namesSize;
  return names;
}

int main() {
  char *n1[] = {"Mary", "John", "Emma"}, *n2[] = {"alice", "Bob", "Bob"};
  int h1[] = {180, 165, 170}, h2[] = {155, 185, 150}, rs1, rs2;
  char **sp1 =
      sortPeople((char **)n1, ARRAY_SIZE(n1), h1, ARRAY_SIZE(h1), &rs1);
  char **sp2 =
      sortPeople((char **)n2, ARRAY_SIZE(n2), h2, ARRAY_SIZE(h2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", sp1[i]); // expect: "Mary","Emma","John"
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", sp2[i]); // expect: "Bob","Alice","Bob"
  printf("\n");
  free(sp1), free(sp2);
}
