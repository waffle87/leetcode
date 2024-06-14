// 720. Decode XORed Array
#include "leetcode.h"

/*
 * there is a hidden integer array 'arr' that consists of 'n' non-negative
 * integers. it was encoded into another integer array 'encoded' of length 'n -
 * 1' such that 'encoded[i] = arr[i] ^ arr[i + 1]'. for example, if 'arr =
 * [1,0,2,1]', then 'encoded = [1,2,3]'. you are given the 'encoded' array. you
 * are also given an integer 'first', that is the first element of 'arr'. ie. of
 * 'arr[0]'. return the original array 'arr'. it can be proved that the answer
 * exists and is unique.
 */

class Solution {
public:
  vector<int> decode(vector<int> encoded, int first) {
    for (int &i : encoded) {
      swap(i, first);
      first ^= i;
    }
    encoded.push_back(first);
    return encoded;
  }
};

int main() {
  Solution obj;
  vector<int> e1 = {1, 2, 3}, e2 = {6, 2, 7, 3};
  for (auto i : obj.decode(e1, 1))
    printf("%d ", i); // expect: 1 0 2 1
  printf("\n");
  for (auto i : obj.decode(e2, 4))
    printf("%d ", i); // expect: 4 2 0 7 4
  printf("\n");
}
