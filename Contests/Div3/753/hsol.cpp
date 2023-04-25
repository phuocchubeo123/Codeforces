#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Dish{
    int min_remain;
    int max_remain;    
    int will_remain;
    int index;
    bool active = true;
};

const int MAXX = 1e6 + 4;
int T;
int N;
int a, b, m, max_taste, dish_after;
vector<int> A, B, M;
array<vector<int>, MAXX> D;
map<int, vector<Dish>> dish_after_map;
map<int, vector<Dish>>::iterator it;
vector<Dish> sort_min_remain;
vector<int> sort_max_remain;
array<pair<int, int>, MAXX> ans;
set<pair<int, int>> ans_pairs;

void read(){
    cin >> N;
    for (int n = 0; n < N; n++){
        cin >> a >> b >> m;
        A.push_back(a), B.push_back(b); M.push_back(m);

        Dish dish;
        dish.min_remain = max(a - m, 0);
        dish.max_remain = min(a, a + b - m);
        dish.index = n;

        dish_after = a + b - m;
        it = dish_after_map.find(dish_after);

        if (it == dish_after_map.end()){
            dish_after_map[dish_after] = {dish};
        }

        else{
            dish_after_map[dish_after].push_back(dish);
        }
    }
}

bool sortMinRemain(Dish dish1, Dish dish2){
    return dish1.min_remain < dish2.min_remain;
}

bool sortMaxRemain(int i, int j){
    return sort_min_remain[i].max_remain < sort_min_remain[j].max_remain;
}

void solve(){
    int ans = 0;
    for (auto &dish: dish_after_map){
        sort_max_remain.clear(); sort_min_remain.clear();
        int i = 0;
        for (auto x: dish.second){
            sort_max_remain.push_back(i);
            sort_min_remain.push_back(x);
            i++;
        }

        sort(sort_min_remain.begin(), sort_min_remain.end(), sortMinRemain);
        sort(sort_max_remain.begin(), sort_max_remain.end(), sortMaxRemain);

        // for (auto x: sort_min_remain){
        //     cout << x.min_remain << ", " << x.max_remain << "; ";
        // }
        // cout << "\n";

        // for (auto x: sort_max_remain){
        //     cout << sort_min_remain[x].min_remain << ", " << sort_min_remain[x].max_remain << "; ";
        // }
        // cout << "\n";

        int curr = 0;
        // cout << sort_max_remain.size() << "\n";

        for (auto x: sort_max_remain){
            // cout << x << " " << sort_min_remain[x].min_remain << " " << sort_min_remain[x].max_remain << "\n";
            Dish correspond_dish = sort_min_remain[x];

            if (not correspond_dish.active) continue;

            while (true){
                if (curr == sort_max_remain.size()) break;

                // cout << sort_min_remain[curr].min_remain << " " << sort_min_remain[curr].max_remain << "; ";
                if (sort_min_remain[curr].min_remain > correspond_dish.max_remain) break;

                else{
                    sort_min_remain[curr].active = false;
                    int ind = sort_min_remain[curr].index;
                    ans_pairs.insert({correspond_dish.max_remain, dish.first - correspond_dish.max_remain});
                    A[ind] = A[ind] - correspond_dish.max_remain;
                    B[ind] = B[ind] - dish.first + correspond_dish.max_remain;
                    curr++;
                }
            }
            // cout << "\n";
        }
    }
}

void printTest(){
    for (auto &dish: dish_after_map){
        cout << dish.first << "\n";
        for (auto chef: dish.second){
            cout << chef.min_remain << ", " << chef.max_remain << "; ";
        }
        cout << "\n";
    }

    cout << "\n";
}

int main(){
    cin >> T;
    for (int t = 0; t < T; t++){
        dish_after_map.clear(); A.clear(); B.clear(); M.clear(); ans_pairs.clear();
        read();

        // if ((T > 61 && t == 61)){
        //     for (auto x: A) cout << x << " ";
        //     cout << "\n";
        //     for (auto x: B) cout << x << " ";
        //     cout << "\n";
        //     for (auto x: M) cout << x << " ";
        //     cout << "\n";
        // }

        // if ((T > 61 && t == 61) || (T <= 61)){
        solve();

        cout << ans_pairs.size() << "\n";

        for (int i = 0; i < A.size(); i++){
            cout << A[i] << " " << B[i] << "\n";
        }
        // }
        // printTest();
    }
}