#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return NULL;
    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
      head = merge(head, lists[i]);
    return head;
  }

private:
  ListNode *merge(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    ListNode *head = list1->val <= list2->val ? list1 : list2;
    head->next = list1->val <= list2->val ? merge(list1->next, list2)
                                          : merge(list1, list2->next);
    return head;
  }
};

int main() {}
