# 3331. Find Subtree Sizes After Changes


class Solution:
    def findSubtreeSizes(self, parent: list[int], s: str) -> list[int]:
        children = [[] for _ in s]
        for i in range(1, len(s)):
            children[parent[i]].append(i)
        ans, prev = [1] * len(s), {}

        def dfs(x):
            c = s[x]
            above = prev.get(c, -1)
            prev[c] = x
            for i in children[x]:
                dfs(i)
            prev[c] = above
            if x:
                ans[above if above >= 0 else parent[x]] += ans[x]

        dfs(0)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findSubtreeSizes(parent=[-1, 0, 0, 1, 1, 1], s="abaabc"))
    print(obj.findSubtreeSizes(parent=[-1, 0, 4, 0, 1], s="abbba"))
