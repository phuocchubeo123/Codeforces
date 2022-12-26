maxn = int(1e6)

# sieve
is_prime = [1 for i in range(maxn)]
prime_factor = [[] for i in range(maxn)]
is_prime[0] = 0
is_prime[1] = 0
for i in range(maxn):
    if is_prime[i] == 1:
        prime_factor[i].append(i)
        for j in range(2 * i, maxn, i):
            is_prime[j] = 0
            prime_factor[j].append(i)

for i in range(maxn):
    if len(prime_factor[i]) >= 4 and len(prime_factor[i+1]) >= 4 and len(prime_factor[i+2]) >= 4 and len(prime_factor[i+3]) >= 4:
        print(i)
        exit()