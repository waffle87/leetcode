// 1286. Iterator for Combination
#include "leetcode.h"

/*
 * design the 'CombinationIterator' class:
 * - 'CombinationIterator(string characters, int combinationLength)' initialises
 * the object with a string 'characters' of sorted distinct lowercase english
 * letters and a number 'combinationLength' as arguments
 * - 'next()' returns the next combination of length 'combinationLength' in
 * lexicographical order
 * - 'hasNext()' returns 'true' iff there exists a next combination
 */

typedef struct c {
  char *str;
  struct c *next;
} CombinationIterator;

void get_comb(CombinationIterator **last, char *s, char *tab, int l, int len) {
  if (l == len) {
    (*last)->next = (CombinationIterator *)malloc(sizeof(CombinationIterator));
    *last = (*last)->next;
    (*last)->str = (char *)calloc(len + 1, 1);
    while (l--)
      ((*last)->str)[l] = tab[l];
    (*last)->next = NULL;
  } else if (!*s)
    return;
  else {
    tab[l] = *s;
    get_comb(last, s + 1, tab, l + 1, len);
    get_comb(last, s + 1, tab, l, len);
  }
}

CombinationIterator *combinationIteratorCreate(char *characters,
                                               int combinationLength) {
  CombinationIterator *cmb =
      (CombinationIterator *)malloc(sizeof(CombinationIterator));
  cmb->next = NULL;
  CombinationIterator *p = cmb;
  char tab[combinationLength + 1];
  get_comb(&p, characters, tab, 0, combinationLength);
  return cmb;
}

char *combinationIteratorNext(CombinationIterator *obj) {
  char *p = obj->next->str;
  obj->next = obj->next->next;
  return p;
}

bool combinationIteratorHasNext(CombinationIterator *obj) { return obj->next; }

void combinationIteratorFree(CombinationIterator *obj) { free(obj); }

int main() {
  char *characters = "abc";
  CombinationIterator *obj = combinationIteratorCreate(characters, 2);
  printf("%s\n", combinationIteratorNext(obj));    // expect: ab
  printf("%d\n", combinationIteratorHasNext(obj)); // expect: 1
  printf("%s\n", combinationIteratorNext(obj));    // expect: ac
  printf("%d\n", combinationIteratorHasNext(obj)); // expect: 1
  printf("%s\n", combinationIteratorNext(obj));    // expect: bc
  printf("%d\n", combinationIteratorHasNext(obj)); // expect: 0
  combinationIteratorFree(obj);
}
