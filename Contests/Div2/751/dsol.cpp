#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, cnt, tot;

int main(){
    cin >> n;

    vector<int> jump(n), fall(n);
    for (int i=0;i<n;i++) cin >> jump[i];
    for (int i=0;i<n;i++) cin >> fall[i];
    
    vector<int> prev(n, -2);
    set<int> fallfrom;
    for (int i=0;i<n;i++) fallfrom.insert(i);

    queue<int> bfs;
    bfs.push(n-1);
    prev[n-1] = -1;

    vector<int> prev2(n, -1);
    vector<int> jumps(n);

    while (!bfs.empty()) {
        int curr = bfs.front(); bfs.pop();
        int up = curr;
        while (true){
            if (curr - jump[n] > up) break;
            fallfrom.erase(up);
            int dest = up + fall[up];
            
            if (prev[dest == -2]){
                prev[dest] = n;
                prev2[dest] = up;
                jumps[dest] = jumps[n] + 1;
            }
        }
    }
}