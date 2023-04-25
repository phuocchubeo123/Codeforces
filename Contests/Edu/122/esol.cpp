#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

const int N = 2e5 + 4;
int T;

void prepare(){

}

int n, m;
vt<tuple<int, int, int>> edges, means;
vt<int> pr(100), in(304), pos(304), can;

void findParent(int x){
    if (pr[x] == x) return;
    findParent(pr[x]);
    pr[x] = pr[pr[x]];
    return;
}

vt<int> kruskal(int c){
    for1(i, n) pr[i] = i;
    for0(i, m) in[i] = 0;
    int min_cost = 0;

    for0(i, m){
        int cost = get<0>(edges[i]), n1 = get<1>(edges[i]), n2 = get<2>(edges[i]);
        findParent(n1);
        findParent(n2);
        if (pr[n1] == pr[n2]) continue;

        pr[pr[n2]] = n1;
        pr[n2] = n1;
        in[i] = 1;
        // cout << n1 << " " << n2 << "\n";
    }

    can.clear();
    for0(i, m){
        if (in[pos[i]]) can.pb(i);
    }

    // for0(i, can.size()) cout << can[i] << " ";
    // cout << "\n";
    return can;
}

void solve(){
    cin >> n >> m;

    for0(i, m){
        int v, u, w;
        cin >> v >> u >> w;
        edges.pb(make_tuple(w, v, u));
    }

    sort(edges.begin(), edges.end());

    // for0(i, m){
    //     cout << get<1>(edges[i]) << " " << get<2>(edges[i]) << "\n";
    // }

    for0(i, m) pos[i] = i;

    for0(i, m){
        forlr(j, i + 1, m, 1){
            means.pb(make_tuple(((get<0>(edges[i]) + get<0>(edges[j]) + 2) / 2), i, j));
        }
    }

    sort(means.begin(), means.end());

    map<int, vt<int>> ans;
    ans[0] = kruskal(0);
    // cout << 0 << "\n";
    // for0(i, m) cout << abs(get<0>(edges[i]) - 0) << " ";
    // cout << "\n";
    set<int> s;

    for0(i, means.size()){
        int mean = get<0>(means[i]), e1 = get<1>(means[i]), e2 = get<2>(means[i]);
        int pos1 = pos[e1], pos2 = pos[e2];
        pos[e1] = pos2;
        pos[e2] = pos1;

        tuple<int, int, int> tmp = edges[pos1];
        edges[pos1] = edges[pos2];
        edges[pos2] = tmp;

        // cout << mean << "\n";
        // for0(i, m){
        //     cout << abs(get<0>(edges[i]) - mean) << " ";
        // }
        // cout << "\n";

        ans[mean] = kruskal(mean);
        s.insert(mean);
    }

    // cout << "\n";

    sort(edges.begin(), edges.end());

    vt<int> nums;
    for (int x: s) nums.pb(x);
    nums.pb(0);
    sort(nums.begin(), nums.end());

    // for (int x: nums){
    //     cout << x << "\n";
    //     for (int y: ans[x]) cout << y << " ";
    //     for (int y: ans[x]){
    //         cout << get<1>(edges[y]) << " " << get<2>(edges[y]) << "\n";
    //     }
    //     cout << "\n";
    // }

    map<int, pair<ll, int>> ans2;
    set<int> s2;

    for (int i: nums){
        // cout << i << "\n";
        s2.insert(i);
        ll tot = 0, ad = 0;

        for (int x: ans[i]){
            // cout << get<1>(edges[x]) << " " << get<2>(edges[x]) << " ";
            // cout << abs(i - get<0>(edges[x])) << "\n";
            if (i < get<0>(edges[x])){
                tot += 1ll * (get<0>(edges[x]) - i);
                ad -= 1;
            }

            else{
                tot += 1ll * (i - get<0>(edges[x]));
                ad += 1;
            }
        }

        ans2[i] = {tot, ad};
    }
    
    for0(i, m){
        int w = get<0>(edges[i]);
        // cout << w << "\n";
        s2.insert(w);
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int m = l + (r - l + 1) / 2;
            if (nums[m] > w) r = m - 1;
            else l = m;
        }

        ll tot = 0, ad = 0;
        for (int x: ans[nums[l]]){
            // cout << get<1>(edges[x]) << " " << get<2>(edges[x]) << " ";
            // cout << abs(i - get<0>(edges[x])) << "\n";
            if (w < get<0>(edges[x])){
                tot += 1ll * (get<0>(edges[x]) - w);
                ad -= 1;
            }

            else{
                tot += 1ll * (w - get<0>(edges[x]));
                ad += 1;
            }
        }

        ans2[w] = {tot, ad};
    }

    nums.clear();
    for (int x: s2) nums.pb(x);

    sort(nums.begin(), nums.end());
    
    // for (int x: nums){
    //     cout << x << " ";
    //     cout << ans2[x].first << " " << ans2[x].second << "\n";
    // }

    ll p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vt<ll> q(k);
    for0(i, p) cin >> q[i];
    forlr(i, p, k, 1){
        q[i] = ((q[i - 1] * a) % c + b) % c;
    }
    sort(q.begin(), q.end());

    ll fin = 0;
    int pt = 0;

    for (ll x: q){
        forlr(i, pt, nums.size(), 1){
            if (nums[i] > x) break;
            pt = i;
        }

        ll tot = ans2[nums[pt]].first, ad = ans2[nums[pt]].second;
        ll answer = tot + 1ll * ad * (x - nums[pt]);
        fin = fin ^ answer;
    }

    cout << fin;
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