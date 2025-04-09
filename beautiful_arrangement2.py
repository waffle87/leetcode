# 667. Beautiful Arrangement II

"""
given two integers 'n' and 'k', construct a list 'answer' that contains 'n'
different positive integers ranging from 1 to 'n' and obeys the following
requirement: suppose this list is 'answer = [a1, a2, a3, ..., an]', the the
list '[a1 - a2, a2 - a3, ..., an-1 - an]' has exactly 'k' distinct integers.
return the list 'answer'. if there are multiple valid answers, return any of
them.
"""


class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        ans, left, right = [0] * n, 1, k + 1
        for i in range(k + 1):
            if i & 1:
                ans[i] = right
                right -= 1
            else:
                ans[i] = left
                left += 1
        for i in range(k + 1, n):
            ans[i] = i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.constructArray(3, 1))
    print(obj.constructArray(3, 2))
