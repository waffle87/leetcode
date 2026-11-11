// 3789. Minimum Cost to Acquire Required Items
#include "leetcode.h"

/*
 * you are given five integers 'cost1', 'cost2', 'costBoth', 'need1', and
 * 'need2'. there are three types of items available:
 * - an item of type 1 costs 'cost1' and contributes 1 unit to the type 1
 * requirement only
 * - an item of type 2 costs 'cost2' and contributes 1 unit to the type 2
 * requirement only
 * - an item of type 3 costs 'costBoth' and contributes 1 unit to both type 1
 * and type 2 requirements. you must collect enough items so that the total
 * contribution toward type 1 is at least 'need1' and similarly such for
 * 'need2'. return an integer representing the minimum possible total cost to
 * achieve these requirements.
 */

long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                      int need2) {
  long long ans = 0;
  if (cost1 + cost2 <= costBoth)
    ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;
  else {
    int cnt3 = need1 < need2 ? need1 : need2;
    ans = 1LL * cnt3 * costBoth;
    need1 -= cnt3;
    need2 -= cnt3;
    if (need1 > 0)
      ans += 1LL * need1 * (cost1 < costBoth ? cost1 : costBoth);
    else if (need2 > 0)
      ans += 1LL * need2 * (cost2 < costBoth ? cost2 : costBoth);
  }
  return ans;
}

int main() {
  long long r1 = minimumCost(3, 2, 1, 3, 2);
  long long r2 = minimumCost(5, 4, 15, 2, 3);
  long long r3 = minimumCost(5, 4, 15, 0, 0);
  printf("%lld\n", r1);
  assert(r1 == 3);
  printf("%lld\n", r2);
  assert(r2 == 22);
  printf("%lld\n", r3);
  assert(r3 == 0);
}
