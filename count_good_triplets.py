# 1534. Count Good Triplets

"""
given an array of integers 'arr', and three integers 'a, b, c', yo need to
find the number of good triplets. a triplet '(arr[i], arr[j], arr[k])' is
good if the following conditions are met: '0 <= i < j < k < arr.len, |arr[i]
- arr[j]| <= (a, b, c)' where '|x|' denotes the absolute value of 'x'. return
the number of good triplets.
"""


class Solution(object):
    def countGoodTriplets(self, arr, a, b, c):
        """
        :type arr: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        cnt = 0
        n = len(arr)
        for i in range(n - 2):
            for k in range(i + 2, n):
                if abs(arr[k] - arr[i]) > c:
                    continue
                for j in range(i + 1, k):
                    if abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b:
                        cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodTriplets(arr=[3, 0, 1, 1, 9, 7], a=7, b=2, c=3))
    print(obj.countGoodTriplets(arr=[1, 1, 2, 2, 3], a=0, b=0, c=1))
