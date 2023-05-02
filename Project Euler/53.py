c = [[0 for i in range(101)] for j in range(101)]

for i in range(101):
    c[i][0] = 1

for i in range(1, 101):
    for j in range(1, i+1):
        c[i][j] = c[i-1][j] + c[i-1][j-1]
        if c[i][j] > 1000000:
            c[i][j] = 1000001

ans = 0
for i in range(1, 101):
    for j in range(i+1):
        if c[i][j] > 1000000:
            ans += 1

print(ans)