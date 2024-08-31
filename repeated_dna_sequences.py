# 187. Repeated DNA Sequences
from collections import defaultdict

"""
the dna sequence is composed of a series of nucleotides abbreviated as A, C,
G, and T. when studying dna it is useful to identify repeated sequences
within the dna. given a string 's' that represents a dna sequence, return all
the 10 letter long sequences (substrings) that occur more than once in a dna
molecule. you may return the answer in any order
"""


class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        seq = defaultdict(int)
        for i in range(len(s)):
            seq[s[i : i + 10]] += 1
        return [key for key, val in seq.iteritems() if val > 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findRepeatedDnaSequences(s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
    print(obj.findRepeatedDnaSequences(s="AAAAAAAAAAAAA"))
