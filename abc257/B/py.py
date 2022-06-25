N, K, Q = map(int, input().split())
A = list(map(int, input().split()))
L = list(map(int, input().split()))

M = {i:0 for i in range(1, N + 1)}
for i in range(K):
    M[A[i]] = 1

for i in range(Q):
    l = L[i] - 1
    if A[l] == N:
        continue
    if l == K - 1:
        A[l] += 1
    elif A[l] + 1 != A[l + 1]:
        A[l] += 1

print(" ".join(map(str, A)))
