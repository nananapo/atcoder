import heapq
import sys

sys.setrecursionlimit(10000000)

N = int(input())

road = {i: [] for i in range(1, N + 1)}
for _ in range(N - 1):
    A, B = map(int, input().split())
    heapq.heappush(road[A], B)
    heapq.heappush(road[B], A)

hist = []
visited = set()

def rec(i):
    hist.append(i)
    visited.add(i)
    while len(road[i]) > 0:
        p = heapq.heappop(road[i])
        if p in visited:
            continue;
        rec(p)
        hist.append(i)

rec(1)

print(" ".join(map(str, hist)))
