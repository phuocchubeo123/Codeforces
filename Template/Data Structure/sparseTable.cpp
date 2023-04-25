#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
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

int lg[maxn];

void calLog(){
    lg[1] = 0;
    rep(i, 2, maxn-1) lg[i] = lg[i/2] + 1;
}

template <typename T>
struct sparseTable{
    vector<vector<T>> st;
    
    sparseTable(){
    }
    sparseTable(vector<T> a){
        st.resize(LOG);
        int sz = a.size();
        forn(i, LOG) st[i].resize(sz);
        forn(i, sz) st[0][i] = a[i];
        rep(i, 1, LOG-1){
            for(int j = 0; j + (1 << i) < sz; j++){
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }

    T query(int l, int r){
        int i = lg[r - l + 1];
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

int main(){
    calLog();
    vi a{5, 7, 9, 3, 2};
    sparseTable<int> st(a);
    cout << st.query(1, 3);
}