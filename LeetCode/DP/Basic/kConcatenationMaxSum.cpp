#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int kConcatenationMaxSum(vector<int>& arr, int k) {
    int n = arr.size(), MOD = 1e9 + 7;
    auto maxsubarr = [&](int repeat) -> int {
        int ans = 0, f = 0;
        for (int i = 0; i < n * repeat; i++) {
            f = max(f, 0) + arr[i % n];
            ans = max(ans, f);
        }

        return ans;
    };
    
    if (k == 1) return maxsubarr(1);
    int sum = reduce(arr.begin(), arr.end());
    long long ans = maxsubarr(2);
    ans += 1LL * max(sum, 0) * (k - 2);
    return ans % MOD; 
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
