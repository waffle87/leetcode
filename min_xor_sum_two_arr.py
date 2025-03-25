# 1879. Minimum XOR Sum of Two Arrays

"""
you are given two integer arrays 'nums1' and 'nums2' of length 'n'. the xor
sum of the two integer arrays is '(nums1[0] ^ nums2[0]) + (nums1[1] ^
nums2[1]) + ...' (0-indexed). rearrange the elements of 'nums2' such that
resulting xor sum is minimised. return the xor sum after the rearrangement.
"""


class Solution(object):
    def minimumXORSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """

        def dfs(mask):
            i = bin(mask).count("1")
            if i >= len(nums1):
                return 0
            return min(
                (nums1[i] ^ nums2[j]) + dfs(mask + (1 << j))
                for j in range(len(nums2))
                if mask & (1 << j) == 0
            )

        return dfs(0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumXORSum(nums1=[1, 2], nums2=[2, 3]))
    print(obj.minimumXORSum(nums1=[1, 0, 3], nums2=[5, 3, 4]))
