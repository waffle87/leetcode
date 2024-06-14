# 880. Decoded String at Index

"""
given an encoded string 's'. to decode the string to a tape, the encoded
string is read one character at a time at a time the following steps are
taken. if the character read is a letter, that letter is written onto the
tape. if the character read is a digit 'd', the entire current tape is
repeatedly written 'd - 1' more times in total. given an integer 'k', return
the k'th letter (1-indexed) in the decoded string.
"""


class Solution(object):
    def decodeAtIndex(self, s, k):
        length = 0
        i = 0
        while length < k:
            if s[i].isdigit():
                length *= int(s[i])
            else:
                length += 1
            i += 1
        for j in range(i - 1, -1, -1):
            char = s[j]
            if char.isdigit():
                length //= int(char)
                k %= length
            else:
                if k == 0 or k == length:
                    return char
                length -= 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.decodeAtIndex("leet2code3", 10))  # expect: o
    print(obj.decodeAtIndex("ha22", 5))  # expect: h
    print(obj.decodeAtIndex("a2345678999999999999999", 10))  # expect: a
