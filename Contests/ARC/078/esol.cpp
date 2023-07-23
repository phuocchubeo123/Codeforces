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

ll t(string s){
    ll n = 0;
    for (char c: s) n = n * 10 + (c - '0');
    return n;
}

bool q(string s){
    cout << "? " << t(s) << "\n";
    cout.flush();
    string b;
    cin >> b;
    return (b == "Y");
}

void a(string s){
    cout << "! " << t(s) << "\n";
    cout.flush();
    return;
}

void solve(){
    int d = 15;
    string s;

    rep(i, 1, 10){
        s.clear();
        s.push_back('1');
        forn(j, i-1) s.push_back('0');
        bool b = q(s);
        if (!b){
            d = i - 1;
            break;
        }
    }

    if (d == 15){
        bool b = q("9");
        if (b){
            a("1");
            return;
        }
        for (int i: {3, 5, 7, 9, 11}){
            s.clear();
            forn(j, i) s.push_back('9');
            bool b = q(s);
            if (b){
                s.pop_back();
                if (q(s)){
                    s.clear();
                    s.push_back('1');
                    forn(j, i-2) s.push_back('0');
                    a(s);
                    return;
                }
                else{
                    s.clear();
                    s.push_back('1');
                    forn(j, i-1) s.push_back('0');
                    a(s);
                    return;
                }
            }
        }
        
    }

    if (d > 1){
        s.clear();
        forn(i, d-1) s.push_back('9');
        bool b = q(s);
        if (b){
            s.clear();
            s.push_back('8');
            forn(i, d) s.push_back('0');
            b = q(s);
            if (b){
                s.clear();
                s.push_back('1');
                forn(i, d-2) s.push_back('0');
                cout << "! " << t(s) << "\n";
                return;
            }
        }
    }

    s.clear();
    forn(i, 15) s.push_back('0');
    forn(i, d-1){
        for (int j: {1, 3, 5, 7, 9}){
            s[i] = '0' + j;
            bool b = q(s);
            if (b){
                s[i]--;
                b = q(s);
                if (b) s[i]--;
                break;
            }
        }
    }

    for(int i: {1, 3, 5, 7, 9}){
        s[d-1] = '0' + i;
        bool b = q(s);
        if (b){
            s[d-1]--;
            b = q(s);
            if (!b) s[d-1]++;
            string ans;
            forn(i, d) ans.push_back(s[i]);
            cout << "! " << t(ans) << "\n";
            cout.flush();
            return;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}