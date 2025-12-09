#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
    int n = arrivals.size();
    unordered_map<int, int> mp;

    int ans = 0;
    for (int r = 0; r < n; r++) {
        int &x = arrivals[r];

        if (mp[x] == m) {
            x = 0;
            mp[x]++;
        } else mp[x]++;

        int l = r + 1 - w;
        if (l >= 0) {
            mp[arrivals[l]]--;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
