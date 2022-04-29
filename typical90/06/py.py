import sys
from collections import deque

N, K = map(int, input().split())
S = input() + "z"

D = {i:deque() for i in range(26)}

for i in range(N - K + 1):
    s = ord(S[i]) - ord("a")
    D[s].append(i)

answer = ""
now = -1

alp = "abcdefghijklmnopqrstuvwxyz"

for _ in range(K):
    for i in range(26):
        l = len(D[i])
        if l == 0:
            continue
        for __ in range(l):
            p = D[i].popleft()
            if p < now:
                continue
            now = p
            answer += alp[i]
            break
        else:
            continue
        k = N - K + _ + 1
        #print(k, S[k])
        D[ord(S[k]) - ord("a")].append(k)
        break

print(answer)
