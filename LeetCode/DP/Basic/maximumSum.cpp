#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> f0(n + 2), f1(n + 2);
    
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        f0[i + 2] = max(f0[i + 1], 0) + arr[i];
        f1[i + 2] = max({f1[i + 1], f0[i], 0}) + arr[i];
        ans = max({ans, f0[i + 2], f1[i + 2]});
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
