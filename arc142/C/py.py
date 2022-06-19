N = int(input())

D = {i:{j:-1 if i != j else 0 for j in range(1, N + 1)} for i in range(1, N + 1)}

HtoE = dict()

def answer(i):
    print("!", i)
    exit()

query_count = 0
def query(i, j, hint = 1):
    global query_count
    if query_count > 2 * N:
        answer(hint)
    query_count += 1
    print("?", i, j, flush=True)
    h = int(input())
    if h == -1:
        exit()
    D[i][j] = h
    return h

# 高さを決定
for i in range(3, N + 1):
    h = query(1, i)
    if h not in HtoE:
        HtoE[h] = [i]
    else:
        HtoE[h].append(i)

# 距離1の子が0個なら距離1
if 1 not in HtoE or len(HtoE[1]) == 0:
    answer(1)

# どの部分木に属するか決定する
min_pair = (-1, 100000)
for i in HtoE[1]:
    now = (i, query(i, 2))
    if min_pair[1] > now[1]:
        min_pair = now
    # 距離1なら答えは2
    if min_pair[1] == 1:
        answer(2)
    if min_pair[1] == 2:
        break

# 一番近い距離が2以外ならその部分木の子なので決定
if min_pair[1] != 2:
    answer(1 + min_pair[1])

# 答えが2なら部分木に含まれるか距離1

# 距離2なノードがないなら距離1
if 2 not in HtoE or len(HtoE[2]) == 0:
    answer(1)

# 適当な距離2のノードから探索
h = query(HtoE[2][0], 2, 3)
if h == 1:
    answer(3)
elif h == 3:
    answer(1)
else:
    answer(3)

