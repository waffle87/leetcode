# 932. Beautiful Array

"""
an array 'nums' of length 'n' is beautiful if 'nums' is a permutation of the
integers in the range '[1, n]', and for every '0 <= i < j < n', there is no
index 'k' with 'i < k < j' where '2  nums[k] == nums[i] + nums[j]'. given
the integer 'n', return any beautiful array 'nums' of length 'n'. there will
be at least one valid answer for the given 'n'.
"""


class Solution(object):
    def beautifulArray(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [1]
        while len(ans) < n:
            ans = [i * 2 - 1 for i in ans] + [i * 2 for i in ans]
        return [i for i in ans if i <= n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.beautifulArray(n=4))
    print(obj.beautifulArray(n=5))
