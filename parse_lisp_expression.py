# 736. Parse Lisp Expression


class Solution(object):
    def evaluate(self, expression):
        """
        :type expression: str
        :rtype: int
        """
        stk, d, tokens = [], {}, [""]

        def getval(x):
            return d.get(x, x)

        def evaluate(tokens):
            if tokens[0] in ("add", "mult"):
                tmp = map(int, map(getval, tokens[1:]))
                return str(tmp[0] + tmp[1] if tokens[0] == "add" else tmp[0] * tmp[1])
            else:
                for i in range(1, len(tokens) - 1, 2):
                    if tokens[i + 1]:
                        d[tokens[i]] = getval(tokens[i + 1])
                return getval(tokens[-1])

        for c in expression:
            if c == "(":
                if tokens[0] == "let":
                    evaluate(tokens)
                stk.append((tokens, dict(d)))
                tokens = [""]
            elif c == " ":
                tokens.append("")
            elif c == ")":
                val = evaluate(tokens)
                tokens, d = stk.pop()
                tokens[-1] += val
            else:
                tokens[-1] += c
        return int(tokens[0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.evaluate(expression="(let x 2 (mult x (let x 3 y 4 (add x y))))"))
    print(obj.evaluate(expression="(let x 3 x 2 x)"))
    print(obj.evaluate(expression="(let x 1 y 2 x (add x y) (add x y))"))
