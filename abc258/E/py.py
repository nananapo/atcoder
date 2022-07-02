import bisect

N,Q,X = map(int, input().split())
W = list(map(int, input().split()))
Wc = [0]
for i in range(N):
    Wc.append(Wc[i] + W[i])

K = []
for q in range(Q):
    K.append(int(input()))

already = set()
start = 0

Lindex = dict() # じゃがいもの順番からループのインデックス
Lcount = dict()
Lstart = -1
Llength = -1
Lspos = -1

for i in range(N + 1):
    if start in already:
        Lstart = i + 1
        Lspos = Lindex[start]
        Llength = i - Lindex[start]
        break
    already.add(start)

    now = start
    count = 0
    su = 0
    while su < X:
        if su + Wc[N] - Wc[now] < X:
            count += N - now
            su += Wc[N] - Wc[now]
            now = 0
            continue
        if now == 0 and Wc[N] + su < X:
            k = (X - su) // Wc[N]
            count += N * k
            su += Wc[N] * k
            continue
        index = bisect.bisect_left(Wc, Wc[now] + X - su, lo=now)
        count += index - now
        su += Wc[index] - Wc[now]
        now = index % N
        break

    Lindex[start] = i
    Lcount[i] = count
    start = now

for k in K:
    if k <= Lstart:
        print(Lcount[k - 1])
    else:
        m = (k - Lstart) % Llength
        print(Lcount[(Lspos + m) % Llength])
