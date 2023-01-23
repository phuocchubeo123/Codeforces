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

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "time: " << duration.count() << "ms\n";
}