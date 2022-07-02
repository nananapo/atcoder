N, X = map(int, input().split())

A_MAX = 10 ** 9 + 1

A=[]
B=[]
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

res = set()
now = 0
for i in range(0, min(N, X)):
    now += A[i] + B[i]
    res.add(now + (X - i - 1) * B[i])
print(min(res))
