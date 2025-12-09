#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool reorderedPowerOf2(int n) {
    unordered_map<string, int> mp;
    for (int i = 0; i <= 31; i++) {
        string s = to_string(1 << i);
        sort(s.begin(), s.end());
        mp[s] = 1;
    }
    
    string s = to_string(n);
    sort(s.begin(), s.end());

    return mp[s];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
