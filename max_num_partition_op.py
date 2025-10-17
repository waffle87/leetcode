# 3003. Maximize the Number of Partitions After Operations

"""
you are given a string 's' and an integer 'k'. first, you are allowed to
change at mose one index in 's' to another lowercase english letter. after
that, do the following partitioning operation until 's' is empty: chose the
longest prefix of 's' containing at most 'k' distinct characters, and delete
the prefix from 's' and increase the number of partitions by one. the
remaining characters (if any) in 's' maintain their initial order. return an
integer denoting the maximum number of resulting partitions after the
operations chosing at most one index to change.
"""


class Solution(object):
    def maxPartitionsAfterOperations(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        alpha_size = 26
        if k == alpha_size:
            return 1
        n, used, cnt, ans = len(s), 0, 0, 1
        ansr = [0] * n
        usedr = [0] * n
        for i in range(n - 1, -1, -1):
            curr = ord(s[i]) - ord("a")
            if (used & (1 << curr)) == 0:
                if cnt == k:
                    cnt = 0
                    used = 0
                    ans += 1
                used |= 1 << curr
                cnt += 1
            ansr[i] = ans
            usedr[i] = used
        ansl = 0
        ans = ansr[0]
        l = 0
        while l < n:
            used = 0
            cnt = 0
            used_prev = 0
            used_2_prev = 0
            last = -1
            r = l
            while r < n:
                curr = ord(s[r]) - ord("a")
                if (used & (1 << curr)) == 0:
                    if cnt == k:
                        break
                    used_prev = used
                    last = r
                    used |= 1 << curr
                    cnt += 1
                elif cnt < k:
                    used_2_prev |= 1 << curr
                r += 1
            if cnt == k:
                if last - l > bin(used_prev).count("1"):
                    ans = max(ans, ansl + 1 + ansr[last])
                if last + 1 < r:
                    if last + 2 >= n:
                        ans = max(ans, ansl + 1 + 1)
                    else:
                        if bin(usedr[last + 2]).count("1") == k:
                            valid = ((1 << alpha_size) - 1) & ~used & ~usedr[last + 2]
                            if valid > 0:
                                ans = max(ans, ansl + 1 + 1 + ansr[last + 2])
                            else:
                                ans = max(ans, ansl + 1 + ansr[last + 2])
                            l1 = ord(s[last + 1]) - ord("a")
                            if (used_2_prev & (1 << l1)) == 0:
                                ans = max(ans, ansl + 1 + ansr[last + 1])
                        else:
                            ans = max(ans, ansl + 1 + ansr[last + 2])
            l = r
            ansl += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPartitionsAfterOperations(s="accca", k=2))
    print(obj.maxPartitionsAfterOperations(s="aabaab", k=3))
    print(obj.maxPartitionsAfterOperations(s="xxyz", k=1))
