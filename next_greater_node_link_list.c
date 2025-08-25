// 1019. Next Greater Node In Linked List
#include "leetcode.h"

/*
 * you are given the 'head' of a linked list with 'n' nodes. for each node in
 * the list, find the value of the next greater node. that is, for eachnode,
 * find the value of the first node that is next to it and has a stricty larger
 * value than it. return an integer array 'answer' where 'answer[i]' is the
 * value of the next greter node of the i'th node (1-indexed). if the i'th node
 * does not have a next greater node, set 'ans[i] = 0'.
 */

int *nextLargerNodes(struct ListNode *head, int *returnSize) {
  int cnt = 0;
  struct ListNode *tmp1 = head, *tmp2;
  for (; tmp1; tmp1 = tmp1->next, cnt++)
    ;
  int *ans = (int *)calloc(cnt, sizeof(int));
  *returnSize = cnt;
  for (tmp1 = head, cnt = 0; tmp1->next; tmp1 = tmp1->next, cnt++)
    for (tmp2 = tmp1->next; tmp2; tmp2 = tmp2->next)
      if (tmp2->val > tmp1->val) {
        ans[cnt] = tmp2->val;
        break;
      }
  return ans;
}

int main() {
  int h1i[] = {2, 1, 5}, h2i[] = {2, 7, 4, 3, 5};
  struct ListNode *h1 = listnode_build(h1i, ARRAY_SIZE(h1i));
  struct ListNode *h2 = listnode_build(h2i, ARRAY_SIZE(h2i));
  int rs1, *nln1 = nextLargerNodes(h1, &rs1);
  int rs2, *nln2 = nextLargerNodes(h2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", nln1[i]); // expect: 5 5 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", nln2[i]); // expect: 7 0 5 5 0
  printf("\n");
  free(nln1);
  free(nln2);
  listnode_free(h1);
  listnode_free(h2);
}
