for i in range(8):
    with open(chr(97+i) + 'sol.cpp', 'w') as file:
        file.writelines(['#include <bits/stdc++.h>\n\n',
                         'using namespace std;\n\n', 
                         'typedef long long ll;\n'])

    with open(chr(97+i) + 'in.txt', 'w') as file:
        pass