# 1399. Count Largest Group

"""
you are given an integer 'n'. each number from 1 to 'n' is grouped according
to the sum of its digits. return the number of groups that have the largest
size.
"""


class Solution(object):
    def get_num(self, n):
        res = 0
        while n != 0:
            res += n % 10
            n //= 10
        return res

    def countLargestGroup(self, n):
        """
        :type n: int
        :rtype: int
        """
        arr, m = [0] * 37, 0
        for i in range(1, n + 1):
            curr = self.get_num(i)
            arr[curr] += 1
            if arr[curr] > m:
                m = arr[curr]
        cnt = 0
        for i in range(37):
            if arr[i] == m:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countLargestGroup(n=13))
    print(obj.countLargestGroup(n=2))
