// 989. Add to Array-Form of Integer
#include "leetcode.h"

/*
 * the array-form of an integer 'num' is an array representing its digits in
 * left to right order. eg 'num = 1231', the array form is 1,3,2,1. given 'num',
 * the array form of an integer, and an integer 'k', return the array-form of
 * 'num + k'
 */

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    int carry = 0, j = num.size() - 1;
    while (j >= 0) {
      int sum = num[j] + (k % 10) + carry;
      k /= 10;
      num[j--] = sum % 10;
      carry = sum / 10;
    }
    while (k > 0) {
      int sum = (k % 10) + carry;
      k /= 10;
      num.insert(num.begin(), sum % 10);
      carry = sum / 10;
    }
    if (carry > 0)
      num.insert(num.begin(), carry);
    return num;
  }
};

int main() {
  Solution obj;
  vector<int> num1 = {1, 2, 0, 0}, num2 = {2, 7, 4}, num3 = {2, 1, 5};
  for (auto i : obj.addToArrayForm(num1, 34))
    cout << i << ','; // expect: 1,2,3,4
  cout << endl;
  for (auto i : obj.addToArrayForm(num2, 181))
    cout << i << ','; // expect: 4,5,5
  cout << endl;
  for (auto i : obj.addToArrayForm(num3, 806))
    cout << i << ','; // expect: 1,0,2,1
}
