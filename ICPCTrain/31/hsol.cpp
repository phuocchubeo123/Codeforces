#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = (1 << 18) + 4;
int T;

template<typename T>
struct segTree{
    vt<T> seg;
    int sz = 1;

    segTree(int n){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }

    segTree(vt<T> v, int n){
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        for0(i, n) update(i, v[i]);
    }

    void update(int pos, T x){
        int ps = sz + pos;
        seg[ps] = x;
        ps /= 2;
        while (ps > 0){
            seg[ps] = seg[ps * 2] + seg[ps * 2 + 1];
            ps /= 2;
        }
    }

    T query(int l, int r){
        if (r < l) return 0;

        l += sz;
        r += sz;
        T qr;

       while (l <= r){
            if (l & 1) qr += seg[l++];
            if (!(r & 1)) qr += seg[r--];
            l /= 2;
            r /= 2;
        }
        return qr;
    }
};

void prepare(){

}

vt<pair<ll, int>> adj[N];
int x[N], y[N], z[N], vis[N];
ll dis[N];

void solve(){
    ll n, l, t;    
    cin >> n >> l >> t;
    ll a, b;
    for1(i, l){
        cin >> a >> b;
        // if (a == b) continue;
        adj[b].pb({i, a});
    }

    // for1(i, n){
    //     cout << i << ":\n";
    //     for (pair<int, int> p: adj[i]) cout << p.first << " " << p.second << "; ";
    //     cout << "\n";
    // }
    // cout << "\n";

    for1(i, n) cin >> x[i];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    for0(i, 8){
        for1(j, n){
            vis[j] = 0;
            y[j] = (x[j] >> i) & 1;
            if (y[j] == 1){
                // cout << j << " ";
                q.push({0, j});
                dis[j] = 0;
            }
            else dis[j] = t + 1;
        }
        // cout << "\n";

        // for1(j, n) cout << y[j] << " ";
        // cout << "\n";

        while (!q.empty()){
            // pair<ll, int> p = q.top();
            // q.pop();
            // cout << p.first << " " << p.second << "\n";
            break;
        }

        ll turn, step, turn_res;
        int curr, next;
        int st = 0;
        while (!q.empty()){
            // priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q2 = q;
            // while (!q2.empty()){
            //     pair<ll, int> pq = q2.top();
            //     q2.pop();
            //     cout << pq.first << " " << pq.second << "; ";
            // }
            // cout << "\n";
            pair<ll, int> p = q.top();
            q.pop();
            turn = p.first;
            curr = p.second;
            // cout << turn << " " << curr << ":\n";
            if (vis[curr]) continue;
            // if (turn > dis[curr]) continue;
            vis[curr] = 1;
            turn_res = turn % l;
            for (pair<ll, int> pp: adj[curr]){
                step = pp.first;
                next = pp.second;
                // cout << step << " " << next << "; ";
                if (step > turn_res) dis[next] = min(dis[next], turn - turn_res + step);
                else dis[next] = min(dis[next], turn - turn_res + step + l);
                q.push({dis[next], next});
            }
            // cout << "\n";
            // if (st == 10) break;
        }
        // cout << "\n";

        for1(j, n){
            if (dis[j] <= t) z[j] += (1 << i);
        }
    }

    for1(i, n) cout << z[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    prepare();

    // cin >> T;
    T = 1;

    while (T--){
        solve();
    }
}