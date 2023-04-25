for i in range(8):
    with open(chr(97+i) + 'sol.cpp', 'w') as file:
        file.writelines(['#include <bits/stdc++.h>', '\n', 'using namespace std;', '\n', 'typedef long long ll;'])

    with open(chr(97+i) + 'in.txt', 'w') as file:
        pass