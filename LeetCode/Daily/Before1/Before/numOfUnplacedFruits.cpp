#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();
    vector<int> vis(n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && baskets[j] >= fruits[i]) {
                ok = 0;
                vis[j] = 1;
                break;
            }
        }
        ans += ok;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
