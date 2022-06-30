N, K = map(int, input().split())
A = list(map(int, input().split()))
B = sorted(A)

for i in range(0, K):
    p = [A[j] for j in range(i, N, K)]
    q = [B[j] for j in range(i, N, K)]
    p = sorted(p)
    for i in range(len(p)):
        if p[i] != q[i]:
            print("No")
            exit()

print("Yes")
