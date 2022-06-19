import bisect

N, Q = map(int, input().split())
A = sorted(list(map(int, input().split())))

Ad = dict()
ac = [0]
for i in range(N):
    ac.append(ac[i] + A[i])
    if A[i] not in Ad:
        Ad[A[i]] = 0
    Ad[A[i]] += 1

for _ in range(Q):
    x = int(input())
    
    if x <= A[0]:
        print(ac[N] - x * N)
        continue
    if x >= A[N - 1]:
        print(x * N - ac[N])
        continue

    l = bisect.bisect_left(A, x)
    res = x * l - ac[l]
    r = bisect.bisect_right(A, x)
    res += (ac[N] - ac[r]) - x * (N - r)
    print(res)
