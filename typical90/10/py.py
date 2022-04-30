N = int(input())

acm1 = [0]
acm2 = [0]
for i in range(N):
    c,p = map(int,input().split())
    if c == 1:
        acm1.append(acm1[i] + p)
        acm2.append(acm2[i])
    else:
        acm1.append(acm1[i])
        acm2.append(acm2[i] + p)
Q = int(input())
for i in range(Q):
    l,r = map(int,input().split())
    print(acm1[r] - acm1[l - 1], acm2[r] - acm2[l-1])
