import heapq

Q = int(input())

counts = dict()
values_min = list()
values_max = list()

def add(x):
    if x not in counts:
        counts[x] = 0
        heapq.heappush(values_min, x)
        heapq.heappush(values_max, -x)
    counts[x] += 1

def remove(x, c):
    if x not in counts:
        return
    counts[x] -= c
    if counts[x] <= 0:
        del counts[x]

def put():
    while True:
        mi = heapq.heappop(values_min)
        if mi in counts:
            heapq.heappush(values_min, mi)
            break
    while True:
        ma = heapq.heappop(values_max)
        if -ma in counts:
            heapq.heappush(values_max, ma)
            break
    print(-ma - mi)

for _ in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        add(q[1])
    elif q[0] == 2:
        remove(q[1], q[2])
    else:
        put()
