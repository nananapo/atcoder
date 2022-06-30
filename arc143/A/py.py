M = list(map(int, input().split()))
M = sorted(M)
A, B, C = M[0], M[1], M[2]

if (C - A) + (C - B) > C:
    print(-1)
    exit()

print(C)
