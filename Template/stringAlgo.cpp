#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vt vector
#define forlr(i, l, r, k) for (int i = l; i < r; i += k)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define pb push_back

bool checkEqual(string s1, string s2){
    int len = s1.length();
    if (s2.length() != len) return 0;

    for0(i, len){
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

vt<int> findBorders(string s){
    int las = 0, len = s.length();
    vt<int> border(len + 1, 0);
    for1(i, len){
        while (las && s[las + 1] != s[i]) las = border[las];
        if (las + 1 < i && s[las + 1] == s[i]) las++;
        border[i] = las;
    }
    return border;
}

vt<int> KMP(string s1, string s2){
    int las = 0;
    vt<int> border = findBorders(s2);
    int len1 = s1.length(), len2 = s2.length();
    vt<int> q;
    int top = -1;
    for1(i, len1){
        while (las && s2[las + 1] != s1[i]) las = border[las];
        if (s2[las + 1] == s1[i]) las++;
        if (las == len2) q.pb(i - len2 + 1), las = border[las];
    }
    return q;
}