#include "leetcode.h"

class Soltuion {
public:
  int findKthNumber(int n, int k) {
    int ans = 0, rankNum = 0, next = 0, rankNext = 0;
    while (rankNum != k) {
      int lower = ans ? 0 : 1, upper = 9;
      while (lower < upper) {
        auto mid = (lower + upper + 1) / 2;
        next = ans * 10 + mid;
        rankNext = rank(next, n);
      }
      ans *= 10, ans += lower;
      rankNum = (ans == next ? rankNext : rank(ans, n));
    }
    return ans;
  }

private:
  static int rank(int prefix, int maxVal) {
    int ret = 1, num = 0;
    for (int i = prefix; i; i /= 10, ++num)
      for (int j = 1; j <= i % 10; ++j)
        ret += numPrefixes(i - j, maxVal);
    ret += num - 1;
    return ret;
  }
  static int numPrefixes(int prefix, int maxVal) {
    if (prefix == 0)
      return 0;
    int ret = 0;
    unsigned long long ull = 1;
    for (unsigned long long val = prefix; val <= maxVal; ull *= 10, val *= 10)
      ret += min(ull, maxVal - val + 1);
    return ret;
  }
};

int main() {
  Soltuion obj;
  cout << obj.findKthNumber(13, 2);
}
