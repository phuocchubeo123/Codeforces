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


typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;
    item () { }
    item (int value) : value(value), cnt(0), l(nullptr), r(nullptr), prior(rand()) {};
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout << t->value << " ";
    output (t->r);
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void insert(pitem &t, pitem x, int i){
    pitem l = nullptr, r = nullptr;
    split(t, l, r, i-1);
    cout << "l: "; output(l); cout << "cnt l: " << l -> cnt; cout << "\n";
    cout << "r: "; output(r); cout << "\n";
    merge(t, l, x);
    cout << "t: "; output(t); cout << "\n";
    merge(t, t, r);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}


void solve(){
    pitem x = new item(5);
    cout << "original x: "; output(x); cout << "\n";
    cout << "cnt x: " << x -> cnt << "\n";

    pitem l = nullptr, r = nullptr;
    split(x, l, r, 0);
    cout << "l: "; output(l); cout << " cnt l: " << cnt(l); cout << "\n";
    cout << "r: "; output(r); cout << " cnt r: " << cnt(r); cout << "\n";
    cout << "r -> l: "; output(r -> l); cout << "\n";
    // pitem y = new item(7);
    // insert(x, y, 2);
    // cout << "pos x: " << x -> cnt << "\n";
    // cout << "pos y: " << x -> l -> cnt << "\n";
    // pitem z = new item(9);
    // // insert(x, z, 2);
    // cout << (x -> cnt) << "\n";
    // cout << (y -> cnt) << "\n";

    // output(x);
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