#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    vector<vector<int>> d(3000, vector<int>(15, 0));
    for (int i = 0; i < 3000; i++){
        d[i][1] = 31;
        d[i][3] = 31;
        d[i][5] = 31;
        d[i][7] = 31;
        d[i][8] = 31;
        d[i][10] = 31;
        d[i][12] = 31;
        d[i][4] = 30;
        d[i][6] = 30;
        d[i][9] = 30;
        d[i][11] = 30;
    }

    for(int i = 0; i < 3000; i++){
        if (i % 400 == 0){
            d[i][2] = 29;
        }
        else{
            if (i % 100 == 0){
                d[i][2] = 28;
            }
            else{
                if (i % 4 == 0){
                    d[i][2] = 29;
                }
                else{
                    d[i][2] = 28;
                }
            }
        }
    }

    int curr = 2023;
    int y;
    cin >> y;

    int tdy = 6;

    while (curr < 2040){
        for (int i = 1; i <= 12; i++){
            (tdy += d[curr][i]) %= 7;
        }
        curr++;
    }

    while (curr > y){
        curr--;
        for (int i = 1; i <= 12; i++){
            (tdy += 60 - d[curr][i]) %= 7;
        }
    }



    int ans = 0;
    for (int i = 1; i <= 12; i++){
        int rem = d[y][i];
        if (tdy != 0){
            rem -= (7 - tdy);
            ans++;
            tdy = 0;
        }
        ans += (rem + 6) / 7;
        (tdy += rem) %= 7;
    }

    cout << ans << "\n";
}