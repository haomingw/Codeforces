def combine(a, tail):
    res = max(a, key=len)
    for x in a:
        if tail:
            if not res.endswith(x):
                return '*'
        else:
            if not res.startswith(x):
                return '*'
    return res


def solve():
    n = int(input())
    s = [input().split('*') for _ in range(n)]
    res = ''
    a, b = [], []
    for x in s:
        a.append(x[0])
        b.append(x[-1])
        res += ''.join(x[1:-1])
    res = combine(a, tail=False) + res
    res += combine(b, tail=True)
    if '*' in res:
        return '*'
    return res


T = int(input())
for t in range(1, T + 1):
    print("Case #%d:" % t, solve())
