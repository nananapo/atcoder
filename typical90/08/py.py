N=int(input())
S=input()

dp = {0:[1,0,0,0, 0,0,0,0]}
index = 0

Z = 10**9 + 7

for _ in range(N):
    s = S[_]
    if s not in "atcoder":
        continue
    cp = [dp[index][i] for i in range(8)]
    i = "atcoder".index(s)
    cp[i + 1] = (cp[i + 1] + dp[index][i]) % Z
    index += 1
    dp[index] = cp

print(dp[index][7])
