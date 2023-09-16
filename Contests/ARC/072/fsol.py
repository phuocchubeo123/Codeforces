n, l = list(map(int, input().strip().split()))

dq = []
ans = []
totx = 0
toty = 0

frt = 0
for i in range(n):
    # print(i, dq, frt)
    # print(frt)
    t, v = list(map(int, input().strip().split()))
    dq.append([v, t*v])
    # print(i, dq, frt)
    totx += v
    toty += t*v

    if i == 0:
        ans.append(dq[0][1])
        continue

    while True:
        x1 = dq[frt][0]
        y1 = dq[frt][1]
        # print(x1, y1, totx, toty)

        if totx - x1 < l:
            dq[frt][1] = y1 / x1 * (x1 - totx + l)
            dq[frt][0] = x1 - totx + l
            totx = totx - x1 + dq[frt][0]
            toty = toty - y1 + dq[frt][1]   
            ans.append(toty)
            break
        else:
            frt += 1
            # if frt > 0:
            #     print(i, frt)
            totx -= x1
            toty -= y1

    # print(i, dq, frt)

    x, y = dq.pop()
    while True:
        if (len(dq) == frt):
            dq.append([x, y])
            break
        x1 = dq[-1][0]
        y1 = dq[-1][1]
        if y1 / x1 < y / x:
            dq.append([x, y])
            break
        else:
            x += x1
            y += y1
            dq.pop()

for i in range(n):
    ans[i] = ans[i] / l
print('\n'.join(map(str, ans)))