// 1502. Can Make Arithmetic Progression From Sequence
#include "leetcode.h"

/*
 * a sequence of numbers is called an arithmetic progression if the difference
 * between any two consecutive elements is the same. gien an array of numbers
 * 'arr', return true if the array can rearranged to form an arithmetic
 * progression. otherwise, return false.
 */

class Solution {
public:
  bool canMakeArithmeticProgression(vector<int> &arr) {
    if (arr.size() <= 2)
      return true;
    auto min = *min_element(begin(arr), end(arr));
    auto max = *max_element(begin(arr), end(arr));
    if ((max - min) % (arr.size() - 1))
      return false;
    int d = (max - min) / (arr.size() - 1);
    for (int i = 0; i < arr.size();) {
      if (arr[i] == min + i * d)
        i++;
      else if ((arr[i] - min) % d)
        return false;
      else {
        int pos = (arr[i] - min) / d;
        if (pos < i)
          return false;
        if (arr[pos] == arr[i])
          return false;
        swap(arr[i], arr[pos]);
      }
    }
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {3, 5, 1}, a2 = {1, 2, 4};
  printf("%d\n", obj.canMakeArithmeticProgression(a1)); // expect: 1
  printf("%d\n", obj.canMakeArithmeticProgression(a2)); // expect: 0
}
