# 1079. Letter Tile Possibilities

"""
given 'n' tiles where each tile has one letter ('tiles[i]') printed on it.
return the number of possible non-empty letters printed on those tiles.
"""


class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        ans = set()

        def dfs(path, tiles):
            if path:
                ans.add(path)
            for i in range(len(tiles)):
                dfs(path + tiles[i], tiles[:i] + tiles[i + 1 :])

        dfs("", tiles)
        return len(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numTilePossibilities("AAB"))
    print(obj.numTilePossibilities("AAABBC"))
    print(obj.numTilePossibilities("V"))
