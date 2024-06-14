// 720. Decode XORed Array
#include <stdio.h>
#include <stdlib.h>

/*
 * there is a hidden integer array 'arr' that consists of 'n' non-negative
 * integers. it was encoded into another integer array 'encoded' of length 'n -
 * 1' such that 'encoded[i] = arr[i] ^ arr[i + 1]'. for example, if 'arr =
 * [1,0,2,1]', then 'encoded = [1,2,3]'. you are given the 'encoded' array. you
 * are also given an integer 'first', that is the first element of 'arr'. ie. of
 * 'arr[0]'. return the original array 'arr'. it can be proved that the answer
 * exists and is unique.
 */

int *decode(int *encoded, int encoded_size, int first, int *return_size) {
  *return_size = encoded_size + 1;
  int *arr = (int *)malloc(*return_size * sizeof(int));
  arr[0] = first;
  for (int i = 0; i < encoded_size; i++)
    arr[i + 1] = arr[i] ^ encoded[i];
  return arr;
}

int main() {
  int e1[] = {1, 2, 3}, es1 = 3, f1 = 1, rs1[] = {};
  int e2[] = {6, 2, 7, 3}, es2 = 4, f2 = 4, rs2[] = {};
  int *d1 = decode(e1, es1, f1, rs1);
  int *d2 = decode(e2, es2, f2, rs2);
  for (int i = 0; i < es1 + 1; i++)
    printf("%d ", d1[i]); // expect: 1 0 2 1
  printf("\n");
  for (int i = 0; i < es2 + 1; i++)
    printf("%d ", d2[i]); // expect: 4 2 0 7 4
  printf("\n");
}
