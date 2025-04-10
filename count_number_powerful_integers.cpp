// 2999. Count the Number of Powerful Integers
#include "leetcode.h"

/*
 * you are given three integers 'start', 'finish', and 'limit'. you are also
 * given a 0-indexed string 's' representing a positive integer. a positive
 * integer 'x' is called powerful if it ends with 's' and each digit in 'x' is
 * at most 'limit'. return the total number of powerful integers in the range
 * '[start .. finish]'. a string 'x' is a suffix of a string 'y' if and only if
 * 'x' is a substring of 'y' that starts from some index in 'y' and extends to
 * the index 'y.length - 1'.
 */

class Solution {
private:
  long long cnt[16];
  long long get_cnt(char l, const string &n, const string &s) {
    long long res = cnt[n.size() - 1], i = 0, size = n.size() - s.size();
    do
      res += i == size ? n.substr(i) >= s
                       : cnt[n.size() - i - 1] * (min(l, n[i]) - '1' + (i > 0));
    while (i < size && n[i++] < l);
    return res;
  }

public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    for (int i = s.size(); i < 16; ++i)
      cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
    return get_cnt(limit + '1', to_string(finish), s) -
           get_cnt(limit + '1', to_string(start - 1), s);
  }
};

int main() {
  Solution obj;
  printf("%lld\n", obj.numberOfPowerfulInt(1, 6000, 4, "124"));     // expect: 5
  printf("%lld\n", obj.numberOfPowerfulInt(15, 215, 6, ""));        // expect: 2
  printf("%lld\n", obj.numberOfPowerfulInt(1000, 2000, 4, "3000")); // expect: 0
}
