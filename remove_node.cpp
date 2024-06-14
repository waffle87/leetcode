#include <bits/stdc++.h>
#include <cstddef>
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *temp = head;
    for (int i = 0; i < n; i++)
      temp = temp->next;
    if (temp == NULL)
      return head->next;
    ListNode *curr = head;
    while (temp->next) {
      temp = temp->next;
      curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
  }
};

int main() {}
