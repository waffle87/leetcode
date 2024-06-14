// 1523. Count Odd Numbers in an Interval Range
#include <math.h>
#include <stdio.h>

// given two non-negative integers 'low' and 'high' return the
// count of odd numbers  * between 'low' and 'high' (incusively)

int countOdds(int low, int high) {
  int ans = 0;
  if (low % 2) {
    ans += (high - low) / 2;
    ans++;
  } else
    ans += (double)ceil((high - low) / 2.0);
  return ans;
}

int main() {
  printf("%d\n", countOdds(3, 7));  // expect: 3
  printf("%d\n", countOdds(8, 10)); // expect: 1
}
