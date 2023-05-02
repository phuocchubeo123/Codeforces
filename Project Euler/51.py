maxn = int(1e7)

# sieve
is_prime = [1 for i in range(maxn)]
is_prime[0] = 0
is_prime[1] = 0
for i in range(maxn):
    if is_prime[i] == 1:
        for j in range(2 * i, maxn, i):
            is_prime[j] = 0

for digits in range(1, 7):
    num = [-1 for i in range(digits)]

    for mask in range((1 << digits)):
        blank = []
        fixed = []
        for i in range(digits):
            if ((mask >> i) & 1) == 1:
                blank.append(i)
            else:
                fixed.append(i)
    
        for fixed_num in range(10 ** len(fixed)):
            n = int(fixed_num)
            for i in fixed:
                num[i] = n % 10
                n //= 10
        
            for i in blank:
                num[i] = -1

            res = []

            for i in range(10):
                for j in blank:
                    num[j] = i
                actual_num = 0
                for j in range(digits):
                    actual_num = actual_num * 10 + num[j]
                if is_prime[actual_num] == 1:
                    res.append(actual_num)
            
            if len(res) == 8:
                print(num, res)