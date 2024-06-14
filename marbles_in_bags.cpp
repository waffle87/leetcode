// 2551. Put Marbles in Bags
#include "leetcode.h"

/*
 * you have 'k' bags. you are given a 0-indexed integer array 'weights' where
 * 'weights[i]' is the weight of the i'th marble. you are also given the integer
 * 'k'. divide the marbles into the 'k' bags according to the following rules
 * - no bag is empty
 * - if the i'th marble and the j'th marble are in a bag, then all the marbles
 * with an index between the i'th and j'th indices should also be in that same
 * bag.
 * - if a bag onsists of all the marbles with an index from 'i' to 'j'
 * inclusively, then the cost of the bag is 'weights[i] + weights[j]' the score
 * after distributing the marbles is the sum of the costs of all the 'k' bags.
 * return the difference between the maximum and minimum scores among marble
 * distributions
 */

class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 0; i < weights.size() - 1; i++) {
      pq1.push(weights[i] + weights[i + 1]);
      pq2.push(weights[i] + weights[i + 1]);
      if (pq1.size() > k - 1) {
        pq1.pop();
        pq2.pop();
      }
    }
    long long ans1 = 0, ans2 = 0;
    while (!pq1.empty()) {
      ans1 += pq1.top();
      ans2 += pq2.top();
      pq1.pop();
      pq2.pop();
    }
    return ans2 - ans1;
  }
};

int main() {
  Solution obj;
  vector<int> w1 = {1, 3, 5, 1}, w2 = {1, 3};
  printf("%lld\n", obj.putMarbles(w1, 2)); // expect: 4
  printf("%lld\n", obj.putMarbles(w2, 2)); // expect: 0
}
