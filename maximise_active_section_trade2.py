# 3501. Maximize Active Section with Trade II
from typing import List

"""
you are given a binary string 's' of length 'n' where '1' represents an
active section, and '0' represents an inactive section. you can perform at
most one trade to maximise the number of active sections in 's'.
additionally, you are given a 2d array 'queries' where 'queries[i] = [l_i,
r_i]' represents a substring 's[l_i ... r_i]'. for each query, determine the
maximum possible number of active sections in 's' after making the optimal
trade on the substring 's[l_i ... r_i]'. return an array 'answer' where
'answer[i]' is the result for 'queries[i]'.
"""


class Solution:
    def maxActiveSectionsAfterTrade(
        self, s: str, queries: List[List[int]]
    ) -> List[int]:
        n = len(s)
        one_cnt = s.count("1")
        type_arr = []
        start = []
        end_idx = []
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            type_arr.append(int(s[i]))
            start.append(i)
            end_idx.append(j - 1)
            i = j
        len = len(type_arr)
        pos_to_seg = [0] * n
        for idx in range(len):
            for j in range(start[idx], end_idx[idx] + 1):
                pos_to_seg[j] = idx
        ans = [0] * len
        for idx in range(1, len - 1):
            if type_arr[idx] == 1:
                ans[idx] = (end_idx[idx - 1] - start[idx - 1] + 1) + (
                    end_idx[idx + 1] - start[idx + 1] + 1
                )
        log_table = [0] * (len + 1)
        for idx in range(2, len + 1):
            log_table[idx] = log_table[idx // 2] + 1
        k = log_table[len] + 1
        st = [[0] * len for _ in range(k)]
        for idx in range(len):
            st[0][idx] = ans[idx]
        for j in range(1, k):
            for idx in range(len - (1 << j) + 1):
                st[j][idx] = max(st[j - 1][idx], st[j - 1][idx + (1 << (j - 1))])

        def query_rmq(l_q, r_q):
            if l_q > r_q:
                return 0
            j = log_table[r_q - l_q + 1]
            return max(st[j][l_q], st[j][r_q - (1 << j) + 1])

        def eval_seg(idx, l, r, seg_l, seg_r):
            if idx <= seg_l or idx >= seg_r:
                return 0
            if type_arr[idx] == 0:
                return 0

            if idx - 1 == seg_l:
                left_len = max(0, end_idx[idx - 1] - l + 1)
            else:
                left_len = end_idx[idx - 1] - start[idx - 1] + 1

            if idx + 1 == seg_r:
                right_len = max(0, r - start[idx + 1] + 1)
            else:
                right_len = end_idx[idx + 1] - start[idx + 1] + 1

            return left_len + right_len

        ans = []
        for l, r in queries:
            seg_l = pos_to_seg[l]
            seg_r = pos_to_seg[r]
            if seg_r - seg_l < 2:
                ans.append(one_cnt)
                continue
            max_gain = 0
            max_gain = max(max_gain, eval_seg(seg_l + 1, l, r, seg_l, seg_r))
            max_gain = max(max_gain, eval_seg(seg_r - 1, l, r, seg_l, seg_r))
            if seg_l + 2 <= seg_r - 2:
                max_gain = max(max_gain, query_rmq(seg_l + 2, seg_r - 2))
            ans.append(one_cnt + max_gain)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxActiveSectionsAfterTrade(s="01", queries=[[0, 1]]))
    print(
        obj.maxActiveSectionsAfterTrade(
            s="0100", queries=[[0, 3], [0, 2], [1, 3], [2, 3]]
        )
    )
    print(
        obj.maxActiveSectionsAfterTrade(s="1000100", queries=[[1, 5], [0, 6], [0, 4]])
    )
    print(obj.maxActiveSectionsAfterTrade(s="01010", queries=[[0, 3], [1, 4], [1, 3]]))
