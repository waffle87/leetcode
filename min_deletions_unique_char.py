# 1647. Minimum Deletions to Make Character Frequencies Unique
from collections import Counter

"""
a string 's' is called good if there are no two different characters in 's'
that have the same frequency. given a string 's', return the minimum number
of characters you need to delete to make 's' good. the frequency of a
character in a string is the number of times it appears in the string. for
example, in the string "aab", the frequency of 'a' is 2, while the frequency
of 'b' is 1.
"""


class Solution:
    def minDeletions(self, s):
        cnt = Counter(s)
        deletions = 0
        used_freq = set()
        for char, freq in cnt.items():
            while freq > 0 and freq in used_freq:
                freq -= 1
                deletions += 1
            used_freq.add(freq)

        return deletions


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDeletions("aab"))  # expect: 0
    print(obj.minDeletions("aaabbbcc"))  # expect: 2
