# 744. Find Smallest Letter Greater Than Target
from bisect import bisect_right

"""
given an array of characters 'letters' that is sorted in non-decreasing
order, and a character 'target'. there are at least two different characters
in 'letters'. return the smallest character in 'letters' that is
lexicographically greater than 'target'. if such a character does not exist,
return the first character in 'letters'.
"""


class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        pos = bisect_right(letters, target)
        return letters[0] if pos == len(letters) else letters[pos]


if __name__ == "__main__":
    obj = Solution()
    print(obj.nextGreatestLetter(letters=["c", "f", "j"], target="a"))
    print(obj.nextGreatestLetter(letters=["c", "f", "j"], target="c"))
    print(obj.nextGreatestLetter(letters=["x", "x", "y", "y"], target="z"))
