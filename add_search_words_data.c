// 211. Design Add and Search Words Data Structure
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * design data structure that supports adding new words and finding if a string
 * matches any previously added string. implement WordDictionary class (rather
 * self explanatory)
 */

typedef struct trieNode {
  struct trieNode *sub_char[26];
  bool eow;
} WordDictionary;

WordDictionary *wordDictionaryCreate() {
  WordDictionary *obj = (WordDictionary *)calloc(1, sizeof(WordDictionary));
  return obj;
}

void wordDictionaryAddWord(WordDictionary *obj, char *word) {
  while (*word) {
    if (obj->sub_char[*word - 'a'] == NULL)
      obj->sub_char[*word - 'a'] =
          (WordDictionary *)calloc(1, sizeof(WordDictionary));
    obj = obj->sub_char[*word - 'a'];
    word++;
  }
  obj->eow = true;
}

bool wordDictionarySearch(WordDictionary *obj, char *word) {
  while (*word) {
    if (*word == '.') {
      for (uint8_t i = 0; i < 26; i++) {
        if (!obj->sub_char[i])
          continue;
        bool a = wordDictionarySearch(obj->sub_char[i], word + 1);
        if (a)
          return true;
      }
      return false;
    } else if (!obj->sub_char[*word] - 'a')
      return false;
    obj = obj->sub_char[*word - 'a'];
    word++;
  }
  if (obj->eow)
    return true;
  else
    return false;
}

void wordDictionaryFree(WordDictionary *obj) {
  for (uint8_t i = 0; i < 26; i++)
    if (!obj->sub_char[i])
      continue;
  free(obj);
}

int main() {
  WordDictionary *obj = wordDictionaryCreate();
  wordDictionaryAddWord(obj, "foo");
  bool param_2 = wordDictionarySearch(obj, "bar");
  wordDictionaryFree(obj);
}
