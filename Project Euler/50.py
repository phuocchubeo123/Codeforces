maxn = int(1e6)

# sieve
is_prime = [1 for i in range(maxn)]
is_prime[0] = 0
is_prime[1] = 0
for i in range(maxn):
    if is_prime[i] == 1:
        for j in range(2 * i, maxn, i):
            is_prime[j] = 0

primes = []
for i in range(maxn):
    if is_prime[i] == 1:
        primes.append(i)

for num_consecutive in range(1, 600):
    tot = 0
    for i in range(num_consecutive):
        tot += primes[i]
    
    if is_prime[tot]:
        print(tot, num_consecutive)
    
    for i in range(len(primes) - num_consecutive):
        tot -= primes[i]
        tot += primes[i+num_consecutive]
        if tot >= 1e6:
            break
        if is_prime[tot]:
            print(tot, num_consecutive)