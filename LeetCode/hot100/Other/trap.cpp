#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], height[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(min(pre[i], suf[i + 1]) - height[i], 0);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
