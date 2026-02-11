# 3721. Longest Balanced Subarray II

"""
you are given an integer array 'nums'. a subarray is called balance if the
number of distinct even numbers in the subarray is equal to the number of
distinct odd numbers. return the legnth of the longest balance subarray.
"""


class Solution(object):
    def longestBalanced(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        m = 1 << n.bit_length()
        mx = [0] * (m << 1)
        mn = [0] * (m << 1)
        lz = [0] * (m << 1)
        last = {}
        ans, curr = 0, 0

        def ctz(i):
            return (i & -i).bit_length() - 1

        def update(i, v):
            mx[i] += v
            mn[i] += v
            lz[i] += v

        def push(i):
            h = i.bit_length()
            i |= m
            while h:
                j = i >> h
                if t := lz[j]:
                    update(j << 1, t)
                    update(j << 1 | 1, t)
                    lz[j] = 0
                h -= 1

        def pull(i):
            i |= m
            while i > 1:
                i >>= 1
                mx[i] = max(mx[i << 1], mx[i << 1 | 1]) + lz[i]
                mn[i] = max(mn[i << 1], mn[i << 1 | 1]) + lz[i]

        def add(i, v):
            push(i)
            s, t = i | m, m << 1
            while s < t:
                z = ctz(s)
                s >>= z
                t >>= z
                if s == t:
                    break
                update(s, v)
                s += 1
            pull(i)

        def query(v):
            i = 1
            while i < m:
                if t := lz[i]:
                    update(i << 1, t)
                    update(i << 1 | 1, t)
                    lz[i] = 0
                i <<= 1
                if not mn[i] <= v <= mx[i]:
                    i |= 1
            return i - m

        for i, v in enumerate(nums, 1):
            x = 1 if v & 1 else -1
            if pi := last.get(v):
                curr -= x
                add(pi, -x)
            curr += x
            add(i, x)
            last[v] = i
            ans = max(ans, i - query(curr))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestBalanced(nums=[2, 5, 4, 3]))
    print(obj.longestBalanced(nums=[3, 2, 2, 5, 4]))
    print(obj.longestBalanced(nums=[1, 2, 3, 2]))
