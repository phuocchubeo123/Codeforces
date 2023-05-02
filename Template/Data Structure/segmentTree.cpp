#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define vi vector<int>

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const int LOG = 26;
const char min_char = 'a';
const double EPS = 1e-9;
const double PI = 3.14159265358979323846;

struct Node{
    ll val;
    Node(int a){val = 1ll * a;}
    Node(ll a){val = a;}
    Node(){val = 0;}
};

Node operator+(const Node& x, const Node& y){
    Node res;
    res.val = x.val + y.val;
    return res;
}

template <typename T>
struct SegTree{
    int sz;
    vector<T> seg;
  
    SegTree(int s){
        sz = s;
        seg.resize(4 * s);
    }

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, int val){
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            // seg[node].update(val) ;
            return;
        }
        int mid = (st + en) / 2;
        update(2*node, st, mid, pos, val);
        update(2*node+1, mid+1, en, pos, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    T query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    T query(int node, int st, int en, int l, int r){
        if ((st > r) || (en < l)) return T();
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }

    int find(int val){
        return find(1, 1, sz, val);
    }

    int find(int node, int st, int en, int val){
        if (st == en) return 1;
        int mid = (st + en) / 2;
        if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
        else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    }
};

template <typename T>
struct LazySegTree{
    int sz;
    vector<T> seg;
    vector<T> lazy;
  
    LazySegTree(int s){
        sz = s;
        seg.resize(4 * s);
        lazy.resize(4 * s);
    }

    void update(int pos, int val){
        update(1, 1, sz, pos, val);
    }

    void update(int node, int st, int en, int pos, int val){
        if (lazy[node]){
            // seg[node].update(lazy[node]);
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > pos) || (en < pos)) return;
        if ((st == pos) && (en == pos)){
            // seg[node].update(val) ;
            return;
        }
        int mid = (st + en) / 2;
        update(2*node, st, mid, pos, val);
        update(2*node+1, mid+1, en, pos, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    void rangeUpdate(int l, int r, int val){
        rangeUpdate(1, 1, sz, l, r, val);
    }

    void rangeUpdate(int node, int st, int en, int l, int r, int val){
        if (lazy[node]){
            // seg[node].update(lazy[node]);
            if (st != en){lazy[2*node] += lazy[node]; lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return;
        if ((st >= l) && (en <= r)){
            // seg[node].update(val);
            if (st != en){lazy[2*node] += val, lazy[2*node+1] += val;}
            return;
        }
        int mid = (st + en) / 2;
        rangeUpdate(2*node, st, mid, l, r, val);
        rangeUpdate(2*node+1, mid+1, en, l, r, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }

    T query(int l, int r){
        return query(1, 1, sz, l, r);
    }

    T query(int node, int st, int en, int l, int r){
        if (lazy[node]){
            // seg[node].update(lazy[node]);
            if (st < en){lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];}
            lazy[node] = 0;
        }
        if ((st > r) || (en < l)) return T();
        if ((l <= st) && (en <= r)) return seg[node];
        int mid = (st + en) / 2;
        T q1 = query(2*node, st, mid, l, r);
        T q2 = query(2*node+1, mid+1, en, l, r);
        return (q1+q2);
    }

    int find(int val){
        return find(1, 1, sz, val);
    }

    int find(int node, int st, int en, int val){
        if (lazy[node]){
            //seg[node].update(lazy[node])
            if (st < en){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
                //dump lazy in 2*node and 2*node+1
            }
            lazy[node] = 0;
        }
        if (st == en) return 1;
        int mid = (st + en) / 2;
        if (seg[2 * node] >= val) return find(2 * node, st, mid, val);
        else return mid - st + 1 + find(2 * node + 1, mid+1, en, val - seg[2 * node]);
    }
};


// Persistent segtree
template<typename T>
struct node
{
    T val;
    node<T>* left, *right;
  
    node() {}
    node(node<T>* l, node<T>* r, T v)
    {
        left = l;
        right = r;
        val = v;
    }
};
  
template<typename T>
struct PersistentSegTree{
    node<T>* version[maxn];
    int sz;

    PersistentSegTree(int n){
        sz = n;
        version[0] = new node<T>(NULL, NULL, T());
        build(version[0], 1, sz);
    }

    void build(node<T>* cur,int l,int r)
    {
        if (l==r){ cur->val = T(); return;}
        int mid = (l+r) / 2;
        cur->left = new node<T>(NULL, NULL, T());
        cur->right = new node<T>(NULL, NULL, T());
        build(cur->left, l, mid);
        build(cur->right, mid+1, r);
        cur->val = cur->left->val + cur->right->val;
    }

    void update(int ver, int pos, T val){
        version[ver] = new node<T>(NULL, NULL, T());
        upgrade(version[ver-1], version[ver], 1, sz, pos, val);
    }

    void upgrade(node<T>* prev, node<T>* cur, int l, int r, int pos, T val){
        if (pos > r or pos < l or l > r) return;
        if (l == r){ cur->val = val; return;}
        int mid = (l+r) / 2;
        if (pos <= mid){
            cur->right = prev->right;
            cur->left = new node<T>(NULL, NULL, T());
            upgrade(prev->left,cur->left, l, mid, pos, val);
        }
        else{
            cur->left = prev->left;
            cur->right = new node<T>(NULL, NULL, T());
            upgrade(prev->right, cur->right, mid+1, r, pos, val);
        }
        cur->val = cur->left->val + cur->right->val;
    }

    T query(int ver, int st, int en){
        node<T>* cur = version[ver];
        return query(cur, 1, sz, st, en);
    }

    T query(node<T>* cur, int l, int r, int st, int en)
    {
        if (st > r or en < l or l > r) return T();
        if (st <= l and r <= en) return cur->val;
        int mid = (l+r) / 2;
        T q1 = query(cur->left, l, mid, st, en);
        T q2 = query(cur->right, mid+1, r, st, en);
        return q1+q2;
    }
};


int main(){
    int n = 4;
    vector<int> a(4);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    SegTree<int> sega(n);

    PersistentSegTree<Node> seg(n);
    cout << seg.query(0, 1, 2).val << "\n";
    seg.update(1, 2, Node(2));
    cout << seg.query(1, 1, 2).val << "\n";
    return 0;
}