N = int(input())
S = input()
W = list(map(int, input().split()))

CHILD = "0"
ADULT = "1"

childCount = 0
adultCount = 0

pair = list()
for i in range(N):
    pair.append((S[i] == CHILD, W[i]))
    if S[i] == CHILD:
        childCount += 1
    else:
        adultCount += 1

pair = sorted(pair, key=lambda x:x[1])

acum = [0]
result = adultCount

i = 0
while i < N:

    (s, w) = pair[i]
    if i + 1 >= N or pair[i + 1][1] != w: 
        acum.append(acum[i] + s)
    else:
        acum.append(acum[i] + s)
        while i + 1 < N and pair[i + 1][1] == w:
            i += 1
            (s2, w) = pair[i]
            acum.append(acum[i] + s2)

    result = max(result, acum[i + 1] + (adultCount - ((i + 1) - acum[i + 1])))

    i += 1

print(result)

