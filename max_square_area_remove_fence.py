# 2975. Maximum Square Area by Removing Fences From a Field

"""
there is a large '(m - 1) + (n - 1)' rectangular field with corners at '(1,
1)' and '(m, n)' containing some horizontal and vertical fences given in
arrays 'hFences' and 'vFences' respectively. horizontal fences are from the
coordinates '(hFences[i], 1)' to '(hFences[i], n)' and vertical fences the
corresponding appropriately. return the maximum area of a square field that
can be formed by removing somee fences or -1 if is impossible to make a
square field.
"""


class Solution(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        """
        :type m: int
        :type n: int
        :type hFences: List[int]
        :type vFences: List[int]
        :rtype: int
        """
        hFences.sort()
        vFences.sort()
        hFences = [1] + hFences + [m]
        vFences = [1] + vFences + [n]
        ans, cnt = -1, {}
        for i in range(len(hFences)):
            for j in range(i + 1, len(hFences)):
                cnt[hFences[j] - hFences[i]] = 1
        for i in range(len(vFences)):
            for j in range(i + 1, len(vFences)):
                if (vFences[j] - vFences[i]) in cnt:
                    ans = max(ans, vFences[j] - vFences[i])
        if ans == -1:
            return ans
        mod = 10**9 + 7
        return (ans * ans) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximizeSquareArea(m=4, n=3, hFences=[2, 3], vFences=[2]))
    print(obj.maximizeSquareArea(m=6, n=7, hFences=[2], vFences=[4]))
