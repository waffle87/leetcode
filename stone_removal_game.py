# 3360. Stone Removal Game


class Solution:
    def canAliceWin(self, n: int) -> bool:
        return (0x61F03F807FC00 >> n & 1) == 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.canAliceWin(n=12))
    print(obj.canAliceWin(n=1))
