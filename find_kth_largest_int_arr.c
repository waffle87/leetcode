// 1985. Find the Kth Largest Integer in the Array
#include "leetcode.h"

/*
 * you are given an array of strings 'nums' and an integer 'k'. each string in
 * 'nums' represents an integer without leading zeros. return the string that
 * represents the k'th largest integer in 'nums'. duplicate numbers should be
 * counted distinctly.
 */

int cmp(const void *a, const void *b) {
  char *aa = *(char **)a, *bb = *(char **)b;
  int na = strlen(aa), nb = strlen(bb);
  if (na == nb) {
    for (int i = 0; i < na; i++)
      if (aa[i] != bb[i])
        return aa[i] - bb[i];
    return 0;
  }
  return na - nb;
}

bool is_leq(char *s, char *t) {
  int n1 = strlen(s), n2 = strlen(t);
  if (n1 < n2)
    return true;
  if (n1 > n2)
    return false;
  for (int i = 0; i < n1; i++) {
    if (s[i] < t[i])
      return true;
    if (s[i] > t[i])
      return false;
  }
  return true;
}

void insert(char **heap, int k, char *s) {
  if (is_leq(s, heap[0]))
    return;
  heap[0] = s;
  int f = 0;
  while (1) {
    int s1 = 2 * f + 1, s2 = 2 * f + 2;
    if (s2 < k) {
      if (is_leq(heap[s1], heap[s2])) {
        if (is_leq(heap[s1], heap[f])) {
          char *tmp = heap[f];
          heap[f] = heap[s1];
          heap[s1] = tmp;
          f = s1;
        } else {
          break;
        }
      } else {
        if (is_leq(heap[s2], heap[f])) {
          char *tmp = heap[f];
          heap[f] = heap[s2];
          heap[s2] = tmp;
          f = s2;
        } else {
          break;
        }
      }
    } else if (s1 < k) {
      if (is_leq(heap[s1], heap[f])) {
        char *tmp = heap[f];
        heap[f] = heap[s1];
        heap[s1] = tmp;
        f = s1;
      } else {
        break;
      }
    } else {
      break;
    }
  }
}

char *kthLargestNumber(char **nums, int numsSize, int k) {
  char **heap = (char **)malloc((k + 1) * sizeof(char *));
  for (int i = 0; i < k; i++)
    heap[i] = nums[i];
  qsort(heap, k, sizeof(char *), cmp);
  for (int i = k; i < numsSize; i++)
    insert(heap, k, nums[i]);
  return heap[0];
}

int main() {
  char *n1[] = {"3", "6", "7", "10"}, *n2[] = {"2", "21", "12", "1"},
       *n3[] = {"0", "0"};
  printf("%s\n", kthLargestNumber((char **)n1, ARRAY_SIZE(n1), 4)); // expect: 3
  printf("%s\n", kthLargestNumber((char **)n2, ARRAY_SIZE(n2), 3)); // expect: 2
  printf("%s\n", kthLargestNumber((char **)n3, ARRAY_SIZE(n3), 2)); // expect: 0
}
