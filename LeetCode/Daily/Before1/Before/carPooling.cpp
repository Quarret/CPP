#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    int cnt[1005]{};
    
    for (auto trip : trips) {
        int num = trip[0], from = trip[1], to = trip[2];
        cnt[from] += num;
        cnt[to] -= num;
    }

    int sum = 0;
    for (int i = 0; i < 1005; i++) {
        sum += cnt[i];
        if (sum > capacity) {
            return false;
        }
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
