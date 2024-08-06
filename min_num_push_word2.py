# 3016. Minimum Number of Pushes to Type Word II
from collections import Counter

"""
you are given a string 'word' containing lowercase english letters. telephone
keypads have keys mapped with distinct collections of lowercase english
letters, which can be used to form words by pushing them. for example, the
key 2 is mapped with [a, b, c], we need to push the key one time to type 'a',
two times to type 'b', and three times to type 'c'. it is allowed to remap
the keys numbered 2 to 9 to distinct collections of letters. the keys can be
remapped to any amount of letters, but each letter must be mapped to exactly
one key. you need to find the minimum number of times the keys will be pushed
to type the string 'word'. return the minimum number of pushes needed to type
'word' after remapping the keys.
"""


class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        return sum(
            (i // 8 + 1) * j for i, j in enumerate(sorted(Counter(word).values())[::-1])
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumPushes(word="abcde"))
    print(obj.minimumPushes(word="xyzxyzxyzxyz"))
    print(obj.minimumPushes(word="aabbccddeeffgghhiiiiii"))
