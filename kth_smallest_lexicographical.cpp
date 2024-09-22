// 440. K-th Smallest in Lexicographical Order
#include "leetcode.h"
// given two integers 'n' and 'k', return the k'th lexicographically smallest
// integer

class Soltuion {
public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    for (--k; k > 0;) {
      int cnt = 0;
      for (long long first = static_cast<long long>(curr), last = first + 1;
           first <= n; first *= 10, last *= 10)
        cnt += static_cast<int>((min(n + 1LL, last) - first));
      if (k >= cnt) {
        ++curr;
        k -= cnt;
      } else {
        curr *= 10;
        --k;
      }
    }
    return curr;
  }
};

int main() {
  Soltuion obj;
  printf("%d\n", obj.findKthNumber(13, 2)); // expect: 10
  printf("%d\n", obj.findKthNumber(1, 1));  // expect: 1
}
