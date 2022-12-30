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

template <typename T>
struct poly{
    vector<T> a;

    void removeZero(){ while (!a.empty() && a.back() == T(0)) a.pop_back();}

    poly(){}
    poly(T a0){a = {a0}; removeZero();}
    poly(const vector<T> &t){ a = t; removeZero();}

    poly operator+=(const poly &t){
        a.resize(max(a.size(), t.a.size()));
        forn(i, a.size()){
            if (i >= t.a.size()) continue;
            a[i] += t.a[i];
        }
        removeZero();
        return *this;
    }
};

int main(){
    vi t{5,3,2,1};
    poly<int> pl(t);
    forn(i, pl.a.size()) cout << pl.a[i] << " ";
    poly<int> pl2(t);
    pl += pl2;
    cout << "\n";
    forn(i, pl.a.size()) cout << pl.a[i] << " ";
}