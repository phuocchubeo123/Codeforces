fact = []
fact.append(1);

maxn = 40
for i in range(1, 2 * maxn):
    fact.append(fact[-1] * i)


binom = []
for i in range(maxn):
    binom.append(fact[2*i] // fact[i] // fact[i])

for x in binom:
    print(x)

print(10**18)