# 811. Subdomain Visit Count
from collections import Counter

"""
a website domain "discuss.leetcode.com" consists of various subdomains. at
the level, we have "com" at the next level, we have "leetcode.com", and the
lest level, "discuss.leetcode.com". when we visit a domain like the above, we
will also visit the parent domains "leetcode.com" and "com" implicitly. a
count paired domain is a domain that has one of the two formats
"rep.d1.d2.d3" or "rep.d1.d2" where "rep" is the number of visits to the
domain and 'd1.d2.d3' is the domain itself. given an array of count paird
domains 'cpdomains' return an array of the count pared domains of each
subdomain in the input. you may return the answer in any order.
"""


class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        cnt = Counter()
        for cp in cpdomains:
            n, s = cp.split()
            cnt[s] += int(n)
            for i in range(len(s)):
                if s[i] == ".":
                    cnt[s[i + 1 :]] += int(n)
        return ["%d %s" % (cnt[k], k) for k in cnt]


if __name__ == "__main__":
    obj = Solution()
    print(obj.subdomainVisits(cpdomains=["9001 discuss.leetcode.com"]))
    print(
        obj.subdomainVisits(
            cpdomains=[
                "900 google.mail.com",
                "50 yahoo.com",
                "1 intel.mail.com",
                "5 wiki.org",
            ]
        )
    )
