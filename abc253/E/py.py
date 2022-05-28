N, M, K = map(int, input().split())

dp = [[0] * 5005] * 1005

for i in range(1, M + 1):
    dp[0][i] = 1

for i in range(1, N):
    ac = 0
    for j in range(1 + K, M + 1):
        ac += dp[i - 1][j]
        ac = ac % 998244353
    for j in range(1, M + 1):
        dp[i][j] = ac
        print(ac, " ", end="")
        j = j + 1
        if j - K >= 1:
            ac += dp[i - 1][j - K]
            ac = ac % 998244353
        if j + K <= M + 1:
            ac -= dp[i - 1][j + K - 1]
            ac = ac % 998244353
    print("")

answer = 0
for i in range(M + 1):
    answer = (answer + dp[N - 1][i]) % 998244353
print(answer)
