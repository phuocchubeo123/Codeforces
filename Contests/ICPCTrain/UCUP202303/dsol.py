import math
import time

def merge(x1, y1, x2, y2):
    if y1 < x2:
        return ['a', 'a']
    if x1 > y2:
        return ['a', 'a']
    return [max(x1, x2), min(y1, y2)]

n, k = list(map(int, input().strip().split()))
f = list(map(int, input().strip().split()))
x = [0 for i in range(n)]
y = [0 for i in range(n)]

# aa = 0
# bb = 0
# start_time = time.time()
# PI = math.pi
# coss = [math.cos(-2 * PI * i / n) for i in range(n)]
# sinn = [math.sin(-2 * PI * i / n) for i in range(n)]

# for i in range(2000):
#     for j in range(2000):
#         aa += sinn[(i * j) % n]
#         bb += coss[(i * j) % n]

# print("Time:")
# print(time.time() - start_time)

PI = math.pi
coss = [math.cos(-2 * PI * i / n) for i in range(n)]
sinn = [math.sin(-2 * PI * i / n) for i in range(n)]

for t in range(n):
    Fr = 0
    Fi = 0
    for s in range(n):
        if s == k:
            continue
        Fr += f[s] * coss[(s * t) % n]
        Fi += f[s] * sinn[(s * t) % n]
    
    a = 2 * math.cos(-2 * math.pi * k * t / n) * Fr
    b = 2 * math.sin(-2 * math.pi * k * t / n) * Fi
    x[t] = a + b
    y[t] = Fr ** 2 + Fi ** 2

print(x)
print(y)

l = 0
r = (2000 ** 4) * 10 

while r - l > 10 ** (-11):
    m = (l + r) / 2
    u = [0 for i in range(n)]
    v = [0 for i in range(n)]
    for t in range(n):
        u[t] = math.ceil(-math.sqrt(m + (x[t] ** 2) / 4 - y[t]) - x[t] / 2)
        v[t] = math.floor(math.sqrt(m + (x[t] ** 2) / 4 - y[t]) - x[t] / 2)

    x1 = u[0]
    y1 = v[0]
    flag = True
    for t in range(1, n):
        x1, y1 = merge(x1, y1, u[t], v[t])
        if x1 == 'a':
            flag = False
            break
    
    if flag:
        r = m
    else:
        l = m

print(math.sqrt(l))