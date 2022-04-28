N = int(input())

MAX = 2 ** N
answer = ""
for i in range(MAX):
    cnt = 0
    for j in range(N):
        mask = 1 << (N - j - 1)
        if mask & i != 0:
            cnt -= 1
            if cnt < 0:
                cnt = -1
                break
        else:
            cnt += 1
    if cnt != 0:
        continue
    for j in range(N):
        mask = 1 << (N - j - 1)
        if mask & i != 0:
            answer += ")"
        else:
            answer += "("
    answer += "\n"
print(answer, end="")
