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

class Solution {
private:
  const string charset =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  map<string, string> url_code, code_url;
  random_device rd;

public:
  string encode(string longUrl) {
    string code;
    if (!url_code.count(longUrl)) {
      for (int i = 0; i < 6; i++)
        code.push_back(charset[rd() % charset.size()]);
      url_code.insert(pair<string, string>(longUrl, code));
      code_url.insert(pair<string, string>(code, longUrl));
    } else
      code = url_code[longUrl];
    return "http://tinyurl.com/" + code;
  }
  string decode(string shortUrl) {
    if (shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19, 6)))
      return "";
    return code_url[shortUrl.substr(19, 6)];
  }
};

int main() {
  Solution obj;
  cout << obj.decode(obj.encode("https://leetcode.com/problems/design-tinyurl"))
       << endl; // expect: https://leetcode.com/problems/design-tinyurl
}
