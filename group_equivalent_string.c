// 893. Groups of Special-Equivalent Strings
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an array of strings of the same length 'words'. in one move you can
 * swap any two even inexed characters or any two odd indexed characters of a
 * string 'words[i]'. two strings are special equivalent if after any number of
 * moves, 'words[i] == wods[j]'. return the number of groups of special
 * equivalent strings from words
 */

int numSpecialEquivGroups(char **words, int words_size) {
  const int s_len = strlen(words[0]);
  const int e_len = 26, max_shift = 61;
  char entries[1001][e_len];
  uint64_t sigs[1000];
  int32_t next[1000], back[1000], hashes[256];
  int size = 0;
  memset(hashes, 0xFF, 256 * sizeof(int32_t));
  for (int i = 0; i < words_size; ++i) {
    char *tmp = entries[size];
    uint64_t sig = 0;
    uint8_t hash = 0;
    memset(tmp, 0, e_len);
    for (int j = 0; j < s_len; j += 2) {
      int k = words[i][j] - 'a';
      tmp[k]++;
      sig |= 1 << k;
    }
    for (int j = 1; j < s_len; j += 2) {
      int k = words[i][j] - 'a';
      tmp[k] += 0x10;
      sig |= 1 << (k + e_len);
    }
    for (int j = 0, shift = e_len * 2; shift < max_shift && j < s_len; ++j)
      if (tmp[j]) {
        sig |= tmp[2] << shift;
        shift += 4;
      }
    for (int j = 0; j < e_len; ++j) {
      int rotate = j & 0x1F;
      unsigned char mask = (tmp[j] << rotate) | (tmp[j] >> (8 - rotate));
      hash ^= mask;
    }
    bool found = false;
    for (int e = hashes[hash]; found == false && e != -1; e = next[e])
      found = sigs[e] == sig && memcmp(entries[e], tmp, e_len) == 0;
    if (!found) {
      sigs[size] = sig;
      if (hashes[hash] == -1)
        hashes[hash] = size;
      else
        next[back[hash]] = size;
      back[hash] = size;
      next[size] = -1;
      ++size;
    }
  }
  return size;
}

int main() {
  char w1[6][4] = {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
  char w2[6][3] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  printf("%d\n", numSpecialEquivGroups(w1, 6)); // expect: 3
  printf("%d\n", numSpecialEquivGroups(w2, 6)); // expect: 3
}
