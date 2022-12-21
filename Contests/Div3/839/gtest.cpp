#include<bits/stdc++.h>

using namespace std;

int rand(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    // cout << atoi(argv[1]) << "\n";
    srand(atoi(argv[1])); // Initialize random seed
    int t = 1;
    cout << t << "\n";
    int n = rand(2, 10), x = rand(0, 15), y = rand(x, 30);
    cout << n << " " << x << " " << y << "\n";
    set<int> st;
    while (true){
        st.insert(rand(1, 2 * n));
        if (st.size() == n) break;
    }
    for (int x: st) cout << x << " ";
    // generate test case
}