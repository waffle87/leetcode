#include <bits/stdc++.h>

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == divisor) {
      if (divisor == -1)
        return INT_MAX;
      else if (divisor == INT_MIN)
        return 1;
      else if (divisor < 0)
        return 1 + divide(dividend - divisor, divisor);
      else
        return -1 + divide(dividend + divisor, divisor);
    } else if (divisor == INT_MIN)
      return 0;
    bool negative = (dividend < 0) ^ (divisor < 0);
    dividend = abs(dividend);
    divisor = abs(divisor);
    int result = 0;
    for (int i = 31; i >= 0; --i) {
      int shiftedDiv = (dividend >> i);
      if (shiftedDiv >= divisor) {
        result += (1 << i);
        dividend -= (divisor << i);
      }
    }
    return (negative ? -result : result);
  }
};

int main() {}
