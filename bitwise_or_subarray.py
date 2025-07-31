# 898. Bitwise ORs of Subarrays

"""
given an integer array 'arr', return the number of distinct bitwise or's of
all the non-empty subarrays of 'arr'. the bitwise or of a subarray is the
bitwise or of each interger in the subarray. the bitwise or of a subarray of
one integer is that integer. a subarray is a contiguous non-empty sequence of
elements within an array.
"""


class Solution(object):
    def subarrayBitwiseORs(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        ans, curr = set(), set()
        for i in arr:
            curr = {i | j for j in curr} | {i}
            ans |= curr
        return len(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.subarrayBitwiseORs(arr=[0]))
    print(obj.subarrayBitwiseORs(arr=[1, 1, 2]))
    print(obj.subarrayBitwiseORs(arr=[1, 2, 4]))
