#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, m;
string s;
const int MAXX = 4 * 1e6 + 5;
array<int, MAXX> dest;
array<int, MAXX> ans;
vector<int> emp1;
vector<int> emp2;
pair<int, int> move_to;
pair<int, int> dfs_helper(int x, int y);
array<bool, MAXX> rec_stack;
pair<int, int> decoder;
int encoder;
int curr, route_length, route_begin;
int cycle_length, cycle_begin;
bool computed;

int encode(int x, int y){
    return x * 2000 + y;
}

pair<int, int> decode(int num){
    if (num == -2001) return make_pair(-1, -1);
    return make_pair(num / 2000, num % 2000);
}

bool not_in_board(pair<int, int> coo){
    return (coo.first < 0 || coo.first >= n) || (coo.second < 0 || coo.second >= m);
}

void read(){
    for (int x = 0; x < n; x++){
        cin >> s; //cout << s << "\n";
        for (int y = 0; y < m; y++){ 
            if (s[y] == 'U') move_to = make_pair(x-1, y);
            if (s[y] == 'D') move_to = make_pair(x+1, y);
            if (s[y] == 'L') move_to = make_pair(x, y-1);
            if (s[y] == 'R') move_to = make_pair(x, y+1);

           if (not_in_board(move_to)){
                dest[encode(x, y)] = encode(-1, -1);
                ans[encode(x, y)] = 1;
            }
            else{
                dest[encode(x, y)] = encode(move_to.first, move_to.second);
                ans[encode(x, y)] = -1;
            }
        }
    }
    // cout << "\n";
}

void find_cycle(int x, int y){
}

void dfs(int x, int y){
    curr = encode(x, y);
    route_length = 0;
    while (true){
        decoder = decode(curr);
        // cout << decoder.first << " " << decoder.second << " ";
        if (rec_stack[curr]){
            // cout << "found cycle" << " ";
            cycle_begin = dest[curr];

            decoder = decode(cycle_begin);
            // cout << decoder.first << " " << decoder.second << " ";
            cycle_length = 1;

            while (cycle_begin != curr){
                rec_stack[cycle_begin] = false;
                cycle_length++;
                cycle_begin = dest[cycle_begin];
            }

            // cout << "done cycle" << " ";
            decoder = decode(cycle_begin);
            // cout << decoder.first << " " << decoder.second << " ";
            // cout << "cycle length" << " " << cycle_length << " ";

            rec_stack[cycle_begin] = false;
            ans[cycle_begin] = cycle_length;
            cycle_begin = dest[cycle_begin];

            while (cycle_begin != curr){
                ans[cycle_begin] = cycle_length;
                cycle_begin = dest[cycle_begin];
            }
            
            route_length = route_length - cycle_length;
            // cout << "done cycle ans";
        }

        if (ans[curr] != -1){
            // cout << "calculated\n";
            route_begin = encode(x, y);

            while (route_begin != curr){
                rec_stack[route_begin] = false;
                ans[route_begin] = route_length + ans[curr];
                route_length--;
                route_begin = dest[route_begin];
            }

            break;
        }

        route_length++;
        rec_stack[curr] = true;
        curr = dest[curr];
        // cout << "\n";
    }
}

void printAns(){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cout << ans[encode(x, y)] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(){
    cin >> n >> m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            ans[encode(x, y)] = -1;
        }
    }
    read();

    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            dfs(x, y);
        }
    }

    int max_ans = 0, max_x, max_y;

    for (int x= 0; x < n; x++){
        for (int y = 0; y < m; y++){
            if (ans[encode(x, y)] > max_ans){
                max_ans = ans[encode(x, y)];
                max_x = x;
                max_y = y;
            }
        }
    }

    // printAns();

    cout << max_x + 1 << " " << max_y + 1 << " " << max_ans << "\n";

    // for (auto x: dest){
    //     for (auto y: x){
    //         cout << y.first << "," << y.second << ";";
    //     }
    //     cout << "\n";
    // }

    // for (auto x: ans){
    //     for (auto y: x){
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
}

int main(){
    cin >> t;
    for (int tt=0;tt<t;tt++){
        solve();
    }
}