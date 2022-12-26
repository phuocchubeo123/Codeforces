maxn = int(1e5)

# sieve
is_prime = [1 for i in range(maxn)]
is_prime[0] = 0
is_prime[1] = 0
for i in range(maxn):
    if is_prime[i] == 1:
        for j in range(2 * i, maxn, i):
            is_prime[j] = 0

for n in range(1000, 10000 - 6660):
    if is_prime[n] and is_prime[n+3330] and is_prime[n+6660]:
        print(n, n+3330, n+6660)