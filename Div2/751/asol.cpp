#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
string s, a, b;

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> s;
        int len = 0;
        int min_index;
        char min_char = 'z';
        for (char c: s){
            if (c < min_char){
                min_char = c;
                min_index = len;
            }
            len++;
        }
        cout << min_char << " ";
        s.erase(min_index, 1);
        cout << s <<  "\n";
    }
}