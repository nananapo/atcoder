import math
import heapq

N = int(input())
J = dict()

for i in range(N):
    x, y, P = map(int, input().split())
    J[i] = (x, y, P)

# i->jに必要な訓練回数をメモ
C = dict()
for i in range(N):
    x, y, p = J[i]
    C[i] = dict()
    for j in range(N):
        x2, y2 = J[j][0], J[j][1]
        C[i][j] = math.ceil((abs(x - x2) + abs(y - y2)) / p)

def di(start):
    S = 0
    d = [(0, start)]
    goal = set()
    while len(d) > 0 and len(goal) != N:
        s, pos = heapq.heappop(d)
        if pos in goal:
            continue
        S = max(S, s)
        goal.add(pos)
        for i in range(N):
            if i not in goal:
                heapq.heappush(d, (C[pos][i], i))
    return S

minS = 10000000000
for i in range(N):
    minS = min(minS, di(i))
print(minS)
