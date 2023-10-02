#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = 1e18;

struct LazySegTree{
    int s;
    vector<ll> seg;
    vector<ll> lz;
    vector<ll> mseg;
    vector<ll> mlz;

    LazySegTree(int sz){
        s = sz;
        seg.resize(4 * s);
        lz.resize(4 * s);
        mseg.resize(4 * s);
        mlz.resize(4 * s);
        for (int i = 0; i < 4 * s; i++){
            seg[i] = -INF;
            lz[i] = 0;
            mseg[i] = -INF;
            mlz[i] = 0;
        }
    }

    void upd(int p, ll val){
        upd(1, 0, s-1, p, val);
    }

    void upd(int nd, int st, int en, int p, ll val){
        
    }

    void update(int l, int r, ll val){
        update(1, 0, s-1, l, r, val);
    }

    void update(int nd, int st, int en, int l, int r, ll val){

    }

    ll query(int l, int r){
        return 0;
    }

    ll query(int nd, int st, int en, int l, int r){
        return 0;
    }

    ll max_query(int l, int r){
        return 0;
    }

    ll max_query(int nd, int st, int en, int l, int r){
        return 0;
    }
};

bool comp(pair<int, int> u, pair<int, int> v){
    return (u.second == v.second) ? (u.first < v.first) : (u.second < v.second);
}

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    vector<pair<int, int>> q;
    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        q.push_back({p[i].first, i});
    }
    sort(p.begin(), p.end(), comp);
    sort(q.begin(), q.end());
    for (int i = 0; i < n; i++){
        pos[q[i].second] = i;
    }

    LazySegTree st(n);

    for (int i = 0; i < n; i++){
        ll a = p[i].first, b = p[i].second;
        int ps = pos[i];
        ll u = st.query()
        st.upd(ps, )
    }
}

int main(){
    solve();
}