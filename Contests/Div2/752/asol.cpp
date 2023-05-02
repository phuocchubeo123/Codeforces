#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int N;
int a;
int max_a;
int after_max;
int curr_length;

int main(){
    cin >> T;
    // T = 1;

    for (int t = 0; t < T; t++){
        curr_length = 0;
        cin >> N;// cout << N << "\n";
        for (int n = 0; n < N; n++){
            cin >> a;// cout << a << " ";
            if (a > curr_length){
                curr_length = a;
            }

            else{
                curr_length++;
            }
        }
        cout << max(curr_length - N, 0) << "\n";
        // cout << "\n";
    }
}