import sys

sys.setrecursionlimit(2000000000)

h1, h2, h3, w1, w2, w3 = map(int, input().split())
H = [h1, h2, h3]
W = [w1, w2, w3]
H2 = [h1, h2, h3]
W2 = [w1, w2, w3]

def check(a,b,c,d,e,f,g,h,i):
    if min(a,b,c,d,e,f,g,h,i) < 1:
        return False
    if H2[0] != a + d + g or H2[1] != b + e + h or H2[2] != c + f + i:
        return False
    if W2[0] != a + b + c or W2[1] != d + e + f or W2[2] != g + h + i:
        return False
    return True

res = 0

for a in range(1, W[0]):
    if H[0] - a < 1:
        break

    H[0] -= a

    for b in range(1, W[0] - a + 1):
        c = W[0] - a - b
        if H[1] - b < 1 or H[2] - c < 1:
            continue
        H[1] -= b
        H[2] -= c
        
        for d in range(1, H[0] + 1):
            e = H[0] - d
            if W[1] - d < 1 or W[2] - e < 1:
                continue
            W[1] -= d
            W[2] -= e
            
            for f in range(1, W[1] + 1):
                g = W[1] - f
                h = H[1] - f
                i = H[2] - g
                if not check(a,b,c,d,f,g,e,h,i):
                    continue
                res += 1

            W[1] += d
            W[2] += e

        H[1] += b
        H[2] += c
    H[0] += a
       
print(res) 
