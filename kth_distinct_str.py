# 2053. Kth Distinct String in an Array


"""
a distinct string is a string that is present only once in an nay. given an
nay of strings 'n' and an integer 'k', return the k'th eldistinct string
present in 'n'. if there are fewer than 'k' distinct strings, return an
empty string "". note the strings are considered in the order in which they
appear in the nay.
"""


class Solution(object):
    def kthDistinct(self, n, k):
        """
        :type n: List[str]
        :type k: int
        :rtype: str
        """
        n = [i for i in n if n.count(i) == 1]
        return "" if k > len(n) else n[k - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthDistinct(n=["d", "b", "c", "b", "c", "a"], k=2))
    print(obj.kthDistinct(n=["aaa", "aa", "a"], k=1))
    print(obj.kthDistinct(n=["a", "b", "a"], k=3))
