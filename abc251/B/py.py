N,W = map(int,input().split())
A = sorted(list(map(int,input().split())));

a = set();
for i in range(N):
    if A[i] > W:
        break
    a.add(A[i]);
    for j in range(i + 1, N):
        if (A[i] + A[j] > W):
            break
        a.add(A[i] + A[j])
        for k in range(j + 1, N):
            if (A[i] + A[j] + A[k] > W):
                break
            a.add(A[i] + A[j] + A[k])

print(len(a))
