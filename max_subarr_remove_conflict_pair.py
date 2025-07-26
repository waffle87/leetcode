# 3480. Maximize Subarrays After Removing One Conflicting Pair

"""
you are given an integer 'n' which represents an array 'nums' containing the
numbers from 1 to 'n' in order. additionally, you are given a 2d array
'conflictingPairs' where 'conflictingPairs[i] = [a, b]' indicates that 'a'
and 'b' form a conflicting pair. remove exactly one element from
'conflictingPairs'. afterward, count the number of non-empty subarrays of
'nums' which do not contain both 'a' and 'b' for any remaining conflicting
pairs '[a, b]'. return the maximum number of subarrays possible after
removing exactly one conflicting pair.
"""


class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        """
        :type n: int
        :type conflictingPairs: List[List[int]]
        :rtype: int
        """
        right = [[] for _ in range(n + 1)]
        for a, b in conflictingPairs:
            right[max(a, b)].append(min(a, b))
        ans, left = 0, [0, 0]
        s = [0] * (n + 1)
        for r in range(1, n + 1):
            for l in right[r]:
                left = max(left, [l, left[0]], [left[0], l])
            ans += r - left[0]
            s[left[0]] += left[0] - left[1]
        return ans + max(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSubarrays(n=4, conflictingPairs=[[2, 3], [1, 4]]))
    print(obj.maxSubarrays(n=5, conflictingPairs=[[1, 2], [2, 5], [3, 5]]))
