H,W = map(int,input().split())
A = dict()
SW = list()
SH = list()
for i in range(H):
    A[i] = list(map(int,input().split()))
    SW.append(sum(A[i]))
for x in range(W):
    s = 0
    for y in range(H):
        s += A[y][x]
    SH.append(s)

answer = {i:[] for i in range(H)}
for y in range(H):
    for x in range(W):
        answer[y].append(SH[x] + SW[y] - A[y][x])

print("\n".join(map(lambda a:" ".join(map(str,answer[a])), answer)))
