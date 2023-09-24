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

bool sub_string(string s, string t){
    int n = s.size(), m = t.size();
    int a = 0, b = 0;
    while (true){
        if (b == m){
            return true;
        }
        if (a == n){
            return false;
        }
        if (s[a] == t[b]){
            a++; b++;
        }
        else{
            a++;
        }
    }
}

vector<string> s3;
vector<string> s2;

void prep(){
    vector<char> s = {'a', 'o', 'g'};
    for (char c1: s){
        for (char c2: s){
            if (c2 == c1) continue;
            for (char c3: s){
                if (c3 == c2 || c3 == c1) continue;
                string t;
                for (int i = 0; i < 3; i++) t.push_back(c1);
                for (int i = 0; i < 3; i++) t.push_back(c2);
                for (int i = 0; i < 3; i++) t.push_back(c3);
                s3.push_back(t);
            }
        }
    }

    for (char c1: s){
        for (char c2: s){
            if (c2 == c1) continue;
            string t;
            for (int i = 0; i < 3; i++) t.push_back(c1);
            for (int i = 0; i < 3; i++) t.push_back(c2);
            s2.push_back(t);
        }
    }
}

void solve(){
    string s; cin >> s;
    for (string t: s3){
        if (sub_string(s, t)){
            cout << 3 << "\n";
            return;
        }
    }

    for (string t: s2){
        if (sub_string(s, t)){
            cout << 2 << "\n";
            return;
        }
    }

    cout << 1 << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    prep();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}