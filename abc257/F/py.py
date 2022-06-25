import math
import heapq
from collections import defaultdict

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        group_members = defaultdict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members

# UnionFindで到達できるか確認
# 0でつなげられるならダイクストラ
# 無理なら-1
N, M = map(int, input().split())
R = {i: set() for i in range(0, N + 1)}

uf = UnionFind(N + 1)
for i in range(M):
    u, v = map(int, input().split())
    R[u].add(v)
    R[v].add(u)
    if u != 0:
        uf.union(u, v)

def di(zero):
    d = [(0, 1)]
    goal = set()
    result = {i: -1 for i in range(1, N + 1)}

    while N not in goal and len(d) > 0:
        cost, pos = heapq.heappop(d)
        if pos in goal:
            continue
        goal.add(pos)
        result[pos] = cost

        if pos == N:
            break

        for i in R[pos]:
            if i == 0:
                i = zero
            if i not in goal:
                heapq.heappush(d, (cost + 1, i))
    return result[N]

hey = []
first = uf.same(1, N)
for i in range(1, N + 1):
    if not first:
            ok = False
            for j in R[0]:
                if uf.same(j, N):
                    ok = True
                    break
            if not ok:
                print(2)
                hey.append(-1)
                continue

    hey.append(di(i))
print(" ".join(map(str, hey)))
