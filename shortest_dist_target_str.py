# 2515. Shortest Distance to Target String in a Circular Array

"""
you are given a 0-indexed circular string array 'words' and a string
'target'. a circular array means that the array's end connects to the array's
beginning. starting from 'startIndex', you can move to either the next word
or the previous word with 1 step at a time. return the shortest distance
needed to reach the string 'target'. if the string 'target' does not exist in
'words', return -1.
"""


class Solution(object):
    def closestTarget(self, words, target, startIndex):
        """
        :type words: List[str]
        :type target: str
        :type startIndex: int
        :rtype: int
        """
        ans, n = len(words), len(words)
        for i, j in enumerate(words):
            if j == target:
                ans = min(ans, abs(i - startIndex), n - abs(i - startIndex))
        return ans if ans < n else -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.closestTarget(
            words=["hello", "i", "am", "leetcode", "hello"],
            target="hello",
            startIndex=1,
        )
    )
    print(
        obj.closestTarget(words=["a", "b", "leetcode"], target="leetcode", startIndex=0)
    )
    print(obj.closestTarget(words=["i", "eat", "leetcode"], target="ate", startIndex=0))
