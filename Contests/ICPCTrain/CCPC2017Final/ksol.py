s1 = set()
s2 = set()

s1.add((0, 0))

ans = [1]

for i in range(1, 6):
    for (u, v) in s1:
        for (x, y) in ((1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)):
            s2.add((u+x, v+y))

    for (u, v) in s2:
        s1.add((u, v))
    
    s2.clear()
    ans.append(len(s1))


t = input()
for i in range(int(t)):
    print("Case #" + str(i+1) + ": ", end="")
    n = int(input())
    if (n < 6):
        print(ans[n])
    else:
        print(ans[5] + 148 * (n-5) + 28 * (n-5) * (n-6) // 2)