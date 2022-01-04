#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 4;
typedef long long ll;

void countingSort(vector<int> v){
    int cnt[N];
    for (int i = 0; i < N; i++) cnt[i] = 0;

    for (int i = 0; i < v.size(); i++) cnt[v[i]] += 1;

    for (int i = 1; i < N; i++) cnt[i] = cnt[i] + cnt[i - 1];

    int output[v.size()];
    for (int i = 0; i < v.size(); i++){
        output[cnt[v[i] - 1]] = v[i];
        --cnt[v[i]];
    }
}