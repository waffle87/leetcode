#include <stdio.h>
#include <stdlib.h>

long long countSubarrays(int *nums, int nums_size, long long k) {}

int main() {
  int n1[] = {2, 1, 4, 3, 5}, ns1 = 5, k1 = 10;
  int n2[] = {1, 1, 1}, ns2 = 3, k2 = 5;
  printf("%lld\n", countSubarrays(n1, ns1, k1)); // expect: 6
  printf("%lld\n", countSubarrays(n2, ns2, k2)); // expect: 5
}
