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
    int cnt;
    int val;
    int f;
    pnode left;
    pnode right;
    int height;

    node(){}
};

ostream& operator<< (ostream& cout, const pnode& N){
    if (N == NULL) cout << "Na"; 
    else cout << N->val;
    return cout;
}

int height(pnode x){
    if (x == NULL) return 0;
    return x -> height;
}

void upd_height(pnode &x){
    x->height = max(height(x->left), height(x->right)) + 1;
}

int cnt(pnode &x){
    if (x == NULL) return 0;
    return x-> cnt;
}

void upd_cnt(pnode &x){
    x->cnt = cnt(x->left) + cnt(x->right) + 1;
}

int f(pnode &x){
    if (x == NULL) return 1e9;
    return x->f;
}

void upd_f(pnode &x){
    x->f = min(f(x->left), f(x->right));
}

pnode newNode(int val){
    pnode x = new node();
    x -> cnt = 1;
    x -> val = val;
    x -> f = val;
    x -> left = NULL;
    x -> right = NULL;
    x -> height = 1;
    return x;
}

pnode newNode(pnode l, int val, pnode r){
    pnode x = new node();
    x -> val = val;
    x -> left = l;
    x -> right = r;
    upd_height(x);
    upd_cnt(x);
    upd_f(x);
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
    upd_cnt(x);
    upd_cnt(y);
    upd_f(x);
    upd_f(y);
    return y;
}

pnode leftRotate(pnode x){
    pnode y = x->right;
    pnode T2 = x->left;
    y->left = x;
    x->right = T2;
    upd_height(x); upd_height(y);
    upd_cnt(x); upd_cnt(y);
    upd_f(x); upd_f(y);
    return y;
}

int getBalance(pnode x){
    if (x == NULL) return 0;
    return height(x->left) - height(x->right);
}

pnode insert(pnode x, int pos, pnode y, int add = 0){
    cout << "insert " << y << " into " << x << "\n";
    if (x == NULL) return y;
    // Insert recursively
    if (add + cnt(x->left) > pos) x->left = insert(x->left, pos, y, add);
    else if (add + cnt(x->left) < pos) x->right = insert(x->right, pos, y, add + cnt(x->left) + 1);
    else{ 
        y->left = x->left; 
        x->left = y;
        upd_height(y); upd_height(x);
        upd_cnt(y); upd_cnt(x);
        upd_f(y); upd_f(x);
    }
    // Update 
    upd_height(x);
    upd_cnt(x);
    upd_f(x);
    cout << x << " " << height(x->left) << " " << height(x->right) << "\n";
    // Rebalance
    int balance = getBalance(x);
    // Left left 
    if (balance > 1 && height(x->left->left) > height(x->right)){
        cout << "ll\n";
        return rightRotate(x);
    }
    // Right right
    if (balance < -1 && height(x->right->right) > height(x->left)){
        cout << "rr\n";
        return leftRotate(x);
    }
    // Left right
    if (balance > 1 && height(x->left->right) > height(x->right)){
        cout << "lr\n";
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }
    // Right left
    if (balance < -1 && height(x->right->left) > height(x->left)){
        cout << "rl\n";
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }
    return x;
}

// pnode joinRightAVL(pnode x, int key, pnode y){
//     pnode l = x->left, r = x->right;
//     int k = x->key;
//     if (height(r) <= height(y) + 1){
//         pnode T = newNode(r, key, y);
//         if (height(T) <= height(l)+1) return newNode(l, k, T);
//         else return leftRotate(newNode(l, k, rightRotate(T)));
//     }
//     else{
//         pnode T = joinRightAVL(r, key, y);
//         pnode T2 = newNode(l, k, T);
//         if (height(T) <= height(l) + 1) return T2;
//         else return leftRotate(T2);
//     }
// }

// pnode joinLeftAVL(pnode x, int key, pnode y){
//     pnode l = y->left, r = y->right;
//     int k = y->key;
//     if (height(l) <= height(x) + 1){
//         pnode T = newNode(x, key, l);
//         if (height(T) <= height(r)+1) return newNode(T, k, r);
//         else return rightRotate(newNode(leftRotate(T), k, r));
//     }
//     else{
//         pnode T = joinLeftAVL(x, key, l);
//         pnode T2 = newNode(T, k, r);
//         if (height(T) <= height(r) + 1) return T2;
//         else return rightRotate(T2);
//     }
// }

// pnode join(pnode x, int key, pnode y){
//     if (height(x) > height(y) + 1) return joinRightAVL(x, key, y);
//     if (height(y) > height(x) + 1) return joinLeftAVL(x, key, y);
//     return newNode(x, key, y);
// }

// void split(pnode x, pnode &y, pnode &z, int key){
//     // Split into <= key and > key
//     if (x == NULL) return void(y = z = NULL);
//     pnode l = x-> left, r = x->right;
//     int k = x->key;
//     if (key == k){ 
//         y = l;
//         y = insert(y, newNode(key));
//         z = r;
//         return;
//     }
//     if (key < k){
//         pnode l2, r2;
//         split(l, l2, r2, key);
//         y = l2;
//         z = join(r2, k, r);
//         return;
//     }
//     if (key > k){
//         pnode l2, r2;
//         split(r, l2, r2, key);
//         z = r2;
//         y = join(l, k, l2);
//         return;
//     }
// }

void solve(){
    pnode N = newNode(5);
    pnode one = newNode(4);
    pnode two = newNode(3);
    N = insert(N, 1, one);
    cout << "tree: " << N << " " << N->left << " " << N->right << "\n";
    // return;
    N = insert(N, 1, two);
    cout << "tree: " << N << " " << N->left << " " << N->right << "\n";
    cout << "left: " << N->right << " " << N->right->left << " " << N->right->right << "\n";
    cout << height(N->left) << " " << height(N->right) << "\n";
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