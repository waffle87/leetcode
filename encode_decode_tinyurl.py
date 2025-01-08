# 535. Encode and Decode TinyURL
from string import ascii_letters
from random import choice

"""
tinyurl is a url shortening service where you enter a url such as
https://looooooongurl.com and it returns a short url such as
http://tinyurl.com/4e9iAk. design a class to encode a url and decode a tiny
url. there is no restriction on how your encode/decode algorithm should work.
you just need to ensure that a url can be encoded to a tiny url and the tiny
url can be decoded to the original url.
"""


class Codec:
    alphabet = ascii_letters + "0123456789"

    def __init__(self):
        self.url_code = {}
        self.code_url = {}

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        while longUrl not in self.url_code:
            code = "".join(choice(Codec.alphabet) for _ in range(6))
            if code not in self.code_url:
                self.code_url[code] = longUrl
                self.url_code[longUrl] = code
        return "http://tinyurl.com/" + self.url_code[longUrl]

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        return self.code_url[shortUrl[-6:]]


if __name__ == "__main__":
    obj = Codec()
    print(obj.decode(obj.encode("https://leetcode.com/problems/design-tinyurl")))
