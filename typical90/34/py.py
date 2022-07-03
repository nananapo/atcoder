N, K = map(int, input().split())
A = list(map(int, input().split()))

left = 0
counts = dict()
result = 0
k = 0

for i in range(N):
    if A[i] in counts and counts[A[i]] > 0:
        counts[A[i]] += 1
        result = max(result, i - left + 1)
        continue
    if k < K:
        counts[A[i]] = 1
        result = max(result, i - left + 1)
        k += 1
        continue
    counts[A[i]] = 1
    for l in range(left, N):
        left += 1
        counts[A[l]] -= 1
        if counts[A[l]] == 0:
            break

print(result)
