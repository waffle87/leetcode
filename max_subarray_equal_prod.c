// 3411. Maximum Subarray With Equal Products
#include "leetcode.h"

long long gcd_ll(long long a, long long b) {
  while (b != 0) {
    long long tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int maxLength(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    long long prod = nums[i];
    long long gcd = nums[i];
    long long lcm = nums[i];
    for (int j = i + 1; j < numsSize; j++) {
      prod *= nums[j];
      gcd = gcd_ll(gcd, nums[j]);
      lcm = lcm * nums[j] / gcd_ll(lcm, nums[j]);
      if (prod > gcd * lcm)
        break;
      if (prod == gcd * lcm) {
        int n = j - i + 1;
        ans = fmax(ans, n);
      }
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 1, 2, 1, 1, 1};
  int n2[] = {2, 3, 4, 5, 6};
  int n3[] = {1, 2, 3, 1, 4, 5, 1};
  int r1 = maxLength(n1, ARRAY_SIZE(n1));
  int r2 = maxLength(n2, ARRAY_SIZE(n2));
  int r3 = maxLength(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r2);
  assert(r2 == 5);
}
