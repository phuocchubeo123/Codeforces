for digits in range(7):
    for x in range(10 ** digits, 10 ** (digits + 1)):
        x1 = int(x)
        cnt = [0 for i in range(10)]
        for i in range(digits+1):
            cnt[x1 % 10] += 1
            x1 //= 10

        flag = True

        for y in range(2 * x, 7 * x, x):
            y1 = int(y)
            cnt2 = [0 for i in range(10)]
            for i in range(digits+1):
                cnt2[y1 % 10] += 1
                y1 //= 10
            
            if cnt2 != cnt:
                # print(x, y)
                # print(cnt, cnt2)
                flag = False
                break

        if flag:
            print(x)        
            break