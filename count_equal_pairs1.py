# 3265. Count Almost Equal Pairs I

"""
you are given an array 'nums' consisting of positive integers. we call two
integers 'x' and 'y' in this problem almost equal if both integers can become
equal after performing the following operation at most once: choose either
'x' or 'y' and swap any two digits within the chosen number. return the
number of indices 'i' and 'j' in 'nums' where 'i < j' such that 'nums[i]' and
'nums[j]' are almost equal. note that it is allowed for an integer to have
leading zeros after performing an operation.
"""


class Solution(object):
    def countPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pow10 = [1000000, 100000, 10000, 1000, 100, 10, 1]
        table, ans = {}, 0
        for swapped in nums:
            cnt = table.get(swapped, 0)
            table[swapped] = cnt + 1
            ans += cnt
            for j in range(6):
                for k in range(j + 1, 7):
                    n = int(swapped / pow10[j] % 10)
                    m = int(swapped / pow10[k] % 10)
                    if n != m:
                        swapped += (m - n) * pow10[j] + (n - m) * pow10[k]
                        ans += table.get(swapped, 0)
                        swapped += (m - n) * pow10[k] + (n - m) * pow10[j]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPairs(nums=[3, 12, 30, 17, 21]))
    print(obj.countPairs(nums=[1, 1, 1, 1, 1]))
    print(obj.countPairs(nums=[123, 231]))
