// 1524. Number of Sub-arrays With Odd Sum
#include "leetcode.h"

/*
 * given an array of integers 'arr', return the number of subarrays with an odd
 * sum. since the answer can be very large, return it modulo 10e9+7.
 */

__attribute__((naked)) int numOfSubarrays(int *arr, int arrSize) {
  __asm__(".intel_syntax noprefix\n"
          "push 0                     \n"
          "push 1                     \n"
          "xor eax, eax               \n"

          "loop:                      \n"
          "add eax, DWORD PTR [rdi]   \n"
          "add rdi, 4                 \n"
          "and eax, 1                 \n"
          "inc QWORD PTR [rsp+rax*8]  \n"
          "dec esi                    \n"
          "jnz loop                   \n"

          "pop rax                    \n"
          "cdq                        \n"
          "pop rdi                    \n"
          "mul rdi                    \n"

          "mov rdi, 1000000007        \n"
          "div rdi                    \n"
          "mov rax, rdx               \n"

          "ret                        \n"

          ".att_syntax\n");
}

int main() {
  int a1[] = {1, 3, 5};
  int a2[] = {2, 4, 6};
  int a3[] = {1, 2, 3, 4, 5, 6, 7};
  int r1 = numOfSubarrays(a1, ARRAY_SIZE(a1));
  int r2 = numOfSubarrays(a2, ARRAY_SIZE(a2));
  int r3 = numOfSubarrays(a3, ARRAY_SIZE(a3));
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 16);
}
