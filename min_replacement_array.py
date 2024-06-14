# 2366. Minimum Replacements to Sort the Array
class Solution(object):
    def minimumReplacement(self, nums):
        x = nums[-1]
        ans = 0
        for i in reversed(nums):
            k = (i + x - 1) // x
            x = i // k
            ans += k - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumReplacement([3, 9, 3]))  # expect: 2
    print(obj.minimumReplacement([1, 2, 3, 4, 5]))  # expect: 0
