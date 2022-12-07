#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

struct Node{
    int mx;
    Node(int a){mx = a;}
    Node(){mx = 0;}
};

Node operator+(const Node& left, const Node& right){
    Node res;
    res.mx = max(left.mx, right.mx);
    return res;
}

template<typename T>
struct SegTree{
  int sz;
  T seg;
  int lazy;
  
  SegTree(int s, int lz=0){
    sz = s;
    seg.resize(4 * s);
    if (lz) lazy.resize(2 * s);
  }

  void update(int l, int r, int val){
    update(1, 1, sz, l, r, val);
  }

  void update(int node, int st, int en, int l, int r, int val){
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
    update(2*node, st, mid, l, r, val);
    update(2*node+1, mid+1, en, l, r, val);
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
    if ((st > r) || (en < l)) return T;
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

int main(){
    n = 4;
    vector<int> a(4);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    segTree<int> sega(a, 4);
    return 0;
}