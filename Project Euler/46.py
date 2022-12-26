maxn = int(1e7)

# sieve
is_prime = [1 for i in range(maxn)]
is_prime[0] = 0
is_prime[1] = 0
for i in range(maxn):
    if is_prime[i] == 1:
        for j in range(2 * i, maxn, i):
            is_prime[j] = 0

# solve
for n in range(3, maxn, 2):
    flag = False
    for m in range(maxn):
        if 2 * m * m > n:
            break
        if is_prime[n - 2 * m * m] == 1:
            print(n, n - 2 * m * m)
            flag = True
            break
    if not flag:
        print(n)
        exit()