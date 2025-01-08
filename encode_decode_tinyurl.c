// 535. Encode and Decode TinyURL
#include "leetcode.h"

/*
 * tinyurl is a url shortening service where you enter a url such as
 * https://looooooongurl.com and it returns a short url such as
 * http://tinyurl.com/4e9iAk. design a class to encode a url and decode a tiny
 * url. there is no restriction on how your encode/decode algorithm should work.
 * you just need to ensure that a url can be encoded to a tiny url and the tiny
 * url can be decoded to the original url.
 */

char *encode(char *longUrl) {
  char *e = longUrl + strlen(longUrl) - 1,
       *tiny = (char *)calloc(10000, sizeof(char));
  while (*e-- != '/')
    ;
  strcat(strcpy(tiny, "https://tinyurl.com/"), e + 2);
  strcpy(tiny + strlen(tiny) + 1, longUrl);
  return tiny;
}

char *decode(char *shortUrl) { return shortUrl + strlen(shortUrl) + 1; }

int main() {
  char *url = "https://leetcode.com/problems/design-tinyurl";
  char *enc = encode(url);
  printf("%s\n",
         decode(enc)); // expect: https://leetcode.com/problems/design-tinyurl
  free(enc);
}
