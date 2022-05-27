N = int(input())

poems = set()

last_i = -1;
last_t = -1

for i in range(N):
    S, T = input().split()
    T = int(T)
    if S in poems:
        continue
    poems.add(S)
    if last_t < T:
        last_t = T
        last_i = i

print(last_i + 1)
