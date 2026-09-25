# 1096. Brace Expansion II


class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        stk = [{""}]
        for i in expression:
            if i == ",":
                stk[-2:] = [stk[-2] | stk[-1], {""}]
            elif i == "}":
                stk[-3:] = [{l + r for r in (stk[-1] | stk[-2]) for l in stk[-3]}]
            elif i == "{":
                stk += [set(), {""}]
            else:
                stk[-1] = {pre + i for pre in stk[-1]}
        return sorted(stk[-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.braceExpansionII(expression="{a,b}{c,{d,e}}"))
    print(obj.braceExpansionII(expression="{{a,z},a{b,c},{ab,z}}"))
