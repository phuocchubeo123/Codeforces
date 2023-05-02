import math

def is_pentagon(m):
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

for n in range(1, 2000):
    P_n = n * (3 * n - 1) / 2
    for m in range(1, 2000):
        P_m = m * (3 * m - 1) / 2
        if is_pentagon(P_n + P_m) and is_pentagon(2 * P_m + P_n):
            print(P_n)
            exit()