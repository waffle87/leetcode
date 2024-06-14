// 881. Boats to Save People
#include "leetcode.h"

/*
 * given an array 'people' where 'people[i]' is the weight of the i'th person,
 * and an infinite number of boats where each boat can carry a maximum weight of
 * 'limit'. each boat carries at most two people at the same time, provided the
 * sum of the weight of those people is at most 'limit'. return minimum number
 * of boats to carry every person
 */

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int max_weight = people.size() - 1, min_weight = 0, ans = 0;
    while (min_weight <= max_weight) {
      if (people[min_weight] + people[max_weight] <= limit) {
        min_weight++;
        max_weight--;
      } else
        max_weight--;
      ans++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {1, 2}, p2 = {3, 2, 2, 1}, p3 = {3, 5, 3, 4};
  printf("%d\n", obj.numRescueBoats(p1, 3)); // expect: 1
  printf("%d\n", obj.numRescueBoats(p2, 3)); // expect: 3
  printf("%d\n", obj.numRescueBoats(p3, 5)); // expect: 4
}
