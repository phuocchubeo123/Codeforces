#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
string s;

int countSubstring(string s, string v){
    int count = 0;

    for (int i = 0; i < s.length() - 1; i++){
        if (s.substr(i, 2) == v) count++;
    }
    return count;
}

int main(){
    cin >> t;
    for (int tt = 0; tt < t; tt++){
        cin >> s;
        int ab_count = countSubstring(s, "ab");
        int ba_count = countSubstring(s, "ba");
        
        if (ab_count == ba_count) cout << s << "\n";
        else {
            for (int i = 0; i < s.length(); i++){
                if (s[i] == 'a') s.replace(i, 1, "b");
                else s.replace(i, 1, "a");
                // cout << s << "\n";
                
                ab_count = countSubstring(s, "ab");
                ba_count = countSubstring(s, "ba");
                if (ab_count == ba_count){
                    cout << s << "\n"; 
                    break;
                }
                else {
                    if (s[i] == 'a') s.replace(i, 1, "b");
                    else s.replace(i, 1, "a");
                }
            }
        }
    }
}