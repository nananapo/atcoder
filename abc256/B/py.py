N = int(input())
A = list(map(int, input().split()))

P = 0

now = {i:0 for i in range(0, 4)}
now[0] = 1

for a in A:
    print(now)
    for i in range(3, -1, -1):
        if i + a >= 4:
            P += now[i]
            now[i] = 0
        else:
            now[i + a] = now[i]
    now[0] = 1

print(P)
