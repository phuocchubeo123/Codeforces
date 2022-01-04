#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 4;
int T, q, m, x[N], y[N];
int after[N], vis[N];
vector<int> arr;
vector<pair<int, int>> qs;
stack<int> s;

void read(){
    cin >> q;

    for (int i = 1; i <= q; i++){
        cin >> m >> x[i];
        if (m == 1){
            y[i] = 0;
        }
        else{
            cin >> y[i];
        }
    }
}

void findAfter(int num){
    int curr = num;

    while (!s.empty()) s.pop();

    s.push(num);

    while (curr != after[curr]){
        curr = after[curr];
        s.push(curr);
    }

    while (!s.empty()){
        curr = s.top();
        s.pop();
        after[curr] = after[after[curr]];
    }
}

void solve(){
    for (int i = 1; i < N; i++) after[i] = i;

    for (int i = q; i >= 1; i--){
        if (y[i] == 0){
            arr.push_back(after[x[i]]);
        }

        else{
            after[x[i]] = after[y[i]];
        }
    }

    reverse(arr.begin(), arr.end());
    for (int n: arr) cout << n << " ";
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}