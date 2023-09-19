// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//#define endl '\n'
const int N = 505;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
pair<ll, ll> a[N], segAB, pA, pB;
int i, j;

ld leng[N][N];

ld angA[N];
ld angB[N];

bool cmp(ll x, ll y){
    return angA[x] < angA[y];
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    ll n;
    cin >> n;
    for (i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll ans = 0;
    vector<ll> v;


    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (j == i) continue;
            leng[i][j] = sqrt((a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second));
        }
    }

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            if (i == j) continue;
            vector<ll> v;
            segAB = {a[j].first - a[i].first, a[j].second - a[i].second};
            pA = a[i];
            pB = a[j];
            for (int k = 1; k <= n; k++){
                if (k == i || k == j) continue;
                v.push_back(k);
                pair<ll, ll> segAX = {a[k].first - pA.first, a[k].second - pA.second};
                angA[k] = acos((segAX.first * segAB.first + segAX.second * segAB.second) / (leng[i][j] * leng[i][k]));
                pair<ll, ll> segBX = {a[k].first - pB.first, a[k].second - pB.second};
                angB[k] = acos((-segBX.first * segAB.first - segBX.second * segAB.second) / (leng[i][j] * leng[j][k]));
            }
            sort(v.begin(), v.end(), cmp);
            ld mx = 1e9;
            for (auto k : v){
                //cout << angle << " " << i << " " << j << " " << k << endl;
                if (angA[k] >= 2) continue;
                if (angA[k] < mx){
                    ans++;
                    mx = angA[k];
                }
            }
        }
    }
    cout << ans / 3;
}
/*
5
0 0
5 0
5 6
4 1
3 3
Ans:
 
Out:
*/