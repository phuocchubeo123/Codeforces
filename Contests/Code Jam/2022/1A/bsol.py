from sys import stdout

t = int(input())
for tt in range(t):
    n = int(input())
    # print(n)
    # stdout.flush()
    
    a = [[i for i in range(1, n + 1)]]
    for i in range(n):
        print(a[i])
    stdout.flush()
    
    b = input().strip().split()
    print(*b)
    stdout.flush()