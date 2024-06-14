# 1207. Unique Number of Occurrences

"""
given an array of integers 'arr', return 'true' if the number of occurences
of each value in the array is unique or 'false' otherwise
"""


class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr.sort()
        v = []
        i = 0
        while i < len(arr):
            cnt = 1
            while i + 1 < len(arr) and arr[i] == arr[i + 1]:
                cnt += 1
                i += 1
            v.append(cnt)
            i += 1
        v.sort()
        for i in range(1, len(v)):
            if v[i] == v[i - 1]:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.uniqueOccurrences(arr=[1, 2, 2, 1, 1, 3]))
    print(obj.uniqueOccurrences(arr=[1, 2]))
    print(obj.uniqueOccurrences(arr=[-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]))
