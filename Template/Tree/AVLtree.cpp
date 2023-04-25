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

typedef struct node* pnode;
struct node{
    int key;
    pnode left;
    pnode right;
    int height;

    node(){}
};

ostream& operator<< (ostream& cout, const pnode& N){
    if (N == NULL) cout << "Na"; 
    else cout << N->key;
    return cout;
}

int height(pnode x){
    if (x == NULL) return 0;
    return x -> height;
}

void upd_height(pnode &x){
    x->height = max(height(x->left), height(x->right)) + 1;
}

pnode newNode(int key){
    pnode x = new node();
    x -> key = key;
    x -> left = NULL;
    x -> right = NULL;
    x -> height = 1;
    return x;
}

pnode newNode(pnode l, int key, pnode r){
    pnode x = new node();
    x -> key = key;
    x -> left = l;
    x -> right = r;
    upd_height(x);
    return x;
}

pnode rightRotate(pnode x){
    pnode y = x->left;
    pnode T2 = y->right;
    // Rotate
    y->right = x;
    x->left = T2;
    // Update height
    upd_height(x);
    upd_height(y);
    return y;
}

pnode leftRotate(pnode x){
    pnode y = x->right;
    pnode T2 = x->left;
    y->left = x;
    x->right = T2;
    upd_height(x);
    upd_height(y);
    return y;
}

int getBalance(pnode x){
    if (x == NULL) return 0;
    return height(x->left) - height(x->right);
}

pnode insert(pnode x, pnode y){
    if (x == NULL) return y;
    // Insert recursively
    if (y->key < x->key) x->left = insert(x->left, y);
    else if (y->key > x->key) x->right = insert(x->right, y);
    else return x;
    // Update height
    upd_height(x);
    // Rebalance
    int balance = getBalance(x);
    // Left left 
    if (balance > 1 && y->key < x->left->key) return rightRotate(x);
    // Right right
    if (balance < -1 && y->key > x->right->key) return leftRotate(x);
    // Left right
    if (balance > 1 && y->key > x->left->key){
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }
    // Right left
    if (balance < -1 && y->key < x->right->key){
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }
    return x;
}

pnode joinRightAVL(pnode x, int key, pnode y){
    pnode l = x->left, r = x->right;
    int k = x->key;
    if (height(r) <= height(y) + 1){
        pnode T = newNode(r, key, y);
        if (height(T) <= height(l)+1) return newNode(l, k, T);
        else return leftRotate(newNode(l, k, rightRotate(T)));
    }
    else{
        pnode T = joinRightAVL(r, key, y);
        pnode T2 = newNode(l, k, T);
        if (height(T) <= height(l) + 1) return T2;
        else return leftRotate(T2);
    }
}

pnode joinLeftAVL(pnode x, int key, pnode y){
    pnode l = y->left, r = y->right;
    int k = y->key;
    if (height(l) <= height(x) + 1){
        pnode T = newNode(x, key, l);
        if (height(T) <= height(r)+1) return newNode(T, k, r);
        else return rightRotate(newNode(leftRotate(T), k, r));
    }
    else{
        pnode T = joinLeftAVL(x, key, l);
        pnode T2 = newNode(T, k, r);
        if (height(T) <= height(r) + 1) return T2;
        else return rightRotate(T2);
    }
}

pnode join(pnode x, int key, pnode y){
    if (height(x) > height(y) + 1) return joinRightAVL(x, key, y);
    if (height(y) > height(x) + 1) return joinLeftAVL(x, key, y);
    return newNode(x, key, y);
}

void split(pnode x, pnode &y, pnode &z, int key){
    // Split into <= key and > key
    if (x == NULL) return void(y = z = NULL);
    pnode l = x-> left, r = x->right;
    int k = x->key;
    if (key == k){ 
        y = l;
        y = insert(y, newNode(key));
        z = r;
        return;
    }
    if (key < k){
        pnode l2, r2;
        split(l, l2, r2, key);
        y = l2;
        z = join(r2, k, r);
        return;
    }
    if (key > k){
        pnode l2, r2;
        split(r, l2, r2, key);
        z = r2;
        y = join(l, k, l2);
        return;
    }
}

void solve(){
    pnode N = newNode(5);
    pnode one = newNode(4);
    pnode two = newNode(3);
    N = insert(N, one);
    N = insert(N, two);
    cout << N << " " << N->left << " " << N->right << "\n";
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