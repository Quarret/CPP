#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> a;
    for (auto &row : grid) {
        for (int t : row) {
            a.push_back(t);
        }
    }
    
    ranges::sort(a);
    int n = a.size(), median = a[n / 2], ans = 0;
    for (int t : a) {
        int diff = abs(t - median);
        if (diff % x) return -1;
        ans += diff / x;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}