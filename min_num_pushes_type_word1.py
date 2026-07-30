# 3014. Minimum Number of Pushes to Type Word I

"""
you are given a string 'word' containing distinct lowercase english letters.
telephone keypas have keys mapped with distinct collections of lowercase
english letters, which can be used to form words by pushing them. it is
allowed to remap the keys numbered 2 - 9 to distinct collections of letters.
the keys can be remapped to any amount of letters, but each letter must be
mapped to exactly one key. you need to find  the minimum number of times the
keys will be pushed to type the string 'word'.
"""


class Solution:
    def minimumPushes(self, word: str) -> int:
        q, r = divmod(len(word), 8)
        return ((q << 2) + r) * (q + 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumPushes(word="abcde"))
    print(obj.minimumPushes(word="xycdefghij"))
