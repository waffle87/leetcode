# 1915. Number of Wonderful Substrings

"""
a wonderful string is a string where at most one letter appears an odd number
of times. for example "ccjjc" and "abab" are wonderful, but "ab" is not.
given a string 'word' that consists of the first ten lowercase letters ('a'
through 'j') return the number of wonderful non-empty substrings in 'word'.
if the same substring appears multiple times in 'word', then count each
occurence separately. a substring is a contiguous sequence of character in a
string.
"""


class Solution(object):
    def wonderfulSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        cnt = [1] + [0] * 1024
        ans, curr = 0,0
        for c in word:
            curr ^= 1 << (ord(c) - ord('a'))
            ans += cnt[curr]
            ans += sum(cnt[curr ^ (1 << i)] for i in range(10))
            cnt[curr] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.wonderfulSubstrings("aba"))  # expect: 4
    print(obj.wonderfulSubstrings("aabb"))  # expect: 9
    print(obj.wonderfulSubstrings("he"))  # expect: 2
