#include "leetcode.h"

class Solution {
public:
  unordered_map<string, string> codeDB, urlDB;
  const string chars =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  string encode(string longUrl) {
    if (urlDB.find(longUrl) != urlDB.end())
      return urlDB[longUrl];
    string code = genCode();
    while (codeDB.find(code) != codeDB.end())
      code = genCode();
    codeDB[code] = longUrl;
    urlDB[longUrl] = code;
    return code;
  }
  string decode(string shortUrl) { return codeDB[shortUrl]; }

private:
  string genCode() {
    string code = "";
    for (int i = 0; i < 6; i++)
      code += chars[rand() % 62];
    return "http://tinyurl.com/" + code;
  }
};

int main() {}
