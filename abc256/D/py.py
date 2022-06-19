N = int(input())
s = list()

for i in range(N):
    l,r = map(int, input().split())
    s.append((l,True))
    s.append((r,False))
    

    rm = None
    ad = None
    for (l2,r2) in s:
        if l2 <= l and r <= r2:
            break
        if l <= l2 and r2 <= r:
            ad = (l, r)
            rm = (l2, r2)
            break
        if l <= l2 and r <= r2:
            ad = (l, r2)
            rm = (l2, r2)
            break
        if l2 <= l and l <= r2 and r2 <= r:
            ad = (l2, r)
            rm = (l2, r2)
            break
    if rm is None:
        s.add((l,r))
    else:
        s.remove(rm)
        s.add(ad)

s = sorted(s, key = lambda x:x[0])

for (l,r) in s:
    print(l, r)
