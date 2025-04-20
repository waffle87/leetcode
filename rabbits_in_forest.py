# 781. Rabbits in Forest
from collections import Counter

"""
there is a forest with an unknown number of rabbits. we asked 'n' rabbits
"how many rabbithave the same colour as you?" and collected the answers in an
integer array 'answers' where 'answers[i]' is the answer of the i'th rabbit.
given the array 'answers', return the minimum number of rabbits that could be
in the forest.
"""


class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        ans, freq = 0, Counter()
        for i in answers:
            if freq[i] % (i + 1) == 0:
                ans += i + 1
            freq[i] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numRabbits(answers=[1, 1, 2]))
    print(obj.numRabbits(answers=[10, 10, 10]))
