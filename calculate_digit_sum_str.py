# 2243. Calculate Digit Sum of a String
from itertools import batched


class Solution:
    def digitSum(self, s: str, k: int) -> str:
        return (
            s
            if len(s) <= k
            else self.digitSum("".join(str(sum(map(int, g))) for g in batched(s, k)))
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.digitSum(s="11111222223", k=3))
    print(obj.digitSum(s="00000000", k=3))
