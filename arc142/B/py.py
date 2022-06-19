N = int(input())

A = [[-1 for j in range(N)] for i in range(N)]

B = [[0 for i in range(N)] for j in range(N)]
C = [[0 for i in range(N)] for j in range(N)]

A[0][0] = 0
def rec(i, j):
    if 
    

for i in range(N):
    for j in range(N):
        if i % 2 == 0:
            A[i][j] = i * N + j
        else:
            A[i][j] = i * N + N - j - 1

def check(i, j):
    a = 0
    b = 0
    base = A[i][j]
    for k in range(i - 1, i + 2):
        for l in range(j - 1, j + 2):
            if (i == k and j == l) or k < 0 or k >= N or l < 0 or l >= N:
                continue
            if base < A[k][l]:
                a += 1
            else:
                b += 1
    return (a, b)

for i in range(N):
    for j in range(N):
        C[i][j] = check(i, j)

for i in range(N):
    print(C[i])
