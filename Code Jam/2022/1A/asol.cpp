#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int tt = 1;
void solve(){
    cout << "Case #" << tt++ << ": ";
    string s;    
    cin >> s;
    char curr = '0';
    string new_s = "";
    for0(i, s.size()){
        int j = i + 1;
        while (j < s.size() && s[j] == s[i]) j++;
        if (j == s.size()){
            new_s.pb(s[i]);
            continue;
        }
        if (s[j] > s[i]){
            new_s.pb(s[i]);
            new_s.pb(s[i]);
            continue;
        }

        else new_s.pb(s[i]);
    }

    cout << new_s << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    cin >> T;
    // T = 1;

    while (T--){
        solve();
    }
}