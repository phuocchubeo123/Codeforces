# T_n = n(n+1)/2
# P_n = n(3n-1)/2
# H_n = n(2n-1)

import math

def is_pentagonal(m):
    # m = n(3n-1) / 2
    # 2m = 3n**2 - n
    # 24m + 1 = 36n**2 - 12n + 1

    p = 24 * m + 1
    if (p != (int(math.sqrt(p))) ** 2):
        return False
    
    p = int(math.sqrt(p))
    if (p + 1) % 6 == 0:
        return True
    else:
        return False

def is_hexagonal(m):
    # m = n(2n-1)
    # 8m + 1 = 16n**2 - 8n + 1

    p = 8 * m + 1
    if (p != (int(math.sqrt(p))) ** 2):
        return False
    
    p = int(math.sqrt(p))
    if (p + 1) % 4 == 0:
        return True
    else:
        return False

for n in range(286, 100000):
    T_n = n * (n + 1) / 2
    if is_pentagonal(T_n) and is_hexagonal(T_n):
        print(T_n)
        exit()