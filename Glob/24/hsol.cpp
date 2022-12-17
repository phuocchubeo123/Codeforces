#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define vi vector<int>

const short maxn = 5004;
const short INF = 15100;

vector<vector<short>> grid(maxn, vector<short>(maxn));
vector<short> vis(maxn);
vector<int> dis(maxn), dis2(maxn);
short r, c, k;
short source, target;

bool valid(short x, short y){
  return ((0 <= x) && (x < r) && (0 <= y) && (y < c));
}

short to_short(short x, short y){
  return x * c + y;
}

void solve(){
  cin >> r >> c >> k;

  short max_door = 0;

  forn(i, r){
    string s;
    cin >> s;
    forn(j, c){
      if (s[j] == '.') grid[i][j] = 0;
      if (s[j] == 'D'){
        grid[i][j] = 1;
        max_door++;
      }
      if (s[j] == '#') grid[i][j] = 2;
      if (s[j] == 'A'){
        grid[i][j] = 3;
        source = to_short(i, j);
      }
      if (s[j] == 'B'){
        grid[i][j] = 4;
        target = to_short(i, j);
      }
    }
  }

  priority_queue<pair<int, short>> pq;

  vector<pair<short, short>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  pq.push({0, source});
  forn(i, r){
    forn(j, c){
      dis[to_short(i, j)] = 1e9;
      dis2[to_short(i, j)] = 1e9;
    }
  }
  dis[source] = 0;
  // cout << source << " " << source / c << " " << source % c << "\n";
  int ans = 1e9;
  for (short door_num = 0; door_num <= max_door; door_num++){
    for (short i = 0; i < maxn; i++) vis[i] = 0;
    
    while (!pq.empty()){
      pair<int, short> curr = pq.top();
      pq.pop();
      
      short x = curr.second / c, y = curr.second % c;
      int cost = -curr.first;
      vis[curr.second] = 1;
      
      for (auto p: directions){
        short u = x + p.first, v = y + p.second;
        // cout << u << " " << v << "\n";
        if (!valid(u, v)) continue;
        if (vis[to_short(u, v)] == 1){
          continue;
        }
      
        if (grid[u][v] == 2){
          continue;
        }
      
        else if (grid[u][v] == 1){
          dis2[to_short(u, v)] = min(cost + 2, dis2[to_short(u, v)]);
        }
      
        else if (grid[u][v] == 4){
          dis[to_short(u, v)] = min(cost + 1, dis[to_short(u, v)]);
          ans = min(ans, dis[to_short(u, v)] + max(door_num, k) - k);
        }
      
        else{
          if (vis[to_short(u, v)] == 1){
            continue;
          }
          dis[to_short(u, v)] = min(cost + 1, dis[to_short(u, v)]);
          pq.push({-dis[to_short(u, v)], to_short(u, v)});
        }
      }
    }
    
    // for (short i = 0; i < r; i++){
    //   for (short j = 0; j < c; j++){
    //     cout << dis[to_short(i, j)] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "\n";
    
    for (short i = 0; i < r; i++){
      for (short j = 0; j < c; j++){
        if (dis2[to_short(i, j)] < 1e9) pq.push({-dis2[to_short(i, j)], to_short(i, j)});
        dis[to_short(i, j)] = dis2[to_short(i, j)];
        dis2[to_short(i, j)] = 1e9;
      }
    }
    // if (door_num == 1) return;
  }

  if (ans == 1e9){
    cout << "HAHAHUHU\n";
  }
  else cout << ans << "\n"; 
}

int main(){
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--){
    solve();
  }
}