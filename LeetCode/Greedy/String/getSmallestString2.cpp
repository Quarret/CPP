#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string getSmallestString(string s, int k) {
    int n = s.size();
    
    for (int i = 0; i < n && k; i++) {
        int dis = min(s[i] - 'a', 26 - (s[i] - 'a'));
        if (k >= dis) {
            s[i] = 'a';
        } else {
            s[i] -= k;
        }

        k -= min(dis, k);
    }

    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
