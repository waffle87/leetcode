// 744. Find Smallest Letter Greater Than Target
#include "leetcode.h"

/*
 * given an array of characters 'letters' that is sorted in non-decreasing
 * order, and a character 'target'. there are at least two different characters
 * in 'letters'. return the smallest character in 'letters' that is
 * lexicographically greater than 'target'. if such a character does not exist,
 * return the first character in 'letters'.
 */

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int low = 0, high = letters.size() - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (letters[mid] <= target)
        low = mid + 1;
      else
        high = mid;
    }
    return letters[low] > target ? letters[low] : letters[0];
  }
};

int main() {
  Solution obj;
  vector<char> l1_2 = {'c', 'f', 'j'};
  vector<char> l3 = {'x', 'x', 'y', 'y'};
  printf("%c", obj.nextGreatestLetter(l1_2, 'a')); // expect: c
  printf("%c", obj.nextGreatestLetter(l1_2, 'c')); // expect: f
  printf("%c", obj.nextGreatestLetter(l3, 'z'));   // expect: x
}
