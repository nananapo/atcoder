

def ret(x):
    tmp = x
    r = 0
    while tmp != 0:
        r = r * 10 + tmp % 10
        tmp //= 10
    return r

def f(x):
    check = set()
    while x not in check:
        check.add(x)
        x = ret(x)
    return min(check)

def solve(t, n, opt):
    if t % 10 == 0:
        return 0
    r = 0
    while t <= n:
        if f(t) == opt:
            r += 1
        t *= 10
    return r

def mysolve(k,n):
    if ret(k) == ret(ret(k)):
        return solve(k, n, k)
    return solve(k, n, k) + solve(ret(k), n, k)

"""
for n in range(1, 1000):
    for k in range(1, 1000):
        res1 = mysolve(k, n)
        res2 = 0
        for i in range(1, n + 1):
            if f(i) == k:
                res2 += 1

        #print(n, k, res1, res2)
        if res1 != res2:
            print("OUT",n,k,res1,res2)
            exit()
    if n % 10 == 0:
        print(n)
"""
N, K = map(int,input().split())
print(mysolve(K, N))
