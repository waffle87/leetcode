// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
#include "leetcode.h"

/*
 * given a 'sentence' that consists of some words separated by a single space,
 * and a 'searchWord', check if 'searchWord' is a prefix of any word in
 * 'sentence'. return the index of the word in 'sentence' (1-indexed) where
 * 'searchWord' is a prefix of the word. if 'searchWord' is a prefix of more
 * than one word, return the index of the first word (minimum index). if there
 * is no such word, return -1. a prefix of a string 's' is any leading
 * contiguous substring of 's'.
 */

int isPrefixOfWord(char *sentence, char *searchWord) {
  int word_idx = 1;
  char *search_ptr;
  while (*sentence != '\0') {
    search_ptr = searchWord;
    while (*sentence == *search_ptr && *search_ptr != '\0') {
      ++sentence;
      ++search_ptr;
    }
    if (*search_ptr == '\0')
      return word_idx;
    while (*sentence != '\0' && *(sentence++) != ' ')
      ;
    ++word_idx;
  }
  return -1;
}

int main() {
  char *s1 = "i love eating burger", *sw1 = "burg";
  char *s2 = "this problem is an easy problem", *sw2 = "pro";
  char *s3 = "i am tired", *sw3 = "you";
  printf("%d\n", isPrefixOfWord(s1, sw1)); // expect: 4
  printf("%d\n", isPrefixOfWord(s2, sw2)); // expect: 2
  printf("%d\n", isPrefixOfWord(s3, sw3)); // expect: -1
}
