// 2014. Longest Subsequence Repeated k Times
#include "leetcode.h"

/*
 * you are given a string 's' of length 'n', and an integer 'k. you are tasked
 * to find the longest subsequence repeated 'k' times in 's'. a subsequence is a
 * string that can be derived from another string by deleting some or no
 * characters without changing the order of the remaining characters. a
 * subsequence 'seq' is repeated 'k' times in a sting 's' if 'seq * k' is a
 * subsequence of 's' where 'seq * k' represents a string constructed by
 * concatenating 'seq' 'k' times. return the longest subsequence repeated 'k'
 * times in string 's'. if multiple subsequences are found, return the
 * lexicographically largest one.
 */

#define QUEUE_SIZE 1000000

struct node {
  char str[8];
  int size;
};

static char max[8];

bool is_subseq(const char *s, const char *t) {
  int i = 0, j = 0, ns = strlen(s), nt = strlen(t);
  while (i < ns && j < nt) {
    if (s[i] == t[j])
      j++;
    i++;
  }
  return j == nt;
}

bool is_repeated(const char *s, const char *seq, int k) {
  int n = strlen(seq), total = n * k;
  if (total > strlen(s))
    return false;
  char *repeated = (char *)malloc((total + 1) * sizeof(char));
  for (int i = 0; i < k; i++)
    strncpy(repeated + i * n, seq, n);
  repeated[total] = '\0';
  int res = is_subseq(s, repeated);
  free(repeated);
  return res;
}

char *longestSubsequenceRepeatedK(char *s, int k) {
  int freq[26] = {0}, n = strlen(s);
  for (int i = 0; i < n; i++)
    freq[s[i] - 'a']++;
  char appear[27];
  int idx = 0;
  for (int i = 25; i >= 0; --i)
    if (freq[i] >= k)
      appear[idx++] = i + 'a';
  appear[idx] = '\0';
  struct node queue[QUEUE_SIZE];
  int front = 0, back = 0;
  queue[back++] = (struct node){"", 0};
  max[0] = '\0';
  int mn = 0;
  while (front < back) {
    struct node curr_node = queue[front++];
    char *curr_str = curr_node.str;
    if (curr_node.size < mn)
      continue;
    if (is_repeated(s, curr_str, k)) {
      if (curr_node.size > mn ||
          (curr_node.size == mn && strcmp(curr_str, max) > 0)) {
        strcpy(max, curr_str);
        mn = curr_node.size;
      }
    } else
      continue;
    if (curr_node.size == 7 || curr_node.size >= n / k)
      continue;
    for (int i = 0; i < idx; ++i) {
      if (back >= QUEUE_SIZE)
        break;
      struct node next;
      strcpy(next.str, curr_str);
      next.str[curr_node.size] = appear[i];
      next.str[curr_node.size + 1] = '\0';
      next.size = curr_node.size + 1;
      queue[back++] = next;
    }
  }
  return strdup(max);
}

int main() {
  char *s1 = "letsleetcode", *s2 = "bb", *s3 = "ab";
  char *lsrk1 = longestSubsequenceRepeatedK(s1, 2);
  char *lsrk2 = longestSubsequenceRepeatedK(s2, 2);
  char *lsrk3 = longestSubsequenceRepeatedK(s3, 2);
  printf("%s\n", lsrk1); // expect: let
  printf("%s\n", lsrk2); // expect: b
  printf("%s\n", lsrk3); // expect: null
}
