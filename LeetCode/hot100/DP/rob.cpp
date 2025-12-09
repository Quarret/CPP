#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n + 2);
    
    for (int i = 0; i < n; i++) {
        f[i + 2] = max(f[i] + nums[i], f[i + 1]);
    }
    
    return f[n + 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
