     
// I_Love_LPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
const int N = 1e3 + 5;
long long mod = 1e9 + 7;
const int lim = 2e5;
const int lg = 19;
const int base = 311;
const long double eps = 1e-6;
ll c[N][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("tests.inp", "r")){
        freopen("tests.inp", "r", stdin);
        freopen("tests.out", "w", stdout);
    }
    // R = 0, B = 1, N = 2, K = 3, Q = 4;
    vector<vector<ll>> p;
    vector<ll> v = {0, 0, 1, 1, 2, 2, 3, 4};
    do {
        ll cntB = 0, cntR = 0, flag = 1;
        for (int i = 0; i < v.size(); i++){
            if (v[i] == 0) cntR++;
            if (v[i] == 1) cntB += i;
            if (v[i] == 3 && cntR != 1){
                flag = 0;
            }
        }
        if (!(cntB & 1)) flag = 0;
        if (flag){
            p.push_back(v);
        }
    } while (next_permutation(v.begin(),v.end()));
    map<ll, ll> mem;
    for (int i = 1; i < p.size(); i++){
        for (int j = 0; j < i; j++){
            ll cnt = 0;
            for (int k = 0; k < 8; k++){
                if (p[i][k] == p[j][k]){
                    cnt++;
                }
            }
            c[i][j] = cnt;
            c[j][i] = cnt;
            mem[cnt]++;
        }
    }
    string s;
    while (cin >> s){
        if (s == "END") return 0;
        ll n;
        cin >> n;
        vector<int> candidates;
        for (int i = 0; i < 960; i++) candidates.push_back(i);
        for (int st = 0; st < 6; st++){
            // cout << "num cands: " << candidates.size() << "\n";
            // cout.flush();

            if (candidates.size() == 1){
                for (int j: p[candidates[0]]){
                    if (j == 0) cout << 'R';
                    if (j == 1) cout << 'B';
                    if (j == 2) cout << 'N';
                    if (j == 3) cout << 'K';
                    if (j == 4) cout << 'Q';
                }
                cout << "\n";
                // cout << candidates[0] << "\n";
                cout.flush();

                int xxxx;
                cin >> xxxx;
                break;
            }
            int mn = 10000;
            int best = 0;
            for (int i = 0; i < 960; i++){
                vector<int> cnt(9, 0);
                for (int j: candidates){
                    cnt[c[i][j]]++;
                }
                int mx = 0;
                for (int u: cnt) mx = max(mx, u);
                if (mx < mn){
                    mn = mx;
                    best = i;
                } 
            }

            for (int j: p[best]){
                if (j == 0) cout << 'R';
                if (j == 1) cout << 'B';
                if (j == 2) cout << 'N';
                if (j == 3) cout << 'K';
                if (j == 4) cout << 'Q';
            }

            cout << '\n';
            cout.flush();


            int cor;
            cin >> cor;
            if (cor == 8) break;

            vector<int> cand2;
            for (int j: candidates){
                if (c[best][j] == cor) cand2.push_back(j);
            }

            candidates = cand2;


        }

    }
}
/*
Ans:
 
Out:
*/