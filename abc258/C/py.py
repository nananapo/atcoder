N, Q = map(int, input().split())
S = input()
head = 0 

for i in range(Q):
    q, x = map(int, input().split())
    if q == 1:
        head = (head - x + N) % N
    else:
        print(S[(head + x - 1) % N])
