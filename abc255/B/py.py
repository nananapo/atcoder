import math

N, K = map(int,input().split())
A = set(list(map(int,input().split())))
X = []
Y = []
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

answer = 0
for i in range(N):
    if i + 1 in A:
        continue
    x, y = X[i], Y[i]
    now2 = 1000000
    for a in A:
        a = a - 1
        now = ((x - X[a]) ** 2 + (y - Y[a]) ** 2) ** 0.5
        now2 = min(now2, now);
    answer = max(answer, now2)
print(answer)
