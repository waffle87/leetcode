// 472. Concatenated Words
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an array of strings 'words' (without duplicates), return all the
 * concatenated words in the given list of 'words'. a concatenated word is
 * defined as as string that is comprised entirely of at least two shorter
 * words in the given array.
 */

static int letterStarts[26];

int cmp(const void *a, const void *b) {
  char *wordA = *((char **)a);
  char *wordB = *((char **)b);
  if (wordA[0] != wordB[0])
    return wordA[0] - wordB[0];
  else
    return strlen(wordB) - strlen(wordA);
}

bool findWord(char **dict, int dictSize, char *word, int offset, int skipIdx) {
  int restLen = strlen(word + offset);
  if (restLen == 0)
    return true;
  char firstLetter = (word + offset)[0];
  int letterStartsIdx = firstLetter - 'a';
  int startDictIdx = letterStarts[letterStartsIdx];
  int endDictIdx = dictSize;
  if (startDictIdx == -1)
    return false;
  while (letterStartsIdx < 25) {
    letterStartsIdx++;
    if (letterStarts[letterStartsIdx] != -1)
      break;
  }
  if (firstLetter != 'z' && letterStarts[letterStartsIdx] != -1)
    endDictIdx = letterStarts[letterStartsIdx];
  for (int i = endDictIdx - 1; i >= startDictIdx; i--) {
    if (i == skipIdx)
      continue;
    int len = strlen(dict[i]);
    if (len == 0)
      continue;
    if (strncmp(dict[i], word + offset, len) == 0) {
      bool res = findWord(dict, dictSize, word, offset + len, skipIdx);
      if (res)
        return true;
    }
  }
  return false;
}

char **findAllConcatenatedWordsInADict(char **words, int wordsSize,
                                       int *returnSize) {
  char **ans = malloc(1000 * sizeof(char *));
  int ansCnt = 0;
  qsort(words, wordsSize, sizeof(char *), cmp);
  for (int i = 0; i < 26; i++)
    letterStarts[i] = -1;
  for (int i = 0; i < wordsSize; i++) {
    if (strlen(words[i]) == 0)
      continue;
    if (letterStarts[words[i][0] - 'a'] == -1)
      letterStarts[words[i][0] - 'a'] = i;
  }
  for (int i = 0; i < wordsSize; i++) {
    int len = strlen(words[i]);
    if (len && findWord(words, wordsSize, words[i], 0, i)) {
      ans[ansCnt] = malloc(len + 1);
      strcpy(ans[ansCnt++], words[i]);
    }
  }
  *returnSize = ansCnt;
  return ans;
}
