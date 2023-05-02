MOD = int(1e10)

tot = 0
for i in range(1, 1001):
    a = 1
    for j in range(i):
        a = (a * i) % MOD
    tot = (tot + a) % MOD

print(tot)