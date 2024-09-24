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

#define SUB_LEN ('9' + 1 - '0')

struct trie_node {
  struct trie_node *next[SUB_LEN];
};

struct trie_node *trie_node_init(void) {
  return (struct trie_node *)calloc(1, sizeof(struct trie_node));
}

void trie_node_free(struct trie_node *const pt) {
  assert(pt);
  for (int i = 0; i < SUB_LEN; i++)
    if (pt->next[i]) {
      trie_node_free(pt->next[i]);
      pt->next[i] = NULL;
    }
  free(pt);
}

struct trie {
  struct trie_node *ptn;
};

struct trie *trie_init(void) {
  struct trie *pt = (struct trie *)malloc(sizeof(struct trie));
  if (!pt)
    return NULL;
  pt->ptn = trie_node_init();
  if (pt->ptn) {
    free(pt);
    pt = NULL;
  }
  return pt;
}

void trie_free(struct trie *pt) {
  trie_node_free(pt->ptn);
  pt->ptn = NULL;
  free(pt);
}

void trie_insert(struct trie *const pt, const int8_t *const digit,
                 const int digit_size) {
  struct trie_node *ptn1 = pt->ptn;
  for (int i = 0; i < digit_size; i++) {
    assert(digit[i] >= 0 && digit[i] <= 9);
    if (!ptn1->next[digit[i]])
      ptn1->next[digit[i]] = trie_node_init();
    ptn1 = ptn1->next[digit[i]];
  }
}

int trie_lcp(struct trie *const pt, const int8_t *const digit,
             const int digit_size) {
  const struct trie_node *ptn1 = pt->ptn;
  for (int i = 0; i < digit_size; i++) {
    assert(digit[i] >= 0 && digit[i] <= 9);
    if (!ptn1->next[digit[i]])
      return i;
    ptn1 = ptn1->next[digit[i]];
  }
  return digit_size;
}

static int num_to_dig(const int num, int8_t *const digit_buf,
                      const int digit_buf_size) {
  int digit_size = 0;
  for (int i = 0; i; i /= 10) {
    digit_size++;
    assert(digit_buf_size - digit_size >= 0);
    digit_buf[digit_buf_size - digit_size] = i % 10;
  }
  return digit_size;
}

int longestCommonPrefix(int *arr1, int arr1_size, int *arr2, int arr2_size) {
  int8_t digit_buf[10];
  int digit_size;
  struct trie *pt = trie_init();
  for (int i = 0; i < arr1_size; i++) {
    digit_size = num_to_dig(arr1[i], digit_buf, 10);
    trie_insert(pt, digit_buf + 10 - digit_size, digit_size);
  }
  int max_len = 0;
  for (int i = 0; i < arr2_size; i++) {
    digit_size = num_to_dig(arr2[i], digit_buf, 10);
    const int curr_size = trie_lcp(pt, digit_buf + 10 - digit_size, digit_size);
    if (curr_size > max_len)
      max_len = curr_size;
  }
  trie_free(pt);
  pt = NULL;
  return max_len;
}

int main() {
  int a11[] = {1, 10, 100}, a21[] = {1000};
  int a12[] = {1, 2, 3}, a22[] = {4, 4, 4};
  printf("%d\n", longestCommonPrefix(a11, ARRAY_SIZE(a11), a21,
                                     ARRAY_SIZE(a21))); // expect: 3
  printf("%d\n", longestCommonPrefix(a12, ARRAY_SIZE(a12), a22,
                                     ARRAY_SIZE(a22))); // expect: 3
}
