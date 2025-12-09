#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxDistinct(string s) {
    int vis[26]{};
    
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (!vis[c]) {
            ans++;
        }
        vis[c] = 1;
    }

    return ans;
}    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
