#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 4;
int T, n, a[N], pr[N][30], d[N], max_depth = 0, max_depth_node;

void read(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int parent(int num){
    if (num == 0) return 0;

    int l = 1;
    while (true){
        if (l >= num) return l - num;
        l *= 2;
    }
}

void calParent(){
    for (int i = 1; i <= n; i++){
        pr[i][0] = a[i];
    }

    for (int i = 1; i <= n; i++){
        int depth = 0;
        int curr = a[i];
        while (curr > 0){
            depth++;
            curr = parent(curr);
            pr[i][depth] = curr;
        }
        d[i] = depth;

        if (depth > max_depth){
            max_depth = depth;
            max_depth_node = i;
        }
    }

    return;
}

int distance(int num){
    int dist = d[max_depth_node] - d[num];
    int pt1 = dist, pt2 = 0;
    while (pr[max_depth_node][pt1] != pr[num][pt2]){
        pt1++;
        pt2++;
        dist += 2;
    }
    return dist;
}

void solve(){
    calParent();

    int max_dis = 0, max_dis_node;
    for (int i = 1; i <= n; i++){
        if (a[i] != a[max_depth_node]){
            int dis = distance(i);
            if (dis > max_dis){
                max_dis = dis;
                max_dis_node = i;
            }
        }
    }

    cout << max_depth_node << " " << max_dis_node << " " << max_dis << "\n";
}

int main(){
    // cin >> T;
    T = 1;

    while (T--){
        read();
        solve();
    }
}