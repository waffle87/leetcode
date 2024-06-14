// 950. Reveal Cards In Increasing Order
#include "leetcode.h"

/*
 * given an integer array 'deck'. there is a deck of cards where every card has
 * a unique integer. the integer on the i'th card is 'deck[i]'. you can order
 * the deck in any order you want. initially, all the cards start face down
 * (unrevealed) in one deck. you will do the following steps repeatedly until
 * all cards are revealed. take the top card of the deck, reveal it, and take it
 * out of the deck. if there are still cards in the deck, then put the next top
 * card of the deck at the bottom of the deck. if there are still unrevealed
 * cards, go back to step 1, otherwise stop. return an ordering of the deck that
 * would reveal the cards in increasing order.
 */

struct ListNode {
  int val;
  struct ListNode *next;
};

typedef struct ListNode l_node;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize) {
  l_node *head = malloc(sizeof(l_node));
  head->val = 0;
  l_node *tmp = head;
  for (int i = 1; i < deckSize; i++) {
    l_node *n = malloc(sizeof(l_node));
    n->val = i;
    tmp->next = n;
    tmp = n;
  }
  l_node *tail = tmp;
  tail->next = NULL;
  tmp = head;
  l_node *post;
  while (tmp->next && tmp->next->next) {
    post = tmp->next;
    tmp->next = tmp->next->next;
    tail->next = post;
    tail = post;
    tail->next = NULL;
    tmp = tmp->next;
  }
  int *ans = malloc(deckSize * sizeof(int));
  qsort(deck, deckSize, sizeof(int), cmp);
  tmp = head;
  l_node *ptr;
  for (int i = 0; i < deckSize; i++) {
    ans[tmp->val] = deck[i];
    ptr = tmp;
    tmp = tmp->next;
    free(ptr);
  }
  *returnSize = deckSize;
  return ans;
}

int main() {
  int d1[] = {17, 13, 11, 2, 3, 5, 7}, d2[] = {1, 1000}, rs1, rs2;
  int *dri1 = deckRevealedIncreasing(d1, ARRAY_SIZE(d1), &rs1);
  int *dri2 = deckRevealedIncreasing(d2, ARRAY_SIZE(d2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", dri1[i]); // expect: 2,13,3,11,5,17,7
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", dri2[i]); // expect: 1,1000
  printf("\n");
  free(dri1), free(dri2);
}
