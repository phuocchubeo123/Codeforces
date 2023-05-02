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

ll x;
void preprocess(){
    x = 1;
    while (x < 1e9) x *= 2;
    x -= 1;
}

struct Node{
    int val;
    Node *left, *right;

    Node(){};
};

Node* newNode(int val = 0, Node* l = NULL, Node* r = NULL){
    Node* cur = new Node();
    cur->val = val;
    cur->left = l;
    cur->right = r;
    return cur;
}

void add(Node* cur, int x, int pos = 30){
    // cout << x << " " << pos << "\n";
    if (pos == -1){ cur->val = 0; return;}
    if ((x >> pos) & 1){
        if (cur->right == NULL) cur->right = newNode();
        add(cur->right, x, pos-1);
    }
    else{
        if (cur->left == NULL) cur->left = newNode();
        add(cur->left, x, pos-1);
    }
}

int valx(Node* x){
    if (x == NULL) return 0;
    return x->val;
}

void upd(Node* pre, Node* cur, int x, int pos = 30){
    if (pos == -1){ cur->val = pre->val + 1; return;}
    if ((x >> pos) & 1){
        cur->left = pre->left;
        cur->right = newNode();
        upd(pre->right, cur->right, x, pos-1);
    }
    else{
        cur->right = pre->right;
        cur->left = newNode();
        upd(pre->left, cur->left, x, pos-1);
    }
    cur->val = valx(cur->left) + valx(cur->right);
}

int find(Node* pre, Node* cur, int x, int pos = 30){
    if (pos == -1){ return 0;}
    if ((x >> pos) & 1){
        if (valx(cur->left) > valx(pre->left)) return find(pre->left, cur->left, x, pos-1);
        else return (1 << pos) + find(pre->right, cur->right, x, pos-1);
    }
    else{
        if (valx(cur->right) > valx(pre->right)) return (1 << pos) + find(pre->right, cur->right, x, pos-1);
        else return find(pre->left, cur->left, x, pos-1);
    }
}

int query(Node* cur, int x, int pos = 30){
    if (pos == -1){ return cur->val;}
    if ((x >> pos) & 1){
        return query(cur->right, x, pos-1);
    }
    else return query(cur->left, x, pos-1);
}

void solve(){
    int n; cin >> n;
    vi a(n+1); rep(i, 1, n) cin >> a[i];

    // rep(i, 1, n) cout << a[i] << " ";
    // cout << "\n";
    
    Node* pre_st[n+1];

    pre_st[0] = newNode();
    int pre = 0;
    add(pre_st[0], 0);
    rep(i, 1, n){
        pre = pre ^ a[i];
        add(pre_st[0], pre);
    }
    pre = 0;
    pre_st[1] = newNode();
    upd(pre_st[0], pre_st[1], 0);
    rep(i, 1, n-1){
        pre = pre ^ a[i];
        pre_st[i+1] = newNode();
        upd(pre_st[i], pre_st[i+1], pre);
    }

    Node* suf_st[n+2];

    suf_st[n+1] = newNode();
    int suf = 0; 
    add(suf_st[n+1], 0);
    per(i, n, 1){
        suf = suf ^ a[i];
        add(suf_st[n+1], suf);
    }
    suf = 0;
    suf_st[n] = newNode();
    upd(suf_st[n+1], suf_st[n], 0);
    per(i, n, 2){
        suf = suf ^ a[i];
        suf_st[i-1] = newNode();
        upd(suf_st[i], suf_st[i-1], suf);
    }

    vector<pii> b; rep(i, 1, n) b.push_back({a[i], i});
    sort(all(b));
    vector<bool> used(n+2, false);
    vi l(n+2), r(n+2);
    rep(i, 1, n){ l[i] = i; r[i] = i;}
    l[0] = 1; r[n+1] = n;
    vi u(n+2), v(n+2);
    for (pii p: b){
        int x = p.first, i = p.second;
        used[i] = true;
        if (used[i-1] && used[i+1]){
            l[i] = l[i-1];
            r[i] = r[i+1];
            l[r[i]] = l[i];
            r[l[i]] = r[i];
        }
        else if (used[i-1]){
            l[i] = l[i-1];
            r[l[i]] = i;
        }
        else if (used[i+1]){
            r[i] = r[i+1];
            l[r[i]] = i;
        }
        u[i] = l[i]; v[i] = r[i];
    }

    vi pre_xor(n+1);
    pre_xor[0] = 0;
    rep(i, 1, n) pre_xor[i] = pre_xor[i-1] ^ a[i];
    vi suf_xor(n+2);
    suf_xor[n+1] = 0;
    per(i, n, 1) suf_xor[i] = suf_xor[i+1] ^ a[i];

    // cout << "pre xor: ";
    // rep(i, 0, n) cout << pre_xor[i] << " ";
    // cout << "\n";


    int tot = 0;
    int ans = 0;
    rep(i, 1, n) tot = tot ^ a[i];
    rep(i, 1, n){
        int le = i - u[i], ri = v[i] - i;
        if (le <= ri){
            // cout << "le:\n";
            rep(j, u[i]-1, i-1){
                int x = tot ^ a[i] ^ pre_xor[j];
                int q = find(suf_st[v[i]+1], suf_st[i], x);
                // cout << "pos: " << i << " " << j << " " << v[i] + 1 << "\n";
                // cout << "x: " << x << " " << q << "\n";
                ans = max(ans, x ^ q);
            }
        }
        else{
            // cout << "ri:\n";
            rep(j, i+1, v[i]+1){
                int x = tot ^ a[i] ^ suf_xor[j];    
                int q = find(pre_st[u[i]-1], pre_st[i], x);
                // cout << "pos: " << i << " " << j << " " << u[i] - 1 << "\n";
                // cout << "x: " << x << " " << q << "\n";
                ans = max(ans, x ^ q);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    preprocess();
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}