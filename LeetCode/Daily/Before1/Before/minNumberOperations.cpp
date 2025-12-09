#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 差分
int minNumberOperations(vector<int>& target) {
    int n = target.size();
    int ans = target[0];
    for (int i = 1; i < n; i++) {
        ans += max(target[i] - target[i - 1], 0);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
