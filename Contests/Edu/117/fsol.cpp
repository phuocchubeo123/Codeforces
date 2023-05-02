#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T;
int n, m, q, a, b;
int t;
array<map<int, int>, N> spec;
vector<pair<int, int>> curr_layer, next_layer;
int best[N], already[N];
map<int, int> ma;
map<int, int>::iterator it;

void read(){
    cin >> n >> m;

    cin >> q;

    if (n <= m){
        for (int i = 0; i < q; i++){
            cin >> a >> b;
            spec[a][b] = 1;
        }
    }

    else{
        int tmp = n;
        n = m;
        m = tmp;
        for (int i = 0; i < q; i++){
            cin >> b >> a;
            spec[a][b] = 1;
        }
    }
}

int potential(pair<int, int> p){
    if (spec[p.first][p.second] == 1) return p.first + p.second + 1;
    return p.first + p.second;
}

bool same(pair<int, int> p){
    if (p.first == n && p.second == m) return true;
    return false;
}

void solve(){
    int ans = 1e9;

    curr_layer = {{1, 1}};
    int l = 0;

    while (true){
        l++; ma.clear();
        // for (int i = 0; i < N; i++){
        //     best[i] = 0; already[i] = 0;
        // }
        
        for (auto curr: curr_layer){
            pair<int, int> next = {min(potential(curr), n), curr.second};

            if (same(next)){
                cout << l << "\n";
                return;
            }

            it = ma.find(next.first);

            if (it == ma.end()){
                ma[next.first] = next.second;
            }

            else{
                ma[next.first] = max(ma[next.first], next.second);
            }

            next = {curr.first, min(potential(curr), m)};

            if (same(next)){
                cout << l << "\n";
                return;
            }

            it = ma.find(next.first);

            if (it == ma.end()){
                ma[next.first] = next.second;
            }

            else{
                ma[next.first] = max(ma[next.first], next.second);
            }
        }

        curr_layer.clear();
        for (auto &next: ma){
            curr_layer.push_back(next);
        }
    }

}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}