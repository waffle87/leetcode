# 2217. Find Palindrome With Fixed Length

"""
given an integer array 'queries' and a positive integer 'intLength', return
an array 'ans' where 'ans[i]' is either the 'queries[i]'th smallest positive
palindreom of length 'intLength' or -1 if no such palindrome exists.
"""


class Solution(object):
    def kthPalindrome(self, queries, intLength):
        """
        :type queries: List[int]
        :type intLength: int
        :rtype: List[int]
        """
        base = 10 ** ((intLength - 1) / 2)
        ans = [q - 1 + base for q in queries]
        for i, a in enumerate(ans):
            a = str(a) + str(a)[-1 - intLength % 2 :: -1]
            ans[i] = int(a) if len(a) == intLength else -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthPalindrome(queries=[1, 2, 3, 4, 5, 90], intLength=3))
    print(obj.kthPalindrome(queries=[2, 4, 6], intLength=4))
