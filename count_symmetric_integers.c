// 2843. Count Symmetric Integers
#include "leetcode.h"

/*
 * you are given two positive integers 'low' and 'high'. an integer 'x'
 * consisting of '2 * n' digits is symmetric if the sum of the first 'n' digits
 * of 'x' is equal to the sum of the last 'n' digits of 'x'. numbers with an odd
 * number of digits are never symmetric. return the number of symmetric integers
 * in the range '[low, high]'.
 */

__attribute__((naked)) int countSymmetricIntegers(int low, int high) {
  /*
  int cnt = 0;
  for (int i = 11; i <= 99; i += 11)
    if (i >= low && i <= high)
      cnt++;
  for (int i = 1; i <= 9; ++i)
    for (int j = 0; j <= 9; ++j) {
      int sum = i + j;
      for (int k = 0; k <= 9; ++k) {
        int l = sum - k;
        if (0 <= l && l <= 9) {
          int num = i * 1000 + j * 100 + k * 10 + l;
          if (num >= low && num <= high)
            cnt++;
        }
      }
    }
  return cnt;
  */
  __asm__ __volatile__(".intel_syntax noprefix           \n\t"
                       "push rbp                         \n\t"
                       "mov rbp, rsp                     \n\t"
                       "sub rsp, 32                      \n\t"
                       "mov dword ptr [rbp-4], edi       \n\t"
                       "mov dword ptr [rbp-8], esi       \n\t"
                       "mov dword ptr [rbp-12], 0        \n\t"
                       "mov eax, 11                      \n\t"
                       "L_loop2:                         \n\t"
                       "cmp eax, 99                      \n\t"
                       "jg L_fourdigit                   \n\t"
                       "mov ecx, dword ptr [rbp-4]       \n\t"
                       "cmp eax, ecx                     \n\t"
                       "jl L_skip2                       \n\t"
                       "mov ecx, dword ptr [rbp-8]       \n\t"
                       "cmp eax, ecx                     \n\t"
                       "jg L_skip2                       \n\t"
                       "add dword ptr [rbp-12], 1        \n\t"
                       "L_skip2:                         \n\t"
                       "add eax, 11                      \n\t"
                       "jmp L_loop2                      \n\t"
                       "L_fourdigit:                     \n\t"
                       "mov r8d, 1                       \n\t"
                       "L_a_loop:                        \n\t"
                       "cmp r8d, 9                       \n\t"
                       "jg L_end                         \n\t"
                       "mov r9d, 0                       \n\t"
                       "L_b_loop:                        \n\t"
                       "cmp r9d, 9                       \n\t"
                       "jg L_next_a                      \n\t"
                       "mov eax, r8d                     \n\t"
                       "add eax, r9d                     \n\t"
                       "mov dword ptr [rbp-16], eax      \n\t"
                       "mov r10d, 0                      \n\t"
                       "L_c_loop:                        \n\t"
                       "cmp r10d, 9                      \n\t"
                       "jg L_next_b                      \n\t"
                       "mov eax, dword ptr [rbp-16]      \n\t"
                       "sub eax, r10d                    \n\t"
                       "cmp eax, 0                       \n\t"
                       "jl L_skip_d                      \n\t"
                       "cmp eax, 9                       \n\t"
                       "jg L_skip_d                      \n\t"
                       "mov ecx, r8d                     \n\t"
                       "imul ecx, 1000                   \n\t"
                       "mov edx, r9d                     \n\t"
                       "imul edx, 100                    \n\t"
                       "add ecx, edx                     \n\t"
                       "mov edx, r10d                    \n\t"
                       "imul edx, 10                     \n\t"
                       "add ecx, edx                     \n\t"
                       "add ecx, eax                     \n\t"
                       "mov edx, dword ptr [rbp-4]       \n\t"
                       "cmp ecx, edx                     \n\t"
                       "jl L_skip_d                      \n\t"
                       "mov edx, dword ptr [rbp-8]       \n\t"
                       "cmp ecx, edx                     \n\t"
                       "jg L_skip_d                      \n\t"
                       "add dword ptr [rbp-12], 1        \n\t"
                       "L_skip_d:                        \n\t"
                       "inc r10d                         \n\t"
                       "jmp L_c_loop                     \n\t"
                       "L_next_b:                        \n\t"
                       "inc r9d                          \n\t"
                       "jmp L_b_loop                     \n\t"
                       "L_next_a:                        \n\t"
                       "inc r8d                          \n\t"
                       "jmp L_a_loop                     \n\t"
                       "L_end:                           \n\t"
                       "mov eax, dword ptr [rbp-12]      \n\t"
                       "leave                            \n\t"
                       "ret                              \n\t"
                       ".att_syntax prefix               \n"
                       :
                       :);
}

int main() {
  printf("%d\n", countSymmetricIntegers(1, 100));     // expect: 9
  printf("%d\n", countSymmetricIntegers(1200, 1230)); // expect: 4
}
