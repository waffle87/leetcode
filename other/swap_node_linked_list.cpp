#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// implementation
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *x = head, *y = head, *t = head;
    while (k > 1) {
      x = x->next;
      t = t->next;
      k--;
    }

    while (t->next) {
      y = y->next;
      t = t->next;
    }

    int temp = x->val;
    x->val = y->val;
    y->val = temp;
    return head;
  }
};
// end

int main() {
  ListNode *l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  l->next->next->next->next = new ListNode(5);
  int k = 2;
  Solution *sol = new Solution();
  sol->swapNodes(l, k);
}
