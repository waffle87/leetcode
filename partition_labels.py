# 763. Partition Labels

"""
you are given a string 's'. we want to partition the string into as many
parts as possible so that each letter appears in at most one part. for
example, the string 'ababcc' can be partitioned into '["abab", "cc"]'. note
that the partition is done so that after concatenating all the parts in
order, the resultant string should be 's'. return a list of integers
representing the size of these parts.
"""


class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        curr, ans = 0, [0]
        ends = {c: i for i, c in enumerate(s)}
        while curr < len(s):
            prev = ends[s[curr]]
            while curr <= prev:
                sym = s[curr]
                prev = max(prev, ends[sym])
                curr += 1
            ans.append(curr)
        return [ans[i] - ans[i - 1] for i in range(1, len(ans))]


if __name__ == "__main__":
    obj = Solution()
    print(obj.partitionLabels(s="ababcbacadefegdehijhklij"))
    print(obj.partitionLabels(s="eccbbbbdec"))
