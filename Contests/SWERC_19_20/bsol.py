t = int(input())

animal_count = dict()

for _ in range(t):
    s = input()
    if s in animal_count:
        animal_count[s] += 1

    else:
        animal_count[s] = 1
    
flag = False

for animal in animal_count:
    if animal_count[animal] > t // 2:
        print(animal)
        flag = True

if not flag:
    print("NONE")