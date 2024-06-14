# 3068. Find the Maximum Sum of Node Values

"""
there exists an undirected tree with 'n' nodes numbered 0 to 'n - 1'. you are
given a 0-indexed 2d integer array 'edges' of length 'n - 1', where 'edges[i]
= [ui,vi]' indicates that there is an edge between nodes 'ui' and 'vi' in the
tree. you are also given a positive integer 'k' and a 0 indexed array of non
negative integers 'nums' of length 'n' where 'nums[i]' represents the value
of the node numbered 'i'. return the maximum possible sum of the values alice
can achieve by performing the operation any number of times.
"""


class Solution(object):
    def maximumValueSum(self, nums, k, edges):
        """
        :type nums: List[int]
        :type k: int
        :type edges: List[List[int]]
        :rtype: int
        """
        ans, c, d = 0, 0, 1 << 30
        for n in nums:
            ans += max(n, b := n ^ k)
            c ^= n < b
            d = min(d, abs(n - b))
        return ans - d * c


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumValueSum(nums=[1, 2, 1], k=3, edges=[[0, 1], [0, 2]]))
    print(obj.maximumValueSum(nums=[2, 3], k=7, edges=[[0, 1]]))
    print(
        obj.maximumValueSum(
            nums=[7, 7, 7, 7, 7, 7], k=3, edges=[[0, 1], [0, 2], [0, 3], [0, 4], [0, 5]]
        )
    )
