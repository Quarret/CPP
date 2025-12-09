#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int beautifulBouquet(vector<int>& flowers, int cnt) {
    int n = flowers.size(), l = 0, ans = 0;
    vector<int> vis(100005, 0);

    for (int r = 0; r < n; r++) {
        vis[flowers[r]]++;

        while (vis[flowers[r]] > cnt) {
            vis[flowers[l]]--;
            l++;
        }

        ans += r - l + 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
