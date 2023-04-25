#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n;
string s, p;

void read(){
    s = "";
    cin >> n;
    bool flag = false;
    for (int i = 0; i < n - 2; i++){
        cin >> p; 
        if (s.size() == 0){
            s = p;
            // cout << s << " ";
            continue;
        }

        // cout << s[s.size() - 1] << " ";
        if (s[s.size() - 1] == p[0]) s.push_back(p[1]);
        else{
            s.insert(s.size(), p);
            flag = true;
        }

        // cout << s << " ";
    }
    if (!flag) s.push_back('a');
    cout << s << "\n";
}

void solve(){
    
}

int main(){
    cin >> T;
    // T = 1;

    while (T--){
        read();
        solve();
    }
}