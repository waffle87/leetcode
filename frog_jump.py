class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype bool
        """
        self.memo = set()
        target = stones[-1]
        stones = set(stones)
        ans = self.bt(stones, 1, 1, target)
        return ans

    def bt(self, stones, curr, speed, target):
        if (curr, speed) in self.memo:
            return False
        if curr == target:
            return True
        if curr > target or curr < 0 or speed <= 0 or curr not in stones:
            return False
        candidate = [speed - 1, speed, speed + 1]
        for c in candidate:
            if (curr + c) in stones:
                if self.bt(stones, curr + c, c, target):
                    return True
        self.memo.add((curr, speed))
        return False

if __name__ == "__main__":
    obj = Solution()
    print(obj.canCross([0,1,3,5,6,8,12,17])) # expect: True
    print(obj.canCross([0,1,2,3,4,8,9,11])) # expect: False
