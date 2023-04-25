#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef complex<double> cd;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

void solve(){
    string s; cin >> s;
    int n = s.size();
    if (n == 1){
        if (s[0] == '_'){
            cout << 1;
            return;
        }
        if (s[0] == 'X'){
            cout << 1;
            return;
        }
        if (s[0] == '0'){
            cout << 1;
            return;
        }
        cout << 0; return;
    }

    if (s[0] == '0'){
        cout << 0;
        return;
    }

    int a = 0, b = 0;
    forn(i, n){
        if (s[i] == '_') b++;
        if (s[i] == 'X') a++;
    }
    if (s[n-1] == '_' && s[n-2] == '_'){
        if (n == 2){
            cout << 3;
            return;
        }
        ll ans = 1;
        if (a > 0) ans *= 10;
        ans *= 4;
        forn(i, b-2) ans *= 10;
        if (s[0] == '_'){ ans /= 10; ans *= 9;}
        if (s[0] == 'X'){ ans /= 10; ans *= 9;}
        cout << ans;
        return;
    }

    if (s[n-2] == '_' && s[n-1] == 'X'){
        if (n == 2){
            cout << 3;
            return;
        }
        ll ans = 1;
        if (s[0] == 'X'){
            ans *= 2;
            forn(i, b-1) ans *= 10;
            cout << ans;
            return;
        }
        ans *= 4;
        forn(i, b-1) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        cout << ans;
        return;
    }

    if (s[n-2] == 'X' && s[n-1] == '_'){
        if (n == 2){
            cout << 3;
            return;
        }
        ll ans = 1;
        if (s[0] == 'X'){
            ans *= 3;
            forn(i, b-1) ans *= 10;
            cout << ans;
            return;
        }
        ans *= 4;
        forn(i, b-1) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        cout << ans;
        return;
    }

    if (s[n-2] == 'X' && s[n-1] == 'X'){
        if (n == 2){
            cout << 0;
            return;
        }
        ll ans = 1;
        if (s[0] == 'X'){
            cout << 0;
            return;
        }
        ans *= 1;
        forn(i, b) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        cout << ans;
        return;
    }

    if (s[n-1] == 'X'){
        ll ans = 1;
        forn(i, b) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        if (s[n-2] == '0' || s[n-2] == '2' || s[n-2] == '5' || s[n-2] == '7'){
            cout << ans; 
            return;
        }
        else{
            cout << 0;
            return;
        }
    }

    if (s[n-1] == '_'){
        ll ans = 1;
        forn(i, b-1) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        if (a > 0) ans *= 10;
        if (s[0] == 'X'){ ans /= 10; ans *= 9;}
        if (s[n-2] == '0' || s[n-2] == '2' || s[n-2] == '5' || s[n-2] == '7'){
            cout << ans; 
            return;
        }
        else{
            cout << 0;
            return;
        }
    }

    if (s[n-2] == 'X'){
        if (n == 2){
            if (s[n-1] == '0') cout << 1;
            else if (s[n-1] == '5') cout << 2;
            else cout << 0;
            return;
        }
        ll ans = 1;
        forn(i, b) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        if (s[n-1] == '0' || s[n-1] == '5'){
            cout << ans * 2;
            return;
        }
        else{
            cout << 0;
            return;
        }
    }

    if (s[n-2] == '_'){
        if (n == 2){
            if (s[n-1] == '0') cout << 1;
            else if (s[n-1] == '5') cout << 2;
            else cout << 0;
            return;
        }
        ll ans = 1;
        forn(i, b-1) ans *= 10;
        if (s[0] == '_'){ans /= 10; ans *= 9;}
        if (a > 0) ans *= 10;
        if (s[0] == 'X'){ ans /= 10; ans *= 9;}
        if (s[n-1] == '0' || s[n-1] == '5'){
            cout << ans * 2;
            return;
        }
        else{
            cout << 0;
            return;
        }
    }

    ll ans = 1;
    forn(i, b) ans *= 10;
    if (s[0] == '_'){ans /= 10; ans *= 9;}
    if (a > 0) ans *= 10;
    if (s[0] == 'X'){ ans /= 10; ans *= 9;}
    if (s[n-2] == '0' && s[n-1] == '0'){
        if (n == 2){
            cout << 0;
            return;
        }
        cout << ans;
        return;
    }
    if (s[n-2] == '2' && s[n-1] == '5'){
        cout << ans;
        return;
    }
    if (s[n-2] == '5' && s[n-1] == '0'){
        cout << ans;
        return;
    }
    if (s[n-2] == '7' && s[n-1] == '5'){
        cout << ans;
        return;
    }
    cout << 0;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
        // cout << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}