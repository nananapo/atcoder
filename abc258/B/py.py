N = int(input())
A = []
for i in range(N):
    A.append(list(map(int, list(input()))))

def move(t, y, x):
    if t == 0: # sita
        if y == N - 1:
            return (x, 0)
        return (x, y + 1)
    if t == 1: # ue
        if y == 0:
            return (x, N - 1)
        return (x, y - 1)
    if t == 2: # migi
        if x == N - 1:
            return (0, y)
        return (x + 1, y)
    if t == 3: # hidari
        if x == 0:
            return (N - 1, y)
        return (x - 1, y)
    if t == 4: #migiue
        if x == N - 1 and y == 0:
            return (0, N - 1)
        if x == N - 1:
            return (0, y - 1)
        if y == 0:
            return (x + 1, N - 1)
        return (x + 1, y - 1)
    if t == 5: # migisita
        if x == N - 1 and y == N - 1:
            return (0, 0)
        if x == N - 1:
            return (0, y + 1)
        if y == N - 1:
            return (x + 1, 0)
        return (x + 1, y + 1)
    if t == 6: # hidari ue
        if x == 0 and y == 0:
            return (N - 1, N - 1)
        if x == 0:
            return (N - 1, y - 1)
        if y == 0:
            return (x - 1, N - 1)
        return (x - 1, y - 1)
    if t == 7: # hidari sita
        if x == 0 and y == N - 1:
            return (N - 1, 0)
        if x == 0:
            return (N - 1, y + 1)
        if y == N - 1:
            return (x - 1, 0)
        return (x - 1, y + 1)

results = set()
for i in range(N):
    for j in range(N):
        for t in range(8):
            ny, nx = i, j
            v = 0
            for k in range(N):
                v = v * 10 + A[ny][nx]
                (nx, ny) = move(t, ny, nx)
            results.add(v)

print(max(results))
