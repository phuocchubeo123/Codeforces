#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
string keyboard;
string word;
array<int, 26> pos;

int encode(char c){
    return ((int) c) - 97;
}

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        for (int i = 0; i < 26; i++) pos[i] = 0;
        cin >> keyboard;
        cin >> word;
        for (int i = 0; i < 26; i++){
            pos[encode(keyboard[i])] = i;
        }
        
        int ans = 0;
        for (int i = 1; i < word.length(); i++){
            ans += abs(pos[encode(word[i])] - pos[encode(word[i-1])]);
        }
        cout << ans << "\n";
    }
}