// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//#define endl '\n'
const int N = 2e5 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll a[3] = {2, 3, 5};
ll vis[N];
ll rd(ll l, ll r){
    return rand() % (r - l + 1) + l;
}
ll mx = 25;
pair<ll, ll> rancho(ll l, ll r){
    pair<ll, ll> x = {rd(l, r), rd(l, r)};
    while (x.first == x.second){
        x = {rd(l, r), rd(l, r)};
    }
    if (x.first > x.second){
        int tmp = x.first;
        x.first = x.second;
        x.second = tmp;
    }
    return x;
}
ll ask(ll x, ll y){
    cout << "? " << x << " " << y << endl;
    ll ans;
    cin >> ans;
    return ans;
}

ll gcd(ll u, ll v){
    if (u == 0) return v;
    if (v == 0) return u;
    if (u > v) return gcd(v, u);
    if (v % u == 0) u;
    return gcd(v%u, u);
}

vector<ll> prime;
void find_prime(){
    for (int i = 2; i <= 100; i++){
        int flag = 1;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                flag = 0;
                break;
            }
        }
        if (flag == 1) prime.push_back(i);
    }
}

vector<vector<ll>> factor(101);

void find_prime_factor(){
    for (int i = 2; i <= 100; i++){
        for (int x: prime) if (i % x == 0) factor[i].push_back(x);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));

    find_prime();

    for (int tt = 1; tt <= 1000; tt++){
        for (int i = 1; i <= mx; i++) vis[i] = 0;
        vector<ll> v;
        ll okie = 0;

        vector<vector<bool>> done(101, vector<bool>(101, 0));

        while (true){
            pair<ll, ll> choose = rancho(1, mx);

            // cout << choose.first << " " << choose.second << "\n";
            // return 0;

            int u1 = choose.first, u2 = choose.second;
            if (done[u1][u2] == 1) continue;
            done[u1][u2] = 1;

            ll ans = ask(u1, u2);
            
            if (ans % 6 == 0){
                v.push_back(u1);
                break;
            }
        }


        for (int i = 1; i <= 100; i++){
            for (int j = i+1; j <= 100; j++) done[i][j] = 0;
        }

        while (true){
            pair<ll, ll> choose = rancho(1, mx);

            int u1 = choose.first, u2 = choose.second;
            if (done[u1][u2] == 1) continue;
            done[u1][u2] = 1;

            ll ans = ask(u1, u2);
            if (ans % 5 == 0){
                v.push_back(u1);
                break;
            }
        }

        cout << "! ";

        for (int i = 0; i < 100; i++){
            cout << 1;
        }

        continue;


        vector<ll> res;
        vector<ll> c2, c3, c5;
        c2.push_back(v[0]);
        c3.push_back(v[0]);
        c5.push_back(v[1]);
        for (int i = 1; i <= 100; i++){
            if (i == v[0] || i == v[1]) continue;
            bool flag = 1;
            for (int j : v){
                ll ans = ask(i, j);
                if (ans % 2 == 0){
                    if (ans % 6 != 0) c2.push_back(i);
                    flag = 0;
                }
                if (ans % 3 == 0){
                    if (ans % 6 != 0) c3.push_back(i);
                    flag = 0;
                }
                if (ans % 5 == 0){
                    c5.push_back(i);
                    flag = 0;
                }
                if (flag == 0) break;
            }
            if (flag == 1) res.push_back(i);
        }

        int sz = res.size();

        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++) done[i][j] = false;
        }

        vector<ll> c7;
        
        while (true){
            pair<ll, ll> choose = rancho(0, sz-1);
            if (done[choose.first][choose.second] == 1) continue;

            int u1 = res[choose.first], u2 = res[choose.second];
            ll ans = ask(u1, u2);
            if (ans % 7 == 0){
                c7.push_back(u1);
                c7.push_back(u2);
                break;
            }
        }

        for (int i = 0; i < sz; i++){
            if (res[i] == c7[0] || res[i] == c7[1]) continue;
            ll ans = ask(res[i], c7[0]);
            if (ans % 7 == 0){
                c7.push_back(res[i]);
                break;
            }
        }

        vector<ll> answer;
        for (int i = 0; i < sz; i++){
            int uu = res[i];
            if (uu != c7[0] && uu != c7[1] && uu != c7[2]){
                answer.push_back(uu);
            }
        }

        int cfalse = 0;
        int num7;

        for (int i = 0; i < c7.size(); i++){
            bool flag = true;
            for (int j = 0; j < answer.size(); j++){
                ll ans = ask(c7[i], answer[j]);
                if (ans > 1){
                    flag = false;
                    break;
                }
            }
            if (!flag){
                cfalse++;
                if (cfalse == 2){
                    num7 = c7[i+1];
                    break;
                }
            }
            else{
                num7 = c7[i];
                break;
            }
        }

        int num6 = v[0];
        int num5 = v[1];

        vector<ll> new_c2;

        for (ll i: c2){
            ll ans = ask(i, num5);
            if (ans % 5 == 0) continue;
            new_c2.push_back(i);
        }

        c2 = new_c2;
        new_c2.clear();

        for (ll i: c2){
            ll ans = ask(i, num7);
            if (ans % 7 == 0) continue;
            new_c2.push_back(i);
        }

        c2 = new_c2;
        new_c2.clear();

        vector<ll> can = answer, new_can;

        for (ll i: can){
            bool flag = false;
            for (ll j: c2){
                ll ans = ask(i, j);
                if (ans > 1){
                    for (int k: c2) if (k != j) new_c2.push_back(k);
                    flag = true;
                    break;
                }
            }
            c2 = new_c2;
            new_c2.clear();
            if (flag){
                new_can.push_back(i);
            }
        }

        can = new_can;
        new_can.clear();
        answer.push_back(c2[0]);


        vector<ll> new_c3;

        for (ll i: c3){
            ll ans = ask(i, num5);
            if (ans % 5 == 0) continue;
            new_c3.push_back(i);
        }

        c3 = new_c3;
        new_c3.clear();

        for (ll i: c3){
            ll ans = ask(i, num7);
            if (ans % 7 == 0) continue;
            new_c3.push_back(i);
        }

        c3 = new_c3;
        new_c3.clear();

        for (ll i: can){
            bool flag = false;
            for (ll j: c3){
                ll ans = ask(i, j);
                if (ans > 1){
                    for (int k: c3) if (k != j) new_c3.push_back(k);
                    flag = true;
                    break;
                }
            }
            c3 = new_c3;
            new_c3.clear();
            if (flag){
                new_can.push_back(i);
            }
        }

        can = new_can;
        new_can.clear();
        answer.push_back(c3[0]);


        vector<ll> new_c5;

        for (ll i: c5){
            ll ans = ask(i, num6);
            if (ans % 2 == 0) continue;
            if (ans % 3 == 0) continue;
            new_c5.push_back(i);
        }

        c5 = new_c5;
        new_c5.clear();

        for (ll i: c5){
            ll ans = ask(i, num7);
            if (ans % 7 == 0) continue;
            new_c5.push_back(i);
        }

        c5 = new_c5;
        new_c5.clear();

        for (ll i: can){
            bool flag = false;
            for (ll j: c5){
                ll ans = ask(i, j);
                if (ans > 1){
                    for (int k: c5) if (k != j) new_c5.push_back(k);
                    flag = true;
                    break;
                }
            }
            c5 = new_c5;
            new_c5.clear();
            if (flag){
                new_can.push_back(i);
            }
        }

        can = new_can;
        new_can.clear();
        answer.push_back(c5[0]);

        vector<int> best(101, 0);
        for (int i: answer) best[i] = 1;

        cout << "! ";
        for (int i = 1; i <= 100; i++) cout << best[i];
        cout << endl;
        cout.flush();
    }
}
/*
2 1
1 1
6 1
1 3
6 3
 
1 2
1 1
5 3
6 2
 
1 1
0 0
5 5
2 4
 
0 3
0 0
3 3
Ans:
 
Out:
*/
 