// 966. Vowel Spellchecker
#include "leetcode.h"

/*
 * given a 'wordlist', we want to implement a spellchecker that converts a query
 * word into a correct word. for a given 'query', the spell checker handles two
 * categories of spelling mistakes: capitalisation and vowel errors. given some
 * 'queries', return a list of words 'answer' where 'answer[i]' is the correct
 * word for 'query = queries[i]'
 */

unsigned int rs_hash1(char *s) {
  unsigned int a = 63689, b = 378551, hash = 0;
  while (*s) {
    hash = hash * a + (*s++);
    a *= b;
  }
  return hash & 0x7FFFFFFF;
}

unsigned int rs_hash2(char *s) {
  unsigned int a = 63689, b = 378551, hash = 0;
  while (*s) {
    char curr = *s;
    if (curr >= 'A' && curr <= 'Z')
      curr = curr - 'A' + 'a';
    hash = hash * a + curr;
    (*s)++;
    a *= b;
  }
  return hash & 0x7FFFFFFF;
}

unsigned int rs_hash3(char *s) {
  unsigned int a = 63689, b = 378551, hash = 0;
  while (*s) {
    char curr = *s;
    if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
      curr = 'A';
    else if (curr == 'A' || curr == 'E' || curr == 'I' || curr == 'O' ||
             curr == 'U')
      curr = 'A';
    else if (curr >= 'A' && curr <= 'Z')
      curr = curr - 'A' + 'a';
    hash = hash * a + curr;
    (*s)++;
    a *= b;
  }
  return hash & 0x7FFFFFFF;
}

char **spellchecker(char **wordlist, int wordlistSize, char **queries,
                    int queriesSize, int *returnSize) {
  int n = wordlistSize * 10;
  unsigned int **hash1 = (unsigned int **)calloc(n, sizeof(unsigned int *));
  unsigned int **hash2 = (unsigned int **)calloc(n, sizeof(unsigned int *));
  unsigned int **hash3 = (unsigned int **)calloc(n, sizeof(unsigned int *));
  for (int i = 0; i < wordlistSize; i++) {
    unsigned int val = rs_hash1(wordlist[i]), d = val;
    while (1) {
      if (!hash1[d % n]) {
        hash1[d % n] = (unsigned int *)malloc(2 * sizeof(unsigned int));
        hash1[d % n][0] = val;
        hash1[d % n][1] = i;
        break;
      } else
        d++;
    }
    val = rs_hash2(wordlist[i]);
    d = val;
    while (1) {
      if (!hash2[d % n]) {
        hash2[d % n] = (unsigned int *)malloc(2 * sizeof(unsigned int));
        hash2[d % n][0] = val;
        hash2[d % n][1] = i;
        break;
      } else
        d++;
    }
    val = rs_hash3(wordlist[i]);
    d = val;
    while (1) {
      if (!hash3[d % n]) {
        hash3[d % n] = (unsigned int *)malloc(2 * sizeof(unsigned int));
        hash3[d % n][0] = val;
        hash3[d % n][1] = i;
        break;
      } else
        d++;
    }
  }
  char **ans = (char **)malloc(queriesSize * sizeof(char *));
  unsigned int val, d;
  for (int i = 0; i < queriesSize; i++) {
    ans[i] = (char *)malloc(8 * sizeof(char));
    val = rs_hash1(queries[i]);
    d = val;
    while (1) {
      if (!hash1[d % n])
        break;
      else if (hash1[d % n][0] == val) {
        int pos = hash1[d % n][1];
        strcpy(ans[i], wordlist[pos]);
        goto next;
      } else
        d++;
    }
    val = rs_hash2(queries[i]);
    d = val;
    while (1) {
      if (!hash2[d % n])
        break;
      else if (hash2[d % n][0] == val) {
        int pos = hash2[d % n][1];
        strcpy(ans[i], wordlist[pos]);
        goto next;
      } else
        d++;
    }
    val = rs_hash3(queries[i]);
    d = val;
    while (1) {
      if (!hash3[d % n])
        break;
      else if (hash3[d % n][0] == val) {
        int pos = hash3[d % n][1];
        strcpy(ans[i], wordlist[pos]);
        goto next;
      } else
        d++;
    }
    ans[i] = "";
  next:
    continue;
  }
  free(hash1);
  free(hash2);
  free(hash3);
  *returnSize = queriesSize;
  return ans;
}

int main() {
  char *w1[] = {"KiTe", "kite", "hare", "Hare"},
       *q1[] = {"kite", "Kite", "KiTe", "Hare", "HARE",
                "Hear", "hear", "keti", "keet", "keto"};
  char *w2[] = {"yellow"}, *q2[] = {"YellOw"};
  int rs1, rs2;
  char **sc1 = spellchecker((char **)w1, ARRAY_SIZE(w1), (char **)q1,
                            ARRAY_SIZE(q1), &rs1);
  char **sc2 = spellchecker((char **)w2, ARRAY_SIZE(w2), (char **)q2,
                            ARRAY_SIZE(q2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf(
        "%s ",
        sc1[i]); // expect:
                 // ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", sc2[i]); // expect: ["yellow"]
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(sc1[i]);
  free(sc1);
  for (int i = 0; i < rs2; i++)
    free(sc2[i]);
  free(sc2);
}
