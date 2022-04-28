N = int(input())
D = {i+1:[] for i in range(N)}
for i in range(N-1):
    A,B = map(int, input().split())
    D[A].append(B)
    D[B].append(A)

def get_max(start):
    count = 0
    already = set(start)

    while len(start) != 0:
        renew = set()
        for i in start:
            for j in D[i]:
                if j not in already:
                    renew.add(j)
                    already.add(j)
        if len(renew) == 0:
            return (count, start)
        count += 1
        start = renew
#        print(start)

(c, s) = get_max(set([1]))
#print(c,s)
(c, s) = get_max(set([list(s)[0]]))
#print(c,s)
print(c+1)
